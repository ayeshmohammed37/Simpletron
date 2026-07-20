namespace Simpletron;

class Program
{
    enum OperationCodes
    {
        // Input/output operations:
        read = 10,
        write = 11,

        // Load/store operations:
        load = 20,
        store = 21,

        // Arithmetic operations:
        add = 30,
        subtract = 31,
        divide = 32,
        multiply = 33,

        // Transfer-of-control operations:
        branch = 40,
        branchNeg = 41,
        branchZero = 42,
        halt = 43
    }


    static void Main(string[] args)
    {
        // 100-word memory for sml instructions
        int[] memory = new int[100];
        // special register to store information before simpletron uses it in calculations
        int accumulator = 0;

        // load sml instructions to the memory
        int i = 0;
        int instruction = 0;

        Console.WriteLine("Enter instructions within [-9999..9999].\n Enter any value out of the range to exit");
        while (i < 100)
        {
            Console.Write(">");
            instruction = int.Parse(Console.ReadLine());

            // check if the instruction withing the range
            if (instruction >= -9999 && instruction <= 9999)
            {
                memory[i++] = instruction;
            }
            else
            {
                i = 101;
            }
        }

    }
}
