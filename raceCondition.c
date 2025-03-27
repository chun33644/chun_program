
#include <stdio.h>
#include <pthread.h>

/*Question_1

int shared_var = 0;

void *func1() {
    for (int i = 0; i < 5; i++) {
       shared_var ++;
       printf("func1 [%d]: %d\n", i, shared_var);
    }

    return NULL;
}

void *func2() {
    for (int i = 0; i < 5; i++) {
        shared_var ++;
        printf("func2 [%d]: %d\n", i, shared_var);
    }
    
    return NULL;
}

void *func3() {
    for (int i = 0; i < 5; i++) {
        shared_var ++;
        printf("func3 [%d]: %d\n", i, shared_var);
    }
    
    return NULL;
}



int main() {

    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);
    pthread_create(&thread3, NULL, func3, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("Shared var: %d\n", shared_var);

    return 0;

}
*/


int shared_var = 0;

pthread_mutex_t lock;

void *func1() {

    pthread_mutex_lock(&lock);
    for (int i = 0; i < 5; i++) {
        shared_var ++;
        printf("func1 [%d]: %d\n", i, shared_var);
    }      
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *func2() {
    
    pthread_mutex_lock(&lock);
    for (int i = 0; i < 5; i++) {
        shared_var ++;
        printf("func2 [%d]: %d\n", i, shared_var);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *func3() {
    
    pthread_mutex_lock(&lock);
    for (int i = 0; i < 5; i++) {
        shared_var ++;
        printf("func3 [%d]: %d\n", i, shared_var);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}



void init_mutex () {
    pthread_mutex_init(&lock, NULL);
}

void destroy_mutex () {
    pthread_mutex_destroy(&lock);
}


int main() {

    pthread_t thread1, thread2, thread3;

    init_mutex();

    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);
    pthread_create(&thread3, NULL, func3, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("Shared var: %d\n", shared_var);

    destroy_mutex();

    return 0;

}


