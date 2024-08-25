int		max(int *tab, unsigned int len)
{
	int i = 0;
	int res = tab[i];

	if (len == 0)
		return(0);

	while(i < len)
	{
		if (res < tab[i])
			res = tab[i];
		i++;
	}
	return(res);
}