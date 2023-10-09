//بسم الله الرحمن الرحيم

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "http_server.h"

int client_socket;

int main()
{
    printf("in the name of Allah\n");
    HTTP_Server server;
    init_Server(&server, 2000);
    connect_server(&server, &client_socket);

    char client_msg[4096];
    read(client_socket, client_msg, sizeof(client_msg) - 1);

    send_html(&server, "BismiAllah.html", &client_socket);
}
