#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}
int	put_nbr_base(uintptr_t n, unsigned int base, char casse, char pref)
{
	int size;
	
	size = 0;
	if (pref == 'x' && ++size && size++)
		ft_putstr_fd("0x", 1);
	if (n >= base)
		size +=	put_nbr_base(n / base, base, casse, 'z');	
	if (n % base <= 9)	
		ft_putchar_fd(n % base + 48, 1);
	else if (casse == 'u')
		ft_putchar_fd(n % base + 55, 1);
	else 
		ft_putchar_fd(n % base + 87, 1);
	return (++size);	
}

int main()
{
	int res = put_nbr_base((uintptr_t)8475, 16, 'u', 'o');
	printf("\n%d\n", res);
}