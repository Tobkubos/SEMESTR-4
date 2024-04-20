import sys        
import socket     
import selectors  
                  
addr = '0.0.0.0'  
port = 8888       
                  

selector = selectors.DefaultSelector()                           
                                                                 
                                                                 
sock = socket.socket()                                           
                                                                 
sock.bind((addr, port))                                          
sock.listen()                                                    
conn, info = sock.accept()                                       
                                                                 
conn.setblocking(False)                                          
                                                                 
selector.register(conn, selectors.EVENT_READ)                    
selector.register(sys.stdin, selectors.EVENT_READ)               
                                                                 
eod = False                                                      
while not eod:                                                   
    objects = selector.select(timeout=15)                        
                                                                 
    if len(objects):                                             
        for key, mask in objects:                                
            if key.fileobj == conn:                              
                rmt_line = str(key.fileobj.recv(1024), "utf-8")  
                if len(rmt_line) == 0:                           
                    eod = True                                   
                else:                                            
                    print(rmt_line)                              
            elif key.fileobj == sys.stdin:                       
                try:                                             
                    lcl_line = input()                           
                    lcl_line += "\n"                             
                    conn.send(bytes(lcl_line, "utf-8"))          
                except EOFError as ex:                           
                    eod = True                                   
                                                                 
    else:                                                        
        print("Timeout")                                         
                                                                 
print("Server closed connection")                                
conn.close()                                                     
                                                                 
sock.close()                                                     