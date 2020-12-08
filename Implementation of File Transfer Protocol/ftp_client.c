#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define protocol 0
#define IP_Address "127.0.0.1" // localhost
#define Port_No 15050
#define buffer_size 32
#define CipherKey 'S'
#define SendRecvFlag 0
// function for clearing buffer
void clearBuf(char *b1)
{
    int i;
    for (i = 0; i < buffer_size; i++)
        b1[i] = '\0';
}
// function for decryption method
char Cipher(char ch1)
{
    return ch1 ^ CipherKey;
}
// function for receiveing file
int recvFile(char *buf1, int s1)
{
    int i;
    char ch1;
    for (i = 0; i < s1; i++)
    {
        ch1 = buf1[i];
        ch1 = Cipher(ch1);
        if (ch1 == EOF)
            return 1;
        else
            printf("%c", ch1);
    }
    return 0;
}
// driver code
int main()
{
    int sockfd1, nBytes;
    struct sockaddr_in addr_con;
    int addrlen = sizeof(addr_con);
    addr_con.sin_family = AF_INET;
    addr_con.sin_port = htons(Port_No);
    addr_con.sin_addr.s_addr = inet_addr(IP_Address);
    char net_buf1[buffer_size];
    FILE *fp1;
    // socket()
    sockfd1 = socket(AF_INET, SOCK_DGRAM,
                     protocol);
    if (sockfd1 < 0)
        printf("\nfile descriptor is not received!!\n");
    else
        printf("\nfile descriptor %d is received\n", sockfd1);
    while (1)
    {
        printf("\nPlease enter the name of file to receive:\n");
        scanf("%s", net_buf1);
        sendto(sockfd1, net_buf1, buffer_size,
               SendRecvFlag, (struct sockaddr *)&addr_con,
               addrlen);
        printf("\n---------Data is Received---------\n");
        while (1)
        {
            // receive
            clearBuf(net_buf1);
            nBytes = recvfrom(sockfd1, net_buf1, buffer_size,
                              SendRecvFlag, (struct sockaddr *)&addr_con,
                              &addrlen);
            // process
            if (recvFile(net_buf1, buffer_size))
            {
                break;
            }
        }
        printf("\n-------------------------------\n");
    }
    return 0;
}
