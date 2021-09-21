#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {
    int *buffer;
    int size;
} buffer_info;

bool consumerIsWorking = true;
bool producerIsWorking = false;
int counter = 0;

void *fill_buffer(void *args) {
    while (1) {
        buffer_info *curr_info = ((buffer_info*) args);
        int *buffer = (*curr_info).buffer;
        int buffer_size = (*curr_info).size;
        if (consumerIsWorking) {
            printf("\nProducer is sleeping\n");
            continue;
        }
        if (counter < buffer_size) {
            buffer[counter] = 1;
            printf("\nProducer: 1\n");
            counter++;
        }
        if (counter == buffer_size) {
            producerIsWorking = false;
        }
    }
}

void *erase_buffer(void *args) {
    while (1) {
        buffer_info *curr_info = ((buffer_info*) args);
        int *buffer = (*curr_info).buffer;
        int buffer_size = (*curr_info).size;
        if (producerIsWorking) {
            printf("\nConsumer is sleeping\n");
            continue;
        }
        if (counter > 0) {
            buffer[counter] = 0;
            printf("\nConsumer: 0\n");
            counter--;
        }
        if (counter == 0) {
            consumerIsWorking = false;
        }
    }
}

int main() {

    int buffer_size = 20;
    int *buffer = malloc(sizeof(int) * buffer_size);

    pthread_t thread1, thread2;

    buffer_info *info = malloc(sizeof(buffer_info));
    (*info).buffer = buffer;
    (*info).size = buffer_size;

    int t1 = pthread_create(&thread1, NULL, fill_buffer, info);
    int t2 = pthread_create(&thread2, NULL, erase_buffer, info);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}


