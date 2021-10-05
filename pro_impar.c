#include <mqueue.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>


mqd_t pipe1;
// char impares[100];

int main(void){

    int h,carry,fd;
	char odd_number[100];
    int i=0;
	char destination[100];
	char odd_numbers[150]="Numeros impares: \n";
    srand(time(NULL));

    

    for (h=0; h<20;){
  		carry= rand() % 1000;  	

		if (carry % 2 == 0){}

		else{
				sprintf(odd_number, "%d ", carry);
				strcat(destination, odd_number);
				h++;
				if (h==10){strcat(destination, "\n");}
		}
    }
	
	strcat(odd_numbers, destination);
   
	strcat(odd_numbers, "\n\n");
    printf("%s", odd_numbers);

    // guard(fd = open("/home/williams/Siot2/fifodir/fifo",O_WRONLY), "No se pudo abrir FIFO");    
    // guard(write(fd, odd_numbers, sizeof(odd_numbers)), "No se pudo escrbir el numero en el FIFO");
    // close(fd);


    pipe1 = mq_open("/cola",O_WRONLY | O_CREAT, 0664, NULL);
    mq_send(pipe1, odd_numbers, strlen(odd_numbers)+1,0);
    return 0;
}

