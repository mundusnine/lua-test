#pragma once

#include "minilua.h"
#include <stdlib.h>
#include <assert.h>

#define MAX_CHARS 512
extern char teal_inputFilename[];
extern char teal_outputFilename[];

void teal_init(lua_State* L);
void teal_init_env(lua_State* L);
void teal_process(lua_State* L);
void teal_gen_lua(lua_State* L);
void teal_shutdown();