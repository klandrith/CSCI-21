#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::stringstream;

void StringStreamMethod(string c, char delim) {
  stringstream ss(c);
  string token, color;
  int r, g, b;
  getline(ss, token, delim);
  color = token.c_str();
  getline(ss, token, delim);
  r = stoi(token);
  getline(ss, token, delim);
  g = stoi(token);
  getline(ss, token, delim);
  b = stoi(token);
  cout << color << " (" << r << "," << g << "," << b << ")\n";
}

void SubStringMethod(string c, string delim) {
  string color, token;
  vector<int> rgb;
  int pos;
  pos = c.find(delim);
  color = c.substr(0,pos);
  for (int i = 0; i < 3; i++) {
    c = c.substr(pos+delim.size());
    pos = c.find(delim);
    token = c.substr(0,pos);
    rgb.push_back(stoi(token));
  }
  cout << color << " (" << rgb[0] << "," << rgb[1] << "," << rgb[2] << ")\n";
}

int main () {
  string c = "mauve^183^132^167";
  StringStreamMethod(c, '^');
  string d = "redOrange->255->83->73";
  SubStringMethod(d, "->");

  return 0;
}
