#include <iostream>
#include <print>
#include <vector>

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
  // int operand{memory.at(0) % 100};
  // OperationCodes operation{memory.at(0) / 100};

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
      
      case OperationCodes::branchNeg :
      
      case OperationCodes::branchZero :
      
      case OperationCodes::halt :
      
      default:
    }
  
  }
  
}