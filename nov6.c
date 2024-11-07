#include<stdio.h>
/*
array={0,0,1,2,1,1,1,1,1,1,1,1,2}
*/
int main()
{ 
int array[8]={0,0,0,1,2,1,1,1};
int n=8;
int mat[8][2];
int i,j,counter;



for(i=0;i<8;++i)
    mat[i][0]=array[i];//array entry
    mat[i][1]=1;//array frequency entry


for (i=0;i<8;++i){
    for(j=0;j<8;++j)
     {include<stdio.h>
/*
array={0,0,1,2,1,1,1,1,1,1,1,1,2}
*/
int main()
{ 
int array[8]={0,0,0,1,2,1,1,1};
int n=8;
int mat[8][2];
int i,j,counter;



for(i=0;i<8;++i)
    mat[i][0]=array[i];//array entry
    mat[i][1]=1;//array frequency entry


for (i=0;i<8;++i){
    for(j=0;j<8;++j)
     {
        if(j!=i)
          if(array[j]==array[i])
             //counter= counter+1;
             mat[i][1]+=1;
      }
 } 



 printf("i=%d\n",i);

 int max =mat[0][1];
 int mode;
 for(i=0;i<8;++i)
 {
    if(max<mat[i][1]){
        max=mat[0][i];
        mode= mat[i][1];

    }
 }
printf("mode =%d",mode); 


 
}
 } 



 printf("i=%d\n",i);

 int max =mat[0][1];
 int mode;
 for(i=0;i<8;++i)
 {
    if(max<mat[i][1]){
        max=mat[0][i];
        mode= mat[i][1];

    }
 }
printf("mode =%d",mode); 


 
}
