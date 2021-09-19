## INTRODUCTION 
Dynamic Programming problems range a lot 

We need to visualize all these algorithms, When you describe a process and translate to code

### Fib Memoization 
Write a function that takes in a number as an argument the function should return the n-th number of the sequence

Step 1: Classic Fibonacci implementation using recursion
```C
int fib(int n){
    if(n <=2) return 1;
    return fib(n-1) + fib(n-2);
} 
```
Time Complexity = O(2^N)
Space Complexity = O(N)

fib(50) = 2^50 = 1.12e+15 // Very very very large
#### Overlapping Sub Problems
Look for patterns
- Duplicate sub trees
- We know the evalutation doesn't change for subtrees

### Memoization 
It's like a memo or reminder, Stores duplicate sub problems, We can use hashmap
keys will arg to fn, value will be return value

```C
int fib(int n, memo){
    if(memo.exists(n)) return memo[n];
    if(n <=2) return 1;
    memo[n] = fib(n-1, memo) + fib(n-2,memo );
    return memo[n];
} 
```

### Grid Traveller Memoization 
Say that you are a traveler on a 2D grid. You begin in the top-left corner and your goal is to travel to the bottom-right corner. You may only move down or right 

In how many ways can you travel to the goal on a grid with dimensions m*n?

```C
    int grid_traveller(int m, int n){
        if(m==1 && m==1) return 1;
        if(m==0 || n==0) return 0;
        return grid_traveller(m-1,n) + grid_traveller(m, n-1);
    }
```

```C 
int grid_traveller(int m, int n, memo){
        if(memo(m,n).exist()) return memo[m,n];
        if(m==1 && m==1) return 1;
        if(m==0 || n==0) return 0;
        memo[m,n] = grid_traveller(m-1,n) + grid_traveller(m, n-1) 
        return memo[m,n];
    }
```

## Alvin's Memoization Recipe
1. Make it work 
    - Visualize the problem as a tree 
    - Implement the tree using recursion 
    - test it (Correct Answer) **Code that is slow and code that is wrong**
2. Make it efficient 
    - Add a memo object if applicable
    - Add a base case to return memo values (if in memo)
    - Store return values into the memo 

Correctness in the solution, and then efficiency in the solution  

### CanSum 
Write a function `canSum(tragetSum, numbers)` that takes in a targetsum and an array of numbers as arguments 
The function should return a boolean indicating whether or not it is possible to generate the targetSum using numbers from the array.

```C
bool canSum(int targetSum, int numbers[]){
    if(targetSum == 0) return true;
    for(int i=0; i<len(numbers); i++){
        int remainder = targetSum - i;
        if(canSum(remainder, numbers) == true){
            return true;
        }
    }
    return false;
}
```