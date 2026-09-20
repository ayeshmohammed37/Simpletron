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

            if (operand > 99)
            {
                throw new Exception($"operand {operand}: out of memory range, (00..99)");
            }
            
            if (!operationCode.IsValid())
            {
                throw new Exception($"OperationCode({operationCode}) not valid.");
            }

            switch (operationCode)
            {
                // read
                case OperationCode.Read:
                    Console.Write("? ");
                    int num = int.Parse(Console.ReadLine());
                    if (num > 9999 || num < -9999)
                    {
                        throw new Exception($"overflow: {num} out of range (-9999...9999)");
                    }
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
                    if (accumulator > 9999 || accumulator < -9999)
                    {
                        throw new Exception($"accumulator overflow: {accumulator} out of range (-9999...9999)");
                    }
                    instructionCounter++;
                    break;
                // Subtract
                case OperationCode.Subtract:
                    accumulator -= memory[operand];
                    if (accumulator > 9999 || accumulator < -9999)
                    {
                        throw new Exception($"accumulator overflow: {accumulator} out of range (-9999...9999)");
                    }
                    instructionCounter++;
                    break;
                // Divide
                case OperationCode.Divide:
                    if (memory[operand] == 0)
                    {
                        throw new Exception($"Cannot divide by zero");
                    }
                    accumulator /= memory[operand];
                    if (accumulator > 9999 || accumulator < -9999)
                    {
                        throw new Exception($"accumulator overflow: {accumulator} out of range (-9999...9999)");
                    }
                    instructionCounter++;
                    break;
                // Multiply
                case OperationCode.Multiply:
                    accumulator *= memory[operand];
                    if (accumulator > 9999 || accumulator < -9999)
                    {
                        throw new Exception($"accumulator overflow: {accumulator} out of range (-9999...9999)");
                    }
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
                default:
                    Console.WriteLine("*** Simpletron execution terminated ***");
                    instructionCounter = 101;
                    break;
            }
        }
    }
}