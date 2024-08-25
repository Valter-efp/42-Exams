#include <unistd.h>
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
	res[len] = '\0';
	if (nbr == 0)
	{
		res[0] = '0';
		return(res);
	}
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = nbr * - 1;
	}
	while(nbr)
	{
		res[--len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return(res);
}

int ft_strlen (char* str)
{
    if (*str == 0)
        return 0;
    return (strlen (str+1) +1);
}

int main(void)
{
	int i = 1;
	while(i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else
			write(1, ft_itoa(i), ft_strlen(ft_itoa(i)));
		i++;
		write(1, "\n", 1);
	}
}
