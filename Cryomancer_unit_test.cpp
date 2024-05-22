#include <gtest/gtest.h>       // Include Google Test framework header
#include "Cryomancer.h"        // Include the header for the Cryomancer class
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
TEST(CryomancerTest, DefaultConstructor) {
    Cryomancer cryomancer;                                  // Create an instance using the default constructor
    EXPECT_EQ(cryomancer.ice_spike_damage, 0);              // Check if ice_spike_damage is initialized to 0
    EXPECT_EQ(cryomancer.arctic_storm_damage, 0);           // Check if arctic_storm_damage is initialized to 0
    EXPECT_EQ(cryomancer.ice_nova_damage, 0);               // Check if ice_nova_damage is initialized to 0
    EXPECT_EQ(cryomancer.ice_armour_counter, 0);            // Check if ice_armour_counter is initialized to 0
    EXPECT_EQ(cryomancer.blizzard_counter, 0);              // Check if blizzard_counter is initialized to 0
    EXPECT_EQ(cryomancer.ice_armour_duration, 0);           // Check if ice_armour_duration is initialized to 0
    EXPECT_EQ(cryomancer.blizzard_duration, 0);             // Check if blizzard_duration is initialized to 0
}

// Test parameterized constructor
TEST(CryomancerTest, ParameterizedConstructor) {
    string name = "CryomancerName";                         // Define a name for the Cryomancer
    Cryomancer cryomancer(name);                            // Create an instance using the parameterized constructor
    EXPECT_EQ(cryomancer.ice_spike_damage, 0);              // Check if ice_spike_damage is initialized to 0
    EXPECT_EQ(cryomancer.arctic_storm_damage, 0);           // Check if arctic_storm_damage is initialized to 0
    EXPECT_EQ(cryomancer.ice_nova_damage, 0);               // Check if ice_nova_damage is initialized to 0
    EXPECT_EQ(cryomancer.ice_armour_counter, 0);            // Check if ice_armour_counter is initialized to 0
    EXPECT_EQ(cryomancer.blizzard_counter, 0);              // Check if blizzard_counter is initialized to 0
    EXPECT_EQ(cryomancer.ice_armour_duration, 0);           // Check if ice_armour_duration is initialized to 0
    EXPECT_EQ(cryomancer.blizzard_duration, 0);             // Check if blizzard_duration is initialized to 0
    // Add more checks as per actual constructor implementation
}

// Test get_ice_armour_duration method
TEST(CryomancerTest, GetIceArmourDuration) {
    Cryomancer cryomancer;                                  // Create a Cryomancer instance
    cryomancer.ice_armour_duration = 15;                    // Set ice_armour_duration to 15
    EXPECT_EQ(cryomancer.get_ice_armour_duration(), 15);    // Check if get_ice_armour_duration() returns 15
}

// Test get_blizzard_duration method
TEST(CryomancerTest, GetBlizzardDuration) {
    Cryomancer cryomancer;                                  // Create a Cryomancer instance
    cryomancer.blizzard_duration = 20;                      // Set blizzard_duration to 20
    EXPECT_EQ(cryomancer.get_blizzard_duration(), 20);      // Check if get_blizzard_duration() returns 20
}

// Mock methods to test ability methods
TEST(CryomancerTest, Ability1) {
    Cryomancer cryomancer;                                  // Create a Cryomancer instance
    MockPlayer player;                                      // Create a MockPlayer instance
    EXPECT_CALL(player, someMethod())                       // Set expectation for someMethod() to be called
        .Times(1);                                          // Expect it to be called exactly once
    // Add the specific checks and method calls here
    cryomancer.ability1(&player, 10);                       // Call ability1 with the player and a cost of 10
}

TEST(CryomancerTest, Ability2) {
    Cryomancer cryomancer;                                  // Create a Cryomancer instance
    MockPlayer player;                                      // Create a MockPlayer instance
    EXPECT_CALL(player, someMethod())                       // Set expectation for someMethod() to be called
        .Times(1);                                          // Expect it to be called exactly once
    // Add the specific checks and method calls here
    cryomancer.ability2(&player, 20);                       // Call ability2 with the player and a cost of 20
}

TEST(CryomancerTest, Ability3) {
    Cryomancer cryomancer;                                  // Create a Cryomancer instance
    MockPlayer player;                                      // Create a MockPlayer instance
    EXPECT_CALL(player, someMethod())                       // Set expectation for someMethod() to be called
        .Times(1);                                          // Expect it to be called exactly once
    // Add the specific checks and method calls here
    cryomancer.ability3(&player, 30);                       // Call ability3 with the player and a cost of 30
}

TEST(CryomancerTest, Ability4) {
    Cryomancer cryomancer;                                  // Create a Cryomancer instance
    MockPlayer player;                                      // Create a MockPlayer instance
    EXPECT_CALL(player, someMethod())                       // Set expectation for someMethod() to be called
        .Times(1);                                          // Expect it to be called exactly once
    // Add the specific checks and method calls here
    cryomancer.ability4(&player, 40);                       // Call ability4 with the player and a cost of 40
}

// Add similar tests for set_subclass_attributes, get_subclass_attributes

// Main function for Google Test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);                 // Initialize Google Test framework
    return RUN_ALL_TESTS();                                 // Run all the tests
}
