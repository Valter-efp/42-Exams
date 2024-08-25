#include <unistd.h>

void put_str_capit(char *str)
{
	int i = 0;

	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 'a' - 'A';
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' '|| str[i - 1] == '\t' || str[i - 1] == '\0'))
			str[i] = str[i] - 'a' + 'A';
		write(1, &str[i], 1);
		i++;
	}
}


int main(int argc, char **argv)
{
	int i = 1;

	if (argc > 1)
	{
		while (i < argc)
		{
			put_str_capit(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return(0);
}