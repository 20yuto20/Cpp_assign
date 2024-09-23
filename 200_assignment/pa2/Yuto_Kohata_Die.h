#ifndef DIE_H
#define DIE_H

class Die {
private:
    int sides; // Number of sides on the die
    int value; // The die's value

public:
    // Constructor
    Die(int numSides);

    // Member functions
    void setSides(int numSides);
    void roll();
    int getSides() const;
    int getValue() const;
};

#endif // DIE_H

// Comment 1: This header file defines the Die class as specified in the UML diagram.
// Comment 2: An include guard is used to prevent multiple inclusions of this header.
// Comment 3: The class has two private member variables: sides and value.
// Comment 4: Public member functions are declared, including a constructor and getter/setter methods.