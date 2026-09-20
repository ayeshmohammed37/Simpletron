namespace Simpletron;

class Program
{
    static void Dump(in int accumulator, in int instructionCounter, in int instructionRegister, in OperationCode operationCode, in int operand, int[] memory)
    {
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

    static void Main(string[] args)
    {
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

        SimpletronSimulator simulator = new SimpletronSimulator();
        simulator.Run();        
    }

}
