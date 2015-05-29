# TowerOfHanoiSolver
There are K pegs. Each peg can hold discs in decreasing order of radius when looked from from bottom to top of the peg. There are N disc which hav radius to 1 to N. Given the initial configuration of the pegs and the final of the pegs, output the moves required to transform from the initial to the final configuration.

This program takes 3 string inputs.

The first line of input will consist of N and K, 3 <= K.

The second line contains N integers. Each integer is in the range of 1 to K where i-th integer denotes the peg to which disc radius i is presen in the initial configuration.

The third line denotes the final configuaration in the format similar to the inital one.

Example:

6 4

4 2 4 3 1 1

1 1 1 1 1 1


NOTE: this program is not so "smart," so it takes time to solve the game. The time to get to a solution increases exponentially according to needed moves to solve which means with a game which require a few moves, the program only needs a few seconds to solve, but with a more complicated game, it might takes minutes or even hours. This one works best for games that require less than 10 moves
