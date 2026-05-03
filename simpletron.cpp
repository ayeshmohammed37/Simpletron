#include <iostream>
#include <print>
#include <vector>
#include <utility>
#include <string>

// printing welcome msg
void printWelcomeMsg() {
  //welcome msg
  std::string msg{
    "***           Welcome to Simpletron           ***\n"
    "***                                           ***\n"
    "*** Please enter your program one instruction ***\n"
    "*** (or data word) at a time. I will type the ***\n"
    "*** location number and a question mark (?).  ***\n"
    "*** You then type the word for that location. ***\n"
    "*** Type the sentinel -99999 to stop entering ***\n"
    "*** your program.                             ***"
  };

  // print welcome msg
  std::println("{}", msg);
}

void printDumpMsg(const std::vector<int>& memory, const int& accumulator, const int& instructionCounter, 
  const int& instructionRegister, const int& operationCode, const int& operand) {

    // print registers content
    std::println("Registers:");
    std::println("{:<30}{:+05d}", "accumulator", accumulator);
    std::println("{:<33}{:02d}", "instructionCounter", instructionCounter);
    std::println("{:<30}{:+05d}", "instructionRegister", instructionRegister);
    std::println("{:<33}{:02d}", "operationCode", operationCode);
    std::println("{:<33}{:02d}", "operand", operand);
    
    // print memory content
    std::println("MEMORY:");
    std::print("  ");
    for (int i{0}; i < 10; i++) {
      std::print("{:>7}", i);
    }
    std::println();
    for (int i{0}; i < 10; i++) {
      std::print("{:>2d}", i * 10); 

      for (int j{i * 10}; j < ((i * 10) + 10); j++) {
        std::print("  {:+05d}", memory.at(j));
      }
      std::println();
    }

}

// loading SML instructions into memeory
void load(std::vector<int>& memory) {
  // word represent instruction that user input
  int word{0};  
  
  int cnt{0};
  while (cnt < 100) {
    std::print("{:0>2d} ? ", cnt);
    std::cin >> word;

    if (word == -99999) {
      break;
    }
    memory.at(cnt++) = std::abs(word);
  }
  std::println("*** Program loading completed ***");
}

void execute(std::vector<int>& memory) {
  std::println("*** Program execution begins ***");
  // accumulator
  // instructionCounter: number of memory location(00..99) containing inst being performed
  // operationCode
  // operand "number of memory location on which the current instruction operates
  // instructionRegister

  // accumulatorRegster
  int accumulator{0};
  // number of memory location containing instruction being performed
  int instructionCounter{0}; // 00..99
  // store the next instruction to be performed then initialize operand and operationcode
  int instructionRegister{0};
  // operation currently being performed (instruction word's left two digits)
  int operationCode{0};
  // store number of memory location on which the current instruction operates
  // instruction's rightmost two digit currtently performed
  int operand{0};

  while (instructionCounter < 100) {
    // instruction execution cycle
    
    // fetch the next instruction to be performed
    instructionRegister = memory.at(instructionCounter);
    
    // extract operationCode and operand from instructionRegister
    operand = instructionRegister % 100;
    operationCode = instructionRegister / 100;

    switch (operationCode) {
      case 10:
        // std::cout << "?";
        std::cin >> memory.at(operand);
        // i++;
        // break;

      case 11 :
        std::println("{}", memory.at(operand));
        // i++;
        // break;
      
      case 20 :
        accumulator = memory.at(operand);
        i++;
        break;

      case 21 :
        memory.at(operand) = accumulator;
        i++;
        break;

      case 30:
        accumulator += memory.at(operand);
        i++;
        break;

      case 31:
        accumulator -= memory.at(operand);
        i++;
        break;

      case 32:
        accumulator /= memory.at(operand);
        i++;
        break;
        
      case 33:
        accumulator *= memory.at(operand);
        i++;
        break;
        
      case 40:
        i = operand;
        break;

      case 41:
        i = accumulator < 0 ? operand : i + 1;
        break;

      case 42:
        i = accumulator == 0 ? operand : i + 1;
        break;
        
      case 43:
        std::println("*** Simpletron execution terminated ***");
        printDumpMsg();
        // i = 101;
        // break;

      default:
        std::println("operation code({}): not defined", std::to_underlying(operation));
        i = 101;
        break;
    }

  }
}

int main() {
  enum class OperationCodes {
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
    halt = 43,
  };
  
  std::vector<int> memory(100, 0);

  printWelcomeMsg();
  load(memory);

  
  int accumulator{0};
  int i{0};
  
  while(i < 100) {
    int operand{memory.at(i) % 100};
    OperationCodes operation{memory.at(i) / 100};

    switch (operation) {
      case OperationCodes::read :
        std::cout << "?";
        std::cin >> memory.at(operand);
        i++;
        break;

      case OperationCodes::write :
        std::println("{}", memory.at(operand));
        i++;
        break;
      
      case OperationCodes::load :
        accumulator = memory.at(operand);
        i++;
        break;

      case OperationCodes::store :
        memory.at(operand) = accumulator;
        i++;
        break;

      case OperationCodes::add :
        accumulator += memory.at(operand);
        i++;
        break;

      case OperationCodes::subtract :
        accumulator -= memory.at(operand);
        i++;
        break;

      case OperationCodes::divide :
        accumulator /= memory.at(operand);
        i++;
        break;
        
      case OperationCodes::multiply :
        accumulator *= memory.at(operand);
        i++;
        break;
        
      case OperationCodes::branch :
        i = operand;
        break;

      case OperationCodes::branchNeg :
        i = accumulator < 0 ? operand : i + 1;
        break;

      case OperationCodes::branchZero :
        i = accumulator == 0 ? operand : i + 1;
        break;
        
      case OperationCodes::halt :
        i = 101;
        break;

      default:
        std::println("operation code({}): not defined", std::to_underlying(operation));
        i = 101;
        break;
    }
  
  }
  
}


/*
"***           Welcome to Simpletron           ***",
"***                                           ***",
"*** Please enter your program one instruction ***",
"*** (or data word) at a time. I will type the ***",
"*** location number and a question mark (?).  ***",
"*** You then type the word for that location. ***",
"*** Type the sentinel -99999 to stop entering ***",
"*** your program.                             ***"

*/