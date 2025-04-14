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
