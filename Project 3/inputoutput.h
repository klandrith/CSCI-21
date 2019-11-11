/*  Programmer:     Kyle Landrith
    Date Completed: 10/31/19
    Resources: None
    Class declaration for an inputoutput function
    to take in a filename and handle the IO for a double linked
    list program.

    OPERATION codes + descriptions

    CODE [argument] : description

    # any text      : ignore as comment
    C               : create dynamic list instance
    X               : clear the current list instance of contents
    D               : delete the dynamic list instance and set to nullptr
    I number        : insert number into list (sorted)
    F number        : add number to front of list
    B number        : add number to back of list
    E number        : eliminate all occurrences of number from the list
    R number        : remove the first occurrence of number from the list
    G number        : get number from the list
    A               : return contents of head node
    Z               : return contents of tail node
    T               : pop the head node
    K               : pop the tail node
    N               : return the size of the list
    P               : print all items in the list

*/
#pragma once

#include <iostream>
#include "dlist.hpp"
#include <string>
#include <fstream>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;
using std::stoi;
using std::exception;
using std::remove;

class InputOutput {
public:
  // InputOutput handles parsing the input file and calling DList functions
  void IOFunction(string filename);
private:
  // create function creates a new list instance
  void create(DList<unsigned int> *&list);

  // clear clears the list instance of all contents
  void clear(DList<unsigned int> *&list);

  //deletelist deletes the list instance
  void deletelist(DList<unsigned int> *&list);

  // insertSorted inserts an item into the list sorted
  void insertSorted(string input, DList<unsigned int> *&list);

  // insertFront inserts an item into the list at the front of list
  void insertFront(string input, DList<unsigned int> *&list);

  // insertBack inserts an item into the list at the back of the list
  void insertBack(string input, DList<unsigned int> *&list);

  // eliminateAllOf eliminates all occurences of an item from the list
  void eliminateAllOf(string input, DList<unsigned int> *&list);

  // eliminateFirstOf eliminates the first occurrence of an item from the list
  void eliminateFirstOf(string input, DList<unsigned int> *&list);

  // get searches the list for an item
  void get(string input, DList<unsigned int> *&list);

  // getHead outputs the value of the head node from the list
  void getHead(DList<unsigned int> *&list);

  // getTail outputs the value of the tail node from the list
  void getTail(DList<unsigned int> *&list);

  // popHead removes the head node from the list
  void popHead(DList<unsigned int> *&list);

  // popTail removes the tail node from the list
  void popTail(DList<unsigned int> *&list);

  // getSize outputs the size of the list
  void getSize(DList<unsigned int> *&list);

  // printList prints the contents of the list
  void printList(DList<unsigned int> *&list);

  // rmCarriageReturn removes '\r' from any input for POSIX compaitibility
  string rmCarriageReturn(string input);

  // converts a string to an int and returns it
  int stringToInt(string input);
};
