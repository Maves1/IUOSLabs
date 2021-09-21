#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int job_number;
} thread_info;

void *print_message(void *args) {
    thread_info *curr_info = ((thread_info*) args);
    printf("Thread number: %d\n", curr_info->job_number);
}

int main() {

    int n = 10;
    for (int i = 0; i < n; i++) {
        pthread_t thread;
        thread_info *curr_info = malloc(sizeof(thread_info));
        (*curr_info).job_number = i;
        int t_return = pthread_create(&thread, NULL, print_message, curr_info);
        printf("Creating thread #%d\n", i);
        pthread_join(thread, NULL);
        /* If we don't wait for the created thread to finish running,
         * it's likely that the last thread won't even have the time to print its message
         * */
    }

    return 0;
}


