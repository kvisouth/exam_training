#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

// int main (void)
// {
//     unsigned char oct = 'A'; //It's octet is 101 (man ascii)
//     print_bits(oct);
// }