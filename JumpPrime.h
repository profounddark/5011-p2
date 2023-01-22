//
// Created by Andrew Asplund on 1/22/23.
//

#ifndef INC_5011_P2_JUMPPRIME_H
#define INC_5011_P2_JUMPPRIME_H

/**
 * The JumpPrime> object encapsulates a positive integer that must be at
 * least 4 digits long. The user can query for the object for the two nearest
 * Prime numbers (either higher or lower). After a set number of queries (based
 * on the distance between the base integer and the farther of the two nearest
 * primes), the JumpPrime object will "jump" to a new base number a set
 * distance from the original number. New queries as to the nearest prime
 * number will be based on this new number.
 *
 * After a set number of "jumps", the <c>JumpPrime</c> object will deactivate.
 * It can be reactivated resetting the base number to the original encapsulated
 * positive integer.
 *
 * DESIGN ASSUMPTIONS:
 * 1. When the JumpPrime object jumps, it jumps in the direction of the last
 * query. If it jumps after an `up` call, the jump is positive in direction.
 * If it jumps after a 'down' call, the jump is negative in direction.
 * 2. When the JumpPrime object jumps, it jumps a specified magnitude past
 * the next prime. For a jump in the positive direction, it jumps to the
 * next higher prime plus the default jump value. For a jump in the negative
 * direction, it jumps to the next lower prime minus the default jump value.
 * 3. The default jump value is specified as a class constant (here, 100).
 */
class JumpPrime {

    // class constants
    static const unsigned int DEFAULT_JUMP_BOUND = 10;
    static const unsigned int DEFAULT_INITIAL_VALUE = 9999;
    static const int DEFAULT_JUMP_VALUE = 100;

    unsigned int initialNumber;
    unsigned int mainNumber;

    bool isRunning;
    bool isBroken;

    int queryCount;
    int queryLimit;

    int jumpCount;
    int jumpLimit;

    unsigned int upperPrime;
    unsigned int lowerPrime;

    bool isPrime(unsigned int testNumber);
    unsigned int findPrime(unsigned int startValue, bool findNext);
    void setPrimeLimits();
    void resetQueryCounter();
    void jumpNumber(int jumpValue);

public:
    JumpPrime(unsigned int initValue = DEFAULT_INITIAL_VALUE,
              unsigned int jumpBound = DEFAULT_JUMP_BOUND);
    unsigned int up();
    unsigned int down();

    bool reset();
    bool revive();

    bool isActive();
    bool isDisabled();

    unsigned int getCurrentValue();





};


#endif //INC_5011_P2_JUMPPRIME_H
