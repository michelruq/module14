cmake_minimum_required(VERSION 3.5)

project (Module14)

set(SRC_LIST 
      main.cpp
	  trie.cpp)
	  
add_executable(trie ${SRC_LIST})	

set(CXX_FLAGS "${CXX_FLAGS} -std=c++11 -Wall")  