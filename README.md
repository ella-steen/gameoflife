# cps222-2023-p1-patta-steen
CPS222 Game of Life Project

This program initializes a board, in which can live 'organisms' (represented by *). An organism is generated originally by user input, which specifies how many, their locations, and how many generations of organisms the game should cycle through. An organism will live if it has 2 or 3 neighbors, but will die if it has fewer than 2 or greater than 3 neighbors. If there is an empty cell with exactly three neighbors, a new organism will 'gestate' and be born there.

Notes on the program:

When testing, we used input files that were slightly altered from the examples given to account for the way our program takes input for initial organism locations. Instead of taking a long string of numbers for locations, it takes each row and column after a return. (Credit to Josh Peters for helping us with this idea.)
Pair programming was utilized throughout the creation of this program, particularly in the final testing stages. 

Credit for assistance given to: 

https://www.geeksforgeeks.org/arrays-in-c-cpp/

https://www.geeksforgeeks.org/iterate-over-characters-of-a-string-in-c/

https://www.techiedelight.com/print-contents-array-cpp/

https://www.digitalocean.com/community/tutorials/two-dimensional-array-in-c-plus-plus 

https://www.quora.com/How-can-I-get-two-integer-inputs-separated-by-a-space-in-C++

https://stackoverflow.com/questions/19154302/git-push-to-specific-branch

https://linuxhint.com/how-to-copy-an-array-in-cpp/

https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm

https://stackoverflow.com/questions/33422793/if-statement-with-logical-or