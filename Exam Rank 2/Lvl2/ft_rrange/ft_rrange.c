#include <stdlib.h>

int ft_absol(int nbr)
{
	if (nbr < 0)
		nbr = nbr * - 1;
	return(nbr);
}

int     *ft_rrange(int start, int end)
{
	int i = 0;
	int len = ft_absol(start - end) + 1;
	int *res = malloc(sizeof(int) * len);

	while (i < len)
	{
		res[i] = end;
		if (start < end)
			end--;
		else
			end++;
		i++;
	}
	return(res);
}

// #include <stdio.h>
// int main (void)
// {
// 	int start = 0;
// 	int end = -3;
// 	int *arr = ft_rrange(start, end);
// 	int len = ft_absol(start - end) + 1;
// 	int i = 0;

// 	while (i < len)
// 	{
// 		printf("%d\n", arr[i]);
// 		i++;
// 	}
// }