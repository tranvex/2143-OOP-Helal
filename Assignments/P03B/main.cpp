 /*
Main To do list 
  - make a new for figthers weapon list 
  - create  better dice 
  
*/

#include <iostream>
#include <vector>
#include <string>
#include "dice.hpp"
#include "fighter.hpp"
#include "weapon.hpp"
#include "json.hpp"
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;







int main() {
  srand(time(0));

  // Warrior f9;
  // cout << endl;
  // cout << f9 << endl;
  // cout << "attack: " << f9.attack() << endl;
  // cout << "Health: " << f9.health();

  // cout << endl;

  // Wizard f10;
  // cout << endl;
  // cout << f10 << endl;
  // cout << "attack: " << f10.attack() << endl;
  // cout << "Health: " << f10.health() << endl;
  
  // //I did the damages for the characters
  // //I decided to give them the damage based off who is stronger
  // //so dragon born is pretty strong
  // //no meeting with griffin..
  


  // cout << endl;


  // Archer f6;
  // cout << endl;
  // cout << f6 << endl;
  // cout << "attack: " << f6.attack() << endl;
  // cout << "Health: " << f6.health();

  // cout << endl;

  // DragonBorn f7;
  // cout << endl;
  // cout << f7 << endl;
  // cout << "attack: " << f7.attack() << endl;
  // cout << "Health: " << f7.health();

  // cout  << endl;

  // Elf f8;
  // cout << endl;
  // cout << f8 << endl;
  // cout << "attack: " << f8.attack() << endl;
  // cout << "Health: " << f8.health();

  
 


  Matchup f4;
  f4.attack();

  cout << endl;
  cout << endl;
  cout << endl;

  f4.defend();




  cout << "This is the game loop" << endl;
  cout << endl;

  f4.fight();

  return 0;
}
