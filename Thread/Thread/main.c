//
//  main.c
//  Thread
//
//  Created by Serhii Kopach on 26.03.16.
//  Copyright (c) 2016 Serhii Kopach. All rights reserved.
//

#include <stdio.h>
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
}
