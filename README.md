# DSA Practice

Data structures and algorithms practice programs in C and Python, written while studying for my B.Tech in Computer Science.

## C programs (`c/`)

| File | Topic |
|---|---|
| `singly_linked_list.c` | Singly linked list: insert and delete at the beginning, end, and any position, plus display |
| `circular_linked_list.c` | Circular linked list with a menu: create, insert, delete, display |
| `stack.c` | Stack built on a linked list: push, pop, peek, display |
| `bubble_sort.c` | Bubble sort |
| `quick_sort.c` | Quick sort (recursive, last element as pivot) |
| `binary_search.c` | Binary search, iterative and recursive |
| `palindrome.c` | Checks whether a number is a palindrome by comparing its digits |

### Compile and run

```
gcc singly_linked_list.c -o singly_linked_list
./singly_linked_list
```

On Windows with MinGW, run `singly_linked_list.exe` instead of `./singly_linked_list`.

`circular_linked_list.c` is menu-driven: choose an option, enter the data when asked, and pick 9 to exit.

### Example outputs

`singly_linked_list.c`
```
List is empty.
10 -> 20 -> 30 -> NULL
List is empty.
5 -> NULL
```

`stack.c`
```
30 20 10
top is 30
20 10
```

`bubble_sort.c`
```
Sorted array: 1 2 4 5 8
```

`quick_sort.c`
```
Sorted array: 1 2 3 4 5 8
```

`binary_search.c` (searching for 45 in a sorted array)
```
iterative: key found at index: 3
recursive: key found at index: 3
```

## Python programs (`python/`)

| File | Topic |
|---|---|
| `subarray_sum.py` | Finds a continuous part of a list that adds up to a target, using a sliding window. Works for non-negative numbers |
| `linear_search.py` | Linear search using a `for ... else` loop |

```
python subarray_sum.py
```

Example: the numbers 1, 2, 3, 4, 5 with target 9 give `[2, 3, 4]`.

## Complexity summary

| Algorithm | Time |
|---|---|
| Bubble sort | O(n^2) |
| Quick sort | O(n log n) average, O(n^2) worst case |
| Binary search | O(log n), needs a sorted array |
| Linear search | O(n) |
| Sliding window subarray sum | O(n) |
| Linked list insert/delete at the head | O(1) |
| Stack push/pop | O(1) |

## Notes

Practice code for learning, so input checking is minimal. In `circular_linked_list.c`, `main` is written as `void main`, which some compilers warn about; standard C uses `int main`.

## Author

Tanishq Gyaneshwar Dhoke ([@Tainydaug](https://github.com/Tainydaug))
