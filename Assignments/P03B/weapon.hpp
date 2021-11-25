#include <iostream>
#include <string>
#include <vector>
#include "dice.hpp"
#include "helpers.hpp"
using namespace std;
#pragma once

class baseWeapon {
  protected:
    string name;    // name of weapon
    string damage;  // damage per roll or "use"
    Dice* die;
    string form;

 public:
  /**
   * @brief Construct a new Base Weapon object
   *  Also invokes the Dice class constructor with the "die" type
   */
  baseWeapon() {
    name = "Fists & Feet";
    damage = "1.d.4";
    die = new Dice(damage);
    form = "formless";
  }

  /**
  * @brief Overloaded Constructor for a new Base Weapon object
  *  Also invokes the Dice class constructor with the "die" type
  * @param choices-vector of string "die" choices like
  * {"2.d.8","2.d.10","3.d.4"}
   */
  baseWeapon(vector<string> choices) {
    name = "Fists & Feet";
    damage = randomChoice(choices);
    die = new Dice(damage);
    form = "formless";
  }

  baseWeapon(string n, vector<string> choices) {
    // name-> /*points at the name of the weapon*/;
    damage = randomChoice(choices);
    die = new Dice(damage);
    form = n;
  }

  double use() { return die->roll(); }

  friend ostream& operator<<(ostream& os, const baseWeapon& w) {
    // this for debugging
    return os << "(" << w.name << ", " << w.damage << ", " << w.form << ")";
  }

};



class Sword: public baseWeapon
{
  public:
    Sword()
    {
      name = "Dagmor";
      damage = "4.d.8";
      die = new Dice(damage); 
      form ="Melee";
    }

};


class staff:public baseWeapon
{ 
  public:
  staff()
  {
    name ="Tööajd";
    damage = "5.d.10";  //  4 - 6 hp 
    die  = new Dice(damage);
    form = "Magic";
  }

};


class bow: public baseWeapon
{
  public:
  bow()
  {
    name ="shotgun bow";
    damage= "3.d.6"; //  
    die =  new Dice(damage);
    form = "Bow"; 
    
  }
};

class Dragontooth:  public baseWeapon
{
  public:
  Dragontooth()
  {
    name ="Dragontooth sword";
    damage = "1.d.9"; //  
    die = new  Dice(damage);
    form = "Massive tooth";
  }
};


class rainbow: public baseWeapon{
  public:
  rainbow()
  {
    name = "Rainbow power";
    damage = "5.d.10";
    die = new Dice(damage);
    form = "Elf power";
  }
};



/*
Update the power size on the weapons
*/