//بسم الله الرحمن لارحيم

#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H
typedef struct HTTP_Server
{
  int socket;
  int port;
} HTTP_Server;

int init_Server(HTTP_Server *http_server, int port);
int connect_server(HTTP_Server *http_server, int *cli_fd);

int get_client_response(int cli_socket);
int send_html(HTTP_Server *HTTP_Server, const char* html_file);

#endif
