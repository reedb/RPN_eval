//*****************************************************************************
//
// eval_rpn.h - Declarations and definitions for RPN evaluator.
//
// Author:  Reed Bement,  2019/1/6
//
//    Notes:
//    ------
//
//*****************************************************************************

class EvalRPN {
    private:
        Stack s();

    public:
        EvalRPN()  { }    // Constructor
        ~EvalRPN() { }    // Destructor
        double eval_rpn(char *expression, double x);
};
