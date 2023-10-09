//بسم الله الرحمن لارحيم

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "http_server.h"

int init_Server(HTTP_Server *http_server, int port)
{
    http_server->port = port;

    http_server->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (0 > http_server->socket)
    {
        perror("ERROR: socket()\n");
        return -1;        
    }

    struct sockaddr_in s_addr;
    bzero((char*)&s_addr, sizeof(s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = INADDR_ANY;
    s_addr.sin_port = htons(http_server->port);
    if(0 > bind(http_server->socket, (struct sockaddr*)(&s_addr), sizeof(s_addr)))
    {
        perror("ERROR: bind()\n");
        return -1;
    }
    return 0;
}

int connect_server(HTTP_Server *http_server, int *cli_fd)
{
  if(0 > listen(http_server->socket, 5))
  {
    perror("ERROR: listen()\n");
    return -1;
  }

  socklen_t cli_len = sizeof(*cli_fd);
  *cli_fd = accept(http_server->socket, (struct sockaddr*)(cli_fd), &cli_len);
  if(0 > *cli_fd)
  {
    perror("ERROR: accept()\n");
    return -1;
  }

  return 0;
}

int send_html(HTTP_Server *HTTP_Server, const char* file_path, int *cli_socket)
{
  printf("BismiAllah: going to send file by the will of Allah\n");
  FILE* fp = fopen(file_path, "r");
  if (NULL == fp)
  {
    perror("file not open\n");
    return -1;
  }
  char buffer[2048];
  fgets(buffer, sizeof(buffer), fp);
  fclose(fp);

  char response_data[4096] = "HTTP/1.1/ 200 OK\r\n\r\n";
  strcat(response_data, response_data);
  strcat(response_data, "\r\n\r\n");

  send(*cli_socket, response_data, sizeof(response_data), 0);
}
