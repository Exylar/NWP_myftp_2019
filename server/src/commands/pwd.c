/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pwd
*/

#include "myftp.h"
#include "command.h"

void pwd(client_t *client)
{
    char buff[2048];
    char *message = malloc(sizeof(char) * 2048);

    if (!client->is_connected) {
        write(client->control_socket, 
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    if (getcwd(buff, 2048) == NULL) {
        write(client->control_socket, "550 File not found\r\n",
        strlen("550 File not found\r\n"));
    } else {
        message = strcat(message, "257 \"");
        message = strcat(message, buff);
        message = strcat(message, "\" is current directory\r\n");
        write(client->control_socket, message, strlen(message));
    }
    free(message);
}