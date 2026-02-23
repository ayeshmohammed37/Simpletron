/*
  Simpletron machine language instructions
*/
// accumulator

// memory: word[100] 


// - load program in memory

// instruction:
//  first two digit are the operation code


#include <array>
#include <iostream>

int main() {
  int accumulator{0};

  std::array<int, 100> memory;

  enum class OperationCodes {
    // Input/Output operations
    read = 10,
    write = 11,

    // Load and Store Operations
    load = 20,
    store = 21,

    // Arithmetic operations
    add = 30,
    subtract = 31,
    divide = 32,
    multiply = 33,

    // Transfare-of-control operations
    branch = 40,
    branchNeg = 41,
    branchZero = 42,
    halt = 43
  };

  
}