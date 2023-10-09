//بسم الله الرحمن الرحيم

#include <stdio.h>
#include "http_server.h"

int cli_socket;

int main()
{
    printf("in the name of Allah\n");
    HTTP_Server server;
    init_Server(&server, 2000);
    connect_server(&server, &cli_socket);
}
