#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	fstream archivo("FUENTE.txt");
	string linea; 

	/*----- Variables globales compartidas -----*/

	int counter = 0, thread_count=6;
	pthread_mutex_t mutex_forvar;
	pthread_mutex_t mutex2;
	pthread_cond_t cond_var;


 void *barrera_condicional(void * arg)

 {

	int my_rank = (int)arg;
	//**Barrier**

	 pthread_mutex_lock(&mutex_forvar);
	 counter++;
	 printf("Running Thread : %ld\n",my_rank);

  if(counter == thread_count)

 {
         counter = 0;

         
         //--Notify all waiting threads--
	 pthread_cond_broadcast(&cond_var);

 }

 else

 {
          while(pthread_cond_wait(&cond_var, &mutex_forvar) != 0);

 }

 //**Release barrier**

 	pthread_mutex_unlock(&mutex_forvar);
	printf("Finished thread : %d\n",my_rank);
	nuevo++;
	pthread_exit(0);

	}
}
