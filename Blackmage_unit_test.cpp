#include <gtest/gtest.h>       // Include Google Test framework header
#include "BlackMage.h"         // Include the header for the BlackMage class
#include "Player.h"            // Include the header for the Player class
#include <string>              // Include string library
using namespace std;           // Use the standard namespace

// Mock Player class for testing purposes
class MockPlayer : public Player {
public:
    MOCK_METHOD(void, someMethod, (), (override)); // Mock a method from the Player class
    // Add other necessary mock methods
};

// Test default constructor
TEST(BlackMageTest, DefaultConstructor) {
    BlackMage blackMage;                                    // Create an instance using the default constructor
    EXPECT_EQ(blackMage.dark_bolt_damage, 0);               // Check if dark_bolt_damage is initialized to 0
    EXPECT_EQ(blackMage.dark_storm_damage, 0);              // Check if dark_storm_damage is initialized to 0
    EXPECT_EQ(blackMage.creeping_death_damage, 0);          // Check if creeping_death_damage is initialized to 0
    EXPECT_EQ(blackMage.shadow_counter, 0);                 // Check if shadow_counter is initialized to 0
    EXPECT_EQ(blackMage.shadow_duration, 0);                // Check if shadow_duration is initialized to 0
}

// Test parameterized constructor
TEST(BlackMageTest, ParameterizedConstructor) {
    string name = "BlackMageName";                          // Define a name for the BlackMage
    BlackMage blackMage(name);                              // Create an instance using the parameterized constructor
    EXPECT_EQ(blackMage.dark_bolt_damage, 0);               // Check if dark_bolt_damage is initialized to 0
    EXPECT_EQ(blackMage.dark_storm_damage, 0);              // Check if dark_storm_damage is initialized to 0
    EXPECT_EQ(blackMage.creeping_death_damage, 0);          // Check if creeping_death_damage is initialized to 0
    EXPECT_EQ(blackMage.shadow_counter, 0);                 // Check if shadow_counter is initialized to 0
    EXPECT_EQ(blackMage.shadow_duration, 0);                // Check if shadow_duration is initialized to 0
    // Add more checks as per actual constructor implementation
}

// Test get_shadow_duration method
TEST(BlackMageTest, GetShadowDuration) {
    BlackMage blackMage;                                    // Create a BlackMage instance
    blackMage.shadow_duration = 10;                         // Set shadow_duration to 10
    EXPECT_EQ(blackMage.get_shadow_duration(), 10);         // Check if get_shadow_duration() returns 10
}

// Mock methods to test ability methods
TEST(BlackMageTest, Ability1) {
    BlackMage blackMage;                                    // Create a BlackMage instance
    MockPlayer player;                                      // Create a MockPlayer instance
    EXPECT_CALL(player, someMethod())                       // Set expectation for someMethod() to be called
        .Times(1);                                          // Expect it to be called exactly once
    // Add the specific checks and method calls here
    blackMage.ability1(&player, 10);                        // Call ability1 with the player and a cost of 10
}

TEST(BlackMageTest, Ability2) {
    BlackMage blackMage;                                    // Create a BlackMage instance
    MockPlayer player;                                      // Create a MockPlayer instance
    EXPECT_CALL(player, someMethod())                       // Set expectation for someMethod() to be called
        .Times(1);                                          // Expect it to be called exactly once
    // Add the specific checks and method calls here
    blackMage.ability2(&player, 20);                        // Call ability2 with the player and a cost of 20
}

TEST(BlackMageTest, Ability3) {
    BlackMage blackMage;                                    // Create a BlackMage instance
    MockPlayer player;                                      // Create a MockPlayer instance
    EXPECT_CALL(player, someMethod())                       // Set expectation for someMethod() to be called
        .Times(1);                                          // Expect it to be called exactly once
    // Add the specific checks and method calls here
    blackMage.ability3(&player, 30);                        // Call ability3 with the player and a cost of 30
}

// Add similar tests for set_subclass_attributes, get_subclass_attributes

// Main function for Google Test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);                 // Initialize Google Test framework
    return RUN_ALL_TESTS();                                 // Run all the tests
}
