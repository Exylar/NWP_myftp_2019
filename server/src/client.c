/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** client
*/

#include "command.h"
#include "myftp.h"

int init_client(int fdsocket, struct sockaddr_in newAdresse,
unsigned int addrLen)
{
    int newSocket = 0;

    if ((newSocket = accept(fdsocket, (struct sockaddr*)&newAdresse,
    &addrLen)) < 0) {
        exit(84);
    }
    printf("Connection accepted from %s:%d\n",
    inet_ntoa(newAdresse.sin_addr), ntohs(newAdresse.sin_port));
    return newSocket;
}

void data_connexion(client_t *client) 
{
    struct sockaddr_in adress;
    unsigned int len = sizeof(adress);
    int newSocket = 0;
    pid_t pid;

    adress.sin_family = AF_INET;
    adress.sin_addr.s_addr = INADDR_ANY;
    adress.sin_port = htons(client->data_port);
    if ((pid = fork()) == 0) {
        while (1) {
            if (newSocket = accept(client->data_socket, (struct sockaddr*)&adress, &len) > 0)
                break;
        }
    }
    close(client->data_socket);
    printf("New socket : %d\n", newSocket);
    client->data_socket = newSocket;
}

void get_command(client_t *client)
{
    for (int i = 0; command[i].name != NULL; i++) {
        if (strstr(client->command, command[i].name) != NULL) {
            command[i].func(client);
            client->last_command = client->command;
            return;
        }
    }
    printf("Commande unknown\n");
    write(client->control_socket, "500 Command Unknown\r\n",
    strlen("500 Command Unknown\r\n"));
}

int client_request(client_t *client)
{
    char buffer[1024];
    int size = 0;


    size = read(client->control_socket, buffer, 1024);
    buffer[size] = '\0';
    client->command = buffer;
    if (size == 0) {
        close(client->control_socket);
        return -1;
    }
    printf("client: %s", buffer);
    get_command(client);
    bzero(buffer, sizeof(buffer));
    return 0;
}