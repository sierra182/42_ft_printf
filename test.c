#include <stdio.h>
#include <unistd.h>

int	put_nbr_base(unsigned int n, unsigned int base)
{
	int size;
	
	size = 0;
	if (n >= base)
		size +=	put_nbr_base(n / base, base);	
	if (n <= 9)
		write(1, &((char)(n % base + 48)), 1);
	else
		write(1, &((char)(n % base + 55)), 1);
	return (size);	
}

int main()
{
	int res = put_nbr_base(42, 10);
	printf("\n%d\n", res);
}