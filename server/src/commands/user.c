/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** user
*/

#include "myftp.h"
#include "command.h"

void user(client_t *client)
{
    char *username;

    if (client->username != NULL)
        free(client->username);
    username = client->command + 5;
    if (username == NULL) {
        write(client->control_socket, "5O1 Wrong syntax, no username send\r\n",
        strlen("5O1 Wrong syntax, no username send\r\n"));
    }
    else {
        if (username) {
            client->username = strdup(username);
            write(client->control_socket, "331 User name ok, need password\r\n",
            strlen("331 User name ok, need password\r\n"));
        }
        else {
            write(client->control_socket, "530 User not logged in\r\n",
            strlen("530 User not logged in\r\n"));
        }
    }
}