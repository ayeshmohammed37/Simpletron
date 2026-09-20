namespace Simpletron;

public enum OperationCode
{
    // Input/output operations:
    Read = 10,
    Write = 11,

    // Load/store operations:
    Load = 20,
    Store = 21,

    // Arithmetic operations:
    Add = 30,
    Subtract = 31,
    Divide = 32,
    Multiply = 33,

    // Transfer-of-control operations:
    Branch = 40,
    BranchNeg = 41,
    BranchZero = 42,
    Halt = 43
}