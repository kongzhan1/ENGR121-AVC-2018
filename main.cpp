#include <stdio.h>
#include "E101.h"

double get_turn();


int main()
{
    //test - just makes it go forward for 2 secs
	init();
	
	for(int i = 0;i<10;i++)
	{
		sleep1(1,0);
		printf("Test %d: %f",i,get_turn());
	}
	
    printf();
	return 0;
}

/**
 * This will return a value between -1 and 1 of where the white line is. 0 is the exact centre. 1 is all the way to right, -1 is all the way to left
 * */
double get_turn()
{
	//get picture
    take_picture();
    
    //determine minimum and maximum shades of white in the picture
    int min_white = 255;
    int max_white = 0;
    
    int y = 120;
    for(int x=0;x<320;x++)
    {
		int white = get_pixel(y,x,3);
		if(white>max_white)
		{
			max_white = white;
		}
		if(white<min_white)
		{
			min_white = white;
		}
	}
	//threshold
	int white_threshold = min_white+(max_white-min_white)/2
    
    int white_pixels = 0;
    double white_location = 0;
    
    for(int x=0;x<320;x++)
    {
		double percent_location = (x-120)/120;//-1 = completely to left, 1 = completely to right, 0 = centre
		int white = get_pixel(y,x,3);
		//detect white
		if(white>threshold)
		{
			white_pixels++;
			white_location += percent_location;
		}
	}
	
	//average location of the white pixels
	double average_white_location = white_location/white_pixels;
	return average_white_location;
}
