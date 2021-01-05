
#include <stdio.h>
#include "minilua.h"
#include<string.h>
#include <assert.h>
// #include "api/api.h

int main(int argc, char** argv) {
	lua_State *L = luaL_newstate();
	if(L == NULL)
		return -1;
	luaL_openlibs(L);
	// api_load_libs(L);


	printf("Lua return %i\n",luaL_loadfile(L,"tlexec.lua"));
	lua_pcall(L,0,-1,0);
	lua_getglobal(L,"tl");
	printf("Type is: %s\n",lua_typename(L,lua_type(L,-1)));

	assert(lua_istable(L,-1));
	lua_pushstring(L,"init_env");
	lua_gettable(L,-2);

	if(lua_isfunction(L,-1))
	{

		lua_pushboolean(L,0);
		lua_pushboolean(L,0);
		int numArgs = 2;
		int numRet = 1;
		lua_pcall(L,numArgs,numRet,0);
		void* test = lua_touserdata(L,-1);

		lua_pushstring(L,"process");
		lua_gettable(L,-2);
		lua_pushstring(L,"tl.tl");
		lua_pushlightuserdata(L,test);
		lua_pushnil(L);
		lua_pushnil(L);

		numArgs = 4;
		numRet = 2;
		lua_pcall(L,numArgs,numRet,0);

		if(lua_istable(L,-2)){
			test = lua_touserdata(L,-2);
			
			printf("It worked\n");
		}
		else {
			printf("%s",lua_tostring(L,-1));
		}

	}
	else {
		printf("What up man !");
	}
	lua_close(L);
	return 0;
}
