![](img/push_swap.png)

# Push_swap


#### Because Swap_push isn’t as natural



## About ##

- Push_swap is a sorting algorithm project at school 42.
- We start with two stacks called A and B.
- A is filled with some random integers (without duplicates) and B is empty.
- We can perform a limited set of instructions on these stacks and the goal is to sort all these integers using the lowest possible number of actions.
- The limited set of instructions are:

| Operation | Description |
| ------------ | ------------ |
| `sa` | swap A - swap the first 2 elements at the top of stack A |
| `sb` | swap B - swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | push A - take the first element at the top of b and put it at the top of A |
| `pb` | push B - take the first element at the top of a and put it at the top of B |
| `ra` | rotate A - shift up all elements of stack A by 1. The first element becomes the last one |
| `rb` | rotate B - shift up all elements of stack B by 1. The first element becomes the last one |
| `rr` | `ra` and `rb` at the same time |
| `rra` | reverse rotate A - shift down all elements of stack A by 1. The last element becomes the first one |
| `rrb` | reverse rotate B - shift down all elements of stack B by 1. The last element becomes the first one |
| `rrr` | `rra` and `rrb` at the same time |


## Links ##

- [LeoFu9487 Tester](https://github.com/LeoFu9487/push_swap_tester.git) (thank you for this awesome tester!)

- [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer) (you will need python3 + rust)

- [Radix Sort](https://www.youtube.com/watch?v=nu4gDuFabIM) (I used this algorithm in my project)

## Functions ##
Only the following functions are allowed to be used in this project:
- write
- read
- malloc
- free
- exit
- [My own Libft library](https://github.com/DeRuina/Libft.git)

## Starting ##

```bash
# Clone this project
$ git clone https://github.com/DeRuina/push_swap.git

# Access
$ cd push_swap

# Compile the program
$ make

# Run the project
$ ./push_swap 5 8 7 2

```

## Testing ##


LeoFu9487 tester:
To see if you pass the parsing test (ERROR_TEST), identity test, and small stack test (size 3 and 5), run
```bash
bash basic_test.sh
```
If you want to see the test cases, check trace_basic

After that, you can do medium and big stack test with this command
```bash
bash loop.sh <stack size> <loop times>
```
For example, this is the result of the following command
```bash
bash loop.sh 100 10
```

![Visualizer](img/push_swap.gif)

## Author

- [@DeRuina](https://github.com/DeRuina)
