/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** socket
*/

#ifndef SOCKET_H_
#define SOCKET_H_

#include <sys/socket.h>
#include <netinet/in.h>

int init_connexion(int port);
static int socket_option(int fdsocket);;
static void init_adresse(struct sockaddr_in *adresse, int port);

#endif /* !SOCKET_H_ */
