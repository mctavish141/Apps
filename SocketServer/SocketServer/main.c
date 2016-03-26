//
//  main.c
//  SocketServer
//
//  Created by Serhii Kopach on 26.03.16.
//  Copyright (c) 2016 Serhii Kopach. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define MY_PORT 8888
#define MAX_CLIENTS 30
#define MAX_CONNECTIONS 3
#define MAX_MESSAGE_SIZE 2000

void *connection_handler (void *socket_desc_ptr) {
    int socket_desc = *(int *)socket_desc_ptr;
    
    char *message = "Greetings!\n";
    write(socket_desc, message, strlen(message) + 1);
    
    long int read_size;
    char client_message[MAX_MESSAGE_SIZE];
    
    do {
        read_size = recv(socket_desc, client_message, MAX_MESSAGE_SIZE, 0);
        
        if (client_message[0] == 4) {
            //
        }
        
        /*printf("Client: %s.", client_message);
        for (int i = 0; i < strlen(client_message) + 1; i++) {
            printf("%d, ", client_message[i]);
        }*/
        
        write(socket_desc, client_message, strlen(client_message) + 1);
        
        bzero(client_message, MAX_MESSAGE_SIZE);
        
    } while (read_size > 0);
    
    if (read_size == 0) {
        printf("Client disconnected.\n");
        fflush(stdout);
    } else if (read_size == -1) {
        printf("Receiving failed.\n");
    }
    
    close(socket_desc);
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    // Create socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf ("--- Socket can not be created.\n");
        return 1;
    } else {
        printf ("+ Socket created.\n");
    }
    
    // Prepare the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(MY_PORT);
    
    // Bind
    int bind_result = bind(socket_desc, (struct sockaddr *)&server, sizeof(server));
    if (bind_result < 0) {
        printf("--- Bind failed.\n");
        return 1;
    } else {
        printf("+ Bind succeeded.\n");
    }
    
    // Listen
    listen(socket_desc, MAX_CONNECTIONS);
    
    printf("Listening to port %d\n", MY_PORT);
    printf("Waiting for connections...\n");
    
    struct sockaddr_in client;
    int new_socket;
    int size_sockaddr_in = sizeof(struct sockaddr_in);
    
    while (1) {
        new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&size_sockaddr_in);
        if (new_socket < 0) {
            printf("--- Accept failed.\n");
            return 1;
        } else {
            printf("+ Connection %d accepted.\n", new_socket);
        }
        
        char *client_ip = inet_ntoa(client.sin_addr);
        int client_port = ntohs(client.sin_port);
        
        printf("Client ip: %s\n", client_ip);
        printf("Client port: %d\n", client_port);
        
        pthread_t sniffer_thread;
        int *new_socket_ptr = malloc(sizeof(int));
        *new_socket_ptr = new_socket;
        
        int thread_create_result = pthread_create(&sniffer_thread, NULL, connection_handler, (void *)new_socket_ptr);
        if (thread_create_result < 0) {
            printf("--- Thread can not be created.\n");
            return 1;
        } else {
            printf("+ Thread created.\n");
        }
        
        printf("Handler assigned.\n");
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
