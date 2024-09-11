# include <unistd.h>

int	ft_atoi(const char *str)
{
	int  i = 0;
	int res = 0;
	int sign = 1;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-')
	{
		sign = sign * - 1;
		i++;
	}
	while (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);		
}

void ft_put_nbr(int n)
{
	char digits[10] = "0123456789";

	if (n > 9)
		ft_put_nbr(n / 10);
	write(1, &digits[n % 10], 1);
}

int ft_is_prime(int n)
{
	int i = 2;

	if (n <= 1)
		return(0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return(0);
		i++;
	}
	return(1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int n = ft_atoi(argv[1]);
		int sum = 0;

		while (n > 0)
		{
			if (ft_is_prime(n))
				sum = sum + n;
			n--;
		}
		ft_put_nbr(sum);
	}
	if (argc != 2)
		ft_put_nbr(0);
	write(1, "\n", 1);
	return (0);
}