#include <stdio.h>

void Merge(int A[], int L[], int nl, int R[], int nr)
{
    int i = 0, j = 0, k = 0;
    
    while((i<nl) && (j<nr))
    {
        if(L[i] < R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<nl)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        A[k] = R[j];
        k++;
        j++;
    }
}

void MergeSort(int A[], int n)
{
    int mid, i;
    if(n<2) return;
    
    mid = n/2;
    int left[mid];
    int right[n-mid];
    
    for(i=0;i<mid;i++)
        left[i] = A[i];
        
    for(i=mid;i<n;i++)
        right[i-mid] = A[i];
        
    MergeSort(left, mid);
    MergeSort(right, n-mid);
    Merge(A, left, mid, right, n-mid);
}

int main()
{
    int i, t;
    static int arr[1000000];
    scanf("%d", &t);
    
    
    for(i=0;i<t;i++)
        scanf("%d\n", &arr[i]);
    MergeSort(arr, t);
    
    for(i=0;i<t;i++)
        printf("%d\n", arr[i]);
    return 0;
}
