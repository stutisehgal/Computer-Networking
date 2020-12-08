#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "netdb.h"
#include "arpa/inet.h"

int main()
{
    char serverResponse[1000];
    char clientResponse[1000];

    //creating a socket
    int socketd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(1234);
    server_address.sin_addr.s_addr = INADDR_ANY;

    connect(socketd, (struct sockaddr *)&server_address, sizeof(server_address));

    while (1)
    { //recieve the data from the server
        recv(socketd, serverResponse, sizeof(serverResponse), 0);
        //recieved data from the server successfully then printing the data obtained from the server
        printf("\nSERVER : %s", serverResponse);

        printf("\nEnter Message :");
        scanf("%s", clientResponse);
        send(socketd, clientResponse, sizeof(clientResponse), 0);
    }

    //closing the socket
    close(socketd);
    return 0;
}
