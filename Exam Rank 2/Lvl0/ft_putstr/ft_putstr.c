#include <unistd.h>

void	ft_putstr(char *str)
{
	int i = 0;

	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

// int main (void)
// {
// 	char *test = "Printing on the standard output";

// 	ft_putstr(test);
// 	write(1, "\n", 1);
// 	return(0);
// }