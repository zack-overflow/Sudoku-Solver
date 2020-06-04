# CS50 Sudoku
## Team Git-That-Money

* Use `make test` to run `testing.sh`
* Output is in `testing.out`

### Error Check:
#### Check arguments
Too few arguments
```
./sudoku
```


Too many arguments
```
./sudoku arg1 arg2
```


Argument is not a valid choice
```
./sudoku invalidChoice
```

### Bad Input for Board
50 groups of 81 random numbers are generated to test `solver`'s response to incorrect/ unsolvable sudoku boards and hit possible edge cases
```
./sudoku solve < ../sudoku/./randboard 50 8
```


### Check each valid argument
Check create
```
./sudoku create
```

Check solve, using sudoku boards from `testboard`
```
./sudoku solve < ../solver/testboard
```

### Unit testing
Unit testing is performed for each helper function through macros.

### Fuzzytesting
Large numbers of boards are generated and fed to `solver` to perform fuzzytesting
```
../sudoku/sudoku create | ../sudoku/sudoku solve
```











