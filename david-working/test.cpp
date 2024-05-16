#include<iostream>
using namespace std;

class Enemy {
    protected:
        int _health = 1;

    public:

        
        //Enemy();
        //Enemy(int health)
        //{
        //    _health = health;
        //}
        virtual int getHealth()
        {
            return _health;
            
        }
        virtual void setHealth(int new_health)
        {
            _health= new_health;
        }
        //int health = 10;
        //Enemy(int h) { cout << "Enemy health is: " << health << endl; }
        //Enemy()	 { cout << "Enemy::Enemy() called" << endl; }
        
        
};

class Sorcerer : virtual public Enemy {
    protected:
        int _mana = 20;
    public:
        
        
        virtual int getMana()
        {
            return _mana;
        }
        virtual void setMana(int new_mana)
        {
            _mana = new_mana;
        }
        /*
        Sorcerer(int m):Enemy()
        {

            cout<<"Sorcerer mana is: "<< mana << endl;
            
        }
        Sorcerer();
        */
};

class Raider : virtual public Enemy {
    protected: 
        int _stamina = 40;
    public:
        virtual int getStamina()
        {
            return _stamina;
        }
        virtual void setStamina(int new_stamina)
        {
            _stamina = new_stamina;
        }
        
        
};

class Cultist : virtual public Sorcerer {
    public:
        protected: 
        int _armour = 50;
    public:
        virtual int getArmour()
        {
            return _armour;
        }
        virtual void setArmour(int new_armour)
        {
            _armour = new_armour;
        }
};

class Headhunter : virtual public Raider {
    
    public:
        protected: 
        int _dexterity = 70;
    public:
        virtual int getDexterity()
        {
            return _dexterity;
        }
        virtual void setDexterity(int new_dexterity)
        {
            _dexterity = new_dexterity;
        }
};

class Opponent : public Cultist, public Headhunter {
    protected:
        string _name = "name";
    public:

        string getName()
        {
            return _name;
        }
        void setName(string new_name)
        {
            _name = new_name;
        }
};

int main() {

    Opponent* opponent = new Opponent();
    cout << "Old Enemy getHealth: " << opponent->getHealth() << endl;
    opponent->setHealth(2);
    cout << "New Enemy getHealth: " << opponent->getHealth() << endl;


    cout << "Old Sorcerer getMana: " << opponent->getMana() << endl;
    opponent->setMana(30);
    cout << "New Sorcerer getMana: " << opponent->getMana() << endl;

    cout << "Old Raider getStamina: " << opponent->getStamina() << endl;
    opponent->setStamina(100);
    cout << "New Raider getStamina: " << opponent->getStamina() << endl;

    cout << "Old Cultist getArmour: " << opponent->getArmour() << endl;
    opponent->setArmour(110);
    cout << "New Cultist getArmour: " << opponent->getArmour() << endl;

    cout << "Old Headhunter getDexterity: " << opponent->getDexterity() << endl;
    opponent->setDexterity(120);
    cout << "New Headhunter getDexterity: " << opponent->getDexterity() << endl;

    cout << "Old Opponent getName: " << opponent->getName() << endl;
    opponent->setName("Barry");
    cout << "New Opponent getName: " << opponent->getName() << endl;





    return 0;
}
/*
class Base {
public:
  // ...
protected:
  int data_;
};
class Der1 : public virtual Base {
                    ↑↑↑↑↑↑↑ // This is the key
public:
  // ...
};
class Der2 : public virtual Base {
                    ↑↑↑↑↑↑↑ // This is the key
public:
  // ...
};
class Join : public Der1, public Der2 {
public:
  void method()
  {
     data_ = 1;  // Good: this is now unambiguous
  }
};
int main()
{
  Join* j = new Join();
  Base* b = j;   // Good: this is now unambiguous
}
*/
