#include<stdio.h>

int main()
{
    int t, i;
    int max, player;
    scanf("%d\n", &t);
    int p1[t], p2[t], lead[t][2];
    for(i=0;i<t;i++)
    {
        scanf("%d %d\n", &p1[i], &p2[i]);
    }
    for(i=0;i<t-1;i++)
    {
        if(p1[i] > p2[i])
        {
            lead[i][0] = 1;
            lead[i][1] = (p1[i] - p2[i]);
        }
        else
        {
            lead[i][0] = 2;
            lead[i][1] = (p2[i] - p1[i]);
        }
        p1[i+1] = p1[i+1] + p1[i];
        p2[i+1] = p2[i+1] + p2[i];
    }
    if(p1[i] > p2[i])
    {
        lead[i][0] = 1;
        lead[i][1] = (p1[i] - p2[i]);
    }
    else
    {
        lead[i][0] = 2;
        lead[i][1] = (p2[i] - p1[i]);
    }
    max = lead[i][1];
    for(i=0;i<t;i++)
    {
        if(max < lead[i][1])
        {
            max = lead[i][1];
            player = lead[i][0];
        }
    }
    printf("%d %d\n", player, max);
    return 0;
}
