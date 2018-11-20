#include <stdio.h>

uint input;

void shifr();
void bit_print();

int main()
{
printf("Enter:");
scanf("%d",&input);
shifr();
printf("%d",input);
return 0;
}

void shifr()
{


bit_print();


for(int i=0;i<17;i+=2)
{
int bit1=0;
int bit2=0;

bit1=input&(1<<i);
bit2=input&(1<<(i+1));

input=input&(~(1<<i));
input=input&(~(1<<(i+1)));


input=input^(bit1<<1);
input=input^(bit2>>1);

}
bit_print();

}

void bit_print()
{
for(int i=32;i>=0;i--)
{

int bit=0;
bit=input&(1<<i);
printf("%d",(bit>>i));


}
printf("\n");
}

