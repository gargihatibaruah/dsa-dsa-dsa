#include<stdio.h>
int main(){
int arr[50],i,num,size;
printf("Enter the size of the array: \n");
scanf("%d",&size);
printf("Enter the elements of the array: \n");
for(i=0;i<size;i++)
{
scanf("%d",&arr[i]);
}
for(i=0;i<size;i++)
{
printf("%d\n",arr[i]);
}
printf("Enter the number you want to insert in last position: \n");
scanf("%d",&num);

arr[size]=num;
size++;
printf("Updated array: \n");
for(i=0;i<size;i++)
{
printf("%d\n",arr[i]);
}

return 0;
}


