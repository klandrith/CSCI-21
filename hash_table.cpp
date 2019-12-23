// Final -- hash table
// hash_table.cpp

#include "hash_table.h"

void HashTable::insert (Item i) {
  Item* got = getItem(i.contents);
  if (got == nullptr) {
    this->items[hash(i)].push_back(i);
  } else {
    got->count++;
  }
}

bool HashTable::remove (string contents) {
  unsigned int i = hash(contents);
  if (getItem(contents) == nullptr) return false;
  for (auto it = items[i].begin(); it != items[i].end(); it++) {
    if (it->contents == contents) {
      items[i].erase(it);
      return true;
    }
  }
  return false;
}

Item* HashTable::getItem (string contents) {
  for (list<Item>& l : items) {
    for (Item& i : l) {
      if (i.contents == contents) {
        return &i;
      }
    }
  }
  return nullptr;
}

unsigned int HashTable::size () {
  unsigned int count(0);
  for(list<Item> l : items){
    count += l.size();
  }
  return count;
}

string HashTable::printDetail () {
  stringstream ss;
  ss << "Items in hash table: " << size() << "\n";
  for(int i(0); i < items.size(); i++) {
    ss << "[" << i << "]\t";
    for (Item j : items[i]) {
      ss << j.contents << " (" << j.count << ") ";
    }
    ss << endl;
  }
  return ss.str();
}

unsigned int HashTable::hash (Item i) {
  return hash(i.contents);
}

unsigned int HashTable::hash (string s) {
  unsigned int sum(0);
  for (char c : s) {
    sum += c;
  }
  return sum % this->items.size();
}
