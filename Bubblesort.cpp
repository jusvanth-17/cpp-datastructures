// #include <iostream>
// using namespace std;
// void bubblesort(int array[],int size)
// {
//     bool sw;
//     for(int step =0 ;step< size-1; ++step)
//     {
//         sw = false;
//         for(int i=0;i < size-step-1;++i)
//         {
//             if(array[i]>array[i+1])
//             {
//                 sw = true;
//                 int temp=array[i];
//                 array[i]=array[i+1];
//                 array[i+1]=temp;
//             }
//         }
//         if(sw == false)
//         break;
//     }
// }
// void printf1(int array[],int size)
// {
//     int i ;
//     for (i = 0; i < size; i++)
//     {
//         cout << " " << array[i];

//     }
// }

// // int main()
// {
//     int array[] = { 64, 34, 25, 12, 22, 11, 90 };
//     int size= sizeof(array) / sizeof(array[0]);
//     bubblesort(array, size);
//     cout<<"The sorted array:";
//     printf1(array,size);
//     return 0;
 
// }

//normal BS
#include <iostream>
using namespace std;
void bubblesort(int array[],int size)
{
   
    for(int step =0 ;step< size-1; ++step)
    {
        for(int i=0;i < size-step-1;++i)
        {
            if(array[i]>array[i+1])
            {
                int temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
            }
        }
    }
}
void printf1(int array[],int size)
{
    int i ;
    for (i = 0; i < size; i++)
    {
        cout << " " << array[i];

    }
}

int main()
{
    int array[] = { 64, 34, 25, 12, 22, 11, 90 };
    int size= sizeof(array) / sizeof(array[0]);
    bubblesort(array, size);
    cout<<"The sorted array:";
    printf1(array,size);
    return 0;
 
}
