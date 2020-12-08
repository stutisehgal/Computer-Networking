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
    char send_msg[1000], recv_msg[1000];

    pid_t cpid;

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(1254);

    /*Creating a socket, assigning IP address and port number for that socket*/
    int socketd;
    socketd = socket(AF_INET, SOCK_STREAM, 0);

    /*Connect establishes connection with the server using server IP address*/
    connect(socketd, (struct sockaddr *)&server_address, sizeof(server_address));

    /*Fork is used to create a new process*/
    cpid = fork();
    if (cpid == 0)
    {
        while (1)
        {
            memset(send_msg, 0, sizeof(send_msg));
            printf("\nEnter Message : ");
            
            /*This function is used to read from server*/
            fgets(send_msg, 10000, stdin);
            
            /*Send the message to server*/
            if (send_msg[0] == 'E' && send_msg[1] == 'X' && send_msg[2] == 'I' && send_msg[3] == 'T')
                break;
            send(socketd, send_msg, strlen(send_msg) + 1, 0);
            printf("\nMessage sent to Server\n");
        }
    }
    else
    {
        while (1)
        {
            memset(recv_msg, 0, sizeof(recv_msg));
            
            /*Receive the message from server*/
            recv(socketd, recv_msg, sizeof(recv_msg), 0);
            if (recv_msg[0] == 'E' && recv_msg[1] == 'X' && recv_msg[2] == 'I' && recv_msg[3] == 'T')
                break;
            printf("\nSERVER : %s\n", recv_msg);
        }
    }
    return 0;
}
