//
//  main.c
//  Thread
//
//  Created by Serhii Kopach on 26.03.16.
//  Copyright (c) 2016 Serhii Kopach. All rights reserved.
//

/*#include <stdio.h>
#include <pthread.h>

// sat_hello function

void *say_hello (void *data) {
    printf("I am function say_hello\n");
    
    return 0;
}

// Main function

int main() {
    // Create thread
    pthread_t thread;
    
    // Thread will run 'say_hello' function
    pthread_create(&thread, NULL, say_hello, NULL);
    
    // Main continues
    printf("I am main\n");
    
    // Wait until 'say_hello' will exit (СЮДА ПОКА МОЖЕШЬ НЕ СМОТРЕТЬ)
    pthread_join(thread, NULL);
    
    return 0;
}*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int a = 0;
pthread_mutex_t count_mutex;

int main () {
    int process_id = fork();
    
    if (process_id == 0) {
        //printf("I am main process\n");
        
        pthread_mutex_lock(&count_mutex);
        a = 3;
        pthread_mutex_unlock(&count_mutex);
    } else {
        //printf("I am not main process.\n");
        
        
        pthread_mutex_lock(&count_mutex);
        a = 4;
        pthread_mutex_unlock(&count_mutex);
    }
    
    printf("%d Hello Sasha and Serezha\n", a);
}