namespace Simpletron;

class Program
{
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
        // Console.WriteLine("Enter instructions within [-9999..9999].\nEnter any value out of range to exit");

        int instruction = default;
        int i = 0;
        while (i < 100)
        {
            Console.Write($"{i:00} ? ");
            instruction = Math.Abs(int.Parse(Console.ReadLine()));

            if (instruction >= 10000)
            {
                Console.WriteLine("*** Program loading completed ***");
                i = 101;
            }
            else
            {
                memory[i++] = instruction;
            }
        }

        // Execute sml program that loaded in memory
        i = 0;
        while (i < 100)
        {
            instruction = memory[i];
            int location = instruction % 100;
            int operation = instruction / 100;

            Console.WriteLine("*** Program execution begins ***");

            switch (operation)
            {
                // read
                case 10: 
                    Console.Write("?? ");
                    int num = int.Parse(Console.ReadLine());
                    memory[location] = num;
                    i++;
                    break;
                // write
                case 11: 
                    Console.WriteLine(memory[location]);
                    i++;
                    break;
                // load
                case 20:
                    accumulator = memory[location];
                    i++;
                    break;
                // store
                case 21:
                    memory[location] = accumulator;
                    i++;
                    break;
                // Add
                case 30:
                    accumulator += memory[location];
                    i++;
                    break;
                // Subtract
                case 31:
                    accumulator -= memory[location];
                    i++;
                    break;
                // Divide
                case 32:
                    accumulator /= memory[location];
                    i++;
                    break;
                // Multiply
                case 33:
                    accumulator *= memory[location];
                    i++;
                    break;
                // Branch
                case 40:
                    i = location;
                    break;
                // BranchNeg
                case 41:
                    i = accumulator < 0 ? location : i + 1;
                    break;
                // BranchZero
                case 42:
                    i = accumulator == 0 ? location : i + 1;
                    break;
                // Halt
                case 43:
                    i = 101;
                    break;
                default:
                    throw new InvalidOperationException($"Operation-Code {operation} Not valid");
            }
        }
    }
}
