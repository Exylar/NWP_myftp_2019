/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** quit
*/

#include "myftp.h"
#include "command.h"

void quit(client_t *client)
{
    write(client->control_socket, "221 Connexion closed succesfully\r\n",
    strlen("221 Connexion closed succesfully\r\n"));
    close(client->control_socket);
    free(client->username);
    free(client->password);
    client->control_socket = 0;
    client->username = NULL;
    client->password = NULL;
}