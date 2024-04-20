#!/usr/bin/python3
# Example socket server based on file operations
# Depends on size of read buffer - blocks if the size
# of data received is smaller then argumet of read
# 
import os
import sys
import socket

if __name__ == "__main__":

    count = 2

    if len(sys.argv) < 2:
        print("Use: %s <addr:port> [<count>]", sys.argv[0])
        sys.exit(1)

 
    bufsize = int(sys.argv[2])
    if bufsize == 0:
        bufsize = 32

    host, port = sys.argv[1].split(':', 1)


    sock = socket.socket()
    sock.bind((host, int(port)))
    sock.listen()

    while count > 0:
        conn, addr = sock.accept()

        inp = conn.makefile(mode='r')

        line = inp.read(bufsize)
        print(line)
        inp.close()

        out = conn.makefile(mode='w')
        out.write("Data received")
        out.flush()
        out.close()

        conn.close()
        count -= 1

    sock.close()