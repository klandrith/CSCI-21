/*  Programmer: Kyle Landrith
    Dated Completed: 10/1/19
    Resources: Geeks for Geeks, Stack Overflow, Tutorialspoint
    Class declaration and implementation for a doubly linked list,
    with various functions to perform all the necessary operations on
    the list
*/

#pragma once

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class DList {
  public:
    // Default constructor
    // Initializes head and tail to nullptr and size to 0
    DList() {
      head = nullptr;
      tail = nullptr;
      size = 0;
    }

    // Destructor.
    // Invokes clear to free the memory associated with all nodes in the list.
    ~DList() {
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
    void insertSorted(T value) {
      // create temp pointer and initialize to head
      // create newNode and pass it the value passed as argument function call
      // create sorted bool for termination of while loop
      Node *temp = head;
      Node *newNode;
      newNode = new Node(value);
      bool sorted = false;
      // while loop to find where to insert and to insert node into list
      while (sorted == false) {
        // list is empty insert newNode and assign tail and head to it
        if (head == nullptr) {
          head = newNode;
          tail = newNode;
          sorted = true;
        }
        //list not empty
        else {
          // temps value is greater than value to insert
          // insert newNode into list and assign pointers correctly
          if (temp->value >= newNode->value) {
            newNode->prev = temp->prev;
            newNode->next = temp;
            // check if current temp has a previous node(ie, not head) to change
            // and assign pointers
            if (temp->prev != nullptr) {
              temp->prev->next = newNode;
            }
            temp->prev = newNode;
            // if temp is head, assign head to newNode instead
            if (temp == head) {
              head = newNode;
            }
            sorted = true;
          }
          // if temp is larger than all nodes in the list, place newNode at
          // tail and assign pointers
          else if (temp == tail) {
            temp->next = newNode;
            newNode->prev = temp;
            tail = newNode;
            sorted = true;
          }
          // if temp is not bigger than value keep going down the list
          else {
            temp = temp->next;
          }
        }
      }
      size++;
    }

    // insertFront creates a new node to contain value and inserts the node
    // at the head of this List. Increases the size by 1.
    void insertFront(T value) {
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
    void insertBack(T value) {
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
    bool eliminateAllOf(T value) {
     Node *temp = head;
     bool eliminated = false;
     while (temp != nullptr) {
       if (temp->value == value) {
         // if current value of temp is not head, change prev node's next pointer
         if (temp->prev != nullptr) {
           temp->prev->next = temp->next;
         }
         // if current value of temp is head, change head to next node
         else {
           head = temp->next;
           if (head != nullptr) {
             head->prev = nullptr;
           }
         }
         // if current value of temp is not tail, change next node's prev pointer
         if (temp->next != nullptr) {
           temp->next->prev = temp->prev;
         }
         // if current value of temp is tail, change tail to prev node
         else {
          tail = temp->prev;
          if (tail != nullptr) {
            tail->next = nullptr;
          }
        }
        // perform deletion operations and cycle forward to next node
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
    bool eliminateFirstOf(T value) {
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
            // and if new head is not nullptr, change head->prev to nullptr
            // note: this is needed if head is the only node left in list and
            // is going to be deleted
            if (temp == head) {
              head = temp->next;
              if (head != nullptr) {
                head->prev = nullptr;
              }
            }
            // if current value of temp is tail, change tail to prev node
            // and if new tail is not nullptr, change tail->next to nullptr
            // note: this is needed if tail is the only node left in list and
            // is going to be deleted
            if (temp == tail) {
              tail = temp->prev;
              if (tail != nullptr) {
                tail->next = nullptr;
              }
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
    bool get(T value) {
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
    T getHead() {
      return head->value;
    }

    // getNumberTail returns the value of the tail node
    T getTail() {
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
      T value;

      Node(T newValue) {
        next = nullptr;
        prev = nullptr;
        value = newValue;
      }
    } *head, *tail; // pointers to head and tail nodes in List
};
