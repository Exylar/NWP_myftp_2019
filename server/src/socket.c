/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** myftp
*/

#include "myftp.h"

static void init_adresse(struct sockaddr_in *adresse, int port)
{
    (*adresse).sin_family = AF_INET;
    (*adresse).sin_addr.s_addr = INADDR_ANY;
    (*adresse).sin_port = htons(port);
}

static int socket_option(int fdsocket)
{
    int opt = 1;

    return setsockopt(fdsocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
        sizeof(opt));
}

int init_data_socket(client_t *client)
{
    int fdsocket_data;
    struct sockaddr_in adress;

    if (client->data_port == 0)
        return 84;
    init_adresse(&adress, client->data_port);
    if ((fdsocket_data = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "%s", "Error: the socket has not been created.");
        return 84;
    }
    if (bind(fdsocket_data, (struct sockaddr *) &adress, sizeof(adress)) != 0) {
        fprintf(stderr, "%s", "Error: the socket has not been binded");
        return 84;
    }
    if (listen(fdsocket_data, 1) != 0) {
        fprintf(stderr, "%s", "Error: the socket cannot be listened");
        return 84;
    }
    client->data_socket = fdsocket_data;
    return 0;
}

int close_data_socket(client_t *client)
{
    close(client->data_socket);
    free(client->data_ip);
    client->data_port = 0;
}

int init_connexion(int port)
{
    int fdsocket;
    struct sockaddr_in adress;

    init_adresse(&adress, port);
    if ((fdsocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "%s", "Error: the socket has not been created.");
        return 84;
    } if (socket_option(fdsocket) != 0) {
        fprintf(stderr, "%s", "Error: the socket has not been configured");
        return 84;
    } if (bind(fdsocket, (struct sockaddr *) &adress, sizeof(adress)) != 0) {
        fprintf(stderr, "%s", "Error: the socket has not been binded");
        return 84;
    } if (listen(fdsocket, 100000) != 0) {
        fprintf(stderr, "%s", "Error: the socket cannot be listened");
        return 84;
    }
    printf("Server Ready\n");
    return fdsocket;
}