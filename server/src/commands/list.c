/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** list
*/

#include "myftp.h"
#include "command.h"

void list(client_t *client)
{
    FILE *pp;
    char buf[1];
    pp = popen("ls -l", "r");
    while (fread(buf, sizeof(char), 1, pp) > 0) {
        if (*buf == '\n')
            write(client->data_socket, "\r\n", 2);
        else
            write(client->data_socket, buf, 1);
    }
    pclose(pp);
    close(client->data_socket);
    write(client->control_socket, "226 Transfert completed\r\n",
    strlen("226 Transfert completed\r\n"));
}