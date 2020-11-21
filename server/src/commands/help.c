/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** help
*/

#include "myftp.h"
#include "command.h"

void help_all(client_t *client)
{
    char message[35 * 10];

    bzero(message, sizeof(message));
    strcat(message, "214 ");
    for (int i = 0; command[i].name; i++) {
        if (i > 0)
            strcat(message, " ");
        strcat(message, command[i].name);
    }
    strcat(message, "\r\n");
    write(client->control_socket, message, strlen(message));
}

void help_command(client_t *client, char *help_command)
{
    int count = 0;
    int is_command = 0;
    char *message = malloc(sizeof(2048));

    help_command[strlen(help_command) - 2] = '\0';
    for (count = 0; command[count].name != NULL; count++) {
        if (strcmp(command[count].name, help_command) == 0) {
            is_command == 1;
            break;
        }
    } if (is_command == 1) {
        bzero(message, sizeof(message));
        message = strcat(message, "214 ");
        message = strcat(message, help_command);
        message = strcat(message, ": ");
        message = strcat(message, command[count].help);
        message = strcat(message, "\r\n");
        write(client->control_socket, message, strlen(message));
    } else
        write(client->control_socket, "214 Command not found\r\n",
        strlen("214 Command not found\r\n"));
    free(message);
}

void help(client_t *client)
{
    char *found;
    int argc = 0;

    while ((found = strsep(&client->command, " ")) != NULL) {
        argc++;
        if (argc == 2)
            break;
    }
    if (argc == 1) {
        help_all(client);
    } else {
        help_command(client, found);
    }
}