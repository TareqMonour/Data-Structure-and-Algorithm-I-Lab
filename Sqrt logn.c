#include<stdio.h>
int main()
{
	int n = 36;
	int low = 0;
	int high = 36;
	int mid;

	while(low<=high)
	{
		mid = (low+high)/2;

		if(mid*mid==n)
		{
			printf("SQRT of %d is = %d",n,mid);
			break;
		}
		else if(mid*mid>n)
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
	return 0;
}
