//
//  Mutex_Pro.h
//  Thread2
//
//  Created by Serhii Kopach on 27.03.16.
//  Copyright (c) 2016 Serhii Kopach. All rights reserved.
//

#include <pthread.h>

typedef struct {
    int *number_pointer;
    pthread_mutex_t *mutex;
} Info;