/*#include<stdio.h>
void main()
{
	int arr[]={1,2,3,4,5};
	int num = 20,pos = 3;
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i=size;i<=pos;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[pos-1] = num;
	size++;
	for(int i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
}*/
#include <stdio.h>

int main()
{
    int arr[10] = {1,2,3,4,5};  // extra space
    int num = 20, pos = 3;
    int size = 5;

    for(int i = size; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = num;
    size++;

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}


