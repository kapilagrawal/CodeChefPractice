#include <stdio.h>
//Updated the description
int main(void) 
{
	int i, n, k, x;
	int count = 0;
	scanf("%d %d", &n, &k);
	for(i = 0;i < n; i++)
	{
	    scanf("%d", &x);
	    if(x % k == 0)
	        count++;
	}
	printf("%d", count);
	return 0;
}
