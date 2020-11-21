/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** cwd
*/

#include <dirent.h>
#include <errno.h>

#include "myftp.h"
#include "command.h"

void cwd(client_t *client)
{
    char *path;
    DIR *directory;

    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    path = strtok(client->command, "CWD ");
    path[strlen(path) - 2] = '\0';
    if (path == NULL)
        write(client->control_socket, "5O1 Wrong syntax, no password send\r\n",
        strlen("5O1 Wrong syntax, no password send\r\n"));
    directory = opendir(path);
    if (directory) {
        if (chdir(path) == 0) {
            write(client->control_socket,
            "250 Correct directory, moving current directory\r\n",
            strlen("250 Correct directory, moving current directory\r\n"));
        }
        else {
            write(client->control_socket, "550 Access denied\r\n",
            strlen("550 Access denied\r\n"));
        }
        closedir(directory);
    } else if (ENOENT == errno) {
        write(client->control_socket, "550 Directory doesn't exist\r\n",
        strlen("550 Directory doesn't exist\r\n"));
    } else {
        write(client->control_socket, "550 Access denied\r\n",
        strlen("550 Access denied\r\n"));
    }
}