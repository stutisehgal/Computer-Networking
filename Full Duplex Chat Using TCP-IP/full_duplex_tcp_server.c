
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int client_socket, socketd;

    socklen_t clientLength;

    char recv_msg[1000], send_msg[1000];
    pid_t cpid;
    
    /*Socket address structure*/
    struct sockaddr_in server_address, client_address;

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(1254);
    
    /*TCP socket is created, an Internet socket address structure is filled with
wildcard address & server’s well known port*/
    socketd = socket(AF_INET, SOCK_STREAM, 0);
    
    /*Bind function assigns a local protocol address to the socket*/
    bind(socketd, (struct sockaddr *)&server_address, sizeof(server_address));
    
    /*Listen function specifies the maximum number of connections that kernel should queue
for this socket*/
    listen(socketd, 5);
    printf("%s\n", "Server is up.");
    
    /*The server to return the next completed connection from the front of the
completed connection Queue calls it*/
    client_socket = accept(socketd, (struct sockaddr *)&client_address, &clientLength);
    
    /*Fork system call is used to create a new process*/
    cpid = fork();

    if (cpid == 0)
    {
        while (1)
        {
            memset(recv_msg, 0, sizeof(recv_msg));
            /*Receiving the request from client*/
            recv(client_socket, recv_msg, sizeof(recv_msg), 0);
            if (recv_msg[0] == 'E' && recv_msg[1] == 'X' && recv_msg[2] == 'I' && recv_msg[3] == 'T')
                break;
            printf("\nCLIENT : %s\n", recv_msg);
        }
    }
    else
    {
        while (1)
        {

            memset(send_msg, 0, sizeof(send_msg));
            printf("\nEnter Message : ");
            
            /*Read the message from client*/
            fgets(send_msg, 10000, stdin);
            
            /*Sends the message to client*/
            if (send_msg[0] == 'E' && send_msg[1] == 'X' && send_msg[2] == 'I' && send_msg[3] == 'T')
                break;
            send(client_socket, send_msg, strlen(send_msg) + 1, 0);
            printf("\nMessage sent to Client\n");
        }
    }
    return 0;
}
