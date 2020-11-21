/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** rmd
*/

#include "myftp.h"
#include "command.h"

void rmd(client_t *client)
{
    struct stat mystat;
    char *path;

    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    path = strtok(client->command, "RMD ");
    path[strlen(path) - 2] = '\0';
    if (stat(path, &mystat) != -1 && S_ISDIR(mystat.st_mode)) {
        remove(path);
        write(client->control_socket, "250 Directory deleted\r\n",
        strlen("250 Directory deleted\r\n"));
    } else {
        write(client->control_socket, "550 Impossible to delete directory\r\n",
        strlen("550 Impossible to delete directory\r\n"));
    }
}