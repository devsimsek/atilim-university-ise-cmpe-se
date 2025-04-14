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
