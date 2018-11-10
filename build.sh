#!/bin/sh

# ---------------------------------------------------
#
# 	A simple shell script for running the proposed
# 	exercise without too much complication. Should
# 	work on any Unix system with the GLFW properly
# 	compilled and installed. Any doubts on the usage
# 	of the program can be directly addressed with the
# 	code authors, as stated below:
#
# Henrique Cunha 	/ RA 759023
# Rodrigo Godinho	/ RA 759020
# Jonathan Silva	/ RA 7590
# Bruno Mengaldo	/ RA 7590
#
# ---------------------------------------------------

# Creating build folders
if [ ! -d "build" ]; then
	mkdir build
	mkdir build/output
fi
if [ ! -d "build/output" ]; then
	mkdir build/output
fi

# Builds the application with the GLFW library
clear
echo "Compiling the main file..."
g++ -std=c++11 -c -g main.cpp -o build/output/main.o
g++ build/output/main.o -o build/main.exec -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor

# Checks for run parameter
if [ $1 = "run" ]; then
	clear
	echo "Compiled. Running...\n"
	build/main.exec # runs the builded executable
fi

echo ""