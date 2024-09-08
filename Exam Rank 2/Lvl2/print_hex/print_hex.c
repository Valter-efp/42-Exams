# include <unistd.h>

int ft_atoi(char *str)
{
	int nbr = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		nbr = nbr * 10;
		nbr = nbr + str[i] - '0';
		++i;
	}
	return (nbr);
}

void print_hex(int nbr)
{
	char hex[] = "0123456789abcdef";

	if (nbr >= 16)
		print_hex(nbr / 16);
	write(1, &hex[nbr % 16], 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write (1, "\n", 1);
	return (0);	
}
