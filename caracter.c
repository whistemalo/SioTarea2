#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){

    int i,carry;
    int h=0;
    srand(time(NULL));
    for (i=1; i<=20;)
    {	
	carry = rand() % 122;
    	if(carry>33){
	        printf(" %c",carry);
		i++;   
	}
	if(i==11)
	{
	 printf(" \n");
	 h=1;
	}
    }
         
    printf(" \n");
        
}


