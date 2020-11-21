/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** mode
*/

#include "myftp.h"
#include "command.h"

void mode(client_t *client)
{
    char *mode;

    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    mode = strtok(client->command, "MODE ");
    if (strstr(mode, "S") == 0) {
        write(client->control_socket, "200 Okay\r\n", strlen("200 Okay\r\n"));
    }
    else {
        write(client->control_socket, "504 Mode not implemented\r\n",
        strlen("504 Mode not implemented\r\n"));
    }
}