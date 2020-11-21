/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** rnto
*/

#include "myftp.h"
#include "command.h"

void rnto(client_t *client)
{
    struct stat mystat;
    char *path;
    char *newname;

    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    if (strcasecmp(client->last_command, "rnfr") != 0) {
        write(client->control_socket,
        "203 You need used RNFR command before\r\n",
        strlen("203 You need used RNFR command before\r\n"));
    }
    path = strtok(client->last_command, "RNFR ");
    path[strlen(path) - 2] = '\0';
    newname = strtok(client->command, "RNTO ");
    newname[strlen(newname) - 2] = '\0';
    if (stat(path, &mystat) == -1 && !S_ISREG(mystat.st_mode)) {
        write(client->control_socket, "550 File not found\r\n",
        strlen("550 File not found\r\n\r\n"));
        return;
    }
    if (rename(path, newname) != -1) {
        write(client->control_socket, "250 File renamed\r\n",
        strlen("250 File renamed\r\n"));
    }
    else {
        write(client->control_socket, "550 File not found\r\n",
        strlen("550 File not found\r\n\r\n"));
    }
}