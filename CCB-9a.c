#include<stdio.h>
#include<stdlib.h>

int Memo[99][99];
int A[99][99];

int TrianSum(int n, int x, int y)
{
    int t1, t2;
    
    if(x>=(n)) return 0;
    
   if(Memo[x][y] != -1) return Memo[x][y];
    
    t1 = TrianSum(n, x+1, y);
    t2 = TrianSum(n, x+1, y+1);
    
    Memo[x][y] = A[x][y] + (t1>t2?t1:t2);
    
    return Memo[x][y];
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
                Memo[j][k] = -1;
            }
        }        
        
        sum = TrianSum(n, 0, 0);
        
        printf("%d\n", sum);
    }
    return 0;
}
