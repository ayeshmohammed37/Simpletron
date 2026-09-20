namespace Simpletron;

class Program
{
    static void Load(int instructionCounter, int instructionRegister, int[] memory)
    {
        while (instructionCounter < 100)
        {
            Console.Write($"{instructionCounter:00} ? ");
            instructionRegister = Math.Abs(int.Parse(Console.ReadLine()));

            if (instructionRegister > 9999)
            {
                Console.WriteLine("*** Program loading completed ***");
                instructionCounter = 101;
            }
            else
            {
                memory[instructionCounter++] = instructionRegister;
            }
        }        
    }

    static void Execute(int instructionCounter, int instructionRegister, int operand, OperationCode operationCode, int accumulator, int[] memory)
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

    static void Main(string[] args)
    {
         // 100-word memory for sml instructions
        int[] memory = new int[100];
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

        // 1- load sml instructions to the memory
        Load(instructionCounter, instructionRegister, memory);

        // 2- Execute sml program that loaded in memory
        Execute(instructionCounter, instructionRegister, operand, operationCode, accumulator, memory);
        
        // prints the name and contents of each register and the complete contents of all 100 memory locations. dump()
        Console.WriteLine("REGISTERS:");
        Console.WriteLine($"accumulator\t\t{accumulator:0000}");
        Console.WriteLine($"instructionCounter\t\t{instructionCounter:00}");
        Console.WriteLine($"instructionRegister\t\t{instructionRegister:0000}");
        Console.WriteLine($"operationCode\t\t{(int)operationCode:00}");
        Console.WriteLine($"operand\t\t{operand:00}");

        Console.WriteLine("\nMEMORY:");
        // header
        Console.Write("  ");
        for (int i = 0; i < 10; i++)
        {
            Console.Write($"{i,7}");
        }
        Console.WriteLine();
        // memory blocks
        for (int i = 0; i < 10; i++)
        {
            Console.Write($"{i*10, 2}");
            for (int j = i*10; j < (i*10+10); j++)
            {
                Console.Write($"  +{memory[j]:0000}");
            }
            Console.WriteLine();
        }
        
    }

}
