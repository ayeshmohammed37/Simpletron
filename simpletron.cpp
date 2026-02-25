#include <array>
#include <cstdlib>
#include <iostream>
#include <print>

// memory size: 100-word
const int memory_size{100};

// operation code specifying the operation to perform
enum class OperationCodes {
  read = 10, write,
  load = 20, store,
  add = 30, subtract, divide, multiply,
  branch = 40, branchNeg, branchZero, halt
};

// get sml program into memory
void getProgram(std::array<int, memory_size>&);

// execute sml program stored in memory
void executeProgram(std::array<int, memory_size>&);

int main() {  
  std::array<int, memory_size> memory{0};

  getProgram(memory);
  executeProgram(memory);
}

void getProgram(std::array<int, memory_size>& memory) {
  std::println("Enter SML Program or 11111 to end program.");

  int instruction;
  size_t i{0};
  while (i < memory_size) {
    std::print("> ");
    std::cin >> instruction;

    if (instruction == 11'111) {
      break;
    }

    if (instruction > 9'999 || instruction < -9'999) {
      std::println("Error: instruction not valid.");
      continue;
    }

    memory.at(i++) = instruction;
  }
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

  int accumulator{0};
  size_t memory_add{0};

  while (memory_add < memory_size) {
    int instruction{memory.at(memory_add)};
    int location{getLocation(instruction)};
    OperationCodes code{getOperationCode(instruction)};

    // Input/Output operations
    if (code == OperationCodes::read) {
      int number;
      std::print(">Number: ");
      std::cin >> number;
      memory.at(location) = number;
      memory_add++;
    }
    else if (code == OperationCodes::write) {
      std::println("Result: {}", memory.at(location));
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
}

