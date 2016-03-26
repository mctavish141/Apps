//
//  main.c
//  Thread
//
//  Created by Serhii Kopach on 26.03.16.
//  Copyright (c) 2016 Serhii Kopach. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>

void *say_hello (void *data) {
    printf("I am function say_hello\n");
    
    return 0;
}

int main() {
    pthread_t thread;
    
    pthread_create(&thread, NULL, say_hello, NULL);
    
    printf("I am main\n");
    
    pthread_join(thread, NULL);
    
    return 0;
}
