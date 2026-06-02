# Elevator Simulator
## Getting Started
```=shell
make all

Elevator Start Running!! 
Elevator1:
+ Current floor is 1
Elevator2:
+ Current floor is 1
```
### User Interface
1. Choose Elevator: 
    + Choose the target elevator number, 1 or 2.
2. Choose Floor: 
    + Assign the desired floor, ranging from 1 to 10.

+ Example
```=shell
---------------
// 1. Move Elevator 1 to 3rd floor.

Choose Elevator: 1
Choose Floor: 3

Elevator1:
+ Before move: Current floor is 1
... Moving to 2 ...
... Moving to 3 ...
+ After move: Current floor is 3
Elevator2:
+ Current floor is 1
---------------
// 2. Move Elevator 2 to 5th floor first, then go downward to 2nd floor.

Choose Elevator: 2
Choose Floor: 5

Elevator1:
+ Current floor is 3

Elevator2:
+ Before move: Current floor is 1
... Moving to 2 ...
... Moving to 3 ...
... Moving to 4 ...
... Moving to 5 ...
+ After move: Current floor is 5
---------------
Choose Elevator: 2
Choose Floor: 2

Elevator1:
+ Current floor is 3

Elevator2:
+ Before move: Current floor is 5
... Moving to 4 ...
... Moving to 3 ...
... Moving to 2 ...
+ After move: Current floor is 2
---------------
```

## Unit Test
```=shell
make test
```
+ Uses google test framework
+ It tests whether the elevator moves `upward` and `downward` correctly.