namespace Simpletron;

public partial class SimpletronSimulator
{
    private void Execute()
    {
        instructionCounter = 0;
        Console.WriteLine("*** Program execution begins ***");
        while (instructionCounter < 100)
        {
            //  instruction execution cycle
            instructionRegister = memory[instructionCounter];
            operand = instructionRegister % 100;
            operationCode = (OperationCode)(instructionRegister / 100);

            switch (operationCode)
            {
                // read
                case OperationCode.Read:
                    Console.Write("? ");
                    int num = int.Parse(Console.ReadLine());
                    memory[operand] = num;
                    instructionCounter++;
                    break;
                // write
                case OperationCode.Write:
                    Console.WriteLine(memory[operand]);
                    instructionCounter++;
                    break;
                // load
                case OperationCode.Load:
                    accumulator = memory[operand];
                    instructionCounter++;
                    break;
                // store
                case OperationCode.Store:
                    memory[operand] = accumulator;
                    instructionCounter++;
                    break;
                // Add
                case OperationCode.Add:
                    accumulator += memory[operand];
                    instructionCounter++;
                    break;
                // Subtract
                case OperationCode.Subtract:
                    accumulator -= memory[operand];
                    instructionCounter++;
                    break;
                // Divide
                case OperationCode.Divide:
                    accumulator /= memory[operand];
                    instructionCounter++;
                    break;
                // Multiply
                case OperationCode.Multiply:
                    accumulator *= memory[operand];
                    instructionCounter++;
                    break;
                // Branch
                case OperationCode.Branch:
                    instructionCounter = operand;
                    break;
                // BranchNeg
                case OperationCode.BranchNeg:
                    instructionCounter = accumulator < 0 ? operand : instructionCounter + 1;
                    break;
                // BranchZero
                case OperationCode.BranchZero:
                    instructionCounter = accumulator == 0 ? operand : instructionCounter + 1;
                    break;
                // Halt
                case OperationCode.Halt:
                    Console.WriteLine("*** Simpletron execution terminated ***");
                    instructionCounter = 101;
                    break;
                default:
                    Console.WriteLine($"Operation-Code {operationCode} Not valid");
                    instructionCounter = 101;
                    break;
            }
        }
    }
}