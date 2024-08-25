#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 1;
	
	if (argc == 2)
	{
		int nbr = atoi(argv[1]);

		if (nbr == 1)
			printf("1");
		while (nbr >= ++i)
		{
			if (nbr % i == 0)
			{
				printf("%d", i);
				if (nbr == i)
					break;
				printf("*");
				nbr = nbr / i;
				i = 1;
			}
		}
	}
	printf("\n");
	return(0);
}