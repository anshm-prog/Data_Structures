#include<stdio.h>
int main()
{
	int arr[26],i  ;
	for(i = 0;i<=25;i++)
	{
		arr[i] = 'A' + i;
		printf("%d%c\n",arr[i],arr[i]);
		
	}
	return 0;
	
}
