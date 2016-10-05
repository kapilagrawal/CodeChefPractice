PROBLEM:
Find the Number of Trailing Zeroes at the end of N!

EXPLANATION:
Let us look at some examples and develop the algorithm step by step as we go along.

Suppose I need to find out how many times 10 is a factor in the expansion of 23!.

A number gets a zero at the end of it if the number has 10 as a factor. For instance, 10 is a factor of 50, 120, and 1234567890.Since 5×2 = 10, I need to account for all the products of 5 and 2. Looking at the factors in the expansion of a factorial, there are many more numbers that are multiples of 2 (2, 4, 6, 8, 10, 12, 14,...)than are multiples of 5 (5, 10, 15,...). That is, if I take all the numbers with 5 as a factor, I'll have way more than enough even numbers to pair with them to get factors of 10 (and another trailing zero on my factorial). So to find the number of times 10 is a factor, all I really need to worry about is how many times 5 is a factor in all of the numbers between 1 and 23. How many multiples of 5 are between 1 and 23? There is 5, 10, 15, and 20, for four multiples of 5. Paired with 2's from the even factors, this makes for four factors of 10, so:

23! has four trailing zeroes

Find the number of trailing zeroes in 101! Okay, how many multiples of 5 are there in the numbers from 1 to 101? There's 5, 10, 15, 20, 25,... Oh, heck; let's do this the short way: 100 is the closest multiple of 5 below 101, and 100 ÷ 5 = 20, so there are twenty multiples of 5 between 1 and 101.

But wait: 25 is 5×5, so each multiple of 25 has an extra factor of 5 that I need to account for. How many multiples of 25 are between 1 and 101? Since 100 ÷ 25 = 4, there are four multiples of 25 between 1 and 101.

Adding these, I get 20 + 4 = 24 trailing zeroes in 101!

Find the number of trailing zeroes in the expansion of 1000! Okay, there are 1000 ÷ 5 = 200 multiples of 5 between 1 and 1000. The next power of 5, namely 25, has 1000 ÷ 25 = 40 multiples between 1 and 1000. The next power of 5, namely 125, will also fit in the expansion, and has 1000 ÷ 125 = 8 multiples between 1 and 1000. The next power of 5, namely 625, also fits in the expansion, and has 1000 ÷ 625 = 1.6.625 has 1 multiple between 1 and 1000. (I don't care about the 0.6 "multiples", only the one full multiple, so I truncate my division down to a whole number.) In total, I have 200 + 40 + 8 + 1 = 249 copies of the factor 5 in the expansion, and thus: 249 trailing zeroes in the expansion of 1000!

The General Algorithm to be followed is given below:

Take the number that you've been given the factorial of.
Divide by 5; if you get a decimal, truncate to a whole number.
Divide by 5^2 = 25; if you get a decimal, truncate to a whole number.
Divide by 5^3 = 125; if you get a decimal, truncate to a whole number.
Continue with ever-higher powers of 5, until your division results in a number less than 1. Once the division is less than 1, stop.
Sum all the whole numbers you got in your divisions. This is the number of trailing zeroes.
Here's how the algorithm works. How many trailing zeroes would be found in 4617!, upon expansion? I'll apply the procedure from above:

5^1 : 4617 ÷ 5 = 923.4, so I get 923 factors of 5
5^2 : 4617 ÷ 25 = 184.68, so I get 184 additional factors of 5
5^3 : 4617 ÷ 125 = 36.936, so I get 36 additional factors of 5
5^4 : 4617 ÷ 625 = 7.3872, so I get 7 additional factors of 5
5^5 : 4617 ÷ 3125 = 1.47744, so I get 1 more factor of 5
5^6 : 4617 ÷ 15625 = 0.295488, which is less than 1, so I stop here.
Then 4617! has 923 + 184 + 36 + 7 + 1 = 1151 trailing zeroes.




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
