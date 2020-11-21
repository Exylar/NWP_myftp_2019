/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** noop
*/

#include "myftp.h"
#include "command.h"

void noop(client_t *client)
{
    write(client->control_socket, "200 Ok\r\n", strlen("200 Ok\r\n"));
}