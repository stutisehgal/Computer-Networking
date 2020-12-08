#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <time.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h> 
#include <netinet/in.h> 

int main()
{
    time_t clock;
	char send_date[1024]; 
	int client_listen = 0, client_connect = 0;
	
	struct sockaddr_in server_address;
	
	client_listen = socket(AF_INET, SOCK_STREAM, 0);
	
	memset(&server_address, '0', sizeof(server_address));
	memset(send_date, '0', sizeof(send_date));
	
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(1234); 	
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(client_listen, (struct sockaddr*)&server_address, sizeof(server_address));
	
	if(bind < 0)
		printf("Bind not successful");

	listen(client_listen, 20);
 
	while(1)
	{
		printf("\n\nConnected to Client");
		client_connect = accept(client_listen, (struct sockaddr*)NULL, NULL);
		clock = time(NULL);
		snprintf(send_date, sizeof(send_date), "%.24s\r\n", ctime(&clock)); 
		write(client_connect, send_date, strlen(send_date));
		printf("\n\nDate Sent");
		close(client_connect);
        sleep(1);
    }
     return 0;
}
