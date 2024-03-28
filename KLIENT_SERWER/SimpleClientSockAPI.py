#!/usr/bin/python3                                                      
import sys                                                              
import socket                                                           
                                                                        
MAX_RECV_SIZE = 10                                                      

def receive_lines(sock, num_lines, end_sequence):
    lines_received = 0
    received_data = ""

    while lines_received < num_lines:
        buf = sock.recv(MAX_RECV_SIZE)
        if not buf:
            break
        received_data += buf.decode("UTF-8")
        lines = received_data.split('\n')
        for line in lines[:-1]:
            print("Received data: >>%s<<" % line)
            lines_received += 1
            if end_sequence in line:
                return
        received_data = lines[-1]

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Use: %s <addr:port> <num_lines> <end_sequence>" % sys.argv[0])
        sys.exit(1)

    try:
        host, port = sys.argv[1].split(':', 1)
        num_lines = int(sys.argv[2])
    except:
        print("Use: %s <addr:port> <num_lines> <end_sequence>" % sys.argv[0])
        sys.exit(1)

    end_sequence = "+++"  # Default end sequence
    if len(sys.argv) >= 4:
        end_sequence = sys.argv[3]

    sock = socket.socket()

    try:
        sock.connect((host, int(port)))
    except Exception as e:
        print("Error connecting to server:", e)
        sys.exit(1)

    try:
        receive_lines(sock, num_lines, end_sequence)
    except Exception as e:
        print("Error receiving data from server:", e)

    sock.close()