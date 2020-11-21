/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pass
*/

#include "myftp.h"
#include "command.h"

void pass_check_user(client_t *client)
{
    if (strcmp(client->username, "Anonymous\r\n") == 0) {
        if (strstr(client->command, "PASS") != NULL &&
        strstr(client->command, "\r\n") != NULL) {
            client->password = strdup(client->command + 4);
            client->is_connected = 1;
            write(client->control_socket, "230 User logged in\r\n",
            strlen("230 User logged in\r\n"));
        }
        else {
            write(client->control_socket, "5O1 Wrong password\r\n",
            strlen("5O1 Wrong passwordr\n"));
        }
    }
    else {
        write(client->control_socket, "530 Unknown user\r\n",
        strlen("530 Unknown user\r\n"));
    }
}

void pass(client_t *client)
{
    if (client->is_connected) {
        write(client->control_socket, "530 You are already connected\r\n",
        strlen("530 You are already connected\r\n"));
        return;
    }
    if (client->username == NULL) {
        write(client->control_socket, "530 You must use the USER command\r\n",
        strlen("530 You must use the USER command\r\n"));
        return;
    }
    else if (client->command == NULL) {
        write(client->control_socket, "5O1 Wrong syntax, no password send\r\n",
        strlen("5O1 Wrong syntax, no password send\r\n"));
    }
    else
        pass_check_user(client);
}