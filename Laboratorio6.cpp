*Universidad del Valle de Guatemala
*Alexa Bravo	18831
*Jorge Suchite	15293
*Laboratorio 6 
*/

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
	archivo.open("FUENTE.txt",ios::in);
	
	if(archivo.fail()){
		cout<<"El archivo no se encuentra";
		
		exit(1);
		
	}
	
	while(!archivo.eof			
		getline(archivo,texto);
		cout<<texto<<endl;
		
	}
	
	archivo.close();
}

	/*----- Variables globales compartidas -----*/

	int counter = 0, thread_count=6;
	pthread_mutex_t mutex_forvar;
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