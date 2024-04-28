package eu.vctl.wfis;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.channels.ByteChannel;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.nio.charset.CharsetDecoder;
import java.nio.charset.StandardCharsets;
import java.util.Set;
import java.net.InetSocketAddress;
import java.net.StandardSocketOptions;



public class ThreadedServer  {
    
    String consMessage = null;
    ConsoleWorker consWorker = null;
    
    private class ConsoleWorker implements Runnable {

        @Override
        public void run()
        {
            Boolean eod = false;
            BufferedReader rdr = new BufferedReader(new InputStreamReader(System.in));
            
            while (! eod) {
                try {
                    String line = rdr.readLine();
    
                    synchronized (this) {
                        consMessage = line + "\r\n";
                        System.out.format(">>%s<<", consMessage);
                    }
                }
                catch (IOException ex) {
                    System.exit(0);
                }
            }
        }
        
    }
    
    private class ServerWorker implements Runnable {

        SocketChannel conn = null;

        ServerWorker(SocketChannel conn) {
            this.conn = conn;
        }
   
    
        public void service() throws IOException {

            CharsetDecoder decoder = StandardCharsets.UTF_8.newDecoder();
            ByteBuffer buf = ByteBuffer.allocate(10);
            CharBuffer cbuf = CharBuffer.allocate(10);

            conn.configureBlocking(false);

            Selector sel = Selector.open();

            // Register connection stream to selection for read operation
            SelectionKey connKey = conn.register(sel, SelectionKey.OP_READ | SelectionKey.OP_WRITE);
            //ByteChannel fifo = Files.newByteChannel(Path.of("thrdserv-inp"), StandardOpenOption.READ);
            //SelectionKey consKey = fifo.register(sel, SelectionKey.OP_READ);  
            
            boolean eod = false;

            while (! eod) {
                int count = sel.select(1000);
                Set<SelectionKey> selectionKeys = sel.selectedKeys();
                for (SelectionKey selectionKey : selectionKeys) {
                    if (selectionKey == connKey) {
                        if (selectionKey.isReadable()) {
                            buf.rewind();
                            cbuf.rewind();

                            ByteChannel channel = (ByteChannel) selectionKey.channel();
                            count = channel.read(buf);

                            while (count > 0) {
                                // Data arrived
                                buf.flip();
                                decoder.decode(buf, cbuf, true);
                                cbuf.flip();
                                StringBuilder out = new StringBuilder();
                                out.append(cbuf);
                                cbuf.clear();
                                System.out.print(out.toString());
                                buf.clear();
                                count = channel.read(buf);  
                            }

                            if (count == -1) {
                                // Remote connection closed
                                eod = true;
                            }
                        }

                        //if (selectionKey == consKey && selectionKey.isReadable()) {
                        if (selectionKey.isWritable() && consMessage != null) {
                            ByteChannel channel = (ByteChannel) selectionKey.channel();
                            synchronized (consWorker) {    
                                ByteBuffer outbuf = ByteBuffer.wrap(consMessage.getBytes());
                            
                                count = channel.write(outbuf);
                                System.out.format("Count: %d\n", count);
                                consMessage = null;
                            }
                        }
                    }
                }
            }
        }   

        @Override
        public void run()
        {
            try {
                service();
            }
            catch (IOException ex) {
                System.err.println(ex.getMessage());
            }
        }
    }

    String host = null;
    int    port = 0;
    
    public ThreadedServer(String host, int port) {
        this.host = host;
        this.port = port;
    }

    public void listen() {
        try (ServerSocketChannel sock = ServerSocketChannel.open()) {
            // 
            sock.bind(new InetSocketAddress(port)); 
            // Run thread reading console
            consWorker = new ConsoleWorker();
            Thread consThread = new Thread(consWorker);
            consThread.start();
            
            
            while (true) {
                SocketChannel conn = sock.accept();
                conn.setOption(StandardSocketOptions.TCP_NODELAY, true);
                // Create new worker for servicing new connection
                ServerWorker wrk = new ServerWorker(conn);
                Thread thread = new Thread(wrk);
                thread.start();
            }
        }
        catch (IOException ex) {
                System.err.println(ex.getMessage());
        }
    }


    
    public static void main(String[] args) {

        // Process argument list
        String[] dest = args[0].split(":", 2);
        String host = "0.0.0.0";
        int    port = 0;

        if (dest.length == 1) {
            port = Integer.parseInt(dest[0]);
        }
        else {
            host = dest[0];
            port = Integer.parseInt(dest[1]);
        }
        
        ThreadedServer server = new ThreadedServer(host, port);
        server.listen();
    }

    
}