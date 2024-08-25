#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		unsigned char seen[256] = {0};
		int i = 0;
		int j = 0;

		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[2][j] == argv[1][i])
				{
					if(!seen[(unsigned char)argv[1][i]])
					{
						write(1, &argv[1][i], 1);
						seen[(unsigned char)argv[1][i]] = 1;
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}