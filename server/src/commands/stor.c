/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** stor
*/

#include "myftp.h"
#include "command.h"

void stor(client_t *client)
{
    write(socket, "125\r\n", strlen("125\r\n"));
}