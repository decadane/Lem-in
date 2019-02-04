#! /bin/bash

#tests funclions

function test_errors
{
	RES=`echo -e $1 | ./lem-in`
	echo -e "$RES\n"
}


#tests tests
test_errors "-3"
test_errors "aa"
test_errors "0"
test_errors "3000000000"
test_errors "4\n##start\n1 0 0\n##start\n2 1 1\n1-2"
test_errors "4\n##end\n1 0 0\n##end\n2 1 1\n1-2"
test_errors "4\n##start\n1 0 0\n\n##end\n2 1 1\n1-2"
test_errors "4\n##start\n1 0 0\n##end\n1 1 1\n1-2"
test_errors "4\n##start\n1 0 0\n##end\n2 1 1\n0-2"
test_errors "4\n##start\n1 0 0\n##end\n2 1 1\n12"
test_errors "4\n##start\n1 0 0\n##end\n2 1 1\n1-2\n1-2"
