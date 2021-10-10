//Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

#define PORT 8080

#define MAXLINE 1024
#define OUT    0
#define IN    1

int countWords(char *str)

{
int state = OUT;
int word_count = 0; // word count

//Scan all characters one by one while (*str)
{
//If next character is a separator, set the
//state as OUT
if (*str == ' ' || *str == '\n' || *str == '\t')
state = OUT;

//If next character is not a word separator and

//state is OUT, then set the state as IN and
//increment word count

else if (state == OUT)

{
state = IN;
++word_count;
}

//Move to next character ++str;

}

return word_count;

}

//Driver code int main() {
int sockfd;
char buffer[MAXLINE];
//char *hello = "Hello from server"; struct sockaddr_in servaddr, cliaddr;

//Creating socket file descriptor

if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { perror("socket creation failed"); exit(EXIT_FAILURE);
}

memset(&servaddr, 0, sizeof(servaddr));

memset(&cliaddr, 0, sizeof(cliaddr));

//Filling server information servaddr.sin_family = AF_INET; // IPv4 servaddr.sin_addr.s_addr = INADDR_ANY; servaddr.sin_port = htons(PORT);

//Bind the socket with the server address

if ( bind(sockfd, (const struct sockaddr *)&servaddr,
sizeof(servaddr)) < 0 )
{
perror("bind failed");
exit(EXIT_FAILURE);
}

int len, n, count=0;

len = sizeof(cliaddr); //len is value/resuslt

n = recvfrom(sockfd, (char *)buffer, MAXLINE, 0, ( struct sockaddr *) &cliaddr, &len); buffer[n] = '\0';

printf("Client text: %s\n", buffer);

//for(int i = 0; buffer[i] != '\0';i++)

//{
//if (buffer[i] == ' ' && buffer[i+1] != ' ')
//count++;

// }

count = countWords(buffer);

sendto(sockfd, &count, sizeof(count), 0, (const struct sockaddr *) &cliaddr, len);

printf("word count sent.\n");

return 0;

}
