#include<stdio.h>

int main(){
    int dog[2]={-90,8};
    int max=dog[0];
    if (max>dog[1]){
    printf("the max value is = %d\n",dog[0]);
    }
    else {
    printf("the max value is = %d\n",dog[1]);
    }
    

    for(int i=1;i< 2; ++i) 
    {
        if(max > dog[i]){
          printf("max =%d\n",max);
        }
        else{
          printf("max =%d\n",dog[i]);  
    }
    }
}


******************************************
output

the max value is = 8
max =8
