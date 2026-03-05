#include <array>
#include <cstdlib>
#include <iostream>
#include <print>
#include <span>
#include <string>

// memory size: 100-word
const int memory_size{100};

// operation code specifying the operation to perform
enum class OperationCodes {
  read = 10, write,
  load = 20, store,
  add = 30, subtract, divide, multiply,
  branch = 40, branchNeg, branchZero, halt
};

const std::string startingMsg{
  "***           Welcome to Simpletron           ***\n"
  "***                                           ***\n"
  "*** Please enter your program one instruction ***\n"
  "*** (or data word) at a time. I will type the ***\n"
  "*** location number and a question mark (?).  ***\n"
  "*** You then type the word for that location. ***\n"
  "*** Type the sentinel -99999 to stop entering ***\n"
  "*** your program.                             ***"
};

const std::string runningMsg{
  "*** Program loading completed ***\n"
  "*** Program execution begins  ***"
};
// reads the SML instructions from the user
void load(std::span<int>);

// execute sml program stored in memory
void executeProgram(std::array<int, memory_size>&);

int main() {  
  std::array<int, memory_size> memory{0};

  load(memory);
  executeProgram(memory);
}

inline void displayMsg(const std::string msg) {
  std::print("{}\n", msg);
}


void load(std::span<int> memory) {
  displayMsg(startingMsg);

  int instruction;
  size_t i{0};
  while (i < memory_size) {
    std::print("{:02d} ? ", i);
    std::cin >> instruction;

    if (instruction =-99999) {
      break;
    }

    if (instruction > 9'999 || instruction < -9'999) {
      std::println("Error: instruction not valid.");
      continue;
    }

    memory.at(i++) = instruction;
  }

  std::println();
}



void executeProgram(std::array<int, memory_size>& memory) {
  // determine location from instruction 
  auto getLocation{
    [](const int& ins) { return std::abs(ins % 100);}
  };

  // determine operation from instruction
  auto getOperationCode{
    [](const int& ins) { return static_cast<OperationCodes>(std::abs(ins / 100));}
  };

  std::println("*** Program loading completed ***");
  std::println("*** Program execution begins  ***");

  int accumulator{0};
  size_t memory_add{0};

  while (memory_add < memory_size) {
    int instruction{memory.at(memory_add)};
    int location{getLocation(instruction)};
    OperationCodes code{getOperationCode(instruction)};

    // Input/Output operations
    if (code == OperationCodes::read) {
      int number;
      std::print("? ");
      std::cin >> number;
      memory.at(location) = number;
      memory_add++;
    }
    else if (code == OperationCodes::write) {
      std::println("? {}", memory.at(location));
      memory_add++;
    }
    // load/store operations
    else if (code == OperationCodes::load) {
      accumulator = memory.at(location);
      memory_add++;
    }
    else if (code == OperationCodes::store) {
      memory.at(location) = accumulator;
      memory_add++;
    }
    // Arithmatic operations
    else if (code == OperationCodes::add) {
      accumulator += memory.at(location);
      memory_add++;
    }
    else if (code == OperationCodes::subtract) {
      accumulator -= memory.at(location);
      memory_add++;
    }
    else if (code == OperationCodes::divide) {
      accumulator *= memory.at(location);
      memory_add++;
    }
    else if (code == OperationCodes::multiply) {
      accumulator *= memory.at(location);
      memory_add++;
    }
    // Transfer-of-control operations
    else if (code == OperationCodes::branch) {
      memory_add = location;
    }
    else if (code == OperationCodes::branchNeg) {
      if (accumulator < 0) {
        memory_add = location;
      }
      else {
        memory_add++;
      }
    }
    else if (code == OperationCodes::branchZero) {
      if (accumulator == 0) {
        memory_add = location;
      }
      else {
        memory_add++;
      }
    }
    else if (code == OperationCodes::halt) {
      memory_add = 101;
    }
  }

  std::println();
  std::println("*** Simpletron execution terminated ***");
}

