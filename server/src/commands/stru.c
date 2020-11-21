/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** stru
*/

#include "myftp.h"
#include "command.h"

void stru(client_t *client)
{
    char *type;

    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    type = strtok(client->command, "STRU ");
    type[strlen(type) - 2] = '\0';
    if (strcmp(type, "F"))
        write(client->control_socket, "200 Ok\r\n", strlen("200 Ok\r\n"));
    else {
        write(client->control_socket, "504 Structure not implemented\r\n",
        strlen("504 Structure not implemented\r\n"));
    }
}