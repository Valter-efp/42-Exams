# include <stdio.h>
# include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);

			while (a != b)
			{
				if (a > b)
					a = a -b;
				else
					b = b - a;
			}
			printf("%d", a);
	}
	printf("\n");
	return(0);
}
