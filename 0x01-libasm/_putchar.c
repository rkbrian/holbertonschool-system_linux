#include <unistd.h>
int main(void)
{
	int c = 'K';
	write(1, &c, 1);
	return (0);
}
