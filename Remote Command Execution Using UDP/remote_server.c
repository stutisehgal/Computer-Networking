#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main()
{

    int socketD = socket(AF_INET, SOCK_DGRAM, 0);
    int size;
    char buffer[1000], message[] = "Execution Successful!";
    struct sockaddr_in clientAddress, serverAddress;

    socklen_t clientLength = sizeof(clientAddress);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(1234);

    bind(socketD, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        recvfrom(socketD, buffer, sizeof(buffer), 0, (struct sockaddr *)&clientAddress, &clientLength);
        system(buffer);
        printf("Successfully executed Command : %s ", buffer);
        sendto(socketD, message, sizeof(message), 0, (struct sockaddr *)&clientAddress, clientLength);
    }
    close(socketD);
    return 0;
}
