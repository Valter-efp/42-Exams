char ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return(c);
}

int get_digit(char c, int digits_in_base)
{
	int digit;
	
	if (c >= '0' && c <= '9')
		digit = c - '0';
	else if (c >= 'a' && c <= 'f')
		digit = c - 'a' + 10;
	else
		return (-1);

	if (digit >= digits_in_base)
		return (-1);
	return (digit);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int res = 0;
	int sign = 1;
	int digit;
	int i = 0;

	if (str[i] == '\0' || str_base < 2 || str_base > 16)
		return(0);

	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}

	while (str[i] != '\0')
	{
		digit = get_digit(ft_tolower(str[i]), str_base);
		if (digit == -1)
			break;
		res = res * str_base + digit;
		i++;
	}
	return(res * sign);
}

/* Test code */
// #include <stdio.h>
// int main(void)
// {
// 	char *str1 = "1a";
// 	int base1 = 16;
// 	printf("String: %s, Base: %d -> Result: %d\n",str1, base1, ft_atoi_base(str1, base1));

// 	char *str2 = "101";
// 	int base2 = 2;
// 	printf("String: %s, Base: %d -> Result: %d\n", str2, base2, ft_atoi_base(str2, base2));

// 	char *str3 = "-7f";
// 	int base3 = 16;
// 	printf("String: %s, Base: %d -> Result: %d\n", str3, base3, ft_atoi_base(str3, base3));

// 	char *str4 = "123";
// 	int base4 = 10;
// 	printf("String: %s, Base: %d -> Result: %d\n", str4, base4, ft_atoi_base(str4, base4));

// 	char *str5 = "7";
// 	int base5 = 8;
// 	printf("String: %s, Base: %d -> Result: %d\n", str5, base5, ft_atoi_base(str5, base5));

// 	char *str6 = "z";
// 	int base6 = 36; // Invalid base, should return 0
// 	printf("String: %s, Base: %d -> Result: %d\n", str6, base6, ft_atoi_base(str6, base6));

// 	char *str7 = "10";
// 	int base7 = 8;
// 	printf("String: %s, Base: %d -> Result: %d\n", str7, base7, ft_atoi_base(str7, base7));

// 	return(0);
// }
