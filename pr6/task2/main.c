#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main() {
	pid_t childPid = fork();
	time_t start = time(NULL), end = start + 5, now = start;
	int childCounts = 0, parentCounts = 0;
	while(now < end){
		if(childPid == 0){
			childCounts++;
		}
		if(childPid > 0){
			parentCounts++;
		}
		now = time(NULL);
	}

    if (childPid > 0)
    {
        printf("Parent: %d \n", parentCounts);
    }
    if (childPid == 0)
    {
        printf("Child: %d \n", childCounts);
    }

	return 0; 
}
