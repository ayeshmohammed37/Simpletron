#include <array>
#include <cstdlib>
#include <iostream>
#include <print>
#include <span>
#include <string>






// load program into memory
// void load(std::span<int>);

// execute sml program stored in memory
// void executeProgram(std::array<int, memory_size>&);





int main() {  
  // memory size: 100-word
  const size_t memory_size{100};
  
  // operation code specifying the operation to perform
  enum class OperationCodes {
    read = 10, write,
    load = 20, store,
    add = 30, subtract, divide, multiply,
    branch = 40, branchNeg, branchZero, halt
  };
  // simpletron memory: 100-word
  std::array<int, memory_size> memory{0};

  // special registers
  int accumulator{0};
  int instructionCounter{0};
  int instructionRegister{0};
  int operationCode{0};
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
    << "*** Program execution begins  ***";
  
    // executeProgram(memory);
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



// void executeProgram(std::array<int, memory_size>& memory) {
//   // determine location from instruction 
//   auto getLocation{
//     [](const int& ins) { return abs(ins % 100);}
//   };

//   // determine operation from instruction
//   auto getOperationCode{
//     [](const int& ins) { return static_cast<OperationCodes>(abs(ins / 100));}
//   };

//   std::println("*** Program loading completed ***");
//   std::println("*** Program execution begins  ***");

//   int accumulator{0};
//   size_t memory_add{0};
//   int instruction{0};
//   OperationCodes operand;
//   int location{0};

//   while (memory_add < memory_size) {
//     instruction = memory.at(memory_add);
//     operand = getOperationCode(instruction);
//     location = getLocation(instruction);
    
//     // Input/Output operations
//     if (operand == OperationCodes::read) {
//       int number;
//       std::print("Number ? ");
//       std::cin >> number;
//       memory.at(location) = number;
//       memory_add++;
//     }
//     else if (operand == OperationCodes::write) {
//       std::println("? {}", memory.at(location));
//       memory_add++;
//     }
//     // load/store operations
//     else if (operand == OperationCodes::load) {
//       accumulator = memory.at(location);
//       memory_add++;
//     }
//     else if (operand == OperationCodes::store) {
//       memory.at(location) = accumulator;
//       memory_add++;
//     }
//     // Arithmatic operations
//     else if (operand == OperationCodes::add) {
//       accumulator += memory.at(location);
//       memory_add++;
//     }
//     else if (operand == OperationCodes::subtract) {
//       accumulator -= memory.at(location);
//       memory_add++;
//     }
//     else if (operand == OperationCodes::divide) {
//       accumulator /= memory.at(location);
//       memory_add++;
//     }
//     else if (operand == OperationCodes::multiply) {
//       accumulator *= memory.at(location);
//       memory_add++;
//     }
//     // Transfer-of-control operations
//     else if (operand == OperationCodes::branch) {
//       memory_add = location;
//     }
//     else if (operand == OperationCodes::branchNeg) {
//       if (accumulator < 0) {
//         memory_add = location;
//       }
//       else {
//         memory_add++;
//       }
//     }
//     else if (operand == OperationCodes::branchZero) {
//       if (accumulator == 0) {
//         memory_add = location;
//       }
//       else {
//         memory_add++;
//       }
//     }
//     else {
//       memory_add = 101;
//     }
//   }

//   std::println();
//   std::println("*** Simpletron execution terminated ***");
// }

