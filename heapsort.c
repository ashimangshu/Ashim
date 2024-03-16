#include <stdio.h>
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    while (l <= n && arr[l] > arr[largest])
    {
        largest = l;
    }
    while (r <= n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        heapify(arr, n, largest);
    }
}
void heapsort(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n; i >= 1; i--)
    {
        int temp1 = arr[1];
        arr[1] = arr[i];
        arr[i] = temp1;

        heapify(arr, i - 1, 1);
    }
}
int main()
{
    int n;
    printf("Enter the size : ");
    scanf("%d", &n);
    int arr[n + 1];
    printf("\n Enter the elements: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n Before sorting: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n After sortinh: ");
    heapsort(arr, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}