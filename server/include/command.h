/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** command
*/

#ifndef COMMAND_H_
#define COMMAND_H_

#include "myftp.h"

void abor(client_t *client);
void allo(client_t *client);
// void appe(client_t *client);
void cdup(client_t *client);
void cwd(client_t *client);
void dele(client_t *client);
void help(client_t *client);
void list(client_t *client);
void mkd(client_t *client);
void mode(client_t *client);
void nlist(client_t *client);
void noop(client_t *client);
void pass(client_t *client);
void pasv(client_t *client);
void port(client_t *client);
void pwd(client_t *client);
void quit(client_t *client);
void rein(client_t *client);
void rest(client_t *client);
// void retr(client_t *client);
void rmd(client_t *client);
void rnfr(client_t *client);
void rnto(client_t *client);
void site(client_t *client);
void smnt(client_t *client);
void stat_ftp(client_t *client);
// void stor(client_t *client);
void stou(client_t *client);
void stru(client_t *client);
void syst(client_t *client);
void type(client_t *client);
void user(client_t *client);

typedef struct command_s {
    char *name;
    void (*func)(client_t *);
    char *help;
} command_t;

static const command_t command[] = {
    {"USER", &user, "Set username for authentification"},
    {"PASS", &pass, "Set password for authentification"},
    {"QUIT", &quit, "Disconnection with the server"},
    {"REIN", &rein, "Reinizialize the connexion"},
    {"PASV", &pasv, "Enable Passive mode for data transfer"},
    {"PORT", &port, "Enable active mode"},
    {"PWD", &pwd, "Display actual working directory"},
    {"NOOP", &noop, "Do nothing return Okay"},
    {"SYST", &syst, "Display the type of the operative systeme"},
    {"CWD", &cwd, "Change working directory"},
    {"CDUP", &cdup, "Change to parent directory"},
    {"DELE", &dele, "Delete file"},
    {"RMD", &rmd, "Delete directory"},
    {"MKD", &mkd, "Create directory"},
    {"MODE", &mode, "Set mode of data tramission"},
    {"HELP", &help, "List available commands"},
    {"STOU", &stou, "Useless"},
    {"NLIST", &nlist, "Useless"},
    {"ALLO", &allo, "Useless"},
    {"REST", &rest, "Useless"},
    {"ABOR", &abor, "Useless"},
    {"STAT", &stat_ftp, "Useless"},
    {"TYPE", &type, "Set transfer type"},
    {"SITE", &site, "Useless"},
    {"SMNT", &smnt, "Useless"},
    {"RNFR", &rnfr, "Rename file from"},
    {"RNTO", &rnto, "Rename file to"},
    {"STRU", &stru, "Set file tranfer structure"},
    {"LIST", &list, "List files in the current directory"},
    {NULL, NULL, NULL}
    // {"STOR", &stor, "Upload file form client to server"},
    // {"RETR", &retr, "Download "},
    // {"APPE", &appe, "Append data to exist list"},
};

#endif /* !COMMAND_H_ */