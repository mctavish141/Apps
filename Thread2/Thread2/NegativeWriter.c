//
//  NegativeWriter.c
//  Thread2
//
//  Created by Serhii Kopach on 27.03.16.
//  Copyright (c) 2016 Serhii Kopach. All rights reserved.
//

#include "NegativeWriter.h"

#include "Mutex_Pro.h"

void *Do2 (void *info_pointer) {
    Info info = *(Info *)info_pointer;
    
    pthread_mutex_lock(info.mutex);
    
    int number = *(info.number_pointer);
    if (number < 0) {
        printf("%d\n", number);
    }
    
    pthread_mutex_unlock(info.mutex);
    
    return 0;
}

void *NegativeWrite (void *info_pointer) {
    pthread_t thread;
    pthread_create(&thread, NULL, Do2, info_pointer);
    pthread_join(thread, NULL);
    
    return 0;
}