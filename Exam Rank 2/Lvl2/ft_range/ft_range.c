#include <stdlib.h>

int ft_abs(int nbr)
{
	if (nbr < 0)
		nbr = nbr * - 1;
	return(nbr);
}

int     *ft_range(int start, int end)
{
	int i = 0;
	int len = ft_abs((end - start)) + 1;	
	int *res = malloc(sizeof(int) * len);

	while(i < len)
	{
		if (start < end)
		{
			res[i] = start;
			start++;
			i++;
		}
		else
		{
			res[i] = start;
			start--;
			i++;
		}
	}
	return(res);
}