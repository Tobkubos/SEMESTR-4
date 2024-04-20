package eu.vctl.wfis.clntsrvr;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.channels.ByteChannel;
import java.nio.channels.Channels;
import java.nio.channels.SelectableChannel;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.nio.charset.CharsetDecoder;
import java.nio.charset.StandardCharsets;
import java.util.Set;
import java.net.Socket;
import java.net.SocketAddress;
import java.net.InetSocketAddress;
import java.net.ServerSocket;

public class ParallelServer {
    static int port = 8888;
    
    
	public static void main(String[] args) {
		
		boolean eod = false;
		CharsetDecoder decoder = StandardCharsets.UTF_8.newDecoder();
		try {
			Selector sel = Selector.open();
			
			try (ServerSocketChannel sock = ServerSocketChannel.open()) {
				// 
				sock.bind(new InetSocketAddress(port)); 
				SocketChannel conn = sock.accept();
				//ios
				//BufferedReader rdr = new BufferedReader(Channels.newReader(conn, "UTF-8"));
				//BufferedWriter wrt = new BufferedWriter(Channels.newWriter(conn, "UTF-8"));
				Reader rdr = Channels.newReader(conn, "UTF-8");
				Writer wrt = Channels.newWriter(conn, "UTF-8");
				
				Object[] ios = {rdr, wrt };
				
				conn.configureBlocking(false);
				SelectionKey connKey = conn.register(sel, SelectionKey.OP_READ, ios);
				while (! eod) {
					int count = sel.select();
					Set<SelectionKey> selectionKeys = sel.selectedKeys();
					for (SelectionKey selectionKey : selectionKeys) {
						ByteBuffer buf = ByteBuffer.allocate(1024);
						CharBuffer cbuf = CharBuffer.allocate(1024);
						
						ByteChannel channel = (ByteChannel) selectionKey.channel();
						count = channel.read(buf);
						//ios = (Object[]) selectionKey.attachment();
						//rdr = (Reader) ios[0];
						//wrt = (Writer) ios[1];

						//int ch = rdr.read();
						if (count == -1) {
							eod = true;
						}
						else {
							buf.flip();
							decoder.decode(buf, cbuf, true);
							cbuf.flip();
							StringBuilder out = new StringBuilder();
							out.append(cbuf);
							cbuf.clear();
							System.out.println(out.toString());
							
						}
						rdr.close();
						
					}
				}
			}
			catch (IOException ex) {
				System.err.println(ex.getMessage());
			}
		}
		catch (IOException ex) {
			System.out.println(ex.getMessage());
		}
	}

}