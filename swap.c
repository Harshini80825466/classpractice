#include<stdio.h>
/*write a c pgrm that computes the product of two integers by calling a function mult*/


int mult(int a,int b)
{  
    
   return a*b;
}

int swap(int a,int b){
    int temp;
    temp=a;
    a= b;
    b=temp;
    printf("the swap function prints:a= %d,b= %d\n",a,b);
}
int main ()
{
    int cat1,cat2;
    printf("enter two integer: \n");
    scanf("%d %d", &cat1 ,&cat2 ); //intro to &=ampersand= address/location
    printf("the values of integers before swap are %d and %d\n",cat1,cat2);
    printf("prod is %d\n",mult(cat1,cat2));
    swap(cat1,cat2);
    printf("the integer values after swap are %d and%d\n",cat2,cat1);

    return 0;
}

**********************
output
  
enter two integer: 
23
45
the values of integers before swap are 23 and 45
prod is 1035
the swap function prints:a= 45,b= 23
the integer values after swap are 45 and23
