/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** stat
*/

#include "myftp.h"
#include "command.h"

void stat_ftp(client_t *client)
{
    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    write(client->control_socket, "202 Commande not implemanted\r\n",
    strlen("202 Commande not implemanted\r\n"));
}