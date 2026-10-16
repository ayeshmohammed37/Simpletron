namespace Simpletron;

public enum OperationCode
{
    // Input/output operations:
    // Read a word from the keyboard into a specific memory location.
    Read = 10,
    // Write a word from a specific memory location to the screen.
    Write = 11,

    // Load/store operations:
    // Load a word from a specific memory location into the accumulator.
    Load = 20,
    // Store a word from the accumulator into a specific memory location.
    Store = 21,

    // Arithmetic operations:
    // Add a word from a specific memory location to the word in the accu-
    // mulator (leave the result in the accumulator).
    Add = 30,
    // Subtract a word from a specific memory location from the word in the
    // accumulator (leave the result in the accumulator).
    Subtract = 31,
    // Divide a word from a specific memory location into the word in the
    // accumulator (leave the result in the accumulator).
    Divide = 32,
    // Multiply a word from a specific memory location by the word in the
    // accumulator (leave the result in the accumulator).
    Multiply = 33,
    // Modulo a word from a specific memory location into the word in the
    // accumulator and leave the remainder in the accumulator).
    Modulo = 34,
    // Exponentiation calculations, Get exponent of word for the accumulator(base)
    // and leave the result in the accumulator
    Exp = 35,
    
    // Transfer-of-control operations:
    // Branch to a specific memory location.
    Branch = 40,
    // Branch to a specific memory location if the accumulator is negative.
    BranchNeg = 41,
    // Branch to a specific memory location if the accumulator is zero.
    BranchZero = 42,
    // Halt—i.e., the program has completed its task.
    Halt = 43
}