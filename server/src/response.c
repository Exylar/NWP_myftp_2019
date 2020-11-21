/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** response
*/

#include "myftp.h"
#include "response.h"

void send_message(int socket, code_t code, char *message)
{
   char *buffer;

   asprintf(&buffer, "%d %s\r\n", code, message);
   write(socket, buffer, strlen(buffer));
   free(buffer);
}