#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <iconv.h>
#include <signal.h>

#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/utsname.h>
#include <arpa/inet.h>

#define BUFFER_SIZE (1024*1024)

typedef struct {
    short port;
    char* addr;
    int   debug;
} parms_t;

char inpbuf[BUFFER_SIZE];
char outbuf[BUFFER_SIZE];
char cnvbuf[BUFFER_SIZE]; /* For iconv */
void pid_printf(const char* msg, ...);
void pid_perror(char* msg);
char* get_cmdline(char* argv[], int start, int limit); 

void init_parms(parms_t *parms, int argc, char* argv[])
{
    int opt;

    parms->debug    = 0;
    parms->addr     = NULL;
    parms->port     = 0;

    while ((opt = getopt(argc, argv, ":p:a:d:")) != -1) {
        /* printf("%c %s\n", opt, *__opargf()); */
        switch (opt) {
        case 'p': /* Port number */
            parms->port = (short) atoi(optarg);
            break;
        case 'a': /* Listen address */
            parms->addr = optarg;
            break;
        case 'd': /* Enable debug info */
            printf("%s\n", optarg);
            parms->debug = atoi(optarg);
            break;
        case ':':
            printf("Invalid parm value\n!");
        default:
            printf("%c\n", opt);
        }
    }
    if (parms->addr == NULL | parms->port == 0 ) {
        printf("Use %s -a <addr> -p <port> [-d <level>] [message]\n", argv[0]);
        exit(1);
    }
       
}

in_addr_t convipv4(char* addrstr) {

    char *octet;
    char* buffer = malloc(strlen(addrstr) + 1);

    if (buffer == NULL) {
        /* if moc error - give safe response */
        return htonl(INADDR_ANY);
    }

    in_addr_t addr = (in_addr_t) 0;
    strcpy(buffer, addrstr);

    octet = strtok(buffer, ".");
    while (octet != NULL) {
      addr = (addr << 8) | (unsigned char) atoi(octet);
      octet = strtok(NULL, ".");
    }
    free(buffer);
    return htonl(addr);
}


int main(int argc, char* argv[]) {

  parms_t parms;
  char*   noptarg;
  char*   cmdline = "";


  int sock = -1;
  int count = -1;
  pid_t pid = 0;
  pid_t fpid = 0;
  int rc = 0;

  pid = getpid();

  init_parms(&parms, argc, argv);

  if (optind < argc) {
    cmdline = get_cmdline(argv, optind, argc);
    //printf("%s\n", cmdline);
  }



  struct sockaddr_in servaddr, connaddr;

  servaddr.sin_family = AF_INET;

  /* read address from command line */
  if (parms.addr != NULL) {
      servaddr.sin_addr.s_addr = convipv4(parms.addr);
      if (parms->debug > 0) {
          pid_printf("IP address for connect: %s <0x%8.8X>\n", 
                     parms.addr, 
                     servaddr.sin_addr.s_addr);
      }
  }
  else {
      pid_printf("No IP address specified, exiting!\n"); 
      rc = 1;
  }
  servaddr.sin_port = htons(parms.port);

  sock = socket(AF_INET, SOCK_STREAM, 0);

  if (sock < 0) {
    pid_perror("SOCKET: ");
    rc = 1;
  }


  if (connect(sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
    pid_perror("CONNECT: ");
    rc = 1;
  }

  count = snprintf(cnvbuf, sizeof(cnvbuf), "%s\n", cmdline);
  count = write(sock, cnvbuf, count); 
  if (count == -1) {
    pid_perror("WRITE: ");
    rc = 1;
  }
    

  count = read(sock, cnvbuf, sizeof(cnvbuf));
  if (count == -1) {
    pid_perror("READ: ");
    rc = 1;
  }

  pid_printf("%.*s\n", count, cnvbuf);

  close(sock);
  if (count == -1) {
    pid_perror("CLOSE: ");
    rc = 1;
  }

finally:
  if (strlen(cmdline) > 0 ) {
    free(cmdline);
  }
  pid_printf("Main process finished\n");
  return rc;
  
    
}



void pid_printf(const char* format, ...) {
    pid_t pid = getpid();
    char* fmtptr = NULL;
    int   fmtlen = 0;
    char* bufptr = NULL;
    int   buflen = 0;
    char* fmtpfx = "%8.8X ";

    printf("%8.8X ", pid);
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    fflush(stdout);
    return;
}

void pid_perror(char* msg) {
    pid_t pid = getpid();
    char* bufptr = NULL;
    int   buflen = 0;

    buflen = 8 + 1 + strlen(msg) + 1;
    bufptr = malloc(buflen);

    if (bufptr) {
        snprintf(bufptr, buflen, "%8.8X %s", pid, msg);
        perror(bufptr);
        fflush(stderr);
        free(bufptr);
    }


    return;
}

#define BUF_CHUNK_SIZE  256

char* get_cmdline(char* argv[], int start, int limit) {
    char* bufptr = NULL;
    char* bufpos = NULL;
    int   buflen = 0;
    int   count = 0;


    for (int i = start; i < limit; ++i) {
      buflen += strlen(argv[i]) + 1;
    }
    ++buflen; /* last postion for null character */

    bufptr = malloc(buflen);
    
    if (bufptr) {
      bufpos = bufptr;
      for (int i = start; i < limit; ++i) {
        count = sprintf(bufpos, "%s ", argv[i]);
        bufpos += count;
      }
    }


    return bufptr;
}
/* vim: set sw=4: */