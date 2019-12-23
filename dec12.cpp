#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Example showing:
//
// 1. inheritance
// 2. virtual functions
// 3. function overriding
// 4. pure virtual functions (commented out parts)
// 5. keyword auto

// class Being {
// public:
//   Being(): alive(true) {}
//
//   virtual void beBorn() = 0;
//   virtual void die() = 0;
//   virtual bool isAlive() = 0;
//
// protected:
//   bool alive;
// };

class Animal /* : public Being */ {
public:
  Animal() {
      cout << "Animal::Animal()" << endl;
  }

  Animal(string name): name(name) {
    cout << "Animal::Animal(" << name << ")" << endl;
  }

  virtual ~Animal() {
    cout << "Animal::~Animal(" << this->name << ")" << endl;
  }

  virtual void print() {
    cout << "animal -> " << name << endl;
  }
protected:
  string name;
};

class Mammal : public Animal {
public:
  Mammal() {
    cout << "Mammal::Mammal" << endl;
  }

  Mammal(string name) : Animal(name) {
    cout << "Mammal::Mammal(" << name << ")" << endl;
  }

  ~Mammal() {
    cout << "Mammal::~Mammal(" << this->name << ")" << endl;
  }

  void print() {
    cout << "MAMMAL! -> " << this->name << endl;
  }
};

int main() {
  // Animal a1("snail");
  // a1.print();
  //
  // Mammal m1("tiger");
  // m1.print();

  vector<Animal*> zoo;
  zoo.push_back(new Mammal("gorilla"));
  zoo.push_back(new Animal("fish"));

  for (auto *a : zoo) {
    a->print();
  }

  for (size_t i=0; i<zoo.size(); i++) {
    delete zoo[i];
  }
  zoo.clear();

  return 0;
}
