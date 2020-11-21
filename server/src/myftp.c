/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** myftp
*/

#include "myftp.h"
#include "socket.h"

int init_server(int port)
{
    int fdsocket;

    fdsocket = init_connexion(port);
    return fdsocket;
}

int check_client_request(fdclient_t *list, int fdsocket, fd_set *readfds)
{
    fdclient_t *begin = list;
    int value = 0;

    for (; list != NULL;) {
        if (FD_ISSET(list->fd, readfds) && list->fd != fdsocket)
            value = client_request(list->data_client);
        if (value == -1) {
            remove_element(begin, list->fd);
            break;
        } value = 0;
        if (list->next != NULL)
            list = list->next;
        else
            break;
    }
    value = 0;
    list = begin;
}

int loop_server(int fdsocket)
{
    fdclient_t *list = init_list_client(fdsocket);
    int newSocket = 0;
    struct sockaddr_in newAdresse;
    unsigned int addrLen = sizeof(newAdresse);
    fd_set readfds;
    int socketMax = 0;

    while (1) {
        FD_ZERO(&readfds);
        readfds = reset_list(list, &socketMax);
        if (select(socketMax + 1, &readfds, NULL, NULL, NULL) == -1) {
            printf("Error: Select failed\n");
            return 84;
        } if (FD_ISSET(fdsocket, &readfds)) {
            newSocket = init_client(fdsocket, newAdresse, addrLen);
            add_client(list, newSocket, newAdresse);
        }
        check_client_request(list, fdsocket, &write);
    }
    close(newSocket);
    return 0;
}