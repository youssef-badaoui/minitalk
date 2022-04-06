#include <stdio.h>

void ft_pow(int a, long long  b)
{
	long long res = a;
	while(--b)
	{
		res *= a;
	}
    printf("%d\n", res);
}
int main()
{
    ft_pow(1,1000000000);
}