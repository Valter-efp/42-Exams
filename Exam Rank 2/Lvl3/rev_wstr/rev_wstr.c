#include <unistd.h>

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
	if (argc == 2)
	{
		int i = 0;
		int ws = 0;
		int we = 0;
		char *str = argv[1];

		while(str[i])
			i++;
		
		while (i >= 0)
		{
			while (str[i] == '\0' || str[i] == ' ')
				i--;
			we = i + 1;
			while (str[i] && str[i] != ' ')
				i--;
			ws = i +1;
			int flag;
			flag = ws;
			ft_putword(str, ws, we);
			if (flag != 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return(0);
}