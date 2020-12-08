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
    char serverMessage[1000];
    char clientMessage[1000];
    //create the server socket
    int socketd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(1234);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //calling bind function to connect specified IP and port
    bind(socketd, (struct sockaddr *)&server_address, sizeof(server_address));

    listen(socketd, 5);

    //starting the accepting
    int client_socket = accept(socketd, NULL, NULL);

    while (1)
    {
        printf("\nEnter Message :");
        scanf("%s", serverMessage);
        send(client_socket, serverMessage, sizeof(serverMessage), 0);
        //recieve the data from the server
        recv(client_socket, &clientMessage, sizeof(clientMessage), 0);
        //recieved data from the server successfully then printing the data obtained from the server
        if (clientMessage[0] == 'e' & clientMessage[1] == 'x' && clientMessage[2] == 'i' && clientMessage[3] == 't')
            break;
        printf("\nCLIENT: %s", clientMessage);
        //close the socket
        close(socketd);
        sleep(1);
    }
    return 0;
}
