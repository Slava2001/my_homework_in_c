#include <stdio.h>
#include <inttypes.h> 

void sdvig(int n);
int get_bit(int n);
void print_bit();
void set_bit(int n,int value);

uint input=0;

int n;

int main()
{
	while(1)
	{
		printf("input:\n");
		scanf("%"SCNu32,&input);
		printf("input n:\n");
		scanf("%d",&n);
		n=n%32;

		print_bit();	

		sdvig(n);

		print_bit();

		printf("%"PRIu32"\n",input);

	}
	return 0;
}

void sdvig(int n)
{
for(int i=0;i<n;i++)
{
int a=0;
a=get_bit(0);
input=input>>1;
set_bit(31,a);	
}
}

void print_bit()
{
	for(int i=31;i>=0;i--)
	printf("%d",get_bit(i));
	printf("\n");
}

int get_bit(int n)
{
	uint a=0;
	a=input&(1<<n);
	return a>>n;
}
void set_bit(int n,int value)
{
	input=input&(~(1l<<n));
	input=input|(value<<n);
}
