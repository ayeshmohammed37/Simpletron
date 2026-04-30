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

  int accumulator{0};
  int operand{0};
  int location{0};
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

  for (int i{0}; i < cnt; i++) {
    operand = memory.at(i) % 100;

  }
}