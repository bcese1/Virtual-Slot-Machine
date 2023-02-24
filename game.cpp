/* 
 * File:   game.cpp
 * Author: benja
 *
 * Created on March 9, 2021, 4:43 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include "Virtualslotmachine.hpp"
#include "Spin.hpp"
using namespace std;

/*
 * 
 */
void createpayoutpin()
{
  cout << "----------------------" << endl;
  cout << "| Payout Combination |" << endl;
  cout << "----------------------" << endl;
  cout << "|  ";
  cout << "A  A  A";
  cout << "  |";
  cout << "  $6";
  cout << "   |" << endl;
  cout << "|  ";
  cout << "B  B  B";
  cout << "  |";
  cout << "  $15";
  cout << "  |" << endl;
  cout << "|  ";
  cout << "C  C  C";
  cout << "  |";
  cout << "  $50";
  cout << "  |" << endl;
  cout << "|  ";
  cout << "7  7  7";
  cout << "  | ";
  cout << " $500";
  cout << " |" << endl;
  cout << "----------------------" << endl << endl;
}
void createVSM(int money, int pay, Virtualslotmachine* vsm)
{
    cout << "----------------" << endl;
    cout << "| Slot Machine |" << endl;
    cout << "----------------" << endl;
    cout << "|  " << vsm->getS1prev();
    cout << "   " << vsm->gets2prev();
    cout << "   " << vsm->gets3prev() << "  |" << endl;
    cout << "|> " << vsm->gets1();
    cout << "   " << vsm->gets2();
    cout << "   " << vsm->gets3() << " <|" << endl;
    cout << "|  " << vsm->gets1next();
    cout << "   " << vsm->gets2next();
    cout << "   " << vsm->gets3next() << "  |" << endl;
    cout << "----------------" << endl << endl;
}
class Game
{
public:
    void MainMenu(void)
    {
      cout << "Select an Option:" << endl;
      cout << "1. Pay $1 to play slot machine" << endl;
      cout << "2. Exit" << endl;

    }

    int UserInput (void)
    {
      int selection;
      cout << "\nEnter your selection: ";
      cin >> selection;
      return selection;
    }
};



int main (int argc, char** argv)
{
  int money = 100;
  int choice;
  const int pay = 1;
  Game Menu;
  Virtualslotmachine *vsm = new Virtualslotmachine();
  vsm->reel();
  cout << "Welcome to the Virtual Slot Machine" << endl;
  createpayoutpin ();
  cout << "Current Balance $" << money << endl;
  createVSM(money, pay, vsm);
  
  
  
  Menu.MainMenu ();
  choice = Menu.UserInput ();
  
  while(1)
    {
      switch(choice)
        {
        case 1:
        {
          system("CLS");
          
          if(money > 0)
            {
                vsm->reel();
                createpayoutpin();
                int payout = vsm->pay ();
                money = money - pay;
                
                cout << "Current Balance $" << money << endl;
                createVSM(money, pay, vsm);
                
                if(payout == 500)
                  {
                    cout << "JACKPOT!" << endl << endl;
                  }
                money = money + payout;
                cout << "Congratulations you just won $" << payout << endl;
                Menu.MainMenu ();
                choice = Menu.UserInput ();
            }
          else
            {
              cout << "Balance at $0. Exiting Game" <<endl;
              abort();
            }
          break;
        }  
        case 2:
          cout << "exit" << endl;
          abort();
          break;
          
        default:
          system("CLS");
          cout << "invalid entry. Please try again!\n" << endl;
          Menu.MainMenu ();
          choice = Menu.UserInput ();
        }
        
    }
}

