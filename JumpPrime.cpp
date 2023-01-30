//
// Created by Andrew Asplund on 1/22/23.
//

#include "JumpPrime.h"

/**
 * isPrime determines whether or not the given positive integer is a prime
 * number or not (i.e., a whole number greater than one that cannot be exactly
 * divided by any whole number other than itself)
 * @param testNumber the positive integer to test
 * @return true if the number is prime, false otherwise
 */
bool JumpPrime::isPrime(unsigned int testNumber) {

    for (unsigned int i = 2; i < testNumber; i++) {
        if (testNumber % i == 0) {
            return false;
        }
    }

    return true;
}

/**
 * findPrime finds either the next nearest prime number or the previous nearest
 * prime number in sequence, depending on the value of the passed parameter.
 * @param startValue the positive integer to start the search from
 * @param findNext true to return the next prime number in sequence, false to
 * return the previous prime number in sequence.
 * @return the next (or previous) positive prime integer within the bounds of
 * the unsigned integer date type
 */
unsigned int JumpPrime::findPrime(unsigned int startValue, bool findNext) {
    // determine if this needs to count up or down
    int stepValue = findNext ? 1 : -1;

    unsigned int result = startValue + stepValue;

    while (!isPrime(result)) {
        result = result + stepValue;
    }

    return result;
}


/**
 * setPrimeLimits finds a new upper and lower prime number based on the
 * established stored number (mainNumber).
 */
void JumpPrime::setPrimeLimits() {

    upperPrime = findPrime(mainNumber, true);
    lowerPrime = findPrime(mainNumber, false);

}

/**
 * resetQueryCounter sets the new query limits (based on the distance between
 * the next and previosu prime number) and resets the query counter to 0.
 */
void JumpPrime::resetQueryCounter() {
    queryLimit = upperPrime - lowerPrime;
    queryCount = 0;
}

/**
 * jumpNumber "jumps" the value of the stored number, mainNumber, by a
 * specified amount. After a set number of "jumps", the JumpPrime will deactive.
 * @param jumpValue the value (positive or negative) to "jump" the stored
 * number by.
 */
void JumpPrime::jumpNumber(int jumpValue) {

    // initiate the jump
    mainNumber = mainNumber + jumpValue;

    setPrimeLimits();
    resetQueryCounter();

    jumpCount++;

    // test to see if JumpPrime object has reached the jump limit
    if (jumpCount >= jumpLimit) {
        // turn off the object
        currentState = Inactive;

    }
}

JumpPrime::JumpPrime(unsigned int initValue, unsigned int jumpBound) {

    // less than four digits
    if (initValue < 1000) {
        currentState = Failed;

    }
    // otherwise, proceed with initialization
    else {
        currentState = Active;
        jumpLimit = jumpBound;
        initialNumber = initValue;
        this->reset();
    }
}

/**
 * up returns the next highest prime number from the number stored in the
 * JumpPrime object. Does not return accurate results if the JumpPrime object
 * has been deactivated.
 * PRECONDITION: the JumpPrime object is running.
 * @return the next highest prime number. If the JumpPrime object has been
 * deactivated, returns 0.
 */
unsigned int JumpPrime::up() {
    if (currentState == Active) {
        // storing the upper prime in the case that the object jumps
        // after this query
        unsigned int returnValue = upperPrime;

        queryCount++;

        if (queryCount >= queryLimit) {
            jumpNumber(upperPrime - DEFAULT_JUMP_VALUE);

        }

        return returnValue;
    }
    return 0;
}

/**
 * down returns the next lowest prime number from the number stored in the
 * JumpPrime object. Does not return accurate results if the JumpPrime object
 * has been deactivated.
 * PRECONDITION: the JumpPrime object is running.
 * @return the next lowest prime number. If the JumpPrime object has been
 * deactivated, returns 0.
 * @return
 */
unsigned int JumpPrime::down() {
    if (currentState == Active) {
        // storing the upper prime in the case that the object jumps
        // after this query
        unsigned int returnValue = lowerPrime;

        queryCount++;

        if (queryCount >= queryLimit) {
            jumpNumber(lowerPrime - DEFAULT_JUMP_VALUE);
        }

        return returnValue;
    }
    return 0;
}


/**
 * Reset attempts to reset the JumpPrime object to the original integer value.
 * This will fail if the JumpPrime object was already made irreparable.
 * PRECONDITION: the JumpPrime object is not permanently deactivated.
 * @return true if the reset is successful, false otherwise.
 */
bool JumpPrime::reset() {
    if (currentState == Failed) {
        return false;
    }

    else {
        currentState = Active;
        mainNumber = initialNumber;

        setPrimeLimits();
        resetQueryCounter();

        jumpCount = 0;

        return true;
    }
}

/**
 * Revive attempts to revive a disabled JumpPrime object. This resets the
 * query and jump count and allows the object to be queried again. If the
 * object is already active, it permanently disables the object (makes it
 * irreparable).
 * PRECONDITION: the JumpPrime object is not currently active.
 * @return true if the attempt to revive the object was successful. false
 * otherwise.
 */
bool JumpPrime::revive() {
    // object is not running and is not permanently broken
    if (currentState == Inactive) {
        // revive the object
        currentState = Active;
        jumpCount = 0;
        queryCount = 0;
    }
    // in any other case
    else {
        // revive permanently disables the object
        currentState = Failed;
    }

    return (currentState == Active);
}

/**
 * IsActive returns whether or not the JumpPrime object has been deactivated
 * due to excessive jumps.
 * @return true if currently active, false otherwise
 */
bool JumpPrime::isActive() {
    return (currentState == Active);
}

/**
 * IsDeactivated returns whether or not the JumpPrime object has been
 * permanently deactivated due to improper operation.
 * @return true if the JumpPrime object has been permanently disabled,
 * false otherwise.
 */
bool JumpPrime::isDisabled() {
    return (currentState == Failed);
}

/**
 * GetCurrentValue returns the current value encapsulated by the JumpPrime
 * object. When the object is instantiated (or reset), this is the initial
 * set value. After a jump, this is the new jumped-to value.
 * @return the current value encapsulated by the JumpPrime object.
 */
unsigned int JumpPrime::getCurrentValue() {
    return mainNumber;
}










