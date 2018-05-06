#include <stdio.h>
#include "E101.h"

int main()
{
    //test - just makes it go forward for 2 secs
	init();
	
    set_motor(0,127);
    set_motor(1,127);
    
    sleep1(2,0);
    
    set_motor(0,0);
    set_motor(1,0);
    
	return 0;
}
