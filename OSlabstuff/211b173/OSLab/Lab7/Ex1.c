/******************Producer and Consumer*************************/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t empty, full;
pthread_mutex_t mutex;

void* producer(void* arg) {
    int item;
    while (1) {
        item = rand() % 100; // Produce a random item
        sem_wait(&empty); // Wait for an empty slot
        pthread_mutex_lock(&mutex);
        buffer[in] = item; // Insert the item into buffer
        printf("Producer produced item: %d\n", item);
        in = (in + 1) % BUFFER_SIZE; // Increment the index
        pthread_mutex_unlock(&mutex);
        sem_post(&full); // Signal that a slot is full
        sleep(1); // Sleep for some time
    }
}

void* consumer(void* arg) {
    int item;
    while (1) {
        sem_wait(&full); // Wait for a full slot
        pthread_mutex_lock(&mutex);
        item = buffer[out]; // Remove an item from the buffer
        printf("Consumer consumed item: %d\n", item);
        out = (out + 1) % BUFFER_SIZE; // Increment the index
        pthread_mutex_unlock(&mutex);
        sem_post(&empty); // Signal that a slot is empty
        sleep(1); // Sleep for some time
    }
}

int main() {
    pthread_t tid1, tid2;
    sem_init(&empty, 0, BUFFER_SIZE); // Initialize empty semaphore to buffer size
    sem_init(&full, 0, 0); // Initialize full semaphore to 0
    pthread_mutex_init(&mutex, NULL); // Initialize mutex
    pthread_create(&tid1, NULL, producer, NULL); // Create producer thread
    pthread_create(&tid2, NULL, consumer, NULL); // Create consumer thread
    pthread_join(tid1, NULL); // Wait for producer thread to finish
    pthread_join(tid2, NULL); // Wait for consumer thread to finish
    sem_destroy(&empty); // Destroy empty semaphore
    sem_destroy(&full); // Destroy full semaphore
    pthread_mutex_destroy(&mutex); // Destroy mutex
    return 0;
}
