/*********Readers-Writers*****************/

#include <stdio.h>
#include <pthread.h>

#define MAX_READERS 5
#define MAX_WRITERS 5

int shared_resource = 0;
int num_readers = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_read = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_write = PTHREAD_COND_INITIALIZER;

void* reader(void* arg) {
    int reader_id = *(int*) arg;
    
    while (1) {
        // Acquire the mutex lock
        pthread_mutex_lock(&mutex);
        
        // Wait if there's a writer writing to the resource
        while (num_readers == -1) {
            pthread_cond_wait(&cond_read, &mutex);
        }
        
        // Increment the number of readers
        num_readers++;
        
        // Release the mutex lock
        pthread_mutex_unlock(&mutex);
        
        // Read from the shared resource
        printf("Reader %d read shared resource: %d\n", reader_id, shared_resource);
        
        // Acquire the mutex lock
        pthread_mutex_lock(&mutex);
        
        // Decrement the number of readers
        num_readers--;
        
        // Signal the writer waiting on cond_write if there are no more readers
        if (num_readers == 0) {
            pthread_cond_signal(&cond_write);
        }
        
        // Release the mutex lock
        pthread_mutex_unlock(&mutex);
    }
}

void* writer(void* arg) {
    int writer_id = *(int*) arg;
    
    while (1) {
        // Acquire the mutex lock
        pthread_mutex_lock(&mutex);
        
        // Wait if there's another writer or if there are readers
        while (num_readers != 0) {
            pthread_cond_wait(&cond_write, &mutex);
        }
        
        // Set the number of readers to -1, indicating that a writer is writing
        num_readers = -1;
        
        // Release the mutex lock
        pthread_mutex_unlock(&mutex);
        
        // Write to the shared resource
        shared_resource++;
        printf("Writer %d wrote shared resource: %d\n", writer_id, shared_resource);
        
        // Acquire the mutex lock
        pthread_mutex_lock(&mutex);
        
        // Set the number of readers back to 0, indicating that the writer is done writing
        num_readers = 0;
        
        // Signal all readers waiting on cond_read
        pthread_cond_broadcast(&cond_read);
        
        // Signal any writer waiting on cond_write
        pthread_cond_signal(&cond_write);
        
        // Release the mutex lock
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    int i;
    pthread_t readers[MAX_READERS], writers[MAX_WRITERS];
    int reader_ids[MAX_READERS], writer_ids[MAX_WRITERS];
    
    // Create the reader threads
    for (i = 0; i < MAX_READERS; i++) {
        reader_ids[i] = i;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }
    
    // Create the writer threads
    for (i = 0; i < MAX_WRITERS; i++) {
        writer_ids[i] = i;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }
    
   
// Wait for all threads to finish
for (i = 0; i < MAX_READERS; i++) {
    pthread_join(readers[i], NULL);
}
for (i = 0; i < MAX_WRITERS; i++) {
    pthread_join(writers[i], NULL);
}

return 0;
}
