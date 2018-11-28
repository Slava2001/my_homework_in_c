#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


char c_int[10]="\0\0\0\0\0\0\0\0\0\0";
int out; 


int main()
{
printf("Enter int:");

fgets(c_int,10,stdin);
for(int i=0;i<10;i++)
{
	if(!isdigit(c_int[i])&&c_int[i]!='\0')
	{
	printf("Error!!!");
	return 0;
	}
}

out=atoi(c_int);


printf("%d",out);

return 0;
}
