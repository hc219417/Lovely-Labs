#
#   @file: Makefile
# @author: Hannah Culver
#   @date: January 18, 2022
#  @brief: lab 1 (operator overloading)
#

CC = g++
CFLAGS = -Wall -std=c++11

a.out: MyTime.o MyTime.o
	$(CC) $(CFLAGS) MyTime.o MyTime.o

my_int.o: MyTime.cc MyTime.h
	$(CC) -c $(CFLAGS) MyTime.cc

main.o: MyTime_main.cc MyTime.h
	$(CC) -c $(CFLAGS) main.cc

clean:
	rm -r MyTime.o main.o a.out