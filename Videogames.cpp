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

void removeGame(videogametype game[]) {
  int index = 0;
  cout << "Enter the index you want to remove: ";
  cin >> index;
  cin.ignore();
  index = validInt(index);
  for (int counter = 0; counter < 100; counter++) {
    game[index].name[counter] = '\0';
    game[index].platform[counter] = '\0';
    game[index].releaseDate[counter] = '\0';
    game[index].developer[counter] = '\0';
    game[index].publisher[counter] = '\0';
  }
  game[index].numSales = 0;
}

void addGame(videogametype games[], int &num) {
  char temp[100];
  for (int index = 0; index < 100; index++) {
    temp[index] = '\0';
  }

  for (int index = 0; index < 100; index++) {
    if (strcmp(games[index].name,temp) == 0) {
      cout << "Enter the game's name: ";
      cin.getline(games[index].name, 100);
      cout << endl << "Enter the number of sales: ";
      cin >> games[index].numSales;
      games[index].numSales = validDouble(games[index].numSales);
      cin.ignore();
      cout << "Enter the platform: ";
      cin.getline(games[index].platform, 100);
      cout << "Enter the game's release Date (format: Month day, year): ";
      cin.getline(games[index].releaseDate, 100);
      cout << "Enter the game's developer: ";
      cin.getline(games[index].developer, 100);
      cout << "Enter the game's publisher: ";
      cin.getline(games[index].publisher, 100);
      num++;
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
  char selecInput[100];
  for (int index = 0; index < 100; index++) {
    selecInput[index] = '\0';
  }

  for (int index = 0; index < num; index++) {
    if(strcmp(games[index].name,selecInput) != 0) {
        cout << "Index " << index << ": ";
        printGames(cout, games[index]);
    }
    else {
      cout << endl;
    }
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

void printDataToFile(videogametype games[], int num) {
  ofstream outFile("videogames.txt");
    for (int index = 0; index < num; index++) {
        printGames(outFile, games[index]);
    }
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

void displayMenu(videogametype games[], int num){
  int option = 0;
  int perameter = 0;
  while (option != 7) {
    cout << endl << "1: Display the game list" << endl;
    cout << "2: Remove a game from the list" << endl;
    cout << "3: Add a game to the list" << endl;
    cout << "4: Search game by perameter" << endl;
    cout << "5: Reload original data" << endl;
    cout << "6: Save current data" << endl;
    cout << "7: Quit" << endl;
    cout << "Enter an option: ";
    cin >> option;
    cin.ignore();
    option = validInt(option);
  
    if(option == 1) {
      printGamesToScreen(num, games);
    }
    else if (option == 2) {
      removeGame(games);
    }
    else if (option == 3) {
     addGame(games, num);
    }
    else if (option == 4) {
      cout << "1) By Name" << endl;
      cout << "2) By platform" << endl;
      cout << "3) By developer" << endl;
      cout << "4) By publisher" << endl;
      cout << "Enter perameter: ";
      cin >> perameter;
      cin.ignore();
      perameter = validInt(perameter);
      if (perameter == 1) {
        searchGameByName(num, games);
      }
      else if (perameter == 2) {
        searchGameByPlatform(num, games);
      }
      else if (perameter == 3) {
        searchGameByDeveloper(num, games);
      }
      else if (perameter == 4) {
        searchGameByPublisher(num, games);
      }
      else {
        cout << "Invalid Option!!!";
      }
    }
    else if (option == 5) {
      readGameData(games);
    }
    else if (option == 6) {
      printDataToFile(games, num);
    }
    else if (option == 7) {
      break;
    }
    else {
      cout << "Invalid Option!!!";
    }
  }
}



int main() {
  videogametype games[100];
  int num = readGameData(games);
  displayMenu(games, num);
  cout << "Her";
}