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
		int min =a[j];
		int min_index=j;

		for(int i=j;i<4;i++)
		{
			if(a[i]<min)
			{
				min=a[i];
				min_index=i;
			}
		}

		int temp = a[j];
		a[j] = a[min_index];
		a[min_index] = temp;
		//printf("min value = %d , min ind = %d\n",min,min_index);
	}

	for(int i=0;i<4;i++)
	{
		printf("%d ",a[i]);
	}

	return 0;
}
