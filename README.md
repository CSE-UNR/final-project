# Final Project

## Project Goals
The goal of this project is to:
1.	Familiarize students with **2D Arrays**
3.	Provide students with continued practice using **everything!**
   
## Important Notes
1.	**Filename**: Save your program as `batship.c`

# Program
Batship! (half of battleship)

## Background
This project is loosely based on the game of Battleship (https://en.wikipedia.org/wiki/Battleship_(game)). However, we will only be implementing half of the game.

## Behavior
- The first time the user starts the program, they should begin playing the Batship game.
- Game play consists of prompting a user for where they'd like to "fire" on the opposing player. If they've hit part of a ship, they will see an `X` in that spot. If it's a miss, they will see a `O`. All other spots will be blank until fired upon. 
   - Game play should continue until all parts of every ship have been "hit".
- After the game is done, the user should be shown their score and prompted to play again.

## Requirements
- **You may *NOT* use any libraries other than `stdio` and `stdbool`.**
- There must be ***at least*** 5 functions, in addition to the main (my program had 6)
- Any 2D arrays must be used in the conventional way
   - index values should start a 0 and end at size - 1 
- If the user's move has values outside of the acceptable range, they should be prompted to enter their move until the values are within range.

### Extra Credit
#### Extra Credit tasks will not be considered for grading unless all other requirements have been met.
Choose *one* option from the following: 
- The user may be prompted for a difficulty level. The higher the difficulty, the fewer the ships on the board. *HINT: this requires different files with different ship layouts.*
- After completing a game, the player's name and score is added to a file and an option to view scores is added to a menu.

## Hints
- use the ASCII table (https://www.asciitable.com/) to think of an easy way to transform the column letter into an index integer
- the spots the user guesses is different data than where the ships are located
   - so they should be stored separately

## Example Program Execution
An example executable is provided in this repository.
- You should be able to run it from your project folder in a Linux environment. 
- If you encounter a “permission denied” error when attempting to run the executable, type  
```chmod u+x batshipExecutable```  
into the terminal and try running the executable again.
