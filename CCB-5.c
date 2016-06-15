#include<stdio.h>
//Updated the description
int main()
{
    int t, ii, x, j;
    scanf("%d", &t);
    int n[t], a[200] = {0};
    int y, i, carry = 0, tmp, m = 0;

    for(i=0;i<t;i++)
    {
        scanf("%d", &n[i]);
    }

    for(i=0;i<t;i++)
    {
            x = n[i];
            if(x > 100) return;

            if(x == 100)
            {
                    a[0] = 0;
                    a[1] = 0;
                    a[2] = 1;
                    m = 3;
            }
            else if(x > 9)
            {

                    a[0] = x % 10;
                    a[1] = x / 10;
                    m = 2;
            }
            else
            {
                    a[0] = x;
                    m = 1;
            }

            while(x > 1)
            {
                    for(ii = 0; ii < m; ii++)
                    {
                            y = a[ii];
                            a[ii] = (y * (x - 1) + carry) % 10;
                            carry = (y * (x - 1) + carry) / 10;
                    }
                    if(carry)
                    {
                            while(carry != 0)
                            {
                                    tmp = carry % 10;
                                    carry = carry / 10;
                                    a[ii] = tmp;
                                    //carry = 0;
                                    m++;
                                    ii++;
                            }
                    }
                    x--;
            }
            for(j=m-1;j>=0;j--)
            {
                    printf("%d", a[j]);
            }
    printf("\n");
    }
    return 0;
}

