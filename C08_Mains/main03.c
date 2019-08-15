#include "ft_point.h"
#include <stdio.h>

void	set_point(s_point *point)
{
	point->x = 42;
	point->y = 21;
}

int main (void)
{
	s_point point;

	set_point(&point);
	printf("%d\n%d\n", point.x, point.y);
	return (0);
}
