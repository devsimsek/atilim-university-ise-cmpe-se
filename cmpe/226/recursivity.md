# Recursivity

## What is recursivity?

Recursivity refers to a function that calls itself directly or indirectly. A recursive function solves a problem by breaking it down into smaller instances of the same problem.

## Basic structure of a recursive function

A recursive function typically has two parts:

1. **Base case**: The condition that stops the recursion
2. **Recursive case**: The recursive call to solve a smaller instance of the problem

```cpp
void recursiveFunction(parameters) {
    // Base case
    if (stopping_condition) {
        // This line checks if we've reached the termination condition
        // When this condition is true, the function stops calling itself
        return something;
    }

    // Recursive case
    // This line calls the same function with different parameters
    // The parameters must be modified to eventually reach the base case
    recursiveFunction(modified_parameters);
}
```

## Classic examples of recursion

### Factorial calculation

```cpp
int factorial(int n) {
    // Base case
    if (n <= 1) {
        // If n is 0 or 1, factorial is 1 by definition
        // This is where the recursion stops
        return 1;
    }

    // Recursive case
    // This multiplies n by the factorial of (n-1)
    // Each recursive call decreases n by 1, eventually reaching the base case
    return n * factorial(n - 1);
}
```

Time Complexity: O(n) - making n recursive calls
Space Complexity: O(n) - n stack frames on the call stack

### Fibonacci sequence

```cpp
int fibonacci(int n) {
    // Base cases
    if (n <= 0) {
        // By definition, fibonacci(0) = 0
        // This is the first stopping condition
        return 0;
    }
    if (n == 1) {
        // By definition, fibonacci(1) = 1
        // This is the second stopping condition
        return 1;
    }

    // Recursive case
    // This adds the two previous Fibonacci numbers
    // fibonacci(n-1) is the immediately preceding number
    // fibonacci(n-2) is the number before that
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

Time Complexity: O(2ⁿ) - exponential due to repeated calculations
Space Complexity: O(n) - maximum depth of the recursion tree

## Advantages of recursion

- Makes code cleaner and easier to understand for certain problems
- Natural solution for problems with recursive structure (trees, graphs)
- Eliminates the need for complex loop structures

## Disadvantages of recursion

- Can lead to stack overflow if recursion is too deep
- Often less efficient than iterative solutions due to function call overhead
- May require memoization to avoid redundant calculations

## Tail recursion

A special form of recursion where the recursive call is the last operation in the function.

```cpp
int factorialTail(int n, int accumulator = 1) {
    // Base case
    if (n <= 1) {
        // When n reaches 0 or 1, return the accumulated result
        // The accumulator contains the product of all numbers from the original n down to 2
        return accumulator;
    }

    // Tail recursive case
    // This calls the function with a decremented n and an updated accumulator
    // The accumulator stores the intermediate result (n * accumulator)
    // No operations are performed after the recursive call returns
    return factorialTail(n - 1, n * accumulator);
}
```

Time Complexity: O(n) - same as regular factorial
Space Complexity: O(n) in general, but O(1) with tail call optimization

## Practical tips

1. Always identify a clear base case
2. Ensure progress toward the base case
3. Consider memoization for expensive recursive operations
4. Be mindful of stack space limitations
5. Consider converting to iteration if performance is critical

## Practice problems

Here's some suggested problems: (not related to midterms. just for practice.)

1. Implement a recursive function to calculate the sum of all elements in an array.
2. Implement a recursive function to find the maximum element in a binary tree.
3. Implement a recursive function to generate all permutations of a given string.
4. Implement a recursive function to solve the Tower of Hanoi problem.
5. Implement a recursive function to calculate the Fibonacci sequence using memoization.
6. Implement a recursive function to calculate the power of a number using exponentiation by squaring.
7. Implement a recursive function to calculate the greatest common divisor (GCD) of two numbers using Euclidean algorithm.
8. Implement a recursive function to calculate the least common multiple (LCM) of two numbers using the GCD.
9. Implement a recursive function to calculate the number of ways to climb a staircase with n steps, taking either 1 or 2 steps at a time.
10. Implement a recursive function to calculate the number of ways to partition a set of n elements into k non-empty subsets.
