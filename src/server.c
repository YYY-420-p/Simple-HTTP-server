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

   // linking socket with sockaddr structure and checking for error
     if (bind(socket_fd , (struct sockaddr*)&server_addr , sizeof(server_addr)) < 0 ){
           printf( "ERROR CODE : %d\n" , errno);
           perror(RED "Error" WHT);
           exit(EXIT_FAILURE);
     }

       // putting server on the listening mode
    if (listen(socket_fd , 1 ) < 0 ) {
       printf(RED "LISTENING ERROR\n" WHT );
       exit(EXIT_FAILURE);

    }

    printf(GRE "Server is listening on PORT 80\n" WHT);

    // creating client addr structure to get client infos
     struct sockaddr_in client_addr ;
      socklen_t client_len ;
      client_len = sizeof(client_addr);


    // accepting connection 
     if ( accept(socket_fd , (struct sockaddr*)&client_addr , &client_len) < 0){
        printf (RED "ACCEPT ERROR:%d\n" , errno);
        perror ("ERROR");
        exit(EXIT_FAILURE);
     }

   // succes message after trying to connect to 127.0.0.1:8080
    printf(GRE "Connection Accepted\n" WHT);


   // close socket and end connection
    close(socket_fd);

   return 0 ;
  }
