#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
 
int main()
{
    int network_socket = 0,n = 0;
    char data_rcv[1024];
    struct sockaddr_in server_address;

    memset(data_rcv, '0', sizeof(data_rcv));

    network_socket = socket(AF_INET, SOCK_STREAM, 0);
     if (network_socket < 0)
    {
        printf("\n\nSocket not created \n");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(1234);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection = connect(network_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (connection < 0)
    {
        printf("\n\nConnection failed.\n");
        return 1;
    }
    else 
        printf("\n\nConnected to Server.\n");

    while ((n = read(network_socket, data_rcv, sizeof(data_rcv) - 1)) > 0)
    {
        data_rcv[n] = 0;
        if (fputs(data_rcv, stdout) == EOF)
        {
            printf("\nStandard output error");
        }
 
        printf("\n");
    }
 
    if( n < 0)
    {
        printf("\nStandard input error \n");
    }
 
    return 0;
}
