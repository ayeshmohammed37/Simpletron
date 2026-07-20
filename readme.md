
accumulator: a “special register” in which information is put before the Simpletron uses that information in calculations

A word is a signed four-digit decimal number, such as +3364, -1293, +0007, -0001, etc. 

SML instruction’s first two digits are the operation code specifying the operation to perform. 
SML instruction’s last two digits are the operand—the memory location containing the word to which the operation applies. 


OperationCodes 
    Input/output operations:
        read = 10 Read a word from the keyboard into a specific memory location.
        write = 11 Write a word from a specific memory location to the screen.
    Load/store operations:
        load = 20 Load a word from a specific memory location into the accumulator.
        store = 21 Store a word from the accumulator into a specific memory location.
    Arithmetic operations:
        add = 30 Add a word from a specific memory location to the word in the accumulator (leave the result in the accumulator).
        subtract = 31 Subtract a word from a specific memory location from the word in the accumulator (leave the result in the accumulator).
        divide = 32 Divide a word from a specific memory location into the word in the accumulator (leave the result in the accumulator).
        multiply = 33 Multiply a word from a specific memory location by the word in the accumulator (leave the result in the accumulator).
    Transfer-of-control operations:
        branch = 40 Branch to a specific memory location.
        branchNeg = 41 Branch to a specific memory location if the accumulator is negative.
        branchZero = 42 Branch to a specific memory location if the accumulator is zero.
        halt = 43 Halt—i.e., the program has completed its task.

Simpletron Components
    accumulator
    100-word memory 00,01,...99

running an SML program:
    1- load program into memory

---------------------------
ToDo
- add validation for the instruction from the user input