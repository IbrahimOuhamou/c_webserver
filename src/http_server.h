//بسم الله الرحمن لارحيم

#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H
typedef struct HTTP_Server
{
  int socket;
  int port;
} HTTP_Server;

int init_Server(HTTP_Server *http_server, int port);
int connect_server(HTTP_Server *Http_server, int cli_fd);

#endif
