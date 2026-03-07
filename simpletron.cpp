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

// load program into memory
void load(std::span<int>);

// execute sml program stored in memory
void executeProgram(std::array<int, memory_size>&);

int main() {  
  std::array<int, memory_size> memory{0};

  load(memory);
  
  // executeProgram(memory);
}

bool isValid(int instruction) {
  int op{abs(instruction / 100)};
  int location{abs(instruction % 100)};

  bool opCheck{false};
  bool locationCheck{false};

  if (op == 10 || op == 11 || op == 20 || op == 21 || (op >= 30 && op <= 33) || (op >= 40 && op <= 43)) {
    opCheck = true;
  }
  
  if (location >= 0 && location < 100) {
    locationCheck = true;
  }

  return opCheck && locationCheck;
}

void load(std::span<int> memory) {
  int ins{0};
  int cnt{0};

  while (cnt < memory.size()) {
    std::print("{:02} ? ", cnt);
    std::cin >> ins;

    if (ins > 9999 || ins < -9999) {
      return;
    }

    if (!isValid(ins)) {
      std::println("Error: the instruction is not valid.");
      continue;
    }
    
    memory.at(cnt) = ins;
    cnt++;
  }
}



void executeProgram(std::array<int, memory_size>& memory) {
  // determine location from instruction 
  auto getLocation{
    [](const int& ins) { return abs(ins % 100);}
  };

  // determine operation from instruction
  auto getOperationCode{
    [](const int& ins) { return static_cast<OperationCodes>(abs(ins / 100));}
  };

  std::println("*** Program loading completed ***");
  std::println("*** Program execution begins  ***");

  int accumulator{0};
  size_t memory_add{0};
  int instruction{0};
  OperationCodes operand;
  int location{0};

  while (memory_add < memory_size) {
    instruction = memory.at(memory_add);
    operand = getOperationCode(instruction);
    location = getLocation(instruction);
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

