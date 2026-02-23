#include <array>
#include <cstdlib>
#include <iostream>
#include <print>
#include <span>

constexpr size_t size{100};

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

void getSMLProgram(std::span<int>);
OperationCodes getOperationType(int&);

// Input/Output operations
// read data from keyboard to a specific memory location
void Read(std::array<int, size>&, int);
// write data from specific memory location to the screen
void write(const std::array<int, size>&, int);

// Load/Store Operations
// load data from memory into the accumulator
void load(const std::array<int, size>&, int, int&);
// store data from accumulator into specific memory location
void store(std::array<int, size>&, int, const int&);

//Arithmeticc operations
// add data from specific memory location to accumulator 
void add(const std::array<int, size>&, int, int&);
// subtract data from specific memory location from accumulator 
void subtract(const std::array<int, size>&, int, int&);
// divide data from specific memory location into accumulator 
void divide(const std::array<int, size>&, int, int&);
// multiply data from specific memory location to accumulator 
void multiply(const std::array<int, size>&, int, int&);


int main() {
  
  int accumulator{0};
  std::array<int, size> memory{};
  
  getSMLProgram(memory);
  
  std::print("\nStart runing Program from memory....\n");

  for (size_t i{0}; i < size && memory.at(i) != 0; ++i) {
    OperationCodes operation{getOperationType(memory.at(i))};

    switch (operation) {
      // case OperationCodes::read:


    }
    
  }
  
}


void getSMLProgram(std::span<int> memory) {
  std::cout << "Enter SML program or 11111 to exit:\n";
  
  for (int input; int& address : memory) {
    std::cout << ">";
    std::cin >> input;
    
    if (input == 11111) {
      return;
    }

    address = input;
  }

  std::println();
}

OperationCodes getOperationType(int& instruction) {
  int code{std::abs(instruction / 100)};

  switch (code) {
    case 10:
      return OperationCodes::read;
    case 11:
      return OperationCodes::write;
    case 20:
      return OperationCodes::load;
    case 21:
      return OperationCodes::store;
    case 30:
      return OperationCodes::add;
    case 31:
      return OperationCodes::subtract;
    case 32:
      return OperationCodes::divide;
    case 33:
      return OperationCodes::multiply;
    case 40:
      return OperationCodes::branch;
    case 41:
      return OperationCodes::branchNeg;
    case 42:
      return OperationCodes::branchZero;
    case 23:
      return OperationCodes::halt;    
  }
}

void Read(std::array<int, size>& memory, int location) {
  int number;
  
  std::print("Number: ");
  std::cin >> number;

  memory.at(location) = number;
}

void write(const std::array<int, size>& memory, int location) {
  std::println("{}", memory.at(location));
}

void load(const std::array<int, size>& memory, int location, int& accumulator) {
  accumulator = memory.at(location);
}

void store(std::array<int, size>& memory, int location, const int& accumulator) {
  memory.at(location) = accumulator;
}


