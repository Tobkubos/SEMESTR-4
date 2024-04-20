/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package eu.vctl.wfis;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author Nome
 */
public class SimpleServer
{
    static int count = 2; 
    static int backlog = 25;
    
    public static void main(String args[]) 
    {
        // Arguments
        //  
        if (args.length < 1) {
            System.out.format("Use: SimpleServer <[addr:]port> [<Welcome-message>]\n");
            System.exit(1);
        }

        try 
        {
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

            // Build welcome message
            StringBuilder message = new StringBuilder();
            
            for (int i = 1; i <= args.length-1; ++i)
            {
                message.append(args[i]);
                message.append(' ');
            }

            // ServerSocket implements AutoCloseable
            try (ServerSocket sock = new ServerSocket())
            {
                sock.bind(new InetSocketAddress(host, port), backlog);
                
                while (--count >= 0) {
                    // Socket implements AutoCloseable
                    try (Socket conn = sock.accept())
                    {
                        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(conn.getOutputStream()));
                        out.write(message.toString());
                        out.newLine();
                        out.flush();


                        BufferedReader inp = new BufferedReader(new InputStreamReader(conn.getInputStream()));
                        String line = inp.readLine();
                        System.out.println(line);
                    }
                }
            }
        }
        catch (IOException ex) 
        {
            ex.printStackTrace();
        }
    }

}
    