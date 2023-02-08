// Created by Andrew Asplund
// Date: 02/07/2023
// Revision: 1.0

#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include "DuelingJP.h"

using std::cout;
using std::cin;
using std::endl;
using std::move;

const int TEST_SIZE = 5;
const int TEST_COUNT = 3;
const int TEST_ARRAYS[TEST_COUNT][TEST_SIZE] =
        {{2488, 2489, 2490, 2505, 2509},
         {5000, 5000, 5000, 5000, 5000},
         {5045, 5055, 5065, 5080, 5085}};
const int COLLISION_RESULTS[TEST_COUNT] = {3, 4, 0};
const int INVERSION_RESULTS[TEST_COUNT] = {6, 0, 4};


void printInputData(const int testArray[], int size) {
    cout << "Test array values" << endl;
    for (int i = 0; i < size; i++) {
        cout << testArray[i] << " ";
    }
    cout << endl;
}

// collisionTest tests the collision counting capacity of a DuelingJP object
void collisionTest(DuelingJP testJP, const int assertedResult) {

    cout << "Test Object has size of " << testJP.getSize() << endl;
    cout << "Asserted test results: " << assertedResult << endl;
    cout << "Collision Test (up) results in " << testJP.countCollisions()
        << " collisions." << endl;
    cout << "Collision Test (down) results in " << testJP.countCollisions(false)
        << " collisions." << endl;
    cout << "Note: These should be the same." << endl;

}

// inversionTest tests the inversion counting capacity of a DuelingJP object.
void inversionTest(DuelingJP testJP, const int assertedResult) {
    cout << "Test Object has size of " << testJP.getSize() << endl;
    cout << "Asserted test results: " << assertedResult << endl;
    cout << "Inversion Test results in " << testJP.countInversions()
        << " inversions." << endl;
}

/// testDJPMethods runs a series of tests on sample DuelingJP objects.
/// Tests include testing the collision counter and the inversion counter.
void testDJPMethods() {

    cout << endl << endl;

    cout << "DuelingJP Method Tests" << endl;

    // creating new objects for collision tests
    for (int i = 0; i < TEST_COUNT; i++) {
        cout << "COLLISION TESTS" << endl;
        cout << "** ** ** ** ** ** ** ** **" << endl;
        cout << "Test #" << i << ": Creating DJP" << endl;
        printInputData(TEST_ARRAYS[i], TEST_SIZE);
        DuelingJP testObject(TEST_ARRAYS[i], TEST_SIZE);
        collisionTest(testObject, COLLISION_RESULTS[i]);
        cout << endl;
    }

    // creating new objects for inversion tests
    for (int i = 0; i < TEST_COUNT; i++) {
        cout << "INVERSION TESTS" << endl;
        cout << "** ** ** ** ** ** ** ** **" << endl;
        cout << "Test #" << i << ": Creating DJP" << endl;
        printInputData(TEST_ARRAYS[i], TEST_SIZE);
        DuelingJP testObject(TEST_ARRAYS[i], TEST_SIZE);
        inversionTest(testObject, INVERSION_RESULTS[i]);
        cout << endl;
    }

}

/// moveConstructorTest returns a DuelingJP test for the purposes of
/// testing the move constructor.
/// @return a DuelingJP object
DuelingJP moveConstructorTest(){

    cout << "Instancing unique DuelingJP Object within sub-function." << endl;
    DuelingJP newJP(TEST_ARRAYS[0], TEST_SIZE);
    cout << "newJP has size " << newJP.getSize() << endl;
    cout << "newJP has collision count of " << newJP.countCollisions() << endl;
    cout << "newJP has inversion count of " << newJP.countInversions() << endl;
    cout << "Handing off newJP to parent function." << endl;
    return newJP;
}

/// testUniquePtr tests unique pointers and the move constructor of the
/// DuelingJP object using the && rvalue reference declarator.
void testUniquePtr() {
    cout << endl << endl;
    cout << "Testing move methods." << endl;
    cout << "** ** ** ** ** ** ** ** **" << endl;

    std::unique_ptr<DuelingJP> testJP;

    // wrap rvalue DuelingJP in unique ptr, uses move constructor
    testJP = std::make_unique<DuelingJP>(moveConstructorTest());


    // verify testJP has same content
    cout << "Obtained testJP from child function." << endl;
    cout << "testJP points to " << &testJP << endl;
    cout << "testJP has size " << testJP->getSize() << endl;
    cout << "testJP has collision count of " << testJP->countCollisions() << endl;
    cout << "testJP has inversion count of " << testJP->countInversions() << endl;

    cout << "Moving testJP to new unique ptr." << endl;
    std::unique_ptr<DuelingJP> newJP;

    // this actually just moves the pointer, not the object.
    newJP = std::move(testJP);
    if (testJP == nullptr) {
        cout << "testJP now pointing to null pointer." << endl;
    } else {
        cout << "testJP now pointing to " << &testJP << "." << endl;
    }
    cout << "newJP points to " << &newJP << endl;
    cout << "newJP has size " << newJP->getSize() << endl;
    cout << "newJP has collision count of " << newJP->countCollisions() << endl;
    cout << "newJP has inversion count of " << newJP->countInversions() << endl;

}

// sharedTest tests using shared pointers. A new DuelingJP object is created
// using a shared pointer. Then, two additional shared pointers are created
// pointing to the same object. The two shared pointers are de-scoped and
// the first shared pointer is re-examined.
void sharedTest() {
    cout << endl << endl;
    cout << "Creating new DuelingJP object with shared pointers." << endl;
    cout << "** ** ** ** ** ** ** ** **" << endl;

    std::shared_ptr<DuelingJP> djp1 =
            std::make_shared<DuelingJP>(DuelingJP(TEST_ARRAYS[0], TEST_SIZE));

    cout << "djp1 has size " << djp1->getSize() << " and "
         << djp1->countCollisions() << " collisions." << endl;

    cout << "djp1 reports " << djp1.use_count() << " shared pointers." << endl;
    {
        cout << "Creating new shared pointers djp2 and djp3." << endl;

        std::shared_ptr<DuelingJP> djp2 = djp1;
        std::shared_ptr<DuelingJP> djp3 = djp1;

        cout << "djp2 has size " << djp2->getSize() << " and "
             << djp2->countCollisions() << " collisions." << endl;
        cout << "djp3 has size " << djp3->getSize() << " and "
             << djp3->countCollisions() << " collisions." << endl;

        cout << "djp1 reports " << djp1.use_count() << " shared pointers." << endl;
        cout << "De-scoping djp2 and djp3." << endl;

    }

    cout << "djp1 has size " << djp1->getSize() << " and "
         << djp1->countCollisions() << " collisions." << endl;
    cout << "djp1 reports " << djp1.use_count() << " shared pointers." << endl;

}

/// moveVectorTest creates a vector of three DuelingJP objects and deletes
/// the first element in order to test the move assignment operator of the
/// DuelingJP object. This is due to the fact that the STL Vector uses
/// move assignment operators when moving elements internally.
void moveVectorTest() {

    cout << endl << endl;

    cout << "Testing DuelingJP objects in a STL Vector" << endl;
    cout << "** ** ** ** ** ** ** ** **" << endl;

    std::vector<DuelingJP> coolVector;

    // add three duelingJPs to the vector. This actually uses the internal
    // move constructor in the process of making new DuelingJP objects.
    coolVector.emplace_back(TEST_ARRAYS[0], TEST_SIZE);
    coolVector.emplace_back(TEST_ARRAYS[1], TEST_SIZE);
    coolVector.emplace_back(TEST_ARRAYS[2], TEST_SIZE);

    cout << "STL Vector now has size " << coolVector.size() << endl;
    for (int i = 0; i < (int)coolVector.size(); i++) {
        cout << "Element " << i << " has size " << coolVector[i].getSize()
            << " and " << coolVector[i].countCollisions() << " collisions " << endl;
    }

    cout << "Deleting the first element of the STL Vector to test " << endl;
    cout << "the DuelingJP move assignment operator." << endl;

    // vectors move stuff using move assignment operators, so this
    // will test the move assignment operator.
    coolVector.erase(coolVector.begin());

    cout << "STL Vector now has size " << coolVector.size() << endl;
    for (int i = 0; i < (int)coolVector.size(); i++) {
        cout << "Element " << i << " has size " << coolVector[i].getSize()
             << " and " << coolVector[i].countCollisions() << " collisions " << endl;
    }

}

int main() {

    cout << "The following are tests of the DuelingJP class.";

    // test the actual methods of the DuelingjP object
    testDJPMethods();

    // test creating a unique pointer w/ move constructor
    testUniquePtr();

    // test shared pointer
    sharedTest();

    // vector test
    moveVectorTest();

    return 0;


}
