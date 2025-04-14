# Linked List

## Introduction

Linked lists are a fundamental data structure in computer science. They consist of a sequence of nodes, where each node contains a value and a reference to the next node in the sequence. Linked lists are versatile and can be used to implement various data structures such as stacks, queues, and graphs.

## Advantages and Disadvantages

Linked lists offer several advantages over other data structures such as arrays. They provide efficient insertion and deletion operations, as well as flexible memory allocation. However, linked lists also have some disadvantages, such as slower access times and higher memory overhead.

## Applications

Linked lists have numerous applications in computer science and software engineering. They are commonly used to implement data structures such as stacks, queues, and graphs. Linked lists are also used in various algorithms such as sorting and searching.

## Implementation

Linked lists can be implemented using either singly linked lists or doubly linked lists. In a singly linked list, each node contains a value and a reference to the next node. In a doubly linked list, each node contains a value, a reference to the next node, and a reference to the previous node.

### Singly Linked List

Singly linked lists are a type of linked list where each node contains a value and a reference to the next node in the sequence. Singly linked lists are commonly used to implement data structures such as stacks and queues.

Most of the time, singly linked lists are preferred over doubly linked lists because they require less memory and are easier to implement. However, doubly linked lists can be useful in certain scenarios where bidirectional traversal is required.

So, enough talk. Let's dive into the implementation details.

### Singly Linked List Implementation

I'll implement the list using a separate header file called `linked_list.h`. This way, I follow the convention of separating the implementation from the interface utilising c++'s encapsulation principles.

linked_list.h

```h
#ifndef LINKED_LIST_H // Header guard to prevent multiple inclusion of this file
#define LINKED_LIST_H // Define the header guard

#include <iostream> // Include the input/output stream library

template <typename T> // Define a template parameter T for generic programming
struct Node { // Define a Node structure which is the basic building block of
              // our linked list
  T value;    // Store data of type T in each node
  Node *next; // Pointer to the next node in the list, creating the "link"
};

template <typename T> // Define a template for our LinkedList class with the
                      // same type T
class LinkedList {    // Define the LinkedList class
public:               // Public section containing accessible members
  /**
   * Constructor,
   * Initializes an empty linked list.
   */
  LinkedList()
      : head(nullptr), size(0) {
  } // Constructor initializes head to null and size to 0

  /**
   * Destructor,
   * Frees all memory allocated for the linked list.
   */
  ~LinkedList() {                // Destructor called when object is destroyed
    Node<T> *current = head;     // Start at the head of the list
    while (current != nullptr) { // Loop through each node in the list
      Node<T> *next =
          current->next; // Save the next node before deleting current
      delete current;    // Free the memory for the current node
      current = next;    // Move to the next node
    }
  }

  /**
   * append
   * appends a new node to the end of the linked list.
   */
  void append(const T &value) { // Method to add a node to the end of the list
    Node<T> *newNode =
        new Node<T>{value, nullptr}; // Create a new node with the given value
    if (head == nullptr) {           // If the list is empty
      head = newNode;                // Set the head to the new node
    } else {                         // If the list is not empty
      Node<T> *current = head;       // Start at the head
      while (current->next != nullptr) { // Traverse to the last node
        current = current->next;         // Move to the next node
      }
      current->next = newNode; // Connect the last node to the new node
    }
    size++; // Increment the size counter
  }

  /**
   * append_start
   * appends a new node to the start of the linked list.
   * moves the rest of the list to the next pointer of the new node.
   */
  void append_start(
      const T &value) { // Method to add a node to the start of the list
    Node<T> *newNode = new Node<T>{
        value, head}; // Create a new node pointing to the current head
    head = newNode;   // Update the head to the new node
    size++;           // Increment the size counter
  }

  /**
   * remove
   * removes a node from the linked list.
   */
  void remove(const T &value) { // Method to remove a node with specific value
    Node<T> *current = head;    // Start at the head
    Node<T> *prev = nullptr;    // Keep track of the previous node

    while (current != nullptr) {     // Loop through the list
      if (current->value == value) { // If the current node has the target value
        if (prev == nullptr) {       // If it's the head node
          head = current->next;      // Update head to the next node
        } else {                     // If it's not the head node
          prev->next = current->next; // Bypass the current node
        }
        delete current; // Free the memory for the removed node
        size--;         // Decrement the size counter
        return;         // Exit the function after removing the node
      }
      prev = current;          // Update previous to current before moving
      current = current->next; // Move to the next node
    }
  }

  /**
   * remove_start
   * removes the first node from the linked list.
   */
  void remove_start() {           // Method to remove the first node
    if (head != nullptr) {        // If the list is not empty
      Node<T> *next = head->next; // Save the second node
      delete head;                // Delete the head node
      head = next;                // Update head to the second node
      size--;                     // Decrement the size counter
    }
  }

  /**
   * remove_end
   * removes the last node from the linked list.
   */
  void remove_end() { // Method to remove the last node
    if (head == nullptr ||
        head->next == nullptr) { // If list is empty or has one node
      delete head;               // Delete the head node
      head = nullptr;            // Set head to null
      size = 0;                  // Reset size to 0
    } else {                     // If list has more than one node
      Node<T> *current = head;   // Start at the head
      Node<T> *prev = nullptr;   // Track the previous node

      while (current->next != nullptr) { // Traverse to the last node
        Node<T> *next = current->next;   // Save the next node
        current->next = prev;            // Reverse the link (for head tracking)
        prev = current;                  // Move prev forward
        current = next;                  // Move current forward
      }

      delete current; // Delete the last node
      head = prev;    // Update head to previous (reversed)
      size--;         // Decrement the size counter
    }
  }

  /**
   * search
   * Search for a value in the linked list
   */
  bool search(const T &value) { // Method to search for a value in the list
    Node<T> *current = head;    // Start at the head

    while (current != nullptr) {     // Loop through the list
      if (current->value == value) { // If the value is found
        return true;                 // Return true
      }
      current = current->next; // Move to the next node
    }

    return false; // Return false if value not found
  }

  /**
   * reverse
   * Reverse the linked list
   */
  void reverse() {           // Method to reverse the linked list
    Node<T> *current = head; // Start at the head
    Node<T> *prev = nullptr; // Track the previous node

    while (current != nullptr) {     // Loop through each node
      Node<T> *next = current->next; // Save the next node
      current->next = prev;          // Reverse the link to point to previous
      prev = current;                // Move prev forward
      current = next;                // Move current forward
    }

    head = prev; // Update head to the last node (new first)
  }

  /**
   * display
   * Display the linked list using standard output stream
   */
  void display() {           // Method to print the list
    Node<T> *current = head; // Start at the head

    while (current != nullptr) {          // Loop through each node
      std::cout << current->value << " "; // Print the node's value
      current = current->next;            // Move to the next node
    }

    std::cout << std::endl; // End with a newline
  }

  /**
   * override_<<
   * Override << operator to display the linked list using standard output
   * stream
   */
  friend std::ostream &
  operator<<std::ostream &os,
             const LinkedList &list) { // Overload the << operator
    Node<T> *current = list.head;      // Start at the head of the provided list

    while (current != nullptr) {   // Loop through each node
      os << current->value << " "; // Output the node's value
      current = current->next;     // Move to the next node
    }

    os << std::endl; // End with a newline
    return os;       // Return the output stream
  }

private:         // Private section containing internal members
  Node<T> *head; // Pointer to the first node in the list
  int size;      // Counter to track the number of nodes
};

#endif // LINKED_LIST_H              // End of the header guard
```

Great! Now we can start working on using this header file to implement a sample of singly linked list.

main.cpp

```c++

#include "linked_list.h"

int main() {
  LinkedList<int> list;
  list.append(1); // Add element 1 with value 1 to the back of the list
  list.append(2); // Add element 2 with value 2 to the back of the list
  list.append(3); // Add element 3 with value 3 to the back of the list

  std::cout << "List: ";
  list.display(); // or std::cout << "List: " << list << std::endl; // since we
                  // have overriden the << operator.

  LinkedList<std::string> list2;

  list2.append("this is");
  list2.append("hi world");
  list2.append_start("linked lists!");
  list2.reverse();
  if (!list2.search("hi world"))
    std::cout << "something is not right.";
  else
    std::cout << list2 << std::endl;
  return 0;
}

```

### Doubly Linked List

Doubly Linked Lists are a type of linked list where each node contains a reference to both the next and previous nodes in the list. This allows for efficient traversal in both directions, making them useful for various applications such as implementing stacks, queues, and dequeues.

Before we continue any deeper, what's a stack?

**Stack** is a linear data structure that follows the Last-In-First-Out (LIFO) principle. This means that the last element added to the stack is the first one to be removed. Stacks are commonly used in programming for tasks such as expression evaluation, syntax parsing, and implementing function calls.

A stack supports two main operations:

- Push: Adds an element to the top of the stack
- Pop: Removes the top element from the stack

Additionally, stacks often include operations like:

- Peek: View the top element without removing it
- isEmpty: Check if the stack is empty
- Size: Get the number of elements in the stack

Stacks can be efficiently implemented using linked lists (particularly singly linked lists), where push and pop operations are performed at the head of the list for O(1) time complexity.

Oh, okay. And queues, dequeues?

**Queue** is a linear data structure that follows the First-In-First-Out (FIFO) principle. This means that the first element added to the queue is the first one to be removed. Queues are commonly used in programming for tasks such as task scheduling, breadth-first search, and implementing message passing.

A queue supports two main operations:

- Enqueue: Adds an element to the back of the queue
- dequeue: Removes the front element from the queue

Additionally, queues often include operations like:

- Peek: View the front element without removing it
- isEmpty: Check if the queue is empty
- Size: Get the number of elements in the queue

Queues can be efficiently implemented using linked lists (particularly singly linked lists), where enqueue and dequeue operations are performed at the head and tail of the list for O(1) time complexity.

**dequeue** is a linear data structure that supports insertion and deletion at both ends. This means that elements can be added or removed from either the front or the back of the dequeue. dequeues are commonly used in programming for tasks such as implementing double-ended queues, circular buffers, and priority queues.

A dequeue supports four main operations:

- PushFront: Adds an element to the front of the dequeue
- PushBack: Adds an element to the back of the dequeue
- PopFront: Removes the front element from the dequeue
- PopBack: Removes the back element from the dequeue

Additionally, dequeues often include operations like:

- PeekFront: View the front element without removing it
- PeekBack: View the back element without removing it
- isEmpty: Check if the dequeue is empty
- Size: Get the number of elements in the dequeue

dequeues can be efficiently implemented using doubly linked lists, where push and pop operations are performed at both ends of the list for O(1) time complexity.

Since I am not sure whether the lecturer thought dequeues, I won't go into detail about them here. (I did, you can see them within remove and add operations)

### Doubly Linked List Implementation time!

Okay, let's dive into the implementation of a doubly linked list. (To be fair, doubly linked lists does not differ that much from singly linked lists. We just add a pointer to the previous node. (VERY SIMPLIFIED EXPLANATION))

```h
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <typename T> // Behold the magic of templates! Making our code work
                      // with ANY data type! It's like having a Swiss Army knife
                      // but for data structures. Need an int list? You got it!
                      // String list? Boom! Done! CustomWeirdClass list? No
                      // problemo!
                      struct Node {
  T value; // The sacred vault of our precious data. This is where the magic
           // happens, where dreams come true, and where your precious
           // information lives rent-free. (Yeah, I get poetic about data
           // sometimes, but hey, it's the heart of computing!)
  Node *next; // The cosmic arrow pointing to the future! Each node extends its
              // digital hand to the next, creating the GREAT CHAIN OF DATA!
              // (OMG, THIS LINKING CONCEPT IS REVOLUTIONARY! LET'S NAME OUR
              // CHILD AFTER IT! LINKED LIST JOHNSON! HAS A NICE RING!)
  Node *prev; // The time machine to the past! With this pointer, we can
              // moonwalk through our data! Forward AND backward navigation?
              // TWICE THE POINTERS, TWICE THE EXCITEMENT! It's not just a
              // linked list, it's a DOUBLY linked list! *drops mic*
};

template <typename T> class LinkedList {
public:
  /**
   * Constructor,
   * Initializes an empty linked list. Born with nothing, ready for everything!
   */
  LinkedList() : head(nullptr), tail(nullptr), size(0) {}

  /**
   * Destructor,
   * The grim reaper of memory management. Frees all allocated nodes.
   * Leaving no node behind, no memory leaked. Clean as a whistle!
   */
  ~LinkedList() {
    Node<T> *current = head;
    while (current != nullptr) {
      Node<T> *next = current->next;
      delete current;
      current = next;
    }
  }

  /**
   * Copy constructor
   * The magical cloning machine! Creates a perfect duplicate of another list.
   * Deep copy means we're not just pointing to their stuff, we're making our
   * own copies. It's like photocopying a book instead of stealing it!
   */
  LinkedList(const LinkedList<T> &other)
      : head(nullptr), tail(nullptr), size(0) {
    Node<T> *current = other.head;
    while (current != nullptr) {
      append(current->value);
      current = current->next;
    }
  }

  /**
   * Assignment operator
   * The identity thief (but legal)! "I want to be EXACTLY like that list!"
   * First we clean our old self, then we become a perfect clone of the other
   * list. Marie Kondo would be proud of this clean-then-rebuild approach.
   */
  LinkedList<T> &operator=(const LinkedList<T> &other) {
    if (this != &other) {
      // Clear current list
      Node<T> *current = head;
      while (current != nullptr) {
        Node<T> *next = current->next;
        delete current;
        current = next;
      }
      head = nullptr;
      tail = nullptr;
      size = 0;

      // Copy elements from other
      current = other.head;
      while (current != nullptr) {
        append(current->value);
        current = current->next;
      }
    }
    return *this;
  }

  /**
   * append
   * The caboose attacher! Adds a new node to the tail end of our train.
   * "All aboard! Next stop: The End Of The List!"
   */
  void append(const T &value) {
    Node<T> *newNode = new Node<T>{value, nullptr, nullptr};
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }
    size++;
  }

  /**
   * append_start
   * The line-cutter! Adds a node to the front and pushes everyone back.
   * "Excuse me, I'm kind of a big deal, I'll just squeeze in at the front
   * here."
   */
  void append_start(const T &value) {
    Node<T> *newNode = new Node<T>{value, head, nullptr};
    if (head != nullptr) {
      head->prev = newNode;
    } else {
      tail = newNode;
    }
    head = newNode;
    size++;
  }

  /**
   * remove
   * The exorcist! "I cast thee out, foul node with value X!"
   * Searches for a value and removes its node from existence.
   * It's like it was never there... *spooky ghost noises*
   */
  void remove(const T &value) {
    Node<T> *current = head;

    while (current != nullptr) {
      if (current->value == value) {
        if (current->prev == nullptr) {
          // It's the head
          head = current->next;
        } else {
          current->prev->next = current->next;
        }

        if (current->next == nullptr) {
          // It's the tail
          tail = current->prev;
        } else {
          current->next->prev = current->prev;
        }

        delete current;
        size--;
        return;
      }
      current = current->next;
    }
  }

  /**
   * remove_start
   * The head chopper! Off with its head! The second node gets a promotion.
   * "The king is dead, long live the king!"
   */
  void remove_start() {
    if (head != nullptr) {
      Node<T> *toDelete = head;
      head = head->next;

      if (head != nullptr) {
        head->prev = nullptr;
      } else {
        tail = nullptr; // List is now empty
      }

      delete toDelete;
      size--;
    }
  }

  /**
   * remove_end
   * The tail docking procedure! Snip snip, goodbye last node.
   * The second-to-last node suddenly finds itself at the end of the line.
   * "I guess this is my stop..."
   */
  void remove_end() {
    if (tail == nullptr) {
      return;
    }

    Node<T> *toDelete = tail;
    tail = tail->prev;

    if (tail != nullptr) {
      tail->next = nullptr;
    } else {
      head = nullptr; // List is now empty
    }

    delete toDelete;
    size--;
  }

  /**
   * search
   * The detective! "I'm looking for a node with THIS specific value..."
   * Searches high and low, leaves no stone unturned in the quest for your data.
   * Returns with the truth: found it (true) or it's not here (false).
   */
  bool search(const T &value) {
    Node<T> *current = head;

    while (current != nullptr) {
      if (current->value == value) {
        return true;
      }
      current = current->next;
    }

    return false;
  }

  /**
   * reverse
   * The Uno reverse card! Forward becomes backward, head becomes tail!
   * It's like looking at your list in a mirror, but we actually rearrange
   * all the pointers to make it permanent. Mind = blown!
   */
  void reverse() {
    if (head == nullptr || head == tail) {
      return; // Empty list or single node
    }

    Node<T> *current = head;
    Node<T> *temp = nullptr;

    // Swap next and prev pointers for all nodes
    while (current != nullptr) {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev; // Move to the next node (which is now prev)
    }

    // Swap head and tail
    temp = head;
    head = tail;
    tail = temp;
  }

  /**
   * display
   * The town crier! "Hear ye, hear ye! The contents of this list are as
   * follows..." Walks through the list from start to finish, announcing each
   * value to the console.
   */
  void display() {
    Node<T> *current = head;

    while (current != nullptr) {
      std::cout << current->value << " ";
      current = current->next;
    }

    std::cout << std::endl;
  }

  /**
   * display_reverse
   * The backwards town crier! Same as display, but starts from the tail and
   * works backwards. It's like reading the end of a book first, you monster!
   */
  void display_reverse() {
    Node<T> *current = tail;

    while (current != nullptr) {
      std::cout << current->value << " ";
      current = current->prev;
    }

    std::cout << std::endl;
  }

  /**
   * operator<<
   * The list whisperer! Teaches streams how to understand our linked list.
   * "Just print each value with a space between them, it's not rocket science!"
   * Makes it possible to do cool stuff like: cout << myList;
   */
  friend std::ostream &operator<<(std::ostream &os, const LinkedList &list) {
    Node<T> *current = list.head;

    while (current != nullptr) {
      os << current->value << " ";
      current = current->next;
    }

    os << std::endl;
    return os;
  }

private:
  Node<T> *head;
  Node<T> *tail; // The caboose pointer! Makes adding to the end WAY faster!
  int size;
};

#endif // LINKED_LIST_H
```

And the corresponding main would be;

main.cpp

```c++
#include "d_linked_list.h"

int main() {
  LinkedList<int> list;

  // by d_linked_list.h, we can use the LinkedList class to create a doubly
  // linked list.

  // Create a doubly linked list with some elements
  list.append(1);
  list.append(2);
  list.append(3);

  // Print the elements of the list
  std::cout << list << std::endl;

  list.append_start(0); // what do you think will this line do?
  std::cout << list << std::endl;

  list.remove(2); // hmmm...
  std::cout << list << std::endl;

  list.remove_start(); // more confusing sounds.
  std::cout << list << std::endl;

  list.remove_end(); // whoa? is that... going to... REMOVE THE LAST ELEMENT!?!?
  std::cout << list << std::endl;

  auto _to_search = list; // copying to avoid data loss.

  if (_to_search.search(
          0)) { // Should return true since we appended 0 at the first
                // position, wait... is that right?
    std::cout << "Coast is clear capitan!"; // hehe :D
  }

  _to_search = list; // overriding just so I can reuse :D

  if (_to_search.search(1)) {
    std::cout << "owa. you found me...";
  }

}
```

Great, now that you learned about linked lists, you can move on to solving some problems.

## Practice Problems

Here's some suggested problems: (not related to midterms. just for practice.)

1. Create a basic doubly linked class (use templates!).
2. Using string manipulation, create a function that reverses a string.
3. Implement a simple queue using a linked list with enqueue and dequeue operations.
4. Create a function that merges two sorted linked lists into a single sorted list.
5. Implement a function to detect if a linked list has a cycle (a node pointing back to a previous node).
6. Write a function to find the middle element of a linked list in one pass.
7. Create a function that removes all duplicates from an unsorted linked list.
8. Implement a stack using a linked list with push and pop operations.
9. Write a function to swap every pair of adjacent nodes in a linked list.
10. Create a function that checks if a linked list is a palindrome (reads the same forward and backward).
