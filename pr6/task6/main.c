#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (){
	pid_t child_pid = fork();
	if (child_pid > 0) {
		system("ps -l | grep 'Z'");
		sleep(10);
        wait(NULL);
        system("ps -l | grep 'Z'");
	}
	return 0;
}