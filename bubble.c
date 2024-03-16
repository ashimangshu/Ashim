#include<stdio.h>
void print(int *A,int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d",A[i]);
    }
    printf("\n");
}
void bubblesort(int *A,int n){
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
            temp=A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
            }
        }
    }
}

int main(){
   
    int A[]={5,4,3,2,1};
    int n=5;
    print(A,n);
    bubblesort(A,n);
    print(A,n);
    return 0;
}