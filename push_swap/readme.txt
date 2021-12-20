Requirements:

- executable file name "push_swap"
- Makefile
- no globals
- allowed functions:
	- write
	- read
	- malloc
	- free
	- exit

Rules:

- 2 Stacks a and b
- a contains random number of positive or negative numbers
- b is empty
- sort ascending in a

Sorting operations:

- sa:	swap top two of a / nothing if only one element
- sb:	swap top two of b / nothing if only one element
- ss:	sa and sb at same time
- pa:	push top of b to a / nothing if b is empty
- pb:	push top of a to b / nothing if b is empty
- ra:	move up all elements of a by 1 / top becomes last
- rb:	move up all elements of b by 1 / top becomes last
- rr:	ra and rb at same time
- rra:	move down all elements of a by 1 / last becomes top
- rrb:	move down all elements of b by 1 / last becomes top
- rrr:	rra and rrb at same time

Find the best solution for:


Evals:
Errormanagement: right Input numeric, doubles, already sorted, to big (bigger or smaller Int)

Inputmenge:
3 -> 3
5 -> 12
100 -> 700 -1 for every 200 more
500 -> 5500 -1 for every 1500 more