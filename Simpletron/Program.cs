namespace Simpletron;

class Program
{
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
