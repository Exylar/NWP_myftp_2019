/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** appe
*/

#include "myftp.h"
#include "command.h"

void appe(int socket, char *client_command, client_t *client)
{
    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    write(socket, "125\r\n", strlen("125\r\n"));
}