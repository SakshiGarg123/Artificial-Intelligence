https://www.cs.princeton.edu/courses/archive/spr10/cos226/assignments/8puzzle.html

http://www.dsi.unive.it/~atorsell/AI/03-heuristicsearch.pdf (Page 6)

8 Puzzle Problem
Write a program to solve the 8-puzzle problem using the A* search algorithm.

The problem. The 8-puzzle problem is a puzzle invented and popularized by Noyes Palmer Chapman in the 1870s. It is played on a 3-by-3 grid with 8 square blocks labeled 1 through 8 and a blank square. Your goal is to rearrange the blocks so that they are in order. You are permitted to slide blocks horizontally or vertically into the blank square. The following shows a sequence of legal moves from an initial board position (left) to the goal position (right).
    1  3        1     3        1  2  3        1  2  3        1  2  3
 4  2  5   =>   4  2  5   =>   4     5   =>   4  5      =>   4  5  6
 7  8  6        7  8  6        7  8  6        7  8  6        7  8 

 initial                                                      goal

Write a program that reads the initial board from an input file and prints on standard output a sequence of board positions that solves the puzzle in the fewest number of moves. Also print out the total number of moves and the total number of states ever enqueued.
The input will consist of the 8 by 8 initial board position. The input format uses 0 to represent the blank square.


Implement the following search algorithms for solving 8-puzzle:
Depth-first search.
Breadth-first search.
Greedy best-first search.
A* search.

For each of these algorithms, feel free to set a reasonable execution limit -- e.g., quit after some maximum number of nodes have been expanded. Take care to avoid getting stuck in infinite loops. For greedy best-first and A* search, use the two heuristics defined in this lecture:
h1 = number of misplaced tiles
h2 = sum of Manhattan distances between every tile's current and desired position

For each problem instance in this file and each search algorithm, report the following:
Number of steps (path cost) of the solution (if found).
Number of nodes expanded.
Maximum tree depth searched.
Maximum size of the fringe.

Next, generate 50 random 8-puzzle instances by starting from the goal state and shuffling for some sufficiently large number of steps. Solve each of these instances using the A* algorithm with heuristics h1 and h2 and report the averages of the four above performance statistics.
