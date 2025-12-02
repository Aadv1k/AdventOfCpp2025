CFLAGS = -Wall -Werror -Wextra -g -ggdb
CC = g++

SRC_FILES = $(wildcard ./solutions/*.cpp)
SO_FILES := $(patsubst ./solutions/%.cpp,./bin/shared/%.so,$(SRC_FILES))

./bin/main: $(SO_FILES) ./main.cpp
	mkdir -p $(@D)
	$(CC) -o $@ ./main.cpp


./bin/shared/%.so: ./solutions/%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $^ 
