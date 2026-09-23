namespace Simpletron;

class Program
{

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

        string path = "/home/ayesh/workspace/dev/Simpletron/file.sml";

        
        Console.WriteLine(welcomeMsg);

        SimpletronSimulator simulator = new SimpletronSimulator();
        simulator.Run(path);
    }
}
