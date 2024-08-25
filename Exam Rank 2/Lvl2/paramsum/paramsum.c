#include <unistd.h>

void ft_putnbr(int n)
{
	char digits[10] = "0123456789";

	if (n >= 10)
		ft_putnbr( n / 10);
	write(1, &digits[n % 10], 1);
}

int main (int argc, char **argv)
{
	*argv = NULL;

	if (argc > 0)
		ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return(0);
}