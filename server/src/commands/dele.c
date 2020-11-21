/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** dele
*/

#include "myftp.h"
#include "command.h"

void dele(client_t *client)
{
    struct stat mystat;
    char *path;

    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    path = strtok(client->command, "DELE ");
    path[strlen(path) - 2] = '\0';
    if (stat(path, &mystat) != -1 && S_ISREG(mystat.st_mode)) {
        remove(path);
        write(client->control_socket, "250 File deleted\r\n",
        strlen("250 File deleted\r\n"));
    } else {
        write(client->control_socket, "550 Impossible to delete file\r\n",
        strlen("550 Impossible to delete file\r\n"));
    }
}