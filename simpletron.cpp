#include <iostream>
#include <print>
#include <vector>
#include <utility>
#include <string>

void printWelcomeMsg() {
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
  std::println("{}", msg);
}

void load(std::vector<int>& memory) {
  int word{0};  
  int cnt{0};

  while (cnt < 100) {
    std::print("{:2d} ? ", cnt);
    std::cin >> word;

    if (word == -99999) {
      break;
    }
    memory.at(cnt++) = std::abs(word);
  }
  std::println("*** Program loading completed ***\n*** Program execution begins ***");
}

int main() {

  printWelcomeMsg();

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

  int word{0};
  std::vector<int> memory(100, 0);
  
  int cnt{0};
  std::println("Enter instructions or (-10000) to end the program");

  while (cnt < 100) {
    std::print(">");
    std::cin >> word;

    if (word == -10000) {
      break;
    }
    
    memory.at(cnt++) = std::abs(word);
  }
  
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