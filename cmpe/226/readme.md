# Welcome to Atılım University, Data Structures and Algorithms midterm 1 preparation notes

> This repository contains notes and resources for the midterm exam preparation.
> devsimsek's 226 midterm 1 preparation notes © 2025 by devsimsek is licensed under [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International](https://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1)
> Please note that if you're planning to sell these notes, you should first review the license terms that apply to this content. I am not responsible for any legal issues that may arise from the sale of these notes and I won't suggest you try to sell them since I may take legal action against you.

## Table of Contents

- [Introduction](#introduction)
- [Data Structures](#data-structures)
- [Algorithms](#algorithms)
- [Resources](#resources)

# Introduction

Welcome to the Atılım University Data Structures and Algorithms midterm 1 preparation notes repository. This repository is designed to help my fellow mates to prepare for the midterm exam by providing somewhat comprehensive notes and resources.

The first midterm will contain questions from the following topics:

- Data Structures
  - Linked Lists
  - Stacks
  - Queues
  - Trees
  - Graphs
- Algorithms
  - Recursion
  - Searching
  - Sorting
  - Dynamic Programming
  - Greedy Algorithms
  - Divide and Conquer

PS: It also requires knowledge of 225 (Object Oriented Programming). So if you are not familiar with Object Oriented Programming, please take the course before the midterm exam. If you can't take the course, I feel sorry for you. Nothing is over yet, but you must close that gap as fast as you can.

## Data Structures

Data Structures, is a fundamental concept in computer science that refers to the way data is organized and stored in a computer system. It is a blueprint for organizing and storing data in a way that allows for efficient access and manipulation. Data structures are essential for building efficient and scalable software systems. C++ is a powerful programming language which can utilize data structures to create efficient and scalable software systems.

### What Kind of Data Structures?

Considering that you can create your own data structures, there are many different types of data structures that can be used to solve various problems. Some common data structures include:

- Arrays
- Linked Lists
- Stacks
- Queues
- Trees
- Graphs

Most of these data structures can be implemented using C++ templates, which allows for generic programming and code reuse. Additionally, C++ provides a rich set of standard library containers, such as vectors, lists, and maps, which can be used to implement many common data structures.

Also you are expected to learn some of them within 225, such as arrays and objects.

#### Arrays

Arrays are one of the fundamental data structures in computer science. They are used to store a collection of elements of the same data type in contiguous memory locations. Arrays are useful for storing and accessing data in a sequential manner, and they provide efficient access to elements based on their index.

You can think of this like key-value pairs. Only the key is the index.

Within C++, they require a fixed size at compile time, which can be a limitation in some cases. However, C++ also provides dynamic arrays, which can be resized at runtime using the `std::vector` container. (Foreshadowing...)

#### Linked Lists

Linked lists are data structures that consist of a sequence of elements, where each element (called a node) contains both data and a reference (or link) to the next node in the sequence. Unlike arrays, linked lists do not store data in contiguous memory locations, which gives them unique advantages and disadvantages.

**Components of a Linked List:**

1. **Node**: Basic building block containing:

   - Data (the value stored)
   - Pointer to the next node

2. **Head**: Pointer to the first node in the list

3. **Tail** (optional): Pointer to the last node in the list

**Types of Linked Lists:**

1. **Singly Linked List**: Each node points to the next node only
2. **Doubly Linked List**: Each node has pointers to both next and previous nodes
3. **Circular Linked List**: The last node points back to the first node, forming a circle

**Example Implementation of a Singly Linked List Node in C++:**

```cpp
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};
```

**Basic Operations and Their Time Complexity:**

- **Insertion at beginning**: O(1)
- **Insertion at end**: O(1) with tail pointer, O(n) without
- **Insertion at middle**: O(n) to find position, O(1) to insert
- **Deletion**: O(1) after finding the node, O(n) to find the node
- **Search**: O(n)

**Example: Adding a Node at the Beginning:**

```cpp
template <typename T>
void insertAtBeginning(Node<T>*& head, T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
}
```

**Advantages of Linked Lists:**

- Dynamic size (can grow and shrink as needed)
- Efficient insertions and deletions (when position is known)
- No need for contiguous memory

**Disadvantages of Linked Lists:**

- Random access is not efficient (cannot directly access elements by index)
- Extra memory required for pointers
- Not cache-friendly due to non-contiguous memory allocation

For a detailed implementation and more examples, please refer to the [linked_list.md](linked_list.md) file.

#### Stacks

Stacks are a fundamental data structure in computer science. They are used to store a collection of elements of the same data type in a last-in-first-out (LIFO) manner. Stacks are useful for storing and accessing data in a sequential manner, and they provide efficient insertion and deletion of elements. I wont go any deeper than this since the first midterm won't cover them.

#### Queues

Queues are a fundamental data structure in computer science. They are used to store a collection of elements of the same data type in a first-in-first-out (FIFO) manner. Queues are useful for storing and accessing data in a sequential manner, and they provide efficient insertion and deletion of elements. I wont go any deeper than this since the first midterm won't cover them.

#### Trees

Trees are a fundamental data structure in computer science. They are used to store a collection of elements of the same data type in a hierarchical manner. Trees are useful for storing and accessing data in a sequential manner, and they provide efficient insertion and deletion of elements.

Again, I won't go any deeper than this since the first midterm won't cover them.

#### Graphs

Graphs are a fundamental data structure in computer science. They are used to store a collection of elements of the same data type in a non-hierarchical manner. Graphs are useful for storing and accessing data in a sequential manner, and they provide efficient insertion and deletion of elements.

Again, I won't go any deeper than this since the first midterm won't cover them.

## Algorithms

Algorithms are a fundamental concept in computer science. They are used to solve problems by breaking them down into a series of steps. Algorithms are useful for solving problems in a sequential manner, and they provide efficient solutions to problems. For example, the binary search algorithm is a popular algorithm used to search for an element in a sorted array. It works by repeatedly dividing the search interval in half until the element is found or the interval is empty.

We will cover recursivity in this section but also discuss the time complexity of algorithms and how to analyze them.

### Recursion

Recursion is a programming technique where a function calls itself to solve a problem by breaking it down into smaller, similar subproblems. A recursive solution consists of:

1. **Base case(s)**: The simplest scenario(s) that can be solved directly without further recursion
2. **Recursive case(s)**: Where the function calls itself with a simpler version of the original problem

Recursion is particularly useful for problems that can be naturally divided into simpler versions of themselves, such as tree traversals, searching algorithms, and mathematical calculations.

**Key Characteristics of Recursion:**

- Each recursive call works on a smaller instance of the same problem
- Must have at least one base case to prevent infinite recursion
- The solution to the original problem is built from solutions to the subproblems

**Example 1: Factorial Calculation**

The factorial of a non-negative integer n (denoted as n!) is the product of all positive integers less than or equal to n.

```cpp
int factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case
    else {
        return n * factorial(n - 1);
    }
}
```

**Execution for factorial(4):**

1. factorial(4) calls factorial(3) and waits
2. factorial(3) calls factorial(2) and waits
3. factorial(2) calls factorial(1) and waits
4. factorial(1) returns 1 (base case)
5. factorial(2) completes: 2 \* 1 = 2
6. factorial(3) completes: 3 \* 2 = 6
7. factorial(4) completes: 4 \* 6 = 24

**Example 2: Fibonacci Sequence**

The Fibonacci sequence is a series where each number is the sum of the two preceding ones, starting from 0 and 1.

```cpp
int fibonacci(int n) {
    // Base cases
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

**Advantages of Recursion:**

- Often leads to elegant, easy-to-understand solutions
- Natural fit for problems with recursive structures (trees, graphs)
- Can reduce complex problems to simple cases

**Disadvantages of Recursion:**

- Can be less efficient than iterative solutions due to function call overhead
- Risk of stack overflow with deep recursion
- May lead to redundant calculations (can be mitigated with memoization)

**Recursion vs. Iteration:**

- Recursion uses the system stack to manage function calls
- Iteration uses explicit control structures (loops)
- Any recursive solution can be rewritten as an iterative one (sometimes with an explicit stack)

For a more detailed explanation and additional examples, refer to the [recursivity.md](recursivity.md) file.

### Algorithm Analysis: Time and Space Complexity

Understanding how to analyze algorithms in terms of their efficiency is crucial for developing optimal solutions to computational problems. The two primary metrics used for this analysis are time complexity and space complexity.

#### Time Complexity

Time complexity is a measure of the amount of computational time required by an algorithm to run as a function of the input size. It answers the question: "How does the running time of an algorithm grow as the input size increases?"

**Key Aspects of Time Complexity:**

1. **Big O Notation**: The standard way to express time complexity, which describes the upper bound of an algorithm's growth rate.

2. **Common Time Complexities (from fastest to slowest):**

   - O(1) - Constant time: The algorithm takes the same amount of time regardless of input size
   - O(log n) - Logarithmic time: Time grows logarithmically with input size (e.g., binary search)
   - O(n) - Linear time: Time grows linearly with input size (e.g., linear search)
   - O(n log n) - Linearithmic time: Common in efficient sorting algorithms (e.g., merge sort, heap sort)
   - O(n²) - Quadratic time: Often seen in nested loops (e.g., bubble sort, insertion sort)
   - O(n³) - Cubic time: Three nested loops
   - O(2ⁿ) - Exponential time: Time doubles with each additional element (e.g., recursive Fibonacci)
   - O(n!) - Factorial time: Extremely slow (e.g., brute force traveling salesman)

3. **Asymptotic Analysis**: Focuses on the behavior of algorithms for large inputs, ignoring constants and lower-order terms.

#### Space Complexity

Space complexity measures the amount of memory an algorithm requires as a function of the input size. It answers the question: "How does the memory usage grow as the input size increases?"

**Key Aspects of Space Complexity:**

1. **Components of Space Complexity:**

   - **Auxiliary Space**: Extra space used by the algorithm (not including input)
   - **Input Space**: Space used to store the input
   - **Total Space**: Auxiliary space + Input space

2. **Common Space Complexities:**

   - O(1) - Constant space: Fixed amount of extra space regardless of input size
   - O(log n) - Logarithmic space: Often seen in divide and conquer algorithms
   - O(n) - Linear space: Extra space grows linearly with input size
   - O(n²) - Quadratic space: Often in algorithms that store 2D arrays or matrices

3. **Stack Space in Recursion**: Each recursive call typically adds a new frame to the call stack, which counts toward space complexity.

#### How to Determine Time and Space Complexity

**Steps to Analyze Time Complexity:**

1. **Identify the Basic Operations**: Determine which operations will be executed most frequently.

2. **Count the Number of Basic Operations**:

   - For loops: Consider how many iterations will occur
   - Nested loops: Multiply the number of iterations of each loop
   - If statements: Consider the complexity of the condition and the body
   - Recursive calls: Analyze the recurrence relation

3. **Express as a Function of Input Size**: Formulate how the operation count relates to input size.

4. **Apply Big O Simplification Rules**:
   - Drop constants: O(2n) → O(n)
   - Drop lower-order terms: O(n² + n) → O(n²)
   - Keep only the dominant term: O(n³ + n² + n) → O(n³)

**Examples of Time Complexity Analysis:**

1. **Simple Loop**:

```cpp
for (int i = 0; i < n; i++) {
    // O(1) operation
}
```

Time Complexity: O(n) - The loop runs n times, each with constant time operations.

2. **Nested Loops**:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // O(1) operation
    }
}
```

Time Complexity: O(n²) - The outer loop runs n times, and for each iteration, the inner loop runs n times.

3. **Logarithmic Complexity**:

```cpp
for (int i = 1; i < n; i *= 2) {
    // O(1) operation
}
```

Time Complexity: O(log n) - The loop variable doubles each time, resulting in log₂(n) iterations.

**Steps to Analyze Space Complexity:**

1. **Identify Memory Allocation**: Determine what data structures are created and how their size relates to input.

2. **Account for Recursive Stack Space**: Each recursive call typically adds a frame to the call stack.

3. **Express as a Function of Input Size**: Formulate how memory usage relates to input size.

4. **Apply Big O Simplification Rules**: Similar to time complexity analysis.

**Examples of Space Complexity Analysis:**

1. **In-place Algorithm**:

```cpp
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
```

Space Complexity: O(1) - Only a fixed amount of extra space is used regardless of input size.

2. **Linear Space Usage**:

```cpp
int* duplicateArray(int arr[], int n) {
    int* result = new int[n];
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }
    return result;
}
```

Space Complexity: O(n) - The additional space used grows linearly with the input size.

3. **Recursive Factorial**:

```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

Space Complexity: O(n) - The call stack will have n frames at the deepest point of recursion.

Understanding time and space complexity is essential for comparing algorithms, making informed implementation choices, and optimizing solutions for different constraints and requirements.

## Resources

If you really require more information or fast help, contact me and we will see what I can do for you.

Meanwhile, here are some resources that may be helpful:

- [Big O Notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Time Complexity](https://en.wikipedia.org/wiki/Time_complexity)
- [Space Complexity](https://en.wikipedia.org/wiki/Space_complexity)
- [Recursion](<https://en.wikipedia.org/wiki/Recursion_(computer_science)>)
- [Dynamic Programming](https://en.wikipedia.org/wiki/Dynamic_programming)
- [Memoization](https://en.wikipedia.org/wiki/Memoization)
- [Greedy Algorithms](https://en.wikipedia.org/wiki/Greedy_algorithm)
- [Divide and Conquer](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm)
- [Backtracking](https://en.wikipedia.org/wiki/Backtracking)
- [Graph Algorithms](https://en.wikipedia.org/wiki/Graph_algorithm)
- [Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Binary Search](https://en.wikipedia.org/wiki/Binary_search_algorithm)
- [Hash Tables](https://en.wikipedia.org/wiki/Hash_table)
- [Heap](<https://en.wikipedia.org/wiki/Heap_(data_structure)>)
- [Priority Queue](https://en.wikipedia.org/wiki/Priority_queue)
- [Linked Lists](https://en.wikipedia.org/wiki/Linked_list)
- [Trees](<https://en.wikipedia.org/wiki/Tree_(data_structure)>)
- [Graphs](<https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)>)

# About Me

I am a software engineer with a passion for problem-solving and learning new technologies. I have experience in various programming languages and frameworks, and I am always eager to take on new challenges.

# Contact Me

If you have any questions or need help, feel free to reach out to me. I am always happy to help!

- [Blog](https://smsk.dev)
- [LinkedIn](https://www.linkedin.com/in/devsimsek/)
- [GitHub](https://github.com/devsimsek)
- [Mastodon](https://universeodon.com/@devsimsek)
