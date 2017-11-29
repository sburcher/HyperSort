# Makefile for sort code for 32S(p,d) experiment with Hyperion
# Made 11/28/2017
# Sean Burcher
# Adapted from Makefile for his2root by Cory Thornsberry

##################################################################

CC=g++

CFLAGS = -fPIC -Wall -O3 -std=c++0x `root-config --cflags` -Iinclude 
LDLIBS = -lstdc++ `root-config --libs` 
LDFLAGS = `root-config --glibs`


# Directories
TOP_LEVEL = $(shell pwd)
INCLUDE_DIR = $(TOP_LEVEL)/include
SOURCE_DIR = $(TOP_LEVEL)/src
OBJ_DIR = $(TOP_LEVEL)/obj

INSTALL_DIR = ~/bin

# Executables
SORT = sort
SORT_SRC = $(SOURCE_DIR)/sort.cpp
SORT_OBJ = $(OBJ_DIR)/sort.o


#####################################################################

all: $(OBJ_DIR) $(SORT) 
#	Create all directories, make all objects, and link executable

#####################################################################

$(OBJ_DIR):
#	Make the object file directory
	@if [ ! -d $@ ]; then \
		echo "Making directory: "$@; \
		mkdir $@; \
	fi

#####################################################################

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
#	Compile C++ source files
	$(CC) -c $(CFLAGS) $< -o $@

#####################################################################

$(SORT): $(OBJECTS) $(SORT_OBJ)
	$(CC) $(LDFLAGS) $(OBJECTS) $(SORT_OBJ) -o $@ $(LDLIBS)


#####################################################################

install: $(SORT) 
#	Install tools into the install directory
	@echo "Installing tools to "$(INSTALL_DIR)
	@ln -s -f $(TOP_LEVEL)/$(SORT) $(INSTALL_DIR)/sort

#####################################################################

tidy: clean
	@rm -f $(SORT) 
	@rm -f $(INSTALL_DIR)/sort

clean:
	@rm -f $(OBJ_DIR)/*.o
