#include "../ft_printf.h"

int ft_print_str(const char *str, int count)
{
	int 	index;

	index = 0;
	if (!str)
		str = "(null)"; 
	while (str[index])
	{
		count = ft_print_char(str[index], count);
		index++;
	}
	return (count);
}