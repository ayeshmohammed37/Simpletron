namespace Simpletron;

class Program
{
    const int MemorySize = 1000;
    static void Main(string[] args)
    {
        // 100-word memory for sml instructions
        int[] memory = new int[MemorySize];
        // special register to store information before simpletron uses it in calculations
        int accumulator = default;
        // store the number of the memory location (00 to 99) containing the instruction being performed
        int instructionCounter = default;
        // store the operation currently being performed (the instruction word’s left two digits)
        OperationCode operationCode = default;
        // store the number of the memory location on which the current instruction operates.
        int operand = default;
        // the next instruction to be performed from memory 
        int instructionRegister = default;


        // Welcome to Simpletron
        string welcomeMsg =
            "***            Welcome to Simpletron          ***\n" +
            "***                                           ***\n" +
            "*** Please enter your program one instruction ***\n" +
            "*** (or data word) at a time. I will type the ***\n" +
            "*** location number and a question mark (?).  ***\n" +
            "*** You then type the word for that location. ***\n" +
            "*** Type the sentinel -99999 to stop entering ***\n" +
            "*** your program.                             ***";

        Console.WriteLine(welcomeMsg);

        try
        {
            // 1- load sml instructions to the memory
            Load(ref instructionCounter, ref instructionRegister, memory);
            // 2- Execute sml program that loaded in memory
            Execute(ref instructionCounter, ref instructionRegister, ref operand, ref operationCode, ref accumulator, memory);
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
            Console.WriteLine("*** Simpletron execution abnormally terminated ***");
        }
        finally
        {
            // 3- prints the name and contents of each register and the complete contents of all 100 memory locations. dump()
            Dump(in accumulator, in instructionCounter, in instructionRegister, in operationCode, in operand);
        }
    }

    static void Load(ref int instructionCounter, ref int instructionRegister, int[] memory)
    {
        while (instructionCounter < MemorySize)
        {
            Console.Write($"{instructionCounter,4} ? ");
            instructionRegister = Math.Abs(int.Parse(Console.ReadLine()));

            if (instructionRegister > 9999)
            {
                Console.WriteLine("*** Program loading completed ***");
                instructionCounter = MemorySize + 1;
            }
            else
            {
                memory[instructionCounter++] = instructionRegister;
            }
        }
    }

    static void Execute(ref int instructionCounter, ref int instructionRegister,
        ref int operand, ref OperationCode operationCode,
        ref int accumulator, int[] memory)
    {
        // start from first block in the memory
        instructionCounter = 0;

        Console.WriteLine("*** Program execution begins ***");
        
        while (instructionCounter < MemorySize)
        {
            // instruction execution cycle
            // fetch the contents of the next instruction to be performed
            instructionRegister = memory[instructionCounter];
            // exxtract operand and operationCode from the instructionRegister
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
                // Arithmetic operations
                case OperationCode.Add:
                case OperationCode.Subtract:
                case OperationCode.Divide:
                case OperationCode.Multiply:
                case OperationCode.Modulo:
                    ExecuteAritheticOperations(ref accumulator, ref  instructionCounter, ref  operand, memory, operationCode);
                    break;
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
                    return;
                default:
                    throw new Exception($"invalid Operation-Code: {operationCode}");
            }
        }
    }
    
    static void ExecuteAritheticOperations(ref int accumulator, ref int instructionCounter, ref int operand, int[] memory, OperationCode operationCode)
    {
        switch (operationCode)
        {
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
                if (memory[operand] == 0)
                {
                    throw new Exception("Division by zero");
                }
                accumulator /= memory[operand];
                instructionCounter++;
                break;
            // Multiply
            case OperationCode.Multiply:
                accumulator *= memory[operand];
                instructionCounter++;
                break;
            case OperationCode.Modulo:
                if (memory[operand] == 0)
                {
                    throw new Exception("Modulos by zero");
                }
                accumulator %= memory[operand];
                instructionCounter++;
                break;
        }

        if (accumulator > 9999)
        {
            throw new Exception("accumulator overflows");
        }
    }

    static void Dump(in int accumulator, in int instructionCounter, 
        in int instructionRegister, in OperationCode operationCode, 
        in int operand)
    {
        Console.WriteLine("REGISTERS:");
        Console.WriteLine($"accumulator                     {accumulator:+0000;-0000;+0000}");
        Console.WriteLine($"instructionCounter              {instructionCounter,5:00}");
        Console.WriteLine($"instructionRegister             {instructionRegister:+0000;-0000;+0000}");
        Console.WriteLine($"operationCode                   {(int)operationCode,5:00}");
        Console.WriteLine($"operand                         {operand,5:00}");
    }
}
