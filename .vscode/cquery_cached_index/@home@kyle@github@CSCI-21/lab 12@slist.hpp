// Lab 12 -- templated singly-linked list class
//
// Programmer name: Kyle Landrith
// Date completed:  9/17/19

#include <sstream>
#include <stdexcept>
#include <string>
using std::logic_error;
using std::ostringstream;
using std::string;

template <typename T>
class SList {
public:
  // Default constructor.
  // Initializes head to nullptr, size to 0.
  SList() {
    head = nullptr;
    size = 0;
  }

  // Destructor.
  // Invokes clear to free the memory associated with all nodes in the list.
  ~SList() {
    clear();
  }

  // Create a new node to contain value and insert the node
  // at the head of this SList. Increases the size by 1.
  void pushFront(T value) {
    Node *temp;
    temp = new Node(value);
    temp->next = head;
    head = temp;
    size++;
  }

  // Remove the head node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  void popFront() noexcept(false) {
    if (head == nullptr) {
    throw std::logic_error("EMPTY LIST");
    }
    else {
      Node *temp = head;
      head = head->next;
      delete temp;
      size--;
    }
  }

  // Return the value stored in the head Node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  T front() noexcept(false) {
    if (head == nullptr) {
      throw std::logic_error("EMPTY LIST");
    }
    else {
      return head->value;
    }
  }

  // Return the number of nodes in this list.
  unsigned int getSize() const {
    return size;
  }

  // Check to see if this list is empty.
  bool empty() const {
    if (head == nullptr) {
      return true;
    }
    else {
      return false;
    }
  }

  // Free the memory associated with all nodes in the list.
  // Resets head to nullptr and size to 0.
  void clear() {
    while (head != nullptr) {
      Node *temp = head->next;
      delete head;
      head = temp;
    }
    head = nullptr;
    size = 0;
  }

  // Return a string representation of this list.
  // Displays the values (starting from head) of each node in the list,
  // separated by comma.
  //
  // EXAMPLE: "13,-1,0,99,-47"
  string toString() const {
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

private:
  unsigned int size; // the number of nodes in this list

  // A singly-linked list node with a pointer to next and a data field.
  // Implements a constructor to initialize the data field to a param value
  // and the pointer to nullptr.
  struct Node {
    Node *next;
    T value;

    Node(T newValue) {
      next = nullptr;
      value = newValue;
    }
  } * head; // a pointer to the first node in the list
};
