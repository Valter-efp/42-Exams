#include <unistd.h>

void ft_putword(char *str, int start, int end)
{
	while (start < end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

int main(int argc, char *argv[])
{
	char *str;
	int i = 0;
	int fws;
	int fwe;

	if (argc > 1)
	{
		str = argv[1];

		while (str[i] == ' ' || str[i] == '\t')
			i++;
		fws = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
		fwe = i;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i])
		{
			while (str[i])
			{
				if (str[i] == ' ' || str[i] == '\t')
				{
					while (str[i] == ' ' || str[i] == '\t')
						i++;
					if (str[i])
						write(1, " ", 1);
				}
				else
				{
					write(1, &str[i], 1);
					i++;
				}
			}
			write(1, " ", 1);
		}
		ft_putword(str, fws, fwe);
	}
	write(1, "\n", 1);
	return 0;
}
