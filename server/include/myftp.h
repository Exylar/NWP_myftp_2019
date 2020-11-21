/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** myftp
*/

#ifndef __MY_FPT_H__
#define __MY_FPT_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <fcntl.h>



typedef struct client_s {
    int control_socket;
    int data_socket;
    char *username;
    char *password;
    char *data_ip;
    int data_port;
    int is_connected;
    char *command;
    char *last_command;
} client_t;

typedef struct fdclient_s {
    int fd;
    struct fdclient_s *next;
    client_t *data_client;
} fdclient_t;

fd_set reset_list(fdclient_t *list, int *socketMax);
void add_client(fdclient_t *list, int socketClient,
struct sockaddr_in newAdresse);
fdclient_t *init_list_client(int socketServer);
client_t *init_struct_client(int newSocket, struct sockaddr_in newAdresse);
int remove_element(fdclient_t *list, int fd);

void data_connexion(client_t *client);
int init_client(int fdsocket, struct sockaddr_in newAdresse,
unsigned int addrLen);
int client_request(client_t *client);

int init_data_socket(client_t *client);
int close_data_socket(client_t *client);

int init_server(int port);
int loop_server(int fdsocket);

#endif
