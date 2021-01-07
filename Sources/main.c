#include <stdio.h>
#include <assert.h>
#include <time.h>

#include "api/api.h"
#include "teal.h"
#include "str.h"
#include "lua.h"

int main(int argc, char** argv) {
	lua_State *L = luaL_newstate();
	double time_spent = 0.0;
	luaL_openlibs(L);
	api_load_libs(L);

	teal_init(L);

	

	teal_process(L);

	clock_t begin = clock();
	
	teal_gen_lua(L);

	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("Time elpased is %f seconds", time_spent);
	
	teal_shutdown();
	lua_close(L);
	return 0;
}



