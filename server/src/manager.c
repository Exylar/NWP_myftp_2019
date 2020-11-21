/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** manager
*/

#include "command.h"
#include "myftp.h"

client_t *init_struct_client(int newSocket, struct sockaddr_in newAdresse)
{
    client_t *client = (client_t *)calloc(1, sizeof(client_t));

    client->control_socket = newSocket;
    client->data_socket = 0;
    client->data_ip = NULL;
    client->data_port = 0;
    client->is_connected = 0;
    client->username = NULL;
    client->password = NULL;
    client->last_command = NULL;
    return client;
}

fdclient_t *init_list_client(int socketServer)
{
    fdclient_t *list = malloc(sizeof(fdclient_t));

    list->fd = socketServer;
    list->next = NULL;
    list->data_client = NULL;
    return list;
}

void add_client(fdclient_t *list, int socketClient,
struct sockaddr_in newAdresse)
{
    fdclient_t *begin = list;
    fdclient_t *nodeClient = malloc(sizeof(fdclient_t));

    for (; list->next != NULL;)
        list = list->next;
    nodeClient->fd = socketClient;
    nodeClient->next = NULL;
    nodeClient->data_client =
    (client_t *)init_struct_client(socketClient, newAdresse);
    write(nodeClient->data_client->control_socket, "220 Welcome in my FTP\r\n",
    strlen("220 Welcome in my FTP\r\n"));
    list->next = nodeClient;
    list = begin;
}

fd_set reset_list(fdclient_t *list, int *socketMax)
{
    fdclient_t *begin = list;
    fd_set readfds;

    for (; list != NULL;) {
        if (list->fd != 0)
            FD_SET(list->fd, &readfds);
        if (*socketMax < list->fd)
            *socketMax = list->fd;
        if (list->next != NULL)
            list = list->next;
        else
            break;
    }
    list = begin;
    return readfds;
}

int remove_element(fdclient_t *list, int fd)
{
    fdclient_t *begin = list;
    fdclient_t *save;
    int res = 0;

    for (; list->next->fd != fd && list->next->next != NULL;)
        list = list->next;
    save = list->next;
    if (save->next == NULL) {
        list->next = NULL;
        res = 1;
    }
    else
        list->next = save->next;
    free(save->data_client);
    free(save);
    list = begin;
    return res;
}
