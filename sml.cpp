#include <array>
#include <iostream>
#include <print>
#include <span>

void getSMLProgram(std::span<int>);
void Read(int&);

int main() {
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
  
  int accumulator{0};
  std::array<int, size> memory{};
  
  getSMLProgram(memory);
  
  for (size_t i{0}; i < size && memory.at(i) != 0; ++i) {
    // Input/Output operations

    // Load and Store Operations
    // Arithmetic operations
    // Transfare-of-control operations
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

void Read(int& address) {
  
}
