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
