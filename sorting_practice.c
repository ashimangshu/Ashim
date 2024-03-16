#include<stdio.h>
#include<stdlib.h>

void print(int arr[],int n)

{
    for (int i=0;i<n;i++)
    {
    printf("%d",arr[i]);
    }   
}

void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;

    }
}

void selection_sort(int arr[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        if(min!=i)// swap(arr[i],arr[min]);
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    
}
////merge sort

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = low;
        int i = low;
        int j = high;

        while (i <= j) {
            while (arr[i] <= arr[pivot] && i <= high) {
                i++;
            }
            while (arr[j] > arr[pivot]) {
                j--;
            }

            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else {
                break; // Break the loop when i crosses j
            }
        }

        int temp1 = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp1;

        int loc = j; // Update the location of the pivot

        quicksort(arr, low, loc - 1);
        quicksort(arr, loc + 1, high);
    }
}
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i;
    int r=2*i +1;
    while(l <= n && arr[l]>arr[largest])
    {
        largest=l;
    }
    while(r <= n && arr[r]<arr[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;

        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        heapify(arr,n,i);
    }
    for(int i=n;i>=1;i--)
    {
        int temp1= arr[1];
        arr[1]=arr[i];
        arr[i]=temp1;

        heapify(arr,n,1);
    }
}

int main()
{
    int n;
    printf("please enter the size of the array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: \n");
    for(int i=1;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("original array:\n");
    print(arr,n);
  //insertion_sort(arr,n);
   // selection_sort(arr,n);
   //mergeSort(arr,0,n);
   //quicksort(arr,0,n-1);
   heapsort(arr,n);
    printf("\n");
    printf("sorted array:\n");
    print(arr,n);

    return 0;
}