using System;
using System.Runtime.InteropServices;

namespace Zad2
{
    class DLLImport
    {
        [DllImport("Dll.dll", CallingConvention = CallingConvention.StdCall)]
        static extern int Sum(int a, int b);

        [DllImport("DLL.dll", CallingConvention = CallingConvention.StdCall)]
        static extern int Diff(int a, int b);

        [DllImport("DLL.dll", CallingConvention = CallingConvention.StdCall)]
        static extern int Mult(int a, int b);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.StdCall)]
        static extern int Abs(int a);

        [DllImport("Dll.dll", CallingConvention = CallingConvention.StdCall)]
        static extern float Average(float a, float b);

        static void Input(ref int n)
        {
            while (!int.TryParse(Console.ReadLine(), out n))
            {
                Console.WriteLine("Ошибка ввода!Введите целое число");
            }
        }

        static void Main()
        {
            Console.WriteLine("First nomber:");
            int a = 0;
            Input(ref a);
            Console.WriteLine("Second nomber:");
            int b = 0;
            Input(ref b);
            Console.WriteLine($"a={a}\tb={b}");
            Console.WriteLine("Sum of a and d: " + Sum(a, b));
            Console.WriteLine("Difference between a and b: " + Diff(a, b));
            Console.WriteLine("Multiplication a and b: " + Mult(a, b));
            Console.WriteLine($"Module of a={Abs(a)},of b={Abs(b)}");
            Console.WriteLine("Average of a and b: " + Average((float)a, (float)b));

        }
    }
}
