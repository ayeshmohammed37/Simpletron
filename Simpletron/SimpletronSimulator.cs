namespace Simpletron;

public partial class SimpletronSimulator
{
    // 100-word memory for sml instructions
    private int[] memory = new int[100];
    // special register to store information before simpletron uses it in calculations
    private int accumulator = default;
    // store the number of the memory location (00 to 99) containing the instruction being performed
    private int instructionCounter = default;
    // store the operation currently being performed (the instruction word’s left two digits)
    private OperationCode operationCode = default;
    // store the number of the memory location on which the current instruction operates.
    private int operand = default;
    // the next instruction to be performed from memory 
    private int instructionRegister = default;

    public void Run(string path)
    {
        // 1- load sml instructions to the memory
        Load(path);
        // 2- Execute sml program that loaded in memory
        Execute();
        // 3- prints the name and contents of each register and the complete contents of all 100 memory locations. dump()
        Dump();
    }
}