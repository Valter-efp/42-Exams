#include <stdlib.h>

int ft_strlen(char *str)
{
	int len = 0;

	while(str[len])
		len++;
	return(len);
}

char    *ft_strdup(char *src)
{
	int i = 0;
	int len = ft_strlen(src);
	char *dup;

	dup = malloc(sizeof(char) * (len +1));
	while(src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *orginal = "Hello, this is a test string.";

// 	printf("Printing the original string : ");
// 	printf("%s", orginal);
// 	printf("\n");
// 	printf("Printing the duplicate string: ");
// 	printf("%s", ft_strdup(orginal));
// 	printf("\n");	
// }