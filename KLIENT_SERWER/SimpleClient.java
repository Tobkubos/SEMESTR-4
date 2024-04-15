/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package eu.vctl.wfis;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;


/**
 *
 * @author Nome
 */
public class SimpleClient
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        
        if (args.length < 1) {
            System.out.format("Use: SimpleClient <addr:port>\n");
            System.exit(1);
        }
        try 
        {
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
            
            try (Socket sock = new Socket())
            {
                sock.connect(new InetSocketAddress(host, port));
                BufferedWriter out = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
                out.write(message.toString());
                out.newLine();
                out.flush();
                BufferedReader inp = new BufferedReader(new InputStreamReader(sock.getInputStream()));
                String line = inp.readLine();
                System.out.println(line);
            }
        }
        catch (IOException ex) 
        {
            ex.printStackTrace();
        }
    }
}