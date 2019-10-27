#include "slist.h"

// Default constructor.
// Initializes head to nullptr, size to 0.
SList::SList() {
  head = nullptr;
  size = 0;
}

// Create a new node to contain value and insert the node
// at the head of this SList. Increases the size by 1.
void SList::pushFront(int value) {
  Node *temp;
  temp = new Node(value);
  temp->next = head;
  head = temp;
  size++;
}

// Return the value stored in the head Node.
// Throws std::logic_error("EMPTY LIST") when list is empty
int SList::front() noexcept(false) {
  if (head == nullptr) {
    throw std::logic_error("EMPTY LIST");
  }
  else {
    return head->value;
  }
}

// Return the number of nodes in this list.
unsigned int SList::getSize() const {
  return size;
}

// Check to see if this list is empty.
bool SList::empty() const {
  if (head == nullptr) {
    return true;
  }
  else {
    return false;
  }
}

// Return a string representation of this list.
// Displays the values (starting from head) of each node in the list,
// separated by comma.
//
// EXAMPLE: "13,-1,0,99,-47"
string SList::toString() const {
  ostringstream stream;
  Node *output = head;
  while (output != nullptr) {
    if (output->next == nullptr) {
      stream << output->value;
    }
    else {
      stream << output->value << ",";
    }
    output = output->next;
  }
  return stream.str();
}
