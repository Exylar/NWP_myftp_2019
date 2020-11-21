/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** cdup
*/

#include <dirent.h>
#include <errno.h>

#include "myftp.h"
#include "command.h"

void cdup(client_t *client)
{
    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    if (chdir("../") != 0) {
        write(client->control_socket,
        "550 Impossible to change directory\r\n",
        strlen("550 Impossible to change directory\r\n"));
    }
    else {
        write(client->control_socket,
        "250 Current directory changed\r\n",
        strlen("250 Current directory changed\r\n"));
    }
}