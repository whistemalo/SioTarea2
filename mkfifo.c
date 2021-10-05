#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

int guard(int ret, char * err) {
          if (ret == -1) { perror(err); exit(1); }
            return ret;
}

int main(void){
    guard(mkfifo("/home/williams/Siot2/fifodir/fifo",0666),"No se pudo crear la tuberia!");
    return 0;
}




