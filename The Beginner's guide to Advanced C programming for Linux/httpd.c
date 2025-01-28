// 12:30 fixa headers från en annan fil

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
  char url[128];
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
  
  req = malloc(sizeof(httpreq));

  for (p=str; *p && *p != ' '; p++);
  if (*p == ' ')
  *p = 0;
  else
    {
      error = "parse_http() NOSPACE error";
      free(req);

      return 0;
    }
  strncpy(req->method, str, 7);
  
  for (str=++p; *p && *p != ' '; p++);
  if (*p == ' ')
  *p = 0;
  else
    {
      error = "parse_http() 2ND SPACE error";
      free(req);

      return 0;
    }

  
  strncpy(req->url, str, 127);
  return req;
}

/* return 0 on error, or return the data */
char *cli_read(int c)
{
  static char buf[512];

  memset(buf, 0, 512);
  if (read(c, buf, 511) < 0)
    {
      error = "read() error";
      return 0;
    }
  else
    return buf;
}

void http_response(int c, char *contenttype, char *data)
{
  char buf[512];
  int n;

  n = strlen(data);
  memset(buf, 0, 512);
  snprintf(buf, 511,
	   "Content-Type: %s\n"
	   "Content-Length: %d\n"
	   "\n%s\n",
	   contenttype, n, data);
  
  n = strlen(buf);
  write(c, buf, n);

  return;
}

void http_headers(int c, int code)
{
  char buf[512];
  int n;
  
  memset(buf, 0, 512);
  snprintf(buf, 511,
	   "HTTP/1.0 %d OK\n"
	   "Server: httpd.c\n"
	   "Content-Language: en\n"
	   "Expires: -1\n"
	   "X-Frame-Options: SAMEORIGIN\n",
	   code);

  n = strlen(buf);
  write(c, buf, n);

  return;
	



/* X-XSS-Protection: 0 */
/* X-Frame-Options: SAMEORIGIN */	   
}

  
void cli_conn(int s, int c){
  httpreq *req;
  char buf[512]; //needed
  char *p;
  char *res;



  p = cli_read(c);
  if (!p)
    {
      fprintf(stderr, "%s\n", error);
      close(c);

      return;
    }

  req = parse_http(p);
  if (!req)
    {
      fprintf(stderr, "%s\n", error);
      close(c);

      return;
    }

  if ((!strcmp(req->method, "GET")) && (!strcmp(req->url, "/app/webpage")))
    {
      res = "<html>Hello world</html>";
      http_headers(c, 200); /* 200 = everything ok */
      http_response(c, "text/html", res);
    }
  else
    {
      res = "File not found";
      http_headers(c, 404); /* 404 = file not found */
      http_response(c, "text/plain", res);
    }
  
  free(req);
  close(c);

  return;
}

// argc = argument count, argv = argument vector
int main(int argc, char *argv[])
{
  int s, c;
  char *port;
  
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



