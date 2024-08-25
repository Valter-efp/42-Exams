#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	if (nbr == -2147483648)
		return("-2147483648\0");
	int n = nbr;
	int len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	char *res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return(NULL);
	res[len] = '\0';
	if (nbr == 0)
	{
		res[0] = '0';
		return(res);
	}
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	while(nbr)
	{
		res[--len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return(res);
}