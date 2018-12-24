#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

char lib[64][8];

int load_replaces();

int main(int argc,char *argv[])
{

if(load_replaces())
{
	return  -1;
} 






		char *input="input.c";
		char *out="out.c";
		
		
	
			if(argc==2)
			{
				input=argv[1];
				if(freopen(input,"r",stdin)==NULL){printf("wrong dir\n");return -1;}
			}else
			if(argc==3)
			{
				input=argv[1];	
				out=argv[2];
				if(freopen(input,"r",stdin)==NULL || freopen(out,"w",stdout)==NULL){printf("wrong dir\n");return -1;}
			}else if(argc!=1)
			{
			printf("wrong arguments\nuse: ./main input.c out.c\n");
			return -1;
			}






	
	
	
	char line[256];
	srand(time(NULL));
    while( fgets(line, 256, stdin)!=NULL)
    {
    	for(int i=0;i<strlen(line);i++)
    	{
			int lib_line=64;

			for(int q=0;q<64;q++)
			{
				if(lib[q][0]==line[i])
				{
					
					lib_line=q;
					break;
				}
			}

    		if(lib_line<60)
			{
    			int lib_char=rand()%strlen(lib[lib_line]);
			
	    		putc(lib[lib_line][lib_char],stdout);
			}else
			{
				putc(line[i],stdout);
			}
    	}

	   

    }

return 0;


}



int load_replaces()
{
FILE *replacesfile;
replacesfile=freopen("replaces.txt","r",stdin);

if(replacesfile==NULL)
{
printf("Replaces not found!\n");
return -1;	
}

int count_line=0;

char line[3];

bool find;

while( fgets(line, 3, stdin)!=NULL)
    {
    	find=false;
    	for(int i=0;i<10;i++)
    	{
    		if(lib[i][0]==line[0])
    		{
    			lib[i][strlen(lib[i])]=line[1];
    			find=true;
    			break;
    		}

    	}

    	if(!find)
    	{
    			
    			lib[count_line][0]=line[0];
    			lib[count_line][1]=line[1];
    			count_line++;
    	}



    }


fclose(replacesfile);
return 0;


}




