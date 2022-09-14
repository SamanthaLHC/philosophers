#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

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

int stuff = 0;
pthread_mutex_t mutex;
//mutex prevent race condition 
void *function()
{
	for(int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		stuff++;
		pthread_mutex_unlock(&mutex);
	}	
}

int main(int ac, char **av)
{
	// a place where stock information about the thread, 
	//a pthread _t type variable v
	pthread_t th[4];
	int i;
	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 4; i++)
	{
		if (pthread_create(th + i, NULL, &function, NULL) != 0)
			return 1;
		printf("thread %d has started\n", i);
	}
	for (i = 0; i < 4; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return 3;
		printf("thread %d finished execution\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("stuff : %d\n", stuff);
}

//multithreads, launch at the same time  : 
//(two loops one for create the othe for pthread_join)

// sam@Hyperius ~/philosophers % gcc -pthread main.c
// sam@Hyperius ~/philosophers % ./a.out
// thread 0 has started
// thread 1 has started
// thread 2 has started
// thread 3 has started
// thread 0 finished execution
// thread 1 finished execution
// thread 2 finished execution
// thread 3 finished execution
// stuff : 4000000

// executing one after the other:
// (pthread_join in the same loop as pthread_create)

// sam@Hyperius ~/philosophers % gcc -pthread main.c
// sam@Hyperius ~/philosophers % ./a.out            
// thread 0 has started
// thread 0 finished execution
// thread 1 has started
// thread 1 finished execution
// thread 2 has started
// thread 2 finished execution
// thread 3 has started
// thread 3 finished execution
// stuff : 4000000
