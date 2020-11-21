/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** port
*/

#include "myftp.h"
#include "command.h"

void get_data(char *data, client_t *client)
{
    char *find;
    char *parse_data[6];
    int i = 0;
    char *ip = malloc(sizeof(char) * 100);

    while ((find = strsep(&data, " ,")) != NULL) {
        if (!(strcmp(find, "\0") == 0) && !(strcmp(find, "\r\n") == 0)) {
            parse_data[i] = find;
            i++;
        }
    }
    for (int j = 0; j < 4; j++) {
        strcat(ip, parse_data[j]);
        if (j < 3)
            strcat(ip, ".");
    }
    client->data_ip = ip;
    client->data_port = (atoi(parse_data[4]) * 256) + atoi(parse_data[5]);
}

void port(client_t *client)
{
    char *data;
    if (!client->is_connected) {
        write(client->control_socket,
        "530 You must be connected to use this command\r\n",
        strlen("530 You must be connected to use this command\r\n"));
        return;
    }
    data = strtok(client->command, "PORT");
    get_data(data, client);

    write(client->control_socket, "200 PORT command successful\r\n",
    strlen("200 PORT command successful\r\n"));
}