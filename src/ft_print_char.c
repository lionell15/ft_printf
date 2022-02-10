#include "../ft_printf.h"

int ft_print_char(const char c, int count)
{
	write(1, &c, 1);
	count += 1;
	return (count);
}