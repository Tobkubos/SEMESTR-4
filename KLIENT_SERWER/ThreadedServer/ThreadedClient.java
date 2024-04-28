package eu.vctl.wfis;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.net.InetSocketAddress;
import java.net.Socket;

/**
 *
 * @author nome
 */
public class ThreadedClient 
{
    
    int    port = 0;
    String host = "127.0.0.1";
    String msg  = "";
    
    class ClientWriter implements Runnable {
        
        BufferedWriter out = null;
        ClientWriter(BufferedWriter out) {
            this.out = out;
        }
        
        @Override
        public void run()
        {
            long delay = (long) (10 * 1000 * Math.random());
            Boolean cont = true;
            while (cont)
            try
            {
                Thread.sleep(delay);
                String msg = String.format("Message after %d ms delay", delay); 
                out.write(msg);
                out.newLine();
                out.flush();
                delay = (long) (10 * 1000 * Math.random());
            } 
            catch (InterruptedException | IOException ex) {
                cont = false;
                //Logger.getLogger(ThreadedClient.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
    ThreadedClient(String host, int port, String msg)
    {
        this.host = host;
        this.port = port;
        this.msg  = msg;
    }
    
    void service() {
        try (Socket sock = new Socket())
        {
            sock.connect(new InetSocketAddress(host, port));
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));

            ClientWriter clientWriter = new ClientWriter(out); 
            Thread thread = new Thread(clientWriter);
            thread.start();
            BufferedReader inp = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            
            String srvrMsg = inp.readLine();
            while (srvrMsg != null && srvrMsg.length() > 0) {
                System.out.println(srvrMsg);
                srvrMsg = inp.readLine();
            }
        }
        catch (IOException ex) 
        {
            ex.printStackTrace();
        }
        
    }
    
    public static void main(String args[]) {
 
        if (args.length < 1) {
            System.out.format("Use: ThreadedClient <addr:port>\n");
            System.exit(1);
        }
        // Process argument list
        String[] dest = args[0].split(":", 2);
        String host = dest[0];
        int    port = Integer.parseInt(dest[1]);

        StringBuilder message = new StringBuilder();

        for (int i = 1; i <= args.length-1; ++i)
        {
            message.append(args[i]);
            message.append(' ');
        }

        ThreadedClient client = new ThreadedClient(host, port, message.toString());
        client.service();
        
    }

}