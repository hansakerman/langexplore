/* httpd.c */

#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// don't listen/bind to internet.
//#define LISTENADDR "0.0.0.0"
// just localhost
#define LISTENADDR "127.0.0.1"

/* global */
char *error;

// The socket file descriptor returned is an 'int'
/* returns 0 on error, or it returns a socket fd */

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
    // htons ~ convert byte order ?? something like that.
    srv.sin_port = htons(portno);

    // We are typecasting struct the "srv" pointer.
    if (bind(s, (struct sockaddr *)&srv, sizeof(srv)))
    {
        // global variable!
        error = "bind() error";
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

/* returns 0 on error, or returns the new client's socket fd */
int cli_accept(int s)
{
    int c;
    socklen_t addrlen;
    struct sockaddr_in cli;

    addrlen = sizeof(cli);
    memset(&cli, 0, sizeof(cli));
    c = accept(s, (struct sockaddr *)&cli, &addrlen);
    if (c < 0)
    {
        error = "accept() error";
        return 0;
    }

    return c;
}

void cli_conn(int s, int c)
{
  return;
  // Handle the client connection here
    //close(c); // Close the client socket after handling
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

    printf("Listening on %s:%s\n", LISTENADDR, port);

    while (1)
    {
        c = cli_accept(s);
        if (!c)
        {
            fprintf(stderr, "%s\n", error);
            continue;
        }

        printf("Incoming connection\n");
        if (fork() == 0)
        {
            // Child process
            cli_conn(s, c);
            exit(0); // Exit the child process after handling the client
        }
        close(c); // Parent process closes the client socket
    }

    return 0;
}

