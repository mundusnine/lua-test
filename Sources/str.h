#pragma once

#include <stdio.h>
#include <string.h>

#pragma GCC diagnostic push 
#pragma GCC diagnostic ignored "-Wsizeof-array-argument"


void set_str(char dest[], char src[]){
	if(512 > sizeof(src)){
		memcpy(dest,src,sizeof(src));
	}
	else {
		printf("Size of the src string is too big for destination, resize the destination string"); 
	}
}








#pragma GCC diagnostic pop