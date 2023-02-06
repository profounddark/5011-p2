//
// Created by Andrew Asplund on 2/1/23.
//

#ifndef INC_5011_P2_DUELINGJP_H
#define INC_5011_P2_DUELINGJP_H

#include <vector>
#include "JumpPrime.h"

/// DuelingJP is a container for JumpPrime objects used for testing.
class DuelingJP {

    /// Pointer to array of JumpPrime objects of size listSize.
    JumpPrime *jumperList;

    /// The size of the jumperList array.
    int listSize;

    /// areActive verifies that all JumpPrime objects are currently active
    /// (i.e., they have not been deactivated).
    /// @return true if all of the member JumpPrime objects are active.
    bool areActive();

    /// reactivateJumpers goes through all of the JumpPrime objects and
    /// reactivates any that were not active.
    void reactivateJumpers();

public:

    /// DuelingJP Constructor creates a new DuelingJP object with a set of
    /// JumpPrime objects specified by a given array of initial values.
    /// @param [in] initValues Array of initial values for JumpPrime objects
    /// @param [in] size The size of the array of initial values.
    /// @pre All values of array are valid JumpPrime initial values.
    DuelingJP(int  initValues[], int size);


    /// DuelingJP Destructor for disposing of JumpPrime garbage
    ~DuelingJP();

    /// DuelingJP Copy Constructor creates a duplicate DuelingJP object with
    /// the same JumpPrime objects.
    /// @param [in] sourceObject The DuelingJP object to copy.
    DuelingJP(const DuelingJP & sourceObject);


    /// DuelingJP Move Constructor assigns a new DuelingJP with the content
    /// of the original and eliminates the source.
    /// @param [in] sourceObject The DuelingJP object to move
    DuelingJP(DuelingJP && sourceObject);


    /// DuelingJP overloaded assignment operator assigns a duplicate of the
    /// contents of one DuelingJP object to another.
    /// @param [in] sourceObject  The DuelingJP object to copy.
    /// @return A pointer to the new DuelingJP object.
    DuelingJP &operator=(const DuelingJP & sourceObject);

    /// DuelingJP overloaded move assignment operator swaps the contents
    /// of one DuelingJP to another.
    /// @param sourceObject
    /// @return A pointer to the DuelingJP object with the content.
    DuelingJP &operator=(DuelingJP && sourceObject);

    /// countCollisions will run a single pass test through the list of
    /// JumpPrime objects, identifying any instances where two objects have
    /// the same value.
    /// @param [in] testUp If true, tests the JumpPrime objects in the "up"
    /// direction. Defaults to true.
    /// @return The number of JumpPrime objects that collided.
    int countCollisions(bool testUp = true);


    /// getSize returns the number of JumpPrime objects in this DuelingJP.
    /// @return The number of JumpPrime objects in the DuelingJP object.
    int getSize();



};


#endif //INC_5011_P2_DUELINGJP_H
