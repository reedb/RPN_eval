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
        Stack s;

    public:
        EvalRPN()  { }    // Constructor
        ~EvalRPN() { }    // Destructor
        double DoEvalRPN(char *expression, double x);
    private:
        void HandleBinary(char *pszWord);
        void HandleUnary(char *pszWord);
        void HandleConVar(char *pszWord, double x);

        double Str2D(char *pszWord);
};
