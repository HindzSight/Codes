/************Dinning Philosophers*************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define LEFT(i) ((i) + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS
#define RIGHT(i) ((i) + 1) % NUM_PHILOSOPHERS

pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left_fork = id;
    int right_fork = RIGHT(id);

    while (1) {
        // Thinking
        printf("Philosopher %d is thinking.\n", id);

        // Pick up forks
        pthread_mutex_lock(&forks[left_fork]);
        printf("Philosopher %d picks up fork %d.\n", id, left_fork);

        pthread_mutex_lock(&forks[right_fork]);
        printf("Philosopher %d picks up fork %d.\n", id, right_fork);

        // Eating
        printf("Philosopher %d is eating.\n", id);
        sleep(2);

        // Put down forks
        pthread_mutex_unlock(&forks[left_fork]);
        printf("Philosopher %d puts down fork %d.\n", id, left_fork);

        pthread_mutex_unlock(&forks[right_fork]);
        printf("Philosopher %d puts down fork %d.\n", id, right_fork);
    }
}

int main() {
    int i;
    int ids[NUM_PHILOSOPHERS];

    // Initialize mutexes
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create threads for philosophers
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
