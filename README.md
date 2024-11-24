# Final Project

## Project Goals
The goal of this project is to:
1.	familiarize students with **Arrays of Strings**: https://erinkeith.github.io/135/topics/arrays_strings
2.	provide students with continued practice using **everything else!** https://erinkeith.github.io/cs135
   
## Important Notes
1.	**Filename**: Save your program as `madlibs.c`

# Program
MADLIBS! This project is loosely based on the game of Madlibs (https://en.wikipedia.org/wiki/Mad_Libs).

## Behavior
The program should load a madlib from a file and get the appropriate input from the user. It should then display the madlib text with the user's input inserted into the correct locations. 

The input file should contain the text of the madlib on separate lines. The user input is indicated by a single capital letter on a separate line:  
A - Adjective  
N - Noun  
V - Verb  

There are two example files provided so you can understand the input format.

## Requirements
- **You may *NOT* use any libraries other than `stdio` and `stdbool`.**
   - Any string functions used must be written within the program.
   - You may re-use the functions you wrote in Project 6.
- There must be ***at least*** 5 functions, in addition to the main (my program had 8)
- Any arrays must be used in the conventional way.
   - Index values should start `0`
   - Index values should end at `size - 1`, unless it is a C-style string.
- Any collection of single values must be stored in a 1D array.

### Extra Credit
#### Extra Credit tasks will not be considered for grading unless all other requirements have been met.
Use Command Line Arguments to get the madlibs file name at program execution.

## Hints
- It will be easier if you're very careful about how things are stored.
   - C-style strings are 1D arrays which store language.
   - Other 1D arrays store a collection of single values.
   - Arrays of strings store a collection of strings.
- For my program, I put the process of separating language from single values into reading the file so that tasks like getting the user inputs were more straightforward.
  
## Example Program Execution
An example executable (program) is provided in this repository. You should be able to run it from your project folder after cloning the repository in a Linux environment.  
- If you encounter a “permission denied” error when attempting to run the executable, type  
```chmod u+x madlibExecutable```  
into the terminal and try running the executable again.
