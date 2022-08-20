#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define PORT portnumber	

int main(int argc , char *argv[])
{
	printf("Receiving bytes from reader\n");	
	int socket_desc;
	struct sockaddr_in server;
	char *message , server_reply[800];
	int flag=0;
	int nbytes;
	
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket\n");
	}
	
	//ip address reader
	server.sin_addr.s_addr = inet_addr("card reader ip");
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);




	//Connect to Reader
	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		printf("connect error\n");
		return 1;
	}
	
	printf("Connected\n");
	
	
	//Receive a reply from the server
	nbytes= recv(socket_desc, server_reply , 800 , flag);
	if( nbytes < 0)
	{
		printf("Reader failed\n");
	}
	printf("From Reader\n");
	//prints output from the cardreader
	puts(server_reply);
	printf("No. of Bytes = %d\n",nbytes);
	
	return 0;
}
 
