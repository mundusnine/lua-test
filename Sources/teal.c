#include "teal.h"

#define ENVNAME "g_env"
#define RESTABLE "g_result"
#define OUT "g_out"

char teal_inputFilename[MAX_CHARS] = "tl.tl";
char teal_outputFilename[MAX_CHARS] = "test.lua";
int numArgs = 0;
int numRet = 0;

void teal_init(lua_State* L){
	int hasFailed = luaL_loadfile(L,"tl.lua");
	if(!hasFailed){
		lua_pcall(L,0,-1,0);
	}
	else{
		printf("Failed to load teal, is tl.lua in the same path as executable ?");
	}
}

void teal_init_env(lua_State* L){

	lua_getglobal(L,ENVNAME);
	if(lua_type(L,-1) == LUA_TNIL){
		lua_getglobal(L,"tl");
		lua_pushstring(L,"init_env");
		lua_gettable(L,-2);

		if(lua_isfunction(L,-1))
		{
			lua_pushboolean(L,0);
			lua_pushboolean(L,0);
			numArgs = 2;
			numRet = 1;
			lua_pcall(L,numArgs,numRet,0);
			lua_setglobal(L,ENVNAME);
		}
	}
}

void teal_process(lua_State* L){
	teal_init_env(L);

	lua_getglobal(L,"tl");
	lua_pushstring(L,"process");
	lua_gettable(L,-2);
	lua_pushstring(L,teal_inputFilename);
	lua_getglobal(L,ENVNAME);
	lua_pushnil(L);
	lua_pushliteral(L,"{}");//@TODO:Modules we need to find a way to populate this later

	numArgs = 4;
	numRet = 2;
	lua_pcall(L,numArgs,numRet,0);
	if(lua_istable(L,-2)){
		lua_pop(L,1);
		lua_setglobal(L,RESTABLE);
	}
	else {//Show errors
		printf("%s",lua_tostring(L,-1));
	}
}

void teal_gen_lua(lua_State* L){

	lua_getglobal(L,"tl");
	lua_pushstring(L,"pretty_print_ast");
	lua_gettable(L,-2);
    lua_getglobal(L,RESTABLE);
    lua_pushstring(L,"ast");
    lua_gettable(L,-2);
	lua_remove(L,-2);//Remove RESTABLE
	numArgs = 1;
	numRet = 1;
	lua_pcall(L,numArgs,numRet,0);
	char* output = lua_tostring(L,-1);

	FILE* f = fopen(teal_outputFilename,"w+");
	fprintf(f,"%s\n",output);
	fclose(f);
}

void teal_shutdown(){
}