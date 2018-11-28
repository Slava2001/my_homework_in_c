#include <stdio.h>

char dir[256];
char name[256];

void search();

int main()
{
	printf("Enter dir:");
	fgets(dir,256,stdin);
	search();
	printf("%s",name);	


return 0;
}
void search()
{
int t=0;
	for(int i=0;i<255;i++)
	{
		if((dir[i]=='/')|(dir[i]=='\\'))
		{	
			t=i;
			continue;
		}
	}
	int a=0;
	for(int i=(t+1);i<256;i++)
	{
		name[a]=dir[i];
		a++;
	}
}
