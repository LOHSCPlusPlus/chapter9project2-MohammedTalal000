#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


struct videogametype {
  enum {MAX_CHAR_LEN=100};
  char name[MAX_CHAR_LEN];
  double numSales;
  char platform[MAX_CHAR_LEN];
  char releaseDate[MAX_CHAR_LEN];
  char developer[MAX_CHAR_LEN];
  char publisher[MAX_CHAR_LEN];
  videogametype();
};

videogametype::videogametype() {
  for (int index = 0; index < MAX_CHAR_LEN; index++) {
    name[index] = '\0';
    platform[index] = '\0';
    releaseDate[index] = '\0';
    developer[index] = '\0';
    publisher[index] = '\0';
  }
  numSales = 0;
}
double validDouble(double num) {
  while (!cin) {
    cin.clear();
    cin.ignore(1000,'\n');
    cout << "Invalid Data!" << endl;
    cout << "Enter again: ";
    cin >> num;
  }
  return num;
}

int validInt(int num) {
  while (!cin) {
    cin.clear();
    cin.ignore(1000,'\n');
    cout << "Invalid Data!" << endl;
    cout << "Enter again: ";
    cin >> num;
  }
  return num;
}

void printGames(ostream &out, videogametype game){
  out << game.name << ";";
  out << game.numSales << ";";
  out << game.platform << ";";
  out << game.releaseDate << ";";
  out << game.developer << ";";
  out << game.publisher << endl;
  
}

void addGame(videogametype games[]) {
  char temp[100];
  for (int index = 0; index < 100; index++) {
    temp[index] = '\0';
  }

  for (int index = 0; index < 100; index++) {
    if (strcmp(games[index].name,temp) == 0) {
      cout << "Enter the game's name: ";
      cin.ignore();
      cin.getline(games[index].name, 100);
      cout << endl << "Enter the number of sales: ";
      cin >> games[index].numSales;
      games[index].numSales = validDouble(games[index].numSales);
      cout << "Enter the platform: ";
      cin.ignore();
      cin.getline(games[index].platform, 100);
      cout << "Enter the game's release Date (format: Month day, year): ";
      cin.ignore();
      cin.getline(games[index].releaseDate, 100);
      cout << "Enter the game's developer: ";
      cin.ignore();
      cin.getline(games[index].developer, 100);
      cout << "Enter the game's publisher: ";
      cin.ignore();
      cin.getline(games[index].publisher, 100);
      break;
    }
  }
}


void searchGameByPublisher(int num, videogametype games[]) {
  char selecInput[100];
  for (int index = 0; index < 100; index++) {
    selecInput[index] = '\0';
  }
  cout << "\nPlease enter the publisher: ";
  cin.getline(selecInput, 100);
  cout << endl;

  for(int counter = 0; counter < num; counter++) {
    if (strcmp(games[counter].publisher,selecInput) == 0) {
      cout << "Index " << counter << ": ";
      printGames(cout, games[counter]);
    }
  }
}

void searchGameByDeveloper(int num, videogametype games[]) {
  char selecInput[100];
  for (int index = 0; index < 100; index++) {
    selecInput[index] = '\0';
  }
  cout << "\nPlease enter the developer: ";
  cin.getline(selecInput, 100);
  cout << endl;

  for(int counter = 0; counter < num; counter++) {
    if (strcmp(games[counter].developer,selecInput) == 0) {
      cout << "Index " << counter << ": ";
      printGames(cout, games[counter]);
    }
  }
}

void searchGameByPlatform(int num, videogametype games[]) {
  char selecInput[100];
  for (int index = 0; index < 100; index++) {
    selecInput[index] = '\0';
  }
  cout << "\nPlease enter the platform: ";
  cin.getline(selecInput, 100);
  cout << endl;

  for(int counter = 0; counter < num; counter++) {
    if (strcmp(games[counter].platform,selecInput) == 0) {
      cout << "Index " << counter << ": ";
      printGames(cout, games[counter]);
    }
  }
}


void searchGameByName(int num, videogametype games[]) {
  char selecInput[100];
  for (int index = 0; index < 100; index++) {
    selecInput[index] = '\0';
  }
  cout << "\nPlease enter the name: ";
  cin.getline(selecInput, 100);
  cout << endl;

  for(int counter = 0; counter < num; counter++) {
    if (strcmp(games[counter].name,selecInput) == 0) {
      cout << "Index " << counter << ": ";
      printGames(cout, games[counter]);
    }
  }
}

void printGamesToScreen(int num, videogametype games[]) {
  for (int index = 0; index < num; index++) {
        cout << "Index " << index << ": ";
        printGames(cout, games[index]);
  }
}




videogametype readGame(ifstream &inFile){
    videogametype game; 
    inFile.get(game.name, videogametype::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> game.numSales;
    inFile.ignore(100,';');
    inFile.get(game.platform, videogametype::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile.get(game.releaseDate, videogametype::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile.get(game.developer, videogametype::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile.get(game.publisher, videogametype::MAX_CHAR_LEN, '\n');
    inFile.ignore(100,'\n');

    return game;
}



int readGameData(videogametype example[]) {
  ifstream gameFile("videogamesOriginal.txt");
  int numGames = 0;
  while(gameFile.peek() != EOF && numGames < 99) {
      example[numGames] = readGame(gameFile);
      numGames++;
  }
  return numGames;
}




int main() {
  videogametype games[100];
  int num = readGameData(games);
  printGamesToScreen(num, games);
  addGame(games);
  printGamesToScreen(num, games);
  // searchGameByName(num, games);
  // searchGameByDeveloper(num, games);
  // searchGameByPlatform(num, games);
  // searchGameByPublisher(num, games);
}