/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** mkd
*/

#include "myftp.h"
#include "command.h"

void mkd(client_t *client)
{
    char *path;
    char *message = malloc(sizeof(char) * 2048);

    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    path = strtok(client->command, "MKD ");
    path[strlen(path) - 2] = '\0';
    if (mkdir(path, 755) != 1) {
        message = strcat(message, "257 \"");
        message = strcat(message, path);
        message = strcat(message, "\" is created\r\n");
        write(client->control_socket, message, strlen(message));
    } else {
        write(client->control_socket,
        "550 Impossible to create directory\r\n",
        strlen("550 Impossible to create directory\r\n"));
    }
}