#include<stdio.h>
int main()
{
int arr[50],i,num,pos,size,key;
printf("Enter the size of elements in the array:  \n");
scanf("%d",&size);

printf("Enter the elements of the array:  \n");
for(i=0;i<size;i++)
{scanf("%d",&arr[i]);
}

printf("Original array: \n");
for(i=0;i<size;i++) //i=0
{printf("%d\n",arr[i]);
}
    key=arr[size-1];
    for(i=size-1;i<=size-1;i++){
        arr[i]=arr[i+1]; //shifting to left so we will start from pos-1
    }                 
    size--;

    printf("The deleted element is: %d\n",key);
    printf("The updated array is: \n");
    for(i=0;i<size;i++)
    {printf("%d\n",arr[i]);
    }
    return 0;
}
