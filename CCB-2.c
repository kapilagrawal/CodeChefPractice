#include <stdio.h>

int main(void) 
{
	// your code goes here
	int amt;
	float bal;
	scanf("%d" "%f", &amt, &bal);
	if((amt > 0 && amt <= 2000) && (bal >= 0 && bal <= 2000))
	{
	   if((amt % 5) != 0)
	   {
	   	   printf("%.2f\n", bal);
	       return 0;
	   }
	   else if( (bal < ( (float)amt+0.50) ) )
	   {
	       printf("%.2f\n", bal);
	       return 0;
	   }
	   else
	   {
	       bal = bal - (float)amt - 0.5;
	       printf("%.2f\n", bal);
	   }
	}
	return 0;
}
