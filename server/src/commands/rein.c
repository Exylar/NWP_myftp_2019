/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** rein
*/

#include "myftp.h"
#include "command.h"

void rein(client_t *client)
{
    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    write(client->control_socket, "120 Reinizialize connexion\r\n",
    strlen("120 Reinizialize connexion\r\n"));
    client->is_connected = 0;
    free(client->username);
    free(client->password);
    client->username = NULL;
    client->password = NULL;
}