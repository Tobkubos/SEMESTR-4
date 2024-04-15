client: client.c
	gcc -g -o $@ $^
readfile: readfile.c
	gcc -g -o $@ $^