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

	bool comit=false;	
	bool str=false;
   

    while( fgets(line, 256, stdin)!=NULL)
    {
    	for(int i=0;i<strlen(line);i++)
    	{

    		if(line[i]=='\"')str!=str;
    		if(!str&&line[i]=='/'&&line[i+1]=='*')comit=true;
    		if(!str&&line[i-2]=='*'&&line[i-1]=='/')comit=false;
    		if(!str&&line[i]=='/'&&line[i+1]=='/'){putc('\n',stdout);break;}
    		if(!comit)putc(line[i],stdout);
    	}
    }


return 0;
}
