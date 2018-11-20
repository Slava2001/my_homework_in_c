//143
//53
#include <stdio.h>

int x=0;
int y=0;
char type=0;
char background='.';
char pen='*';
char line[142];

void Draw_d(int *x,int *y);
void Draw_x(int *x,int *y);
void Draw_k(int *x,int *y);
void Draw_f(int *x,int *y);

int main()
{
	while(1)
	{
		printf("Enter type:\n1 \\\n2 X\n3 []\n4 [*]\n5 exit\n");
		scanf("%d",&type);
		printf("Enter X:");
		scanf("%d",&x);
		x--;
		printf("Enter Y:");
		scanf("%d",&y);
		y--;

		for(int m=0;m<=sizeof(line);m++)
			line[m]=' ';

		switch(type)
		{
		case 1:
			Draw_d(&x,&y);
		break;
		case 2:
			Draw_x(&x,&y);
		break;
		case 3:
			Draw_k(&x,&y);
		break;
		case 4:
			Draw_f(&x,&y);
		break;
		default:
			return 0;
		}

	}
return 0;
}

void Draw_f(int *x,int *y)
{
	for(int t=0;t<=*x;t++)
		line[t]=background;

	printf("%s\n",line);

	for(int t=0;t<=*y-2;t++)
	{
		for(int i=0;i<*x;i++)
		line[i]=pen;
	
		line[0]=background;
		line[*x]=background;
		printf("%s\n",line);
	}

	for(int t=0;t<=*x;t++)
		line[t]=background;

	printf("%s\n",line);
}

void Draw_k(int *x,int *y)
{
	for(int t=0;t<=*x;t++)
		line[t]=background;

	printf("%s\n",line);

	for(int t=0;t<=*x;t++)
		line[t]=pen;
	
	line[0]=background;
	line[*x]=background;
	printf("%s\n",line);

	for(int i=0;i<=*y-4;i++) 
	{
		for(int d=0;d<=*x;d++)
			line[d]=background;

		line[1]=pen;
		line[*x-1]=pen;
		printf("%s\n",line);
	}

	for(int d=0;d<=*x;d++)
		line[d]=pen;
	
	line[0]=background;
	line[*x]=background;
	printf("%s\n",line);

	for(int t=0;t<=*x;t++)
		line[t]=background;
	
	printf("%s\n",line);
}


void Draw_x(int *x,int *y)
{
	int s=10;

	if(*x<*y)
	{s=*x;}else{s=*y;}

		for(int i=0;i<=s;i++)
		{
			for(int t=0;t<=*x;t++)
				line[t]=background;
			
			line[i]=pen;
			line[s-i]=pen;
			printf("%s\n",line);
		}	
		for(int i=0;i<*y-s;i++)
		{
			for(int t=0;t<=*x;t++)
				line[t]=background;

			printf("%s\n",line);
		}
}

void Draw_d(int *x,int *y)
{
	int s;
	
	if(*x<*y)
	{
		s=*x;
	}else
	{
		s=*y;
	}
	

	
	for(int i=0;i<=s;i++)
	{
		for(int t=0;t<=*x;t++)
			line[t]=background;

		line[i]=pen;
		printf("%s\n",line);
	}

	for(int t=0;t<*y-s;t++)
	{
		for(int i=0;i<=*x;i++)
			line[i]=background;
			
		printf("%s\n",line);
	}			
}






