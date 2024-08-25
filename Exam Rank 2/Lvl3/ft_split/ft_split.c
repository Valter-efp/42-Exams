#include <stdlib.h>
#include <stdio.h>

int ft_wc(char *str)
{
	int i = 0;
	int wc = 0;

	while(str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if(str[i])
			wc++;
		while(str[i] && (str[i] != ' '&& str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return(wc);
}

char *ft_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while(i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] ='\0';
	return(dest);
}

char    **ft_split(char *str)
{
	int i = 0;
	int ws = 0;
	int j = 0;
	int wc = ft_wc(str);

	char **splited = malloc(sizeof(splited) * (wc + 1));

	while(str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		ws = i;
		while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))	
			i++;
		if(i > ws)
		{
			splited[j] = malloc(sizeof(splited) * ((i-ws) + 1));
			ft_strncpy(splited[j++], &str[ws], i - ws);
		}
	}
	splited[j] = NULL;
	return(splited);
}
