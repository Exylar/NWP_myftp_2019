/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pasv
*/

#include "myftp.h"
#include "command.h"

void get_port(client_t *client)
{
    int fdsocket;
    struct sockaddr_in adress;
    int len = sizeof(adress);
    int myPort;

    client->data_ip = "127.0.0.1";
    adress.sin_family = AF_INET;
    adress.sin_addr.s_addr = INADDR_ANY;
    adress.sin_port = htons(0);
    if ((fdsocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "%s", "Error: the socket has not been created.");
    }
    if (bind(fdsocket, (struct sockaddr *) &adress, sizeof(adress)) != 0) {
        fprintf(stderr, "%s", "Error: the socket has not been binded");
        return;
    }
    if (listen(fdsocket, 1) != 0) {
        fprintf(stderr, "%s", "Error: the socket cannot be listened");
    }
    client->data_socket = fdsocket;
    bzero(&adress, sizeof(adress));
    getsockname(fdsocket, (struct sockaddr *) &adress, &len);
    client->data_port = ntohs(adress.sin_port);
}

void pasv(client_t *client)
{
    char *message = malloc(sizeof(char) * 100);
    char port_message[20];

    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    bzero(message, sizeof(100));
    get_port(client);
    sprintf(port_message, "%d,%d)\r\n", (int)client->data_port / 256,
    (int)client->data_port % 256);
    message = strcat(message, "227 Entering Passive Mode. (127,0,0,1,");
    message = strcat(message, port_message);
    write(client->control_socket, message,
    strlen(message));
    free(message);
    data_connexion(client);
}