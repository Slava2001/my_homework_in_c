 
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include <stdbool.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{

		char *input="input.c";
		char *out="out.c";
		
		if(argc!=1){
		if(argc!=3)
		{
			printf("wrong arguments\nuse: ./main input.c out.c\n");
			return -1;
		}else
		{

			input=argv[1];	

			out=argv[2];

			
			if(freopen(input,"r",stdin)==NULL || freopen(out,"w",stdout)==NULL){printf("wrong dir\n");return -1;}

		}}else
		{
			printf("use ctl+c to exit\n");			
		}






	
	
	
	char line[256];
	int lvl=0;


    while( fgets(line, 256, stdin)!=NULL)
    {
    	
    		int i=0;
    		while(line[i]=='\t')i++;
				for(int q=i;q<strlen(line);q++)
    		{
    		if(line[q]=='}'){lvl--;}
			
			}
			for(int q=0;q<(lvl);q++)putc('\t',stdout);


    		for(int q=i;q<strlen(line);q++)
    		{
    		
			if(line[q]=='{'){lvl++;}
			}
			

			

    			
    	

    		
    		for(;i<strlen(line);i++)
    		{
    			
				putc(line[i],stdout);
			}




	}

    		
	    	


return 0;
}

 
