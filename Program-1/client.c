#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 1234

int main(int argc, char const *argv[])
{
        int sock = 0, valread;
        struct sockaddr_in serv_addr;
        char *hello = "Hello from client";
        char buffer[1024] = {0};
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
                printf("\n Socket creation error \n");
                return -1;
        }

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);

        // Convert IPv4 and IPv6 addresses from text to binary form
        if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
        {
                printf("\nInvalid address/ Address not supported \n");
                return -1;
        }

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
                printf("\nConnection Failed \n");
                return -1;
        }

        int n1,n2,sum;
        printf("Send two numbers to  server");
        scanf("%d",&n1);
        send(sock , &n1 , 4 , 0 );
        printf("first number sent");
        scanf("%d", &n2 );
        send(sock , &n2 ,4 , 0 );
        //printf("Hello message sent\n");
        read( sock , &sum, 1024);
        printf("sum = %d " , sum );
        return 0;
}