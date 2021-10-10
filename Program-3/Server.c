#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

struct demo_struct

{
int id;
char *name;
}demo_struct;

//Driver code int main() {
int sockfd;
struct sockaddr_in servaddr, cliaddr;

// Creating socket file descriptor

if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { perror("socket creation failed");

exit(EXIT_FAILURE);

}

memset(&servaddr, 0, sizeof(servaddr));

memset(&cliaddr, 0, sizeof(cliaddr));

//Filling server information servaddr.sin_family = AF_INET; // IPv4 servaddr.sin_addr.s_addr = INADDR_ANY; servaddr.sin_port = htons(PORT);

//Bind the socket with the server address

if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 )
{
perror("bind failed");
exit(EXIT_FAILURE);
}

int len, n, num, remainder, reversed_id = 0;

len = sizeof(cliaddr); //len is value/resuslt

// int array[5] ;

recvfrom(sockfd, &demo_struct, sizeof(demo_struct), 0, ( struct sockaddr *) &cliaddr, &len);

//n = recvfrom(sockfd,&x, 4, 0, ( struct sockaddr *) &cliaddr, &len);

//n = recvfrom(sockfd,&y, 4, 0, ( struct sockaddr *) &cliaddr, &len);
//printf("Values sent by Client : %d %d\n",x,y);
//sum=x+y;
num = demo_struct.id;
while (num != 0) {
remainder = num % 10;
reversed_id = reversed_id * 10 + remainder;
num /= 10;
}

demo_struct.id = reversed_id;

printf("Reversed id: %d\n", reversed_id);

sendto(sockfd, &reversed_id, sizeof(demo_struct), 0, (const struct sockaddr *) &cliaddr, len);
printf("result sent.\n");

return 0;

}
