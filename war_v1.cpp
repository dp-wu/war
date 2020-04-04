/*
Yvette Wu
programming_ex7.7 - war3.cpp

c++ war3.cpp -o war3
./war3
*/

#include <iostream>
using namespace std;

#include <ctime>
#include <cstdlib>
#include <cctype>
#include <string>


// getting the suits
string suits(int a) {
  switch (a) {
    case 0:
      return "Spades";
    case 1:
      return "Diamonds";
    case 2:
      return "Harts";
    case 3:
      return "Clubs";
    default:
      return "Something went wrong in the suits clause.";
  }
}

// getting the jqka
string nums(int b) {
  switch (b) {
    case 11:
      return "Jack";
    case 12:
      return "Queen";
    case 13:
      return "King";
    case 14:
      return "Ace";
    default:
      return std::to_string(b);
  }
}

// game play
int game() {
  int compNum, humanNum, compSuit, humanSuit, result;
  string ncompNum, nhumanNum, ncompSuit, nhumanSuit, win;

  srand(time(0));
  compNum = rand() % 13 + 2;
  compSuit = rand() % 4;
  humanNum = rand() % 13 + 2;
  humanSuit = rand() % 4;

  if (compNum == humanNum) {
    win =  "It's a tie.";
    result = 0;
  }
  else if (compNum > humanNum) {
    win = "Computer wins!";
    result = -1;
  }
  else if (humanNum > compNum) {
    win = "Human wins!";
    result = 1;
  }

  ncompNum = nums(compNum);
  ncompSuit = suits(compSuit);
  nhumanNum = nums(humanNum);
  nhumanSuit = suits(humanSuit);

  cout << "Computer's card is a " << ncompSuit << " of " << ncompNum << endl;
  cout << "Human's card is a " << nhumanSuit << " of " << nhumanNum << endl;
  cout << "--<< " << win << " >>--" << endl;

  return result;
}

// get the results of the multiple rounds and ask to play again
int main() {
  int compCounter = 0, humanCounter = 0;
  int result;
  char playAgain;

  // replay is playagain
  do {
    // calculate the cummulative results
    result = game();
    if (result == 1) {
      humanCounter += 1;
    }
    else if (result == -1) {
      compCounter += 1;
    }
    cout << "Computer wins: " << compCounter << ", Human wins: " << humanCounter << endl;

    // ask if play again
    while (1) {
      cout << "Continue? [Y/N] ";
      cin >> playAgain;
      cin.ignore(1000, 10);
      playAgain = toupper(playAgain);

      if (playAgain == 'Y' or playAgain == 'N') {
        break;
      }
    }
    if (playAgain == 'N') {
      break;
    }
  } while (1);

  return 0;
}
