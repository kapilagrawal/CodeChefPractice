#include<stdio.h>
#include<stdlib.h>

int A[99][99];

int TrianSum(int x)
{
    int i, j;
    
    for(i=x;i>0;i--)
    {
        for(j=i;j>0;j--)
        {
            if((A[i][j]+A[i-1][j-1]) > (A[i-1][j-1] + A[i][j-1]))
                A[i-1][j-1] = A[i][j]+A[i-1][j-1];
                
            else
                A[i-1][j-1] = A[i-1][j-1] + A[i][j-1];
        }
    }    
    
    return A[i][j];
}
int main()
{
    int t, i, n, j, k, sum;
    
    scanf("%d", &t);
    
    for(i=0;i<t;i++)
    {
        scanf("%d", &n);
        
        for(j=0;j<n;j++)
        {
            for(k=0;k<=j;k++)
            {
                scanf("%d", &A[j][k]);
                
            }
        }        
        
        sum = TrianSum(n-1);
        
        printf("%d\n", sum);
    }
    return 0;
}
