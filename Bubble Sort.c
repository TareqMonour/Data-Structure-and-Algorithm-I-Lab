#include<stdio.h>
int main()
{
	int a[4]={4,5,1,2};

	for(int i=0;i<4;i++)
	{
		printf("%d ",a[i]);
	}

	printf("\nAfter sort :\n");

	for(int j=0;j<4;j++)
	{
		for(int i=1;i<4-j;i++)
		{
			if(a[i]<a[i-1])
			{
				int t = a[i];
				a[i] = a[i-1];
				a[i-1] = t;
			}
		}

	}

	for(int i=0;i<4;i++)
	{
		printf("%d ",a[i]);
	}


	return 0;
}
