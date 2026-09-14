# Modifications to the Simpletron Simulator (ex: 7.11)

- implement load(), execute(), dump()
- Handle Errors: accumulator overflow(out of range[9999..-9999]), divide by zero, false operation code
- load sml prg from a file

a) Extend the Simpletron Simulator’s memory to contain 1000 memory locations
    (000 to 999) to enable the Simpletron to handle larger programs.

b) Allow the simulator to perform remainder calculations. This requires an additional Simpletron Machine Language instruction.

c) Allow the simulator to perform exponentiation calculations. This requires an
    additional Simpletron Machine Language instruction.

d) Modify the simulator to use hexadecimal values rather than integer values to
    represent Simpletron Machine Language instructions.
    See the Number Systems appendix at <https://deitel.com/cpphtp11> to learn about hexadecimal.

e) Modify the simulator to allow output of a newline. This requires an additional Simpletron Machine Language instruction.

f) Modify the simulator to process floating-point values in addition to integers.

g) Modify the simulator to detect division by 0 logic errors.

h) Modify the simulator to detect arithmetic-overflow errors.

i) Modify the simulator to handle string input. [Hint: Each Simpletron word can
    be divided into two groups, each holding a two-digit integer.
    Each two-digit integer represents the ASCII decimal equivalent of a character.
    Add a machinelanguage instruction that will input a string and store it beginning at a specific
    Simpletron memory location. The first half of the word at that location will be
    a count of the number of characters in the string (i.e., the length of the string).
    Each succeeding half word contains one ASCII character expressed as two decimal digits.
    The machine-language instruction converts each character into its
    ASCII equivalent and assigns it to either a left or right half word.]

j) Modify the simulator to handle output of strings stored in the format of part
    (g). [Hint: Add a machine-language instruction that prints a string beginning
    at a specified Simpletron memory location. The first half of the word at that
    location is the length of the string in characters. Each succeeding half word contains one ASCII character expressed as two decimal digits. The
    machine-language instruction checks the length and prints the string by translating each
    two-digit number into its equivalent character.]
