/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** main
*/

#include "socket.h"
#include "myftp.h"

static void usage(void)
{
    printf("USAGE:\t./myftp port path\n");
}

static void help(void)
{
    usage();
    printf("\tport is the port number on which the server socket listens\n");
    printf("\tpath is the path to the home directory for the Anonymous user\n");
}

int main(int argc, char **argv)
{
    int opt;
    FILE *pp;

    opt = getopt(argc, argv, "help");
    if (opt == 'h') {
        help();
        exit(EXIT_SUCCESS);
    }
    else if (argc != 3) {
        usage();
        exit(EXIT_FAILURE);
    }
    return loop_server(init_server(atoi(argv[1])));
}