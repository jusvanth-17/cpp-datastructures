#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int array[],int size)
{
    for(int step=0;step=size-1;step++)
    { 
        int min_idx=step;
        for(int i=i+step;i<size;i++)
        {
          if(i<array[min_idx])
          {
            min_idx=i;
          }
          swap(&array[i],&array[min_idx]);
        }

    }
}
 int main()
 {
    int size;
    int  array[]={10,90,20,50,30};
    size=sizeof(array)/sizeof(array[0]);


 }