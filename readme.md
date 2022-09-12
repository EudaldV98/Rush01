# RUSH 01

Solve the calssic skyscraper puzzle. The way of solving it is quite similar to a sudoku.

## Keywords

Multiple keywords can be used while explaining the project and we can be glad to hear applicants use them:

1. Backtracking

Backtracking is an algorithmic technique for solving problems recursively by trying to build a solution incrementally, one piece at a time, removing those solutions that fail to satisfy the constraints of the problem at any point in time (by time, here, is referred to the time elapsed till reaching any level of the search tree).  Backtracking can also be said as an improvement to the brute force approach. Go check on the internet for a more precise description.

2. Clues (1 and N)

Can be used to improve the brute force approach and potentially reduce the time taken by a backtracking algorithm. The goal is to identify the 2 particular cases where the solution is no other than x. Imagine a board of size N, clue 1 refers to the rule 1. So 1 skyscraper is visible, so the solution can only be N. On the other hand N clue refers to the rule of N.  Here N skyscrapers should be visible, so the row (or column) will be filled with skyscrapers from 1 to N starting right after the rule.

3. High skyscraper

Check the high skyscrapers already placed and clues to place the next high skyscraper of the row/col.

4. Unique sequences

Place the already known sequences. If a N skyscraper is already placed in a row where there's the rule N -1 we already know that N - 1 can be placed just after N.

5. No repetition in row or col

When few rows and cols are filled we can deduce where to place them with the info we have, for rejection/ by default.

6. Highest located far opposite clue 2

Similar to "Unique sequences" but in the case of rules closer to the minimum, where by default we can know that the next higher skyscraper can be placed in the opposite side of the board. If we have N placed nad the rule in the opposite side of the board is 2, we know that N - 1 can be placed in the other side of the board right afer the clue.

7. Lowest skyscraper located adjacent to clue 2

Whenever a 1 - floor skyscraper is placed adjacent to clue 2, the one adjacent to it has to be N (the highest possible).


