cmake_minimum_required(VERSION 3.10)
project(lua-test)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -static-libgcc -static-libstdc++")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DLUA_IMPL")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DLUA_IMPL")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DLUA_IMPL")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DLUA_IMPL")
include_directories(
  "/home/jsnadeau/Documents/repos/lua-test/Libraries/minilua"
)
set(SOURCE_FILES
  "/home/jsnadeau/Documents/repos/lua-test/Sources/main.c"
)
add_executable(lua-test ${SOURCE_FILES})
target_link_libraries(lua-test
)
