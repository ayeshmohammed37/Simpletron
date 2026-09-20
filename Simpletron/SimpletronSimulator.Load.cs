namespace Simpletron;

public partial class SimpletronSimulator
{
    private void Load()
    {
        instructionCounter = 0;
        while (instructionCounter < 100)
        {
            Console.Write($"{instructionCounter:00} ? ");
            instructionRegister = Math.Abs(int.Parse(Console.ReadLine()));

            if (instructionRegister <= 9999)
            {
                memory[instructionCounter++] = instructionRegister;
            }
            else if (instructionRegister == 99999)
            {
                Console.WriteLine("*** Program loading completed ***");
                instructionCounter = 101;
            }
        }
    }
}