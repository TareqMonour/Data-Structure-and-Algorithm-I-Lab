#include<stdio.h>
int main()
{

    int a[7]={3,3,3,3,7,8,9};

	int low_index = 0;
	int high_index = 6;
	int mid_index;
	int key ;
	int save = -1;

	printf("Enter the key = ");
	scanf("%d",&key);

	while(low_index<=high_index)
	{
		mid_index =  (low_index+high_index)/2;

		if(a[mid_index]==key)
		{
			//printf("%d found in index %d",key,mid_index);
			//break;
			save = mid_index;
			low_index = mid_index+1;
		}
		else if(a[mid_index]<key)
		{
			low_index = mid_index+1;
		}
		else
		{
			high_index = mid_index-1;
		}
	}

	printf("Last %d found in index %d",key,save);
	return 0;
}
