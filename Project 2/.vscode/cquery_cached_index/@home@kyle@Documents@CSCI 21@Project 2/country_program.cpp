/*
  Name: Kyle Landrith
  Description: A program to read in values from a csv file containg various
  data on countries throughout the world. Program then gives the user the
  option to display the data in specific ways.
  Date completed: 9/24/19
  Resources: Stack Overflow, Geeks for Geeks, Cplusplus.com

*/
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "CinReader.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

//country struct with variables for all the fields in the csv file
struct Country {
  string countryName;
  unsigned int population;
  unsigned int area;
  double popDensity;
  double netMigration;
  double gdp;
  double literacyRate;
  double birthrate;
};

//function declarations
void parseCSV(string filename, vector<Country> &countries);
bool isInt(string input);
bool isDouble(string input);
void sortCountry(vector<Country> &countries, int sortOption, int count);
bool topPop(const Country &a, const Country &b);
bool bottomPop(const Country &a, const Country &b);
bool topArea(const Country &a, const Country &b);
bool bottomArea(const Country &a, const Country &b);
bool topPopDen(const Country &a, const Country &b);
bool bottomPopDen(const Country &a, const Country &b);
bool topMig(const Country &a, const Country &b);
bool bottomMig(const Country &a, const Country &b);
bool topGDP(const Country &a, const Country &b);
bool bottomGDP(const Country &a, const Country &b);
bool topLiteracy(const Country &a, const Country &b);
bool bottomLiteracy(const Country &a, const Country &b);
bool topBirth(const Country &a, const Country &b);
bool bottomBirth(const Country &a, const Country &b);
void EnterContinue();
void ClearScreen();

//driver
int main (int argc, char *argv[]) {
  ifstream inFile(argv[1]);
  //error checking for command line arguments
  if (argc == 1) {
    cerr << "Error: No file name entered. USAGE: country_program [filename]" << endl;
    return 1;
  }
  if (argc >= 3) {
    cerr << "Too many arguments passed. USAGE: country_program [filename]" << endl;
    return 1;
  }
  if (!inFile.good()) {
    cerr << "Error: Unable to read file passed as argument. Exiting..." << endl;
    return 1;
  }
  inFile.close();
  //create countries vector of structs
  vector<Country> countries;
  //create instance of cinreader
  CinReader reader;
  unsigned int selection = 0;
  unsigned int amountToView = 0;
  //call parsing function and pass in filename and empty vector
  parseCSV(argv[1], countries);
  unsigned int elementscount = countries.size();
  ClearScreen();

  //menu loop
  do {
    cout << "This program will allow you to view various country information...\n" << endl;
    cout << "1:  Enter  1 to view the most populous countries." << endl;
    cout << "2:  Enter  2 to view the least populous countries." << endl;
    cout << "3:  Enter  3 to view the countries with the largest areas." << endl;
    cout << "4:  Enter  4 to view the countries with the smallest areas." << endl;
    cout << "5:  Enter  5 to view the countries with the highest population denisities." << endl;
    cout << "6:  Enter  6 to view the countries with the lowest population densities." << endl;
    cout << "7:  Enter  7 to view the countries with the highest net migration rates." << endl;
    cout << "8:  Enter  8 to view the countries with the lowest net migration rates." << endl;
    cout << "9:  Enter  9 to view the countries with the highest per capita GDP." << endl;
    cout << "10: Enter 10 to view the countries with the lowest per capita GDP." << endl;
    cout << "11: Enter 11 to view the countries with the highest literacy rates." << endl;
    cout << "12: Enter 12 to view the countries with the lowest literacy rates." << endl;
    cout << "13: Enter 13 to view the countries with the highest birthrates." << endl;
    cout << "14: Enter 14 to view the countries with the lowest birthrates." << endl;
    cout << "\nEnter 0 to exit program..." << endl;
    cout << "\nEnter your selection: ";
    selection = reader.readInt(0,14);

    // take in number of entries to view if user does not want to exit program
    if (selection != 0) {
      cout << "\nEnter how many entries you would like to view [" << elementscount << " max]: ";
      amountToView = reader.readInt(1, elementscount);
    }

    //if user has not selected 0 for exit, clearscreen and call sortCounrties
    if (selection != 0) {
      ClearScreen();
      sortCountry(countries, selection, amountToView);
      EnterContinue();
    }
    //if user has selected 0, clearscreen in preparation for program exit
    else {
      ClearScreen();
    }
  } while(selection != 0);
  return 0;
}

//parseCSV function to parse the csv file, carefull to assign zeros to any empty fields
void parseCSV(string filename, vector<Country> &countries) {
  string line;
  //open .csv file
  ifstream inFile;
  inFile.open(filename);

  //while loop to input values from csv file and push to countries vector
  while(inFile.good()) {
    //string variables for raw input from csv
    string countryName;
    string population;
    string area;
    string popDensity;
    string netMigration;
    string gdp;
    string literacyRate;
    string birthrate;
    //variables for passing to country struct and pushing to vector
    unsigned int intpopulation;
    unsigned int intarea;
    double doublepopDensity;
    double doublenetMigration;
    double doublegdp;
    double doubleliteracyRate;
    double doublebirthrate;

    //get the independent fields
    getline(inFile, countryName, ',');
    getline(inFile, population, ',');
    getline(inFile, area, ',');
    getline(inFile, popDensity, ',');
    getline(inFile, netMigration, ',');
    getline(inFile, gdp, ',');
    getline(inFile, literacyRate, ',');
    getline(inFile, birthrate, '\n');

    // check if first line is field definitions line or empty line
    bool ignoreline = false;
    if (countryName[0] == '\0' || countryName[0] == '#') {
      ignoreline = true;
    }
    // do not execute block if line is field definitions line or empty line
    if (!ignoreline) {
      //if-else blocks to handle empty fields and to convert strings to doubles and ints
      if (population == "" || !isInt(population)) {
        intpopulation = 0;
      }
      else {
        intpopulation = std::stoi(population);
      }
      if (area == "" || !isInt(area)) {
        intarea = 0;
      }
      else {
        intarea = std::stoi(area);
      }
      if (popDensity == "" || !isDouble(popDensity)) {
        doublepopDensity = 0;
      }
      else {
        doublepopDensity = std::stod(popDensity);
      }
      if (netMigration == "" || !isDouble(netMigration)) {
        doublenetMigration = 0;
      }
      else {
        doublenetMigration = std::stod(netMigration);
      }
      if (gdp == "" || !isDouble(gdp)) {
        doublegdp = 0;
      }
      else {
        doublegdp = std::stod(gdp);
      }
      if (literacyRate == ""|| !isDouble(literacyRate)) {
        doubleliteracyRate = 0;
      }
      else {
        doubleliteracyRate = std::stod(literacyRate);
      }
      if (birthrate == "" || !isDouble(birthrate)) {
        doublebirthrate = 0;
      }
      else {
        doublebirthrate = std::stod(birthrate);
      }

      //create temp struct with values from the fields and pass to main countries vector
      Country tempCountry = {countryName, intpopulation, intarea, doublepopDensity,
                        doublenetMigration, doublegdp, doubleliteracyRate, doublebirthrate};

      countries.push_back(tempCountry);
    }
  }
  //close csv file
  inFile.close();
}

//isInt verifies that the string contains an int
bool isInt(string input) {
  for (int i = 0; i < input.size(); i++) {
    if (isalpha(input.at(i)) || ispunct(input.at(i)) || isspace(input.at(i))) {
      return false;
    }
  }
  return true;
}

//isDouble verifies that the string contrains a double
bool isDouble(string input) {
  unsigned int decimals = 0;
  for (int i = 0; i < input.size(); i++) {
    if (isalpha(input.at(i)) || isspace(input.at(i))) {
      return false;
    }
    if (ispunct(input.at(i))) {
      if (input.at(i) == '.') {
        decimals++;
      }
      else {
        return false;
      }
    }
  }
  if (decimals > 1) {
    return false;
  }
  return true;
}

//sortCountry function to sort data and output data based on menu selection
void sortCountry(vector<Country> &countries, int sortOption, int count) {
  if (countries.size() > 0 && countries.size() >= count) {
    //switch block to sort and output based on sortOption argument
    switch (sortOption) {
      case 1:
        sort(countries.begin(), countries.end(), topPop);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].population << setw(25) << left << "people" << endl;
        }
        break;
      case 2:
        sort(countries.begin(), countries.end(), bottomPop);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].population << setw(25) << left << "people" << endl;
        }
        break;
      case 3:
        sort(countries.begin(), countries.end(), topArea);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].area << setw(25) << left << "(sq. mi.)" << endl;
        }
        break;
      case 4:
        sort(countries.begin(), countries.end(), bottomArea);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].area << setw(25) << left << "(sq. mi.)" << endl;
        }
        break;
      case 5:
        sort(countries.begin(), countries.end(), topPopDen);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].popDensity << setw(25) << left << "people per (sq. mi.)" << endl;
        }
        break;
      case 6:
        sort(countries.begin(), countries.end(), bottomPopDen);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].popDensity << setw(25) << left << "people per (sq. mi.)" << endl;
        }
        break;
      case 7:
        sort(countries.begin(), countries.end(), topMig);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].netMigration << setw(25) << left << "people" << endl;
        }
        break;
      case 8:
        sort(countries.begin(), countries.end(), bottomMig);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].netMigration << setw(25) << left << "people" << endl;
        }
        break;
      case 9:
        sort(countries.begin(), countries.end(), topGDP);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].gdp << setw(25) << left << "GDP ($ per capita)" << endl;
        }
        break;
      case 10:
        sort(countries.begin(), countries.end(), bottomGDP);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].gdp << setw(25) << left << "GDP ($ per capita)" << endl;
        }
        break;
      case 11:
        sort(countries.begin(), countries.end(), topLiteracy);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].literacyRate << setw(25) << left << "literacy (%)" << endl;
        }
        break;
      case 12:
        sort(countries.begin(), countries.end(), bottomLiteracy);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].literacyRate << setw(25) << left << "literacy (%)" << endl;
        }
        break;
      case 13:
        sort(countries.begin(), countries.end(), topBirth);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].birthrate << setw(25) << left << "birthrate" << endl;
        }
        break;
      case 14:
        sort(countries.begin(), countries.end(), bottomBirth);
        for (int i = 0; i < count; i++) {
          cout << setw(4) << left << i + 1 << setw(25) << left << countries[i].countryName
               << setw(25) << left << countries[i].birthrate << setw(25) << left << "birthrate" << endl;
        }
        break;
      default:
        cerr << "Invalid input!";
    }
  }
}

//functions to return which is greater or lesser of values from vector to be
//passed back to the sort() function called in sortCountry function
//with the capability to ignore 0 fields (fields that initially had no value)
bool topPop(const Country &a, const Country &b) {
  return (a.population > b.population);
}
bool bottomPop(const Country &a, const Country &b) {
  if(a.population == 0) return false;
  if(b.population == 0) return true;
  return (a.population < b.population);
}
bool topArea(const Country &a, const Country &b) {
  return (a.area > b.area);
}
bool bottomArea(const Country &a, const Country &b) {
  if(a.area == 0) return false;
  if(b.area == 0) return true;
  return (a.area < b.area);
}
bool topPopDen(const Country &a, const Country &b) {
  return (a.popDensity > b.popDensity);
}
bool bottomPopDen(const Country &a, const Country &b) {
  if(a.popDensity == 0) return false;
  if(b.popDensity == 0) return true;
  return (a.popDensity < b.popDensity);
}
bool topMig(const Country &a, const Country &b) {
  return (a.netMigration > b.netMigration);
}
bool bottomMig(const Country &a, const Country &b) {
  if(a.netMigration == 0) return false;
  if(b.netMigration == 0) return true;
  return (a.netMigration < b.netMigration);
}
bool topGDP(const Country &a, const Country &b) {
  return (a.gdp > b.gdp);
}
bool bottomGDP(const Country &a, const Country &b) {
  if(a.gdp == 0) return false;
  if(b.gdp == 0) return true;
  return (a.gdp < b.gdp);
}
bool topLiteracy(const Country &a, const Country &b) {
  return (a.literacyRate > b.literacyRate);
}
bool bottomLiteracy(const Country &a, const Country &b) {
  if(a.literacyRate == 0) return false;
  if(b.literacyRate == 0) return true;
  return (a.literacyRate < b.literacyRate);
}
bool topBirth(const Country &a, const Country &b) {
  return (a.birthrate > b.birthrate);
}
bool bottomBirth(const Country &a, const Country &b) {
  if(a.birthrate == 0) return false;
  if(b.birthrate == 0) return true;
  return (a.birthrate < b.birthrate);
}

//EnterContinue prompts user to press enter to continue
void EnterContinue() {
  CinReader reader;
  string enter_accept;
  cout << endl;
  cout << "Press enter to continue...";
  enter_accept = reader.readString();
  ClearScreen();
}

//clearscreen function to clear screen
void ClearScreen() {
#ifdef _WIN32
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}
