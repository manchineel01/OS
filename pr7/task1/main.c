#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* child_thread_function(void * args){
	for(int i = 1; i <= 10; i++){
		printf("Child Thread. Iteration: %d\n", i);
		sleep(2);
	}
}

int main (){
    pthread_t threadId;
    pthread_create(&threadId, NULL, &child_thread_function, NULL);

	for(int i = 1; i <= 10; i++){
		printf("Main Thread. Iteration: %d\n", i);
		sleep(1);
	}
	return 0;
}
