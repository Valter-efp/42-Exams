#include <unistd.h>

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		int flag = 0;

			while (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\0')
				i++;
			while (argv[1][i])
			{
				if (argv[1][i] != ' '&& argv[1][i] != '\t' && argv[1][i] != '\0')
				{
					if (flag)
						write(1, "   ", 3);
					flag = 0;
					write(1, &argv[1][i], 1);
				}
				else
					flag = 1;
				i++;;
			}
	}
	write(1, "\n", 1);
	return(0);
}