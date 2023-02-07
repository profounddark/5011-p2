#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include "DuelingJP.h"

using std::cout;
using std::cin;
using std::endl;
using std::move;




const int TEST_ARRAY_1[] = {2488, 2489, 2490, 2505, 2509};
const int COLLISION_RESULT_1 = 3;

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

void collisionTest(DuelingJP testJP, const int assertedResult) {

    cout << "Test Object has size of " << testJP.getSize() << endl;
    cout << "Asserted test results: " << assertedResult << endl;
    cout << "Collision Test (up) results in " << testJP.countCollisions()
        << " collisions." << endl;
    cout << "Collision Test (down) results in " << testJP.countCollisions(false)
        << " collisions." << endl;
    cout << "Note: These should be the same." << endl;

}

void inversionTest(DuelingJP testJP, const int assertedResult) {
    cout << "Test Object has size of " << testJP.getSize() << endl;
    cout << "Asserted test results: " << assertedResult << endl;
    cout << "Inversion Test results in " << testJP.countInversions()
        << " inversions." << endl;
}

void testDJPMethods() {
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
    cout << "Testing move methods." << endl;
    cout << "** ** ** ** ** ** ** ** **" << endl;

    std::unique_ptr<DuelingJP> testJP;

    // wrap rvalue DuelingJP in unique ptr, uses move constructor
    testJP = std::make_unique<DuelingJP>(moveConstructorTest());

    // verify testJP has same content
    cout << "Obtained testJP from child function." << endl;
    cout << "testJP has size " << testJP->getSize() << endl;
    cout << "testJP has collision count of " << testJP->countCollisions() << endl;
    cout << "testJP has inversion count of " << testJP->countInversions() << endl;

}

void vectorTest() {
    std::vector<DuelingJP> testVector;

    cout << "Adding new DuelingJP object to test vector." << endl;


    testVector.push_back(DuelingJP(TEST_ARRAYS[1], TEST_SIZE));

    cout << "First vector element has size " << testVector[0].getSize() << endl;
    cout << "First vector element has collision count "
        << testVector[0].countCollisions() << endl;

    cout << "Adding new DuelingJP object to front of vector." << endl;

    testVector.insert(testVector.begin(),
                      DuelingJP(TEST_ARRAYS[0], TEST_SIZE));

    cout << "Second element of vector has size " << testVector[1].getSize() << endl;
    cout << "Second element of vector has collision count "
        << testVector[1].countCollisions() << endl;




}

void uniqueMoveTest() {

    std::vector<std::unique_ptr<DuelingJP>> testVector;

    cout << "** ** ** ** ** ** ** ** **" << endl;
    cout << "Testing will now be done on the move methods of the DuelingJP"
        << " class." << endl;

    std::unique_ptr<DuelingJP> newJP(new DuelingJP(TEST_ARRAY_1, TEST_SIZE));

    cout << "newJP has size of " << newJP->getSize() << endl;
    cout << "newJP has collision count of " << newJP->countCollisions() << endl;

    cout << "Vector now has " << testVector.size() << " elements." << endl;
    cout << "moving newJP into vector." << endl;
    testVector.push_back(move(newJP));
    cout << "Test vector has " << testVector.size() << " elements." << endl;
    cout << "Last element has size of " << testVector.back()->getSize() << endl;
    cout << "Last element has collision count of " <<
        testVector.back()->countCollisions() << endl;

    if (newJP == nullptr) {
        cout << "newJP now pointing to null pointer." << endl;
    } else {
        cout << "newJP now pointing to " << newJP << "." << endl;
    }

    cout << endl;

    cout << "Moving element back into newJP." << endl;

    newJP = move(testVector.back());

    cout << "newJP has size of " << newJP->getSize() << endl;
    cout << "newJP has collision count of " << newJP->countCollisions() << endl;

    cout << "Test vector has " << testVector.size() << " elements." << endl;
    if (testVector.back() == nullptr) {
        cout << "Last element of test vector is pointing to null pointer." << endl;
    } else {
        cout << "Last element of test vector is pointing to "
            << testVector.back() << "." << endl;
    }


    cout << endl;


}

void testMoveSem() {

    cout << "** ** ** ** ** ** ** ** **" << endl;
    cout << "Testing will now be done on the move methods of the DuelingJP"
         << " class." << endl;

    cout << "Instancing a new DJP object." << endl;

    std::unique_ptr<DuelingJP> firstDJP(new DuelingJP(TEST_ARRAY_1, TEST_SIZE));
    cout << "The first pointer now points to ";
    if (firstDJP == nullptr) {
        cout << "a null pointer." << endl;
    } else {
        cout << firstDJP << "." << endl;
    }


    cout << "Moving the DJP object to a new unique pointer." << endl;

    std::unique_ptr<DuelingJP> secondDJP = move(firstDJP);

    cout << "The first pointer now points to ";
    if (firstDJP == nullptr) {
        cout << "a null pointer." << endl;
    } else {
        cout << firstDJP << "." << endl;
    }
    cout << "The second pointer now points to ";
    if (secondDJP == nullptr) {
        cout << "a null pointer." << endl;
    } else {
        cout << secondDJP << "." << endl;
    }




}



int main() {
    cout << "The following are tests of the DuelingJP class.";


    testDJPMethods();
    testUniquePtr();
    vectorTest();
    //uniqueMoveTest();
    //testMoveSem();

    return 0;


}
