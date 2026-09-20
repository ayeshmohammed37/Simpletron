namespace Simpletron;

public partial class SimpletronSimulator
{
    private void Dump()
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
}