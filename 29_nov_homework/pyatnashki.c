#include <stdio.h>
#include <termios.h>


void Draw(int a[]);
void flip(int dir);
void create_game();

static struct termios stored;

void init()
{
	struct termios settings;
	tcgetattr(0, &stored);
	settings=stored;

	settings.c_lflag &=(~ICANON);
	settings.c_lflag &=(~ECHO);
	settings.c_cc[VTIME] =0;
	settings.c_cc[VMIN]=1;
	tcsetattr(0,TCSANOW,&settings);
}

void reset()
{
	tcsetattr(0,TCSANOW,&stored);
}



int poz=14;
	
int map[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,0,15};

int main()
{
	char dir;


	init();
	printf("\n");

	create_game();

	Draw(map);
	while((dir=getc(stdin))!='q')
	{

		flip(dir);
		Draw(map);
		int status=1;
		for(int i=0;i<15;i++)
		{
			if(map[i]!=(i+1))
			{
				status=0;
			}
		}
		
		if(status==1)
		{
			printf("WIN!!!");
			reset();
			return 0;
		}
	}



}


void Draw(int a[])
{
	for(int y=0;y<4;y++)
	{
		for(int x=0;x<4;x++)
		{	
			if(a[y*4+x]!=0){
			printf("%3d",a[y*4+x]);}else{printf("   ");}	
		}	
	printf("\n");
	}
	
	printf("\n\n\n");



}

void flip(int dir)
{
	switch (dir)
	{
	case 65:
		if(poz>3)
		{
			map[poz]=map[poz-4];
			map[poz-4]=0;
			poz-=4;
		}
	break;
	case 66:
		if(poz<12)
		{
			map[poz]=map[poz+4];
			map[poz+4]=0;
			poz+=4;
		}
	break;
	case 68:
		if(poz!=0&&poz!=4&&poz!=8&&poz!=12)
		{
			map[poz]=map[poz-1];
			map[poz-1]=0;
			poz--;
		}
	break;
	case 67:
		if(poz!=3&&poz!=7&&poz!=11&&poz!=15)
		{
			map[poz]=map[poz+1];
			map[poz+1]=0;
			poz++;
		}
	break;
	}
}
void create_game()
{
	/*for(int i=0;i<101;i++)
	{
		flip(65-68);
		здесь нужно сгерерировать слуайное число
		такой способ гарантирует что пятнашки можно будет решить
	}*/
}

/*
			 ___   ___   ___   ___
			| 1 | | 2 | | 3 | | 4 |
                        |___| |___| |___| |___|
			
			 ___   ___   ___
			| 5 | | 6 | | 7 |
			|___| |___| |___| 

*/
