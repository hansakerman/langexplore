29:20!!

/* httpd.c */

#include<netinet/in.h>
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

// don't listen/bind to internet.
//#define LISTENADDR "0.0.0.0"
// just localhost
#define LISTENADDR "127.0.0.1"

/* structures */
struct sHttpRequest {
  char method[8]; // "verb" example GET
  car url[128];
};
typedef struct sHttpRequest httpreq;
  
/* global */
char *error;

//The socketfile descriptor returned is an 'int'
/* returns 0 on erro, or it returns a socket fd */

int srv_init(int portno)
{
  int s;
  struct sockaddr_in srv;

  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0)
    {
      // global variable!
      error = "socket() error";
      return 0;
    }

  srv.sin_family = AF_INET;
  srv.sin_addr.s_addr = inet_addr(LISTENADDR);
  // htons ~ convert byte order ?? sumthing like that.
  srv.sin_port = htons(portno);

  // We are typecasting struct the "srv" pointer.
  if(bind(s, (struct sockaddr *)&srv, sizeof(srv)))
    {
      // global variable!
      error ="bind() error";
      return 0;
    }

  if (listen(s, 5))
    {
      close(s);
      error = "listen() error";
      return 0;
    }

  return s;
}

/* returns 0 on error, or return the new clients socket fd */
int cli_accept(int s)
{
  int c;
  socklen_t addrlen;
  struct sockaddr_in cli;

  addrlen = 0; // addrlen = sizeof(cli) ???
  memset(&cli, 0, sizeof(cli));
  c = accept(s, (struct sockaddr *)&cli, &addrlen);
  if (c < 0)
    {
      error = "accept() error";
      return 0;
    }

  return c;
}

/* returns 0 on error, or it returns a httpreq structure */

httpreq *parse_http(char *str)
{
  httpreq *req;
  char *p;
  
  reg = malloc(sizeof(httpreq));
  memset(&req, 0, sizeof(httpreq));

  for (p=str; p && *p != ' '; p++);
  if (*p == ' ')
  *p = 0;
  else
    {
      error = "parse_http() NOSPACE error";
      free(req);
      return 0;
    }

  // 29:20
void cli_conn(int s, int c){
  return;
}

// argc = argument count, argv = argument vector
int main(int argc, char *argv[])
{
  int s, c;
  char *port;
  char *template;
  httpreg *req;
  
  template =
    "GET /fileboar HTTP/1.1\n"
    "Host: 127.0.0.1:8181\n"
    "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:134.0) Gecko/20100101 Firefox/134.0\n"
    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\n"
    "Accept-Language: en-US,en;q=0.5\n"
    "Accept-Encoding: gzip, deflate, br, zstd\n"
    "Connection: keep-alive\n"
    "\n";

   n = strlen(template);
  reg = parse_http(template);
  printf("Method: '%s'\nURL: '%s'\n",
	 req->method, req-url);
  
  if (argc < 2)
    {
      fprintf(stderr, "ERROR: Usage: %s <listening port>\n", argv[0]);
      return -1;
    }
    else
      port = argv[1];
  
  // Create a socket.
  // atoi: ASCII to integer
  s = srv_init(atoi(port));
  if (!s)
    {
      fprintf(stderr, "%s\n", error);
      return -1;
    }

  printf("Listening on %s:%s\n", LISTENADDR,port);
  fflush(stdout);
  
  while(1)
    {
      c = cli_accept(s);
      if (!c)
	{
	  fprintf(stderr, "%s\n", error);
	  continue;
	}

      printf("Incoming connection\n");
      if (!fork())
	cli_conn(s, c);
      }

  return -1;
}



