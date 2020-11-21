/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** client
*/

#include "client.h"

static void usage(void)
{
    printf("USAGE:\t./myftp port\n");
}

static void help(void)
{
    usage();
    printf("\tport port of the server\n");
}

int main(int argc, char **argv)
{
    int opt;
    int i = 0;

    opt = getopt(argc, argv, "help");
    if (opt == 'h') {
        help();
        return 0;
    }
    else if (argc != 2) {
        usage();
        return 84;
    }
    client(connexion(atoi(argv[1])));
    return 0;
}