#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <typename T> // We use templates to make the implementation flexible
                      // and reusable. This means that the same code can be used
                      // for different data types without any modifications. For
                      // example, the first node can be of type int, the second
                      // node can be of type string, and so on.
                      struct Node {
  T value; // Here's our data, where the heart lives, and the soul resides, and
           // the mind is free to roam, and the body is strong and healthy.
           // (Yeah, I get bored sometimes, these are basic principles
           // actually.)
  Node *next; // Here's our next pointer. We point to the next node to make them
              // **linked** together. (WHAT A GREAT IDEA! SHALL WE CALL THIS A
              // LINKED LIST? YES, WE SHALL! YES, WE SHALL! LONG LIVE THE LINKED
              // LIST!)
};

template <typename T> class LinkedList {
public:
  /**
   * Constructor,
   * Initializes an empty linked list.
   */
  LinkedList() : head(nullptr), size(0) {}

  /**
   * Destructor,
   * Frees all memory allocated for the linked list.
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
   * append
   * appends a new node to the end of the linked list.
   */
  void append(const T &value) {
    Node<T> *newNode = new Node<T>{value, nullptr};
    if (head == nullptr) {
      head = newNode;
    } else {
      Node<T> *current = head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = newNode;
    }
    size++;
  }

  /**
   * append_start
   * appends a new node to the start of the linked list.
   * moves the rest of the list to the next pointer of the new node.
   */
  void append_start(const T &value) {
    Node<T> *newNode = new Node<T>{value, head};
    head = newNode;
    size++;
  }

  /**
   * remove
   * removes a node from the linked list.
   */
  void remove(const T &value) {
    Node<T> *current = head;
    Node<T> *prev = nullptr;

    while (current != nullptr) {
      if (current->value == value) {
        if (prev == nullptr) {
          head = current->next;
        } else {
          prev->next = current->next;
        }
        delete current;
        size--;
        return;
      }
      prev = current;
      current = current->next;
    }
  }

  /**
   * remove_start
   * removes the first node from the linked list.
   */
  void remove_start() {
    if (head != nullptr) {
      Node<T> *next = head->next;
      delete head;
      head = next;
      size--;
    }
  }

  /**
   * remove_end
   * removes the last node from the linked list.
   */
  void remove_end() {
    if (head == nullptr || head->next == nullptr) {
      delete head;
      head = nullptr;
      size = 0;
    } else {
      Node<T> *current = head;
      Node<T> *prev = nullptr;

      while (current->next != nullptr) {
        Node<T> *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
      }

      delete current;
      head = prev;
      size--;
    }
  }

  /**
   * search
   * Search for a value in the linked list
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
   * Reverse the linked list
   */
  void reverse() {
    Node<T> *current = head;
    Node<T> *prev = nullptr;

    while (current != nullptr) {
      Node<T> *next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    head = prev;
  }

  /**
   * display
   * Display the linked list using standard output stream
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
   * override_>>
   * Override >> operator to display the linked list using standard output
   * stream
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
  int size;
};

#endif // LINKED_LIST_H
