//
//  main.c
//  Thread2
//
//  Created by Serhii Kopach on 27.03.16.
//  Copyright (c) 2016 Serhii Kopach. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "Randomizer.h"
#include "NegativeWriter.h"
#include "Mutex_Pro.h"

int main () {
    srand((unsigned)time(NULL));
    
    int number = 0;
    pthread_mutex_t mutex;
    
    Info info;
    info.mutex = &mutex;
    info.number_pointer = &number;
    
    fork ();
    
    Randomize(&info);
    NegativeWrite(&info);
    
    return 0;
}