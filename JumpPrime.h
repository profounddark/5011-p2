// Created by Andrew Asplund
// Date: 02/07/2023
// Revision: 2.0

#ifndef INC_5011_P2_JUMPPRIME_H
#define INC_5011_P2_JUMPPRIME_H

/*
 * The JumpPrime object encapsulates a positive integer that must be at
 * least 4 digits long. The user can query the object for the two nearest
 * Prime numbers (either higher or lower). After a set number of queries (based
 * on the distance between the base integer and the farther of the two nearest
 * primes), the JumpPrime object will "jump" to a new base number a set
 * distance from the original number. New queries as to the nearest prime
 * number will be based on this new number.
 *
 * After a set number of "jumps", the JumpPrime object will deactivate.
 * It can be reactivated in one of two ways: either by reactivating it
 * in place (which resets the count of queries and jumps but leaves the
 * encapsulated number at its current value) or by resetting it to the
 * original instance integer.
 *
 * METHODS:
 * 1. up() and down() are the primary methods of use. They return the next or
 * previous prime number in sequence (respectively).
 * 2. revive() reactivates an object that has been deactivated due to
 * exceeding the jump limit. An attempt to revive an object in any other
 * state will result in the object failing.
 * 3. reset() resets the object to its initial state. A failed object
 * cannot be reset.
 * 4. isActive() indicates whether the object is currently in the
 * active state (i.e., capable of returning input).
 * 5. isDisabled() indicates whether the object has failed. A failed object
 * cannot be successfully queried nor can it be reset or revived.
 *
 * OTHER ASSUMPTIONS:
 * 1. When the JumpPrime object jumps, it jumps in the direction of the last
 * query. If it jumps after an `up` call, the jump is positive in direction.
 * If it jumps after a 'down' call, the jump is negative in direction.
 * 2. When the JumpPrime object jumps, it jumps a specified magnitude past
 * the next prime. For a jump in the positive direction, it jumps to the
 * next higher prime plus the default jump value. For a jump in the negative
 * direction, it jumps to the next lower prime minus the default jump value.
 * 3. The default jump value is specified as a class constant (here, 100).
 */

/// The JumpPrime class encapsulates a positive integer and provides the
/// user information about the closest prime numbers in the positive and
/// negative direction.
class JumpPrime {

    enum Status {
        Active, Inactive, Failed
    };

    // class constants
    static const unsigned int DEFAULT_JUMP_BOUND = 10;
    static const unsigned int DEFAULT_INITIAL_VALUE = 9999;
    static const int DEFAULT_JUMP_VALUE = 100;

    unsigned int initialNumber;
    unsigned int mainNumber;

    // for tracking the object's state
    Status currentState;

    int queryCount;
    int queryLimit;

    int jumpCount;
    int jumpLimit;

    unsigned int upperPrime;
    unsigned int lowerPrime;

    /**
     * isPrime determines whether or not the given positive integer is a prime
     * number or not (i.e., a whole number greater than one that cannot be
     * exactly divided by any whole number other than itself)
     * @param testNumber the positive integer to test
     * @return true if the number is prime, false otherwise
     */
    bool isPrime(unsigned int testNumber);

    /**
     * findPrime finds either the next nearest prime number or the previous
     * nearest prime number in sequence, depending on the value of the passed
     * parameter.
     * @param startValue the positive integer to start the search from
     * @param findNext true to return the next prime number in sequence, false
     * to return the previous prime number in sequence.
     * @return the next (or previous) positive prime integer within the bounds
     * of the unsigned integer date type
     */
    unsigned int findPrime(unsigned int startValue, bool findNext);

    /**
     * setPrimeLimits finds a new upper and lower prime number based on the
     * established stored number (mainNumber).
     */
    void setPrimeLimits();

    /**
     * resetQueryCounter sets the new query limits (based on the distance between
     * the next and previosu prime number) and resets the query counter to 0.
     */
    void resetQueryCounter();

    /**
     * jumpNumber "jumps" the value of the stored number, mainNumber, by a
     * specified amount. After a set number of "jumps", the JumpPrime will deactive.
     * @param jumpValue the value (positive or negative) to "jump" the stored
     * number by.
     */
    void jumpNumber(int jumpValue);

public:
    /**
     * Constructor for the JumpPrime object.
     * @param initValue the initial positive integer encapsulated by the
     * object. If none is provided, the defined default value will be used.
     * @param jumpBound the number of times that the object with jump before
     * becoming inactive. If none is specified, the defined default value
     * will be used.
     */
    JumpPrime(unsigned int initValue = DEFAULT_INITIAL_VALUE,
              unsigned int jumpBound = DEFAULT_JUMP_BOUND);

    /**
     * up returns the next highest prime number from the number stored in the
     * JumpPrime object. Does not return accurate results if the JumpPrime object
     * has been deactivated.
     * PRECONDITION: the JumpPrime object is running.
     * @return the next highest prime number. If the JumpPrime object has been
     * deactivated, returns 0.
     */
    unsigned int up();

    /**
     * down returns the next lowest prime number from the number stored in the
     * JumpPrime object. Does not return accurate results if the JumpPrime
     * object has been deactivated.
     * PRECONDITION: the JumpPrime object is running.
     * @return the next lowest prime number. If the JumpPrime object has been
     * deactivated, returns 0.
     * @return
     */
    unsigned int down();

    /**
     * Reset attempts to reset the JumpPrime object to the original integer
     * value. This will fail if the JumpPrime object was already made
     * irreparable.
     * PRECONDITION: the JumpPrime object is not permanently deactivated.
     * @return true if the reset is successful, false otherwise.
     */
    bool reset();

    /**
    * Revive attempts to revive a disabled JumpPrime object. This resets the
    * query and jump count and allows the object to be queried again. If the
    * object is already active, it permanently disables the object (makes it
    * irreparable).
    * PRECONDITION: the JumpPrime object is not currently active.
    * @return true if the attempt to revive the object was successful. false
    * otherwise.
    */
    bool revive();

    /**
     * isActive returns whether or not the JumpPrime object has been deactivated
     * due to excessive jumps.
     * @return true if currently active, false otherwise
     */
    bool isActive();

    /**
     * isDeactivated returns whether or not the JumpPrime object has been
     * permanently deactivated due to improper operation.
     * @return true if the JumpPrime object has been permanently disabled,
     * false otherwise.
     */
    bool isDisabled();

    /**
     * GetCurrentValue returns the current value encapsulated by the JumpPrime
     * object. When the object is instantiated (or reset), this is the initial
     * set value. After a jump, this is the new jumped-to value.
     * @return the current value encapsulated by the JumpPrime object.
     */
    unsigned int getCurrentValue();


};


#endif //INC_5011_P2_JUMPPRIME_H
