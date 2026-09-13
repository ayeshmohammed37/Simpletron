namespace Simpletron;

enum OperationCode
{
    // Input/output operations:
    read = 10,
    write = 11,

    // Load/store operations:
    load = 20,
    store = 21,

    // Arithmetic operations:
    add = 30,
    subtract = 31,
    divide = 32,
    multiply = 33,

    // Transfer-of-control operations:
    branch = 40,
    branchNeg = 41,
    branchZero = 42,
    halt = 43
}