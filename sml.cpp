/*

- Input SML program or 11111 to end
    - initialize i{0}
    - while i < memory_size
        - prompt user to enter instruction
        - check instruction 
          - if instruction > 9999 or instruction < -9999
            - tell the user instruction is out of range 
- execute sml program


- Initialize const memory_size{100}, memory[memory_size]
- Get SML Program into memory
- Execute SML Program from memory
*/

#include <array>
#include <iostream>
#include <print>

const int memory_size{100};

// get sml program into memory
void getProgram(std::array<int, memory_size>&);

int main() {
  std::array<int, memory_size> memory{0};

  getProgram(memory);
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