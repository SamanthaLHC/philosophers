#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
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

//-------   ------//
// ARG IN THREADS //
//-------   ------//

// voir video 7 de code vault
 
//instead of passiuine a fuunction without param we set a void in param
void *function(void *arg)
{
	// we need to cast because of the void ptr 
	int var_to_pass = *(int *)arg;
}

int main(int ac, char **av)
{
	pthread_t th[4];
	int i;
	for (i = 0; i < 4; i++)
	{
		if (pthread_create(&th[i], NULL, &function, NULL) != 0)
			return 1;
	}
	for (i = 0; i < 4; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return 3;
	}
	printf("stuff : %d\n", stuff);
}
