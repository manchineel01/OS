#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main(){
    struct utsname compt;
    uname(&compt);
    
    printf("HostId: %ld\nSysname: %s\nNodename: %s\nRealease: %s\nVersion: %s\nMachine: %s\n", gethostid(), compt.sysname, compt.nodename, compt.release, compt.version, compt.machine);
}