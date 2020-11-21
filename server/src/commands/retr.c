/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** retr
*/

#include "myftp.h"
#include "command.h"

void send_file(client_t *client, int file)
{
    char buff[1];

    if (init_data_socket(client) != 84) {
        write(client->control_socket,
        "425 Impossible to open data connexion\r\n",
        strlen("425 Impossible to open data connexion\r\n"));
        return;
    }
    while (read(file, buff, 1) > 0) {
        write(client->data_socket, buff, 1);
    }
    write(client->control_socket, "226 Transfert completed\r\n",
    strlen("226 Transfert completed\r\n"));
}

void retr(client_t *client)
{
    struct stat mystat;
    char *path;
    int file;

    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    path = strtok(client->command, "RETR ");
    path[strlen(path) - 2] = '\0';
    if ((file = open(path, O_RDONLY)) == -1) {
        write(client->control_socket,
        "550 File not found\r\n", strlen("550 File not found\r\n"));
        return;
    }
    if (fstat(file, &mystat) == -1 || !S_ISREG(mystat.st_mode)) {
        write(client->control_socket,
        "550 File not available\r\n", strlen("550 File not available\r\n"));
        return;
    }
}