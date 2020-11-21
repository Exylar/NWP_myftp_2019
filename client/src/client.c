/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** client
*/

#include "client.h"

int connexion(int port)
{
    int clientSocket;
    struct sockaddr_in serverAddr;
    int ret;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        printf("[-]Error in connection.\n");
        exit(1);
    }
    printf("[+]Client Socket is created.\n");
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    ret = connect(clientSocket, (struct sockaddr*)&serverAddr,
    sizeof(serverAddr));
    if (ret < 0) {
        printf("[-]Error in connection.\n");
        exit(1);
    }
    return clientSocket;
}

void client(int clientSocket)
{
    int dataSocket = 0;
    char buffer[1024 + 5];
    int size = 0;

    printf("[+]Connected to Server.\n");
    size = read(clientSocket, buffer, 1024);
    buffer[size] = '\0';
    printf("Info: %s", buffer);
    while (1) {
        printf("> ");
        gets(buffer);
        size = strlen(buffer);
        buffer[size] = '\r';
        buffer[size + 1] = '\n';
        buffer[size + 2] = '\0';
        write(clientSocket, buffer, size + 2);
        if (strstr(buffer, "QUIT") != NULL){
            close(clientSocket);
            printf("[-]Disconnected from server.\n");
            break;
        }
        if (strstr(buffer, "221") != NULL){
            close(clientSocket);
            printf("[-]Disconnected from server.\n");
        }
    }
}