//syntax: datatype *pointer_name;
#include<stdio.h>
int main(){
    int a=10;
    int *p;
    p=&a; //p points to a
    printf("%p\n",*p); //prints address
    printf("%d",*p); //prints value of a
    return 0;




}