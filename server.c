// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com/

#include <levels.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 

#define PORT 8080
#define SA struct sockaddr
#define MAX_LEVEL 12
#define MAX 80

static void startChallenge(int clientfd);
static int (*levels[MAX_LEVEL])(FILE* clientFile, char** response, size_t size);
static void initLevels();

int main() {
    int serverfd, clientfd, len, opt=1;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1) {
        perror("socket creation failed\n");
        exit(0);
    }

    if (setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("socket options settings failed\n");
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(serverfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        perror("socket bind failed\n");
        exit(0);
    }

    // Now server is ready to listen and verification
    if ((listen(serverfd, 5)) != 0) {
        perror("Listen failed\n");
        exit(0);
    }

    len = sizeof(cli);

    // Accept the data packet from client and verification
    clientfd = accept(serverfd, (SA*)&cli, (socklen_t*)&len);
    if (clientfd < 0) {
        perror("server acccept failed\n");
        exit(0);
    }

    // Function for chatting between client and server
    startChallenge(clientfd);

    // After chatting close the socket
    close(serverfd);
}

static void startChallenge(int clientfd) {
    initLevels();

    int error = 0, level = 1;
    FILE* clientFile = fdopen(clientfd, "r");
    char* response = malloc(sizeof(char) * MAX);

    while (level <= MAX_LEVEL && error!=-1) {
        printf("\033[1;1H\033[2J");
        memset(response, 0, MAX);

        printf("------------- DESAFIO -------------\n");

        if ((error = levels[level - 1](clientFile, &response, MAX))==1) {
            level++;
        } else {
            printf("Respuesta incorrecta: %s\n", response);
            sleep(2);
        }
    }

    free(response);

    if (error == -1) {
        return;
    }

    printf("\033[1;1H\033[2J");

    printf("Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n\n");
}

static void initLevels() {
    levels[0] = level1;
    levels[1] = level2;
    levels[2] = level3;
    levels[3] = level4;
    levels[4] = level5;
    levels[5] = level6;
    levels[6] = level7;
    levels[7] = level8;
    levels[8] = level9;
    levels[9] = level10;
    levels[10] = level11;
    levels[11] = level12;
    srand(time(0));
}