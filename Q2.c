#include<stdio.h>
int main()
{
	int mark;
	printf("Enter a number:");
	scanf("%d",&mark);
	if(mark>=90&&mark<=100)
	{
		printf("A Grade");
	}
	else if(mark>=86&&mark<=89)
	{
		printf("A- grade");
	}
	else if(mark>=82&&mark<=85)
	{
		printf("B+ Grade");
	}
	else if(mark>=78&&mark<=81)
	{
		printf("B Grade");
	}
	else if(mark>=74&&mark<=77)
	{
		printf("B- Grade");
	}
	else if(mark>=70&&mark<=73)
	{
		printf("C+ Grade");
	}
	else if(mark>=66&&mark<=69)
	{
		printf("C Grade");
	}
	else if(mark>=62&&mark<=65)
	{
		printf("C- Grade");
	}
	else if(mark>=58&&mark<=61)
	{
		printf("D+ Grade");
	}
	else if(mark>=55&&mark<57)
	{
		printf("D Grade");
	}
	else if(mark<55)
	{
		printf("F Grade");
	}
	else
	{
		printf("Invalid Mark");
	}
	return 0;
}
