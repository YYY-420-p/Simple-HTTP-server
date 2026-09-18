#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>


#define RED "\e[0;31m"
#define WHT "\e[0;37m"
#define GRE "\x1b[32m"


int main() {

// variables we will need 
int socket_fd = {0};
int client_fd = {0};
char buffer[256] = {0} ;

 // creating a socket and checking for the return value
     socket_fd = socket(AF_INET , SOCK_STREAM , 0 );
    if ( socket_fd < 0){
      printf(RED "SOCKET ERROR: %d\n" , errno);
      perror("ERROR");
      exit(EXIT_FAILURE);
    }

    // filling socket parameters
    struct sockaddr_in server_addr ;
    server_addr.sin_family = AF_INET ;
    server_addr.sin_port   = htons(8080) ;
    server_addr.sin_addr.s_addr = INADDR_ANY ;

 







}
