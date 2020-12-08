#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
    int socketD = socket(AF_INET, SOCK_DGRAM, 0);
    char buffer[1000], message[1000];
    struct sockaddr_in cliaddr, serverAddress;
    socklen_t serverLength = sizeof(serverAddress);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(1234);

    bind(socketD, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    while (1)
    {
        printf("\nEnter the Command to be executed at server side : ");
        fgets(buffer, sizeof(buffer), stdin);
        sendto(socketD, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddress, serverLength);
        printf("\nCommand Sent");
        recvfrom(socketD, message, sizeof(message), 0, (struct sockaddr *)&serverAddress, &serverLength);
        printf("\nUDP SERVER : %s", message);
    }
    return 0;
}
