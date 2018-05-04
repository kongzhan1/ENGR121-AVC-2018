#include <stdio.h>
#include "E101.h"

int main()
{
	init();
	take_picture();
	char fn[5] = "test";
	save_picture(fn);

	return 0;
}
