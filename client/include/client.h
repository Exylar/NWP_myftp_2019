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

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int connexion(int port);
void client(int port);

#endif
