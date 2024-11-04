#include<stdio.h>
/*write a c pgrm that computes the product of two integers by calling a function mult*/
int mult(int a,int b)
{  
    
   return a*b;
}
// int swap(int a,int b){
//     int temp;
//     temp=a;
//     a= b;
//     b=temp;
//     printf("the swap function prints:a= %d,b= %d\n",a,b);
// }

void swap(int *ptr2a,int *ptr2b){


    int *ptr2c =ptr2a; //temp  ptr2c
         ptr2a=ptr2b;
         ptr2b=ptr2c;
    printf("using pointers swap  prints:a= %d,b= %d\n",*ptr2a,*ptr2b);
}
int main ()
{
    int cat1=1;
    int *ptr2cat1=&cat1;
     // ptr2cat1=cat1; another way of intializing not declaring though         // * stands for a dereferencing operator it is a unary operator.
    printf("enter value of ptr2cat1 %d\n" ,*ptr2cat1);
    
    int cat2 =2 ;
    int  *ptr2cat2=&cat2;
    printf("enter value of ptr2cat1 %d\n" ,*ptr2cat2);
    swap(ptr2cat1,ptr2cat2);
    
    // printf("enter two integer: \n");
    // scanf("%d %d", &cat1 ,&cat2 ); //intro to &=ampersand= address/location
    // printf("the values of integers before swap are %d and %d\n",cat1,cat2);
    // printf("prod is %d\n",mult(cat1,cat2));
    // swap(cat1,cat2);
    // printf("the integer values after swap are %d and%d\n",cat2,cat1);

    return 0;
}

*********************************
output

enter value of ptr2cat1 1
enter value of ptr2cat1 2
using pointers swap  prints:a= 2,b= 1
