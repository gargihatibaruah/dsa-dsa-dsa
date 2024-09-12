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
printf("Enter the number you want to insert in 1st position: \n");
scanf("%d",&num);
for(i=size-1;i>=0;i--){
    arr[i+1]=arr[i];
}
arr[0]=num;
size++;
printf("Updated array: \n");
for(i=0;i<size;i++)
{
printf("%d\n",arr[i]);
}

return 0;
}
