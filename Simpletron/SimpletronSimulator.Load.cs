namespace Simpletron;

public partial class SimpletronSimulator
{
    private void Load(string path)
    {

        // get the extension of the source file
        string ext = Path.GetExtension(path);

        instructionCounter = 0;
        // check if the extension of src file is .sml
        if (ext.Equals(".sml"))
        {
            // load the sml program
            string[] instructions = File.ReadAllLines(path);
            foreach (var i in instructions)
            {
                instructionRegister = Math.Abs(int.Parse(i));

                if (instructionRegister > 9999)
                {
                    throw new Exception($"Instruction {instructionRegister} not Valid");
                }
                memory[instructionCounter++] = instructionRegister;
            }
            Console.WriteLine("*** Program loading completed ***");
        }
        else
        {
            // throw exception
            throw new Exception($"Not Valid Source file: {path}");
        }
    }
}