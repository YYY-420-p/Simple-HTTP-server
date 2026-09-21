#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <errno.h>


int main() {
        // variables needed   
        int client_fd = {0} ;
        char buffer[1024] = {0} ;

        // creating a socket file descriptor 
        client_fd = socket(AF_INET , SOCK_STREAM , 0 );

        if ( client_fd < 0 ) {
                printf("socket error : %d\n" , errno);
                exit(EXIT_FAILURE);
        }
// infos about this socket
        struct sockaddr_in client_addr ;
        client_addr.sin_family = AF_INET ;
        client_addr.sin_port = htons (8080) ;
        client_addr.sin_addr.s_addr = INADDR_ANY ;

// linking socket and checking for errors
         if (bind(client_fd , (struct sockaddr*)&client_addr , sizeof(client_addr)) < 0 ) {
                 
                 printf( "Error on binding : %d\n" , errno);
                 exit(EXIT_FAILURE);
                 
         }

                 }


