#include <stdio.h>
//Updated the description
int power(int x, int y)
{
    int i, r = 1;
    for (i = 1; i <= y; i++)
    {
        r = r * x;
    }
    return r;
}

int main()
{
    int r, d, l, j, i = 1, cnt = 0;
    scanf("%d", &l);
    int n[l], z[l];
    for(j=0;j<l;j++)
    {
        scanf("%d", &n[j]);
    }
    for(j=0;j<l;j++)
    {
        i = 1;
        cnt = 0;
        r = power(5, i);
        while(r <= n[j])
        {
            d = n[j]/r;
            cnt = cnt + d;
            i++;
            r = power(5, i);
        }
        z[j] = cnt;
    }
    for(j=0;j<l;j++)
    {
        printf("%d\n", z[j]);
    }
    return 0;
}
