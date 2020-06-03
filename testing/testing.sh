# !/bin/bash
# Team Git That Money
# CS50 Project


echo "Make the file"
make clean
make 

echo "Check if tests made"
if ( ! [ -x fuzzytesting ] )
then
	echo 1>&2 "Fuzzytesting not made"
	exit 1
fi

if ( ! [ -x ./randboard ] )
then
	echo 1>&2 "Randboard not made"
	exit 2
fi


echo "Check with wrong arguments"

../sudoku/sudoku
../sudoku/sudoku arg1 arg2
../sudoku/sudoku invalidChoice



echo "Check with valid arguments"
../sudoku/sudoku create
../sudoku/sudoku solve < ../solver/testBoard


echo "Check solve with many invalid inputs"
./randboard 50 8 | ../sudoku/sudoku solve


echo "Check solve with many valid inputs"
./fuzzytesting 50 | ../sudoku/sudoku solve






























