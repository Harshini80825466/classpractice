#include<stdio.h>
/* swap integers using pointer
these integers are entries of an array called dog . This array is of length 2.

*/


//void swap(int a,intb){

//}
int main(){

int dog[2]={-90,8};

int *ptr2dog = &dog[0];
printf("array[0]=%d ,array=%d \n",dog[0],dog[1]);  
printf("ptr2dog=%d\t ptr2dog next entry= %d\n",*ptr2dog,*(ptr2dog+1));
//********************************
for(int i=0; i<2 ; i++)
    printf("dog[%d]=%d\n",i,dog[i]);
//************************************************** */

//scope of i is only the first line following for-loop.

for(int i=0; i<2 ; i++)
    printf("ptr2dog[%d]=%d\n",i,*(ptr2dog+i));
   
    return 0;
}



*************************
output
array[0]=-90 ,array=8 
ptr2dog=-90	 ptr2dog next entry= 8
dog[0]=-90
dog[1]=8
ptr2dog[0]=-90
ptr2dog[1]=8
