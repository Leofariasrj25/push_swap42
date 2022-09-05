#!/bin/bash

function get_leaks()
{
	printf "input: $1 \t\t"
	valgrind --log-file=".valgrind.txt" ./push_swap ${@:2} > /dev/null 2>&1 
	LEAK=$(grep "in use at exit*" .valgrind.txt | awk -F"in use at exit" '{print $2}');
	printf "$LEAK\n"
	rm ".valgrind.txt"
}

function test_run()
{
	get_leaks "no-input"
	get_leaks "ordered" "1 2 3"
	get_leaks "repeated" "1 1 1"
	get_leaks "int min, int max" "-2147483648 2147483647"
	get_leaks "out of int bounds" "-2147483649 2147483647"
	get_leaks "out of int bounds 2" "-2147483648 2147483648"
	get_leaks "1 numbers" 1
	get_leaks "2 numbers" $(shuf -i 1-2)
	get_leaks "3 numbers" $(shuf -i 1-3)
	get_leaks "5 numbers" $(shuf -i 1-5)
	get_leaks "42 numbers" $(shuf -i 1-42)
	get_leaks "100 numbers" $(shuf -i 1-100)
	get_leaks "500 numbers" $(shuf -i 1-500)
	get_leaks "1000 numbers" $(shuf -i 1-1000)
	printf "\n\n ===[BAD INPUT]=== \n\n"
	get_leaks "bad input0" "3 one 2"
	get_leaks "bad input1" 1 2 3 ---4
	get_leaks "bad input2"
	get_leaks "bad input3" three two one
	get_leaks "bad input4" -1 4 -3 ++2
	get_leaks "bad input5" -1 4 one --3
	get_leaks "bad input6" -1 4 2 -3b
	get_leaks "bad input7" "1 2" "3b"
	get_leaks "bad input8" a e d c b
	get_leaks "bad input9" "\0"
	get_leaks "bad input10" "\0 + 1"
}

test_run
