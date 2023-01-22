#include <iostream>
#include "JumpPrime.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    JumpPrime newJumper(2488);

    cout << "newJumper value: " << newJumper.getCurrentValue() << endl;
    cout << "up value: " << newJumper.up() << endl;
    cout << "down value: " << newJumper.down() << endl;

    return 0;
}
