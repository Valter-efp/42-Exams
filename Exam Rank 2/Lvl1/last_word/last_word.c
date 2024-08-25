#include <unistd.h>

int main (int argc, char **argv)
{
	int len = 0;
	int lwe = 0;
	int lws = 0;

	if (argc == 2)
	{
		while(argv[1][len])
			len++;
		lwe = len - 1;
		while(lwe >= 0 && (argv[1][lwe] == ' ' || argv[1][lwe] == '\t'))
			lwe--;
		lws = lwe;
		while(lws >= 0 && (argv[1][lws] != ' ' && argv[1][lws] != '\t'))
			lws--;
		lws++;
			while(lws <= lwe )
		{
			write(1, &argv[1][lws], 1);
			lws++;
		}
	}
	write(1, "\n", 1);
	return(0);
}