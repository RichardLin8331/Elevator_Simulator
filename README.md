# Elevator Simulator
## Getting Started
```=shell
make all

Elevator Start Running!! 
Elevator 1 is at floor 1
Elevator 2 is at floor 1
```
### User Interface
+ Input (Elevator, Current, Desired): 
    + Commands consist of three integers separated by spaces.
    + The system first moves the designated elevator to the "Current" floor to pick up the user, then proceeds to the "Desired" floor.

+ Example
```=shell
---------------
// 1. Move Elevator 1 to 9th floor first, then go to the 2nd floor.

Input (Elevator, Current, Desired): 
1 9 2
Elevator 1 is at floor 2
Elevator 2 is at floor 1
---------------

Input (Elevator, Current, Desired): 
Elevator 1 is at floor 3
Elevator 2 is at floor 1
---------------

// 2. During Elevator 1's movement, assign Elevator 2.
Input (Elevator, Current, Desired): 
2 5 8
Elevator 1 is at floor 4
Elevator 2 is at floor 1
---------------

Input (Elevator, Current, Desired): 

Elevator 1 is at floor 4
Elevator 2 is at floor 2
---------------

Input (Elevator, Current, Desired): 
Elevator 1 is at floor 5
Elevator 2 is at floor 2
---------------

Input (Elevator, Current, Desired): 
Elevator 1 is at floor 5
Elevator 2 is at floor 3
---------------

Input (Elevator, Current, Desired): 
Elevator 1 is at floor 6
Elevator 2 is at floor 3
---------------

Input (Elevator, Current, Desired): 
Elevator 1 is at floor 6
Elevator 2 is at floor 4
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 7
Elevator 2  is at floor 4
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 7
Elevator 2  is at floor 5
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 8
Elevator 2  is at floor 5
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 8
Elevator 2  is at floor 6
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 9
Elevator 2  is at floor 6
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 9
Elevator 2  is at floor 7
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 8
Elevator 2  is at floor 7
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 8
Elevator 2  is at floor 8
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 7
Elevator 2  is at floor 8
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 6
Elevator 2  is at floor 8
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 5
Elevator 2  is at floor 8
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 4
Elevator 2  is at floor 8
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 3
Elevator 2  is at floor 8
---------------

Input (Elevator, Current, Desired): 
Elevator 1  is at floor 2
Elevator 2  is at floor 8
---------------

Input (Elevator, Current, Desired):
```

## Unit Test
```=shell
make test
```
+ Uses google test framework
+ It tests whether the elevator moves `upward` and `downward` correctly.