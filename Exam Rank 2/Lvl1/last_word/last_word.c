# include <unistd.h>

void ft_putword(char *str, int ws, int we)
{
	while (ws < we)
	{
		write(1, &str[ws], 1);
		ws++;
	}
}

int main(int argc, char **argv)
{
	int i = 0;
	int lwe = 0;
	int lws = 0;

	if (argc == 2)
	{
		char *str = argv[1];

		while (str[i])
			i++;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
			i--;
		lwe = i + 1;
		while ( i >= 0 && (str[i] != ' ' && str[i] != '\t'))
			i--;
		lws = i + 1;
		ft_putword(str, lws, lwe);
	}
	write(1, "\n", 1);
	return (0);
}
