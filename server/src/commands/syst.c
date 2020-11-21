/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** syst
*/

#include "myftp.h"
#include "command.h"

void syst(client_t *client)
{
    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    write(client->control_socket, "215 UNIX Type: L8\r\n",
    strlen("215 UNIX Type: L8\r\n"));
}