//Client side implementation of UDP client-server model 
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
struct sockaddr_in    servaddr;

// Creating socket file descriptor

if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { perror("socket creation failed");
exit(EXIT_FAILURE);
}

memset(&servaddr, 0, sizeof(servaddr));

//Filling server information servaddr.sin_family = AF_INET; servaddr.sin_port = htons(PORT); servaddr.sin_addr.s_addr = INADDR_ANY;


demo_struct.id = 123;

demo_struct.name = "Hello World";

// int array[5] = {1, 2, 3, 4, 5};

int n, len,a,b;

//printf("enter two number : ");
//scanf("%d %d",&a,&b);
//sendto(sockfd, &a, 4, 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));
//sendto(sockfd, &b, 4, 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));

sendto(sockfd, &demo_struct, sizeof(demo_struct), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));

printf("values sent.\n");

struct demo_struct result;

n = recvfrom(sockfd, &result, sizeof(result), 0, (struct sockaddr *) &servaddr, &len); printf("Server Response : %d\n", result.id);

close(sockfd);

return 0;
}
