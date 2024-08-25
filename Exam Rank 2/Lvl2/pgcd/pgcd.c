#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);

		if (a > 0 && b > 0)
		{
			/* when they are  */
			while(a != b)
			{
				if (a > b)
					a = a - b;
				else
					b = b - a;
			}
			printf("%d", a);
		}
	}
	printf("\n");
	return(0);
}