//==============================================================//
//==============================================================//
//functions Ok://
//=============//

//memset/ printf/ malloc/ free / write

//usleep / gettimeofday

//pthread_create

//pthread_detach

//pethread_join

//pthread_mutex_init

//pthread_mutex_destroy

// pthread_mutex_lock

// pthread_mutex_unlock
//=============================================================//
//=============================================================//

//compile with -pthread
// ATTENTION: do not use the flags with this code :
//gcc -pthread -g3 test_lock.c 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutex;

void	*function(void *arg)
{
	// we wanted to lock a single mutex the rest have to wait
	(void) arg;
	pthread_mutex_lock(&mutex);
	printf("got lock\n");
	sleep(1);
	pthread_mutex_unlock(&mutex);
	return NULL;
}

// if you use trylock you have to check the return value
int main(int argc, char* argv[]) {
	(void) argv;
	(void) argc;
    pthread_t th[4];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < 4; i++) {
        if (pthread_create(&th[i], NULL, &function, NULL) != 0) {
            perror("Error at creating thread");
        }
    }
    for (int i = 0; i < 4; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Error at joining thread");
        }
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}