/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** rnfr
*/

#include "myftp.h"
#include "command.h"

void rnfr(client_t *client)
{
    struct stat mystat;
    char *path;

    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    path = strtok(client->command, "RNFR ");
    path[strlen(path) - 2] = '\0';
    if (stat(path, &mystat) != -1 && S_ISREG(mystat.st_mode)) {
        write(client->control_socket, "350 Ready to rename the file\r\n",
        strlen("350 Ready to rename the file\r\n\r\n"));
    }
    else {
        write(client->control_socket, "550 File not found\r\n",
        strlen("550 File not found\r\n\r\n"));
    }
}