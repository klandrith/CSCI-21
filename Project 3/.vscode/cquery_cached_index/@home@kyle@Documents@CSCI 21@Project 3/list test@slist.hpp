/*  Programmer: Kyle Landrith
    Dated Completed: 10/1/19
    Resources: Geeks for Geeks, Stack Overflow, Tutorialspoint
    Class declaration and implementation for a doubly linked list,
    with various functions to perform all the necessary operations on
    the list
*/
#include <iostream>

using std::cout;
using std::endl;
using std::swap;

class SList {
  public:
    // Default constructor
    // Initializes head and tail to nullptr and size to 0
    SList() {
      head = nullptr;
      tail = nullptr;
      size = 0;
    }

    // Destructor.
    // Invokes clear to free the memory associated with all nodes in the list.
    ~SList() {
      clear();
    }

    // clear frees the memory associated with all nodes in the list.
    // Resets head and tail to nullptr and size to 0.
    void clear() {
      while (head != nullptr) {
        Node *temp = head->next;
        delete head;
        head = temp;
      }
      head = nullptr;
      tail = nullptr;
      size = 0;
    }

    // insertSorted inserts a value in the list in a sorted order
    // and increments the size by 1
    void insertSorted(int value) {
      Node *temp = head;
      Node *newNode;
      newNode = new Node(value);
      bool sorted = false;
      while (sorted == false) {
        if (head == nullptr) {
          head = newNode;
          tail = newNode;
          sorted = true;
        }
        else {
          if (temp->value > newNode->value) {
            newNode->prev = temp->prev;
            newNode->next = temp;
            if (temp->prev != nullptr) {
              temp->prev->next = newNode;
            }
            temp->prev = newNode;

            if (temp == head) {
              head = newNode;
            }

            sorted = true;
          }
          else if (temp == tail) {
            temp->next = newNode;
            newNode->prev = temp;
            tail = newNode;
            sorted = true;
          }
          else {
            temp = temp->next;
          }
        }
      }
      size++;
    }

    // insertFront creates a new node to contain value and inserts the node
    // at the head of this List. Increases the size by 1.
    void insertFront(int value) {
      Node *newNode;
      newNode = new Node(value);
      if (head == nullptr) {
        head = newNode;
        tail = newNode;
      }
      else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
      }
      size++;
    }

    // insertBack creates a new node to contain value and insert the node
    // at the tail of the List. Increases size by 1.
    void insertBack(int value) {
      Node *newNode;
      newNode = new Node(value);

      if (head == nullptr) {
        head = newNode;
        tail = newNode;
      }
      else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
      }
      size++;
    }

    // eliminateAllOf eliminates all instances of a value in the list
    // and decriments size accordingly, returns a bool if
    // successful or not, resets head and tail accordingly
    bool eliminateAllOf(int value) {
      Node *temp = head;
      bool eliminated = false;
      while (temp != nullptr) {
        if (temp->value == value) {
          // if current value of temp is not tail, change next node's prev pointer
          if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
          }
          // if current value of temp is not head, change prev node's next pointer
          if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
          }
          // if current value of temp is head, change head to next node
          if (temp == head) {
            head = temp->next;
            head->prev = nullptr;
          }
          // if current value of temp is tail, change tail to prev node
          if (temp == tail) {
            tail = temp->prev;
            tail->next = nullptr;
          }
          Node *temp2 = temp->next;
          delete temp;
          size--;
          eliminated = true;
          temp = temp2;
        }
        else {
          temp = temp->next;
        }
      }
      return eliminated;
    }

    // eliminateFirstOf eliminates first instance of a value in the list
    // and decriments size accordingly, returns a bool if
    // successful or not, resets head and tail accordingly
    bool eliminateFirstOf(int value) {
      Node *temp = head;
      if (temp != nullptr) {
        while (temp != nullptr) {
          if (temp->value == value) {
            // if current value of temp is not tail, change next node's prev pointer
            if (temp->next != nullptr) {
              temp->next->prev = temp->prev;
            }
            // if current value of temp is not head, change prev node's next pointer
            if (temp->prev != nullptr) {
              temp->prev->next = temp->next;
            }
            // if current value of temp is head, change head to next node
            if (temp == head) {
              head = temp->next;
              head->prev = nullptr;
            }
            // if current value of temp is tail, change tail to prev node
            if (temp == tail) {
              tail = temp->prev;
              tail->next = nullptr;
            }
            delete temp;
            size--;
            return true;
          }
          else {
            temp = temp->next;
          }
        }
      }
      return false;
    }

    // getNumber returns a bool if value is found in the list or not
    bool getNumber(int value) {
      Node *temp = head;
      while (temp != nullptr) {
        if (temp->value == value) {
          return true;
        }
        else {
          temp = temp->next;
        }
      }
      return false;
    }

    // getNumberHead returns the value of the head node
    int getNumberHead() {
      return head->value;
    }

    // getNumberTail returns the value of the tail node
    int getNumberTail() {
      return tail->value;
    }

    // popHead removes the head node from the list
    void popHead() {
      if (size > 0) {
        Node *temp = head;
        if (head != tail) {
          head = head->next;
          head->prev = nullptr;
          delete temp;
        }
        else {
          head = nullptr;
          tail = nullptr;
          delete temp;
        }
        size--;
      }
    }

    // popTail removes the tail node from the list
    void popTail() {
      if (size > 0) {
        Node *temp = tail;
        if (tail != head) {
          tail = tail->prev;
          tail->next = nullptr;
          delete temp;
        }
        else {
          head = nullptr;
          tail = nullptr;
          delete temp;
        }
        size--;
      }
    }

    // getSize returns the current size of the list
    unsigned int getSize() {
      return size;
    }

    // printItems prints the items in the list via cout
    void printList() {
      Node *temp = head;
      while (temp != nullptr) {
        if (temp->next != nullptr) {
          cout << temp->value << ",";
        }
        if (temp->next == nullptr) {
          cout << temp->value << endl;
        }
        temp = temp->next;
      }
    }
  private:
    unsigned int size; // number of nodes in the List

    // A doubly linked list with a pointer to next and previous nodes
    // and an integer data field. Includes a constructor to initialize
    // data field and sets pointers to nullptr
    struct Node {
      Node *next;
      Node *prev;
      int value;

      Node(int newValue) {
        next = nullptr;
        prev = nullptr;
        value = newValue;
      }
    } *head, *tail; // pointers to head and tail nodes in List
};
