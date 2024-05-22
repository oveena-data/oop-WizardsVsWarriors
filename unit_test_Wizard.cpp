#include <iostream>
#include "Wizard.h"
#include "FireWizard.h"
#include "WaterWizard.h"

class WizardUnitTest {
public:
    void runTests() {
        testSubclass();
        testMana();
    }

    void testSubclass() {
        FireWizard wizard;
        if (wizard.get_subclass() != "Fire Wizard") {
            std::cout << "Subclass test failed!" << std::endl;
        }
    }

    void testMana() {
        WaterWizard wizard;
        wizard.set_mana(80);
        if (wizard.get_mana() != 80) {
            std::cout << "Mana test failed!" << std::endl;
        }
    }
};

int main() {
    WizardUnitTest wizardTest;
    wizardTest.runTests();
    return 0;
}
