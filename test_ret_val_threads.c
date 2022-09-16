#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

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

void * roll_dice()
{
	int value = (rand() % 6) + 1;
	// allocate is necessary becase of segfault
	int *result = malloc(sizeof(int));
	*result = value;
	// printf("%d\n", value);
	return (void *) &value;
}

// NOT THE BEST WAY WE HAVE TO IMPROVE
int main(int ac, char **av)
{
	pthread_t th;
	int i;
	int *res;
	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
			return 1;
	// the second param in pthread_join, take a refernce to a void ptr
	//(ptr sur ptr) is gonna set the value from what in it (here int *res)
	// void ptr is a sort of wildcard

	if (pthread_join(th, (void **) &res) != 0)
			return 3;
	printf("result: %d\n", *res);
	free(res);
}

