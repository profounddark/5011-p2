#include <iostream>
#include "JumpPrime.h"
#include "DuelingJP.h"

using std::cout;
using std::cin;
using std::endl;

int main() {


    int inputValueArray[5] = {5013, 2488, 2495, 3321, 8492};
    DuelingJP newDuel(inputValueArray, 5);

    cout << "Number of collisions: " << newDuel.countCollisions();
    return 0;


}
