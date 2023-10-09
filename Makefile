#بسم الله الرحمن الرحيم

all:
	mkdir bin
	gcc src/main.c src/http_server.c -o bin/webserver

