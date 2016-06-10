#include<stdio.h>

int main()
{
	int t;
	while(1)
	{
		scanf("%d", &t);
		if(t == 42 )
			exit;
		else
			printf("%d\n", t);
	}
	return;
}
