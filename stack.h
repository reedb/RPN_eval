//*****************************************************************************
//
// stack.h - Declarations and definitions for FILO storage system.
//
// Author:  Reed Bement,  2019/1/6
//
//    Notes:
//    ------
//
//*****************************************************************************

#define STACK_MAX 16384

class Stack {

    private:
        double     data[STACK_MAX];
        int        size;

    public:
        Stack() { size = 0; }    // Constructor
        ~Stack() { }             // Destructor
        int Top();
        void Push(double d);
        double Pop();
};
