## Nqueen 
## Algorithm

Hill Climbing


## Input-N 

(Size of the board)

## Ouput-N 

(Configuration of the board)

Assignment 4

4-Queens
write a program that prints all solutions of the N-queens problem for a given positive value of N. In the N-queens problem, the goal is to place N queens on an N-by-N chess board so that no two queens are on the same row, column, or diagonal. 
Example Output for 4-queens Problem 
(0,1) (1,3) (2,0) (3,2)
(0,2) (1,0) (2,3) (3,1)


N-queens
Implement Hill-climbing search to generate legal n-queens configurations. Start by placing a queen in a random location in each column, and at each step, try to move a queen within its column to reduce the number of conflicts. Experiment with a few simple ways of selecting the successor state and escaping local minima until you get an algorithm that works reasonably well. Report on your implementation choices and their relative performance.

Start with N = 4 and keep increasing N as far as you can (the values don't have to be consecutive). For each N you tried, report the average number of uphill moves and restarts needed to successfully generate an N-queens instance. Empirically, how does the complexity of your implementation scale as a function of N? Use a scatter plot to show answer for this question.

