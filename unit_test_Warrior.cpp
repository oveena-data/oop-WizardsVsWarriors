#include <iostream>
#include "Warrior.h"
#include "Barbarian.h"

class WarriorUnitTest {
public:
    void runTests() {
        testSubclass();
        testStamina();
    }

    void testSubclass() {
        Barbarian warrior;
        if (warrior.get_subclass() != "Barbarian") {
            std::cout << "Subclass test failed!" << std::endl;
        }
    }

    void testStamina() {
        Barbarian warrior("Barbarian");
        warrior.set_stamina(75);
        if (warrior.get_stamina() != 75) {
            std::cout << "Stamina test failed!" << std::endl;
        }
    }
};

int main() {
    WarriorUnitTest warriorTest;
    warriorTest.runTests();
    return 0;
}
