//بسم الله الرحمن لارحيم

typedef struct HTTP_Server
{
  int socket;
  int port;
} HTTP_Server;

void init_Server(HTTP_Server *http_server, int port);

