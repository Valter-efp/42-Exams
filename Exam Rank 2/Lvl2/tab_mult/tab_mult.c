#include <unistd.h>

int ft_atoi(char *str)
{
	int res = 0;
	int sign = 1;
	int i = 0;

	while(str[i] == ' ' || str[i] == '\t')
		i++;
	if(str[i] == '+')
		i++;
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return(sign * res);
}

void ft_putnbr(int n)
{
	char digits[10] = "0123456789";

	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &digits[n % 10], 1);
}

int main (int argc, char **argv)
{
	int tab = 1;

	if (argc == 2)
	{
		int nbr = ft_atoi(argv[1]);
		while(tab <= 9)
		{
			ft_putnbr(tab);
			write(1, " x ", 3);
			ft_putnbr(nbr);
			write(1, " = ", 3);
			ft_putnbr(tab * nbr);
			write(1, "\n", 1);
			tab = tab + 1;
		}
	}
	else
		write(1, "\n", 1);
	return(0);
}