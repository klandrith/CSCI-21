#include <string>
using std::string;

class Cereal {
public:
  void setName(string name) {
    if (name != "Cheerios") {
      this->name = name;
    }
  }
private:
  string name;
  string brand;
  double servingSize;
  unsigned int calsPerServing;
  bool hasToy;
};

int main() {
  Cereal c1;
  c1.setName("Cheerios");

  Cereal c2;
  c2.setName("Fruit Loops");

  return 0;
}
