namespace Simpletron;

partial class Program
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

            // check if the instruction withing the range
            if (instruction >= -9999 && instruction <= 9999)
            {
                memory[i++] = instruction;
            }
            else
            {
                Console.WriteLine("loading program ended");
                i = 101;
            }
        }

        // Execute sml program that loaded in memory
        int j = 0;
        while (j < 100)
        {
            int ins = memory[j];
            int operation = Math.Abs(ins / 100);
            int location = Math.Abs(ins % 100);

            switch (operation)
            {
                case 10:
                    Console.Write("?");
                    memory[location] = int.Parse(Console.ReadLine());
                    j++;
                    break;
                case 11:
                    Console.WriteLine(memory[location]);
                    j++;
                    break;
                case 20:
                    accumulator = memory[location];
                    j++;
                    break;
                case 21:
                    memory[location] = accumulator;
                    j++;
                    break;
                case 30:
                    accumulator += memory[location];
                    j++;
                    break;
                case 31:
                    accumulator -= memory[location];
                    j++;
                    break;
                case 32:
                    accumulator /= memory[location];
                    j++;
                    break;
                case 33:
                    accumulator *= memory[location];
                    j++;
                    break;
                case 40:
                    j = location;
                    break;
                case 41:
                    j = accumulator < 0? location : j + 1;
                    break;
                case 42:
                    j = accumulator == 0? location : j + 1;
                    break;
                case 43:
                default:
                    j = 101;
                    break;
            }
            
        }

    }
}
