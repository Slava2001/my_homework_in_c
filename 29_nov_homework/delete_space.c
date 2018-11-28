#include <stdio.h>
#include <ctype.h>

char c[256];
char out[256];
void del_space();


int main()
{

printf("Enter string:");
fgets(c,256,stdin);


del_space(&c,&out);


printf("%s",out);

}


void del_space()
{
	char last='a';
	int t=0;
	for(int i=0;i<256;i++)
	{
		
		
	        if(isspace(c[i]))
		{
			if(!isspace(last))
			{
				out[t]=' ';
				last=' ';
				t++;
			}
		}
		else
		{
			out[t]=c[i];
			last=c[i];
			t++;
		}
	}
}
