#!/usr/bin/python3                                                      
import sys                                                              
import socket                                                           
                                                                        
MAX_RECV_SIZE = 10                                                      
if __name__ == "__main__":                                              
                                                                        
    if len(sys.argv) < 2:                                               
        print("Use: %s <addr:port> [<msg>]" % sys.argv[0])              
        sys.exit(1)                                                     
                                                                        
                                                                        
    try:                                                                
        host, port = sys.argv[1].split(':', 1)                          
    except:                                                             
        print("Use: %s <addr:port> [<msg>]" % sys.argv[0])              
        sys.exit(1)                                                     
                                                                        
    msg = " ".join(sys.argv[2:])                                        
    if len(msg) == 0:                                                   
        msg = "Connection initiated"                                    
    # Add ne line to nice lookng of trace on server side                
    msg += "\n"                                                         
                                                                        
    sock = socket.socket()                                              
                                                                        
    # Init connection                                                   
    sock.connect((host, int(port)))                                     
                                                                        
    # Send message                                                      
    cbuf = bytes(msg, "UTF-8")                                          
    sock.send(cbuf)                                                     
                                                                        
    # Get data from server nad print on stdout                          
    line = ""                                                           
    buf = sock.recv(MAX_RECV_SIZE)                                      
    cbuf = str(buf, "UTF-8")                                            
    print("Received data: >>%s<<" % cbuf)                               
    while len(buf) > 0:                                                 
        buf = sock.recv(MAX_RECV_SIZE)                                  
        cbuf = str(buf, "UTF-8")                                        
        # Print onlye received data     
        cbuf = str(buf, "UTF-8")                 
        # Print only received data              
        print("Received data: >>%s<<" % cbuf)    
        line += cbuf                             
                                                 
                                                 
    # Print result from server                   
    print(line)                                  
                                                 
    # Close connection                           
    sock.close()                                                                 