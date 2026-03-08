#include <array>
#include <cstdlib>
#include <iostream>
#include <print>
#include <span>
#include <string>


// operation code specifying the operation to perform
enum class OperationCodes {
  read = 10, write,
  load = 20, store,
  add = 30, subtract, divide, multiply,
  branch = 40, branchNeg, branchZero, halt
};

// load program into memory
void load(std::span<int>);

// execute sml program stored in memory
void executeProgram(std::span<int>, int&, int&, int&, OperationCodes&, int&);

void dump(std::span<int>, int&, int&, int&, OperationCodes&, int&);

int main() {  
  // memory size: 100-word
  const size_t memory_size{100};
  
  // simpletron memory: 100-word
  std::array<int, memory_size> memory{0};

  // special registers
  int accumulator{0};
  int instructionCounter{0};
  int instructionRegister{0};
  OperationCodes operationCode{0};
  int operand{0};

  // print welcoming msg
  std::cout << "***            Welcome to Simpletron          ***\n"
            << "***                                           ***\n"
            << "*** Please enter your program one instruction ***\n"
            << "*** (or data word) at a time. I will type the ***\n"
            << "*** location number and a question mark (?).  ***\n"
            << "*** You then type the word for that location. ***\n"
            << "*** Type the sentinel -99999 to stop entering ***\n"
            << "*** your program.                             ***\n";


  load(memory);
  
  // print loading done msg
  std::cout << "*** Program loading completed ***\n"
            << "*** Program execution begins  ***\n";
  
  // executeProgram(memory);
  executeProgram(memory, accumulator, instructionCounter, 
    instructionRegister, operationCode, operand);

  
  dump(memory, accumulator, instructionCounter, 
    instructionRegister, operationCode, operand);
    
}


void load(std::span<int> memory) {
  int ins{0};
  int cnt{0};

  while (cnt < memory.size()) {
    std::print("{:02} ? ", cnt);
    std::cin >> ins;

    if (ins == -9999) {
      return;
    }
    
    if (ins > 9999 || ins < -9999) {
      std::cout << "Error: the instruction out of range(-9999..+9999).\n";
      continue;
    }
    
    memory.at(cnt) = ins;
    cnt++;
  }
}



void executeProgram(std::span<int> memory, int& accumulator,
   int& instructionCounter, int& instructionRegister, OperationCodes& operationCode, int& operand) {

  // determine location from instruction 
  auto getOperand{
    [](const int& ins) { return abs(ins % 100);}
  };

  // determine operation from instruction
  auto getOperationCode{
    [](const int& ins) { return static_cast<OperationCodes>(abs(ins / 100));}
  };

  // check accumulator overflows
  // overflows(arithmetic operation resulting calues out of range +9999 to -9999)
  auto overflow{
    [](const int& accumulator) {
      if (accumulator > +9999 || accumulator < -9999)
        return true;
      return false;
    }
  };

  // instruction execution cycle
  while (instructionCounter < memory.size()) {
    // fetch instruction from memory and store it in instructionRegister
    instructionRegister = memory.at(instructionCounter);
    
    // extract operationCode and operand from instruction register
    operationCode = getOperationCode(instructionRegister); 
    operand = getOperand(instructionRegister);
    
    // determine the operation code
    switch (operationCode) {
      // execute operation
      // update instructionCounter
      
      // Input/output operations:
      // read a word from keyboard into a specific memory location
      case OperationCodes::read:
        int number;
        std::cout << "? ";
        std::cin >> number;
        memory.at(operand) = number;
        instructionCounter++;
        break;

      // write a word from a specific memory location to the screen
      case OperationCodes::write:
        std::cout << memory.at(operand) << "\n";
        instructionCounter++;
        break;
      
      // Load/store operations
      // Load a word from a specific memory location into the accumulator.
      case OperationCodes::load:
        accumulator = memory.at(operand);
        instructionCounter++;
        break;
      
      // Store a word from the accumulator into a specific memory location.
      case OperationCodes::store:
        memory.at(operand) = accumulator;
        instructionCounter++;
        break;
      
      // Arithmetic operations
      // Add a word from a specific memory location to the word in the 
      // accumulator (leave the result in the accumulator).
      case OperationCodes::add:
        accumulator += memory.at(operand);
        if (overflow(accumulator)) {
          std::cout << "Error: accumulator overflow\n";
          std::cout << "\n*** Simpletron execution terminated ***\n";
          instructionCounter = memory.size() + 1;
          break;
        }
        else {
          instructionCounter++;
          break;
        }
      
      // Subtract a word from a specific memory location from the word in the
      // accumulator (leave the result in the accumulator). 
      case   OperationCodes::subtract:
        accumulator -= memory.at(operand);
        if (overflow(accumulator)) {
          std::cout << "Error: accumulator overflow\n";
          std::cout << "\n*** Simpletron execution terminated ***\n";
          instructionCounter = memory.size() + 1;
          break;
        }
        else {
          instructionCounter++;
          break;
        }
    
      // Divide a word from a specific memory location into the word in the
      // accumulator (leave the result in the accumulator). 
      case   OperationCodes::divide:
        if (memory.at(operand) == 0) {
          std::cout << "*** Attempt to divide by zero                  ***\n";
          std::cout << "\n*** Simpletron execution terminated ***\n";
          instructionCounter = memory.size() + 1;
          break; 
        }
        else {
          accumulator = accumulator / memory.at(operand);
          if (overflow(accumulator)) {
            std::cout << "Error: accumulator overflow\n";
            std::cout << "\n*** Simpletron execution terminated ***\n";
            instructionCounter = memory.size() + 1;
            break;
          }
          else {
            instructionCounter++;
            break;
          }
        }
    
      // Multiply a word from a specific memory location by the word in the
      // accumulator (leave the result in the accumulator).
      case   OperationCodes::multiply:
        accumulator *= memory.at(operand);
        if (overflow(accumulator)) {
          std::cout << "Error: accumulator overflow\n";
          std::cout << "\n*** Simpletron execution terminated ***\n";
          instructionCounter = memory.size() + 1;
          break;
        }
        else {
          instructionCounter++;
          break;
        }
      
      // Transfare-of-control operations:
      // Branch to a specific memory location.
      case OperationCodes::branch:
        instructionCounter = operand;
        break;
      
      // Branch to a specific memory location if the accumulator is negative.
      case OperationCodes::branchNeg:
        // check if accumulator is negative then change branch
        switch (bool isNegative = accumulator < 0; isNegative) {
          case true:
            instructionCounter = operand;
            break;
          default:
            instructionCounter++;
            break;          
        }
        break;
      
      // Branch to a specific memory location if the accumulator is zero.
      case OperationCodes::branchZero:
        // check if accumulator is zero then change branch
        switch (bool isZero = accumulator == 0; isZero) {
            case true:
              instructionCounter = operand;
              break;
            default:
              instructionCounter++;
              break;          
          }
          break;

      // Halt—i.e., the program has completed its task.
      case OperationCodes::halt:
        instructionCounter = memory.size() + 1;
        std::cout << "\n*** Simpletron execution terminated ***\n";
        break; 
      
      // invalid operation code
      default: 
        instructionCounter = memory.size() + 1;
        std::cout << "*** Invalid operation code: No operation with code (" 
                  << static_cast<int>(operationCode) << ")\n";
        std::cout << "\n*** Simpletron execution terminated ***\n";
        break;          
    } 
  }
}


void dump(std::span<int> memory, int& accumulator, int& instructionCounter, 
  int& instructionRegister, OperationCodes& operationCode, int& operand) {
  instructionCounter = instructionCounter > 99 ? 99 : instructionCounter;
  std::cout << "\nREGISTERS:\n"
            << std::format("{:<26}{:+05d}\n", "accumulator", accumulator)
            << std::format("{:<29}{:02d}\n", "instructionCounter", instructionCounter)
            << std::format("{:<26}{:+05d}\n", "InstructionRegister", instructionRegister)
            << std::format("{:<29}{:02d}\n", "operationCode", static_cast<int>(operationCode))
            << std::format("{:<29}{:02d}\n", "operand", operand);
  
  std::cout << "\nMEMORY:\n  ";

  // print first row 
  for (int i{0}; i < 10; ++i) {
    std::cout << std::format("  {:>5}", i);
  }
  std::cout << "\n";

  // print memory
  for (int i{0}; i < 10; ++i) {
    std::cout << std::format("{:>2d}", (i * 10));
    
    for (int j{0}; j < 10; ++j) {
      int index{j + i * 10};
      std::cout << std::format("  {:+05d}", memory.at(index));
    }
    std::cout << "\n";
  }
}