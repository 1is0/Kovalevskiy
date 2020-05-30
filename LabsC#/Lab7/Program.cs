using System;

namespace Lab7
{
    class Program
    {
        public static RealNumber GetFractionFromString()
        {
            Console.Write("Fraction: ");
            string str = Console.ReadLine();
            while (!CheckFraction(str))
            {
                Console.Write("Error, repeat: ");
                str = Console.ReadLine();
            }

            try
            {
                string[] arr = str.Split('/');
                return new RealNumber(int.Parse(arr[0]), int.Parse(arr[1]));
            }
            catch
            {
                return new RealNumber(int.Parse(str), 1);
            }
        }

        public static RealNumber Enter()
        {
            int a;
            Console.WriteLine("Input 0 to write nomber as fraction or 1 for default number: ");
            while (!int.TryParse(Console.ReadLine(), out a) || a < 0 || a > 1)
            {
                Console.Write("Error, repeat: ");
            }
            if (a == 0) return GetFractionFromString();
            else return GetNumber();
        }

        public static int CheckNaturalNomber()
        {
            int a;
            while (!int.TryParse(Console.ReadLine(), out a) || a <= 0)
                Console.Write("Error, repeat: ");
            return a;
        }

        public static int CheckIntNomber()
        {
            int a;
            while (!int.TryParse(Console.ReadLine(), out a))
                Console.Write("Error, repeat: ");
            return a;
        }

        public static double CheckDouble()
        {
            double a;
            while (!double.TryParse(Console.ReadLine(), out a))
                Console.Write("Error, repeat: ");
            return a;
        }

        public static bool CheckFraction(string fraction)
        {
            for (int i = 0; i < fraction.Length; i++)
            {
                if (i == 0 && fraction[i] == '-') i++;
                if (fraction[i] == '/' && i != fraction.Length - 1) i++;
                if (!char.IsDigit(fraction[i]) || (fraction[i] == '0' && i == fraction.Length - 1 && fraction[i - 1] == '/')) return false;
            }
            return true;
        }

        public static RealNumber GetNumber()
        {
            Console.Write("Number: ");
            double number = CheckDouble();
            return new RealNumber(number);
        }





        static void Main()
        {
            Console.WriteLine("Input first number");
            var numberone = Enter();
            Console.WriteLine("Input second number");
            var numbertoo = Enter();
            Console.WriteLine("First number:\n" + numberone);
            Console.WriteLine("Second number:\n" + numbertoo);
            int i = 1;
            Console.WriteLine($"{i++}. {numberone.ShowFraction} > {numbertoo.ShowFraction} = " + (numberone > numbertoo));
            Console.WriteLine($"   {numberone.ShowDefNumber} > {numbertoo.ShowDefNumber} = " + (numberone > numbertoo) + "\n");
            Console.WriteLine($"{i++}. {numberone.ShowFraction} < {numbertoo.ShowFraction} = " + (numberone < numbertoo));
            Console.WriteLine($"   {numberone.ShowDefNumber} < {numbertoo.ShowDefNumber} = " + (numberone < numbertoo) + "\n");
            Console.WriteLine($"{i++}. {numberone.ShowFraction} == {numbertoo.ShowFraction} = " + (numberone == numbertoo));
            Console.WriteLine($"   {numberone.ShowDefNumber} == {numbertoo.ShowDefNumber} = " + (numberone == numbertoo) + "\n");
            Console.WriteLine($"{i++}. {numberone.ShowFraction} != {numbertoo.ShowFraction} = " + (numberone != numbertoo));
            Console.WriteLine($"   {numberone.ShowDefNumber} != {numbertoo.ShowDefNumber} = " + (numberone != numbertoo) + "\n");
            Console.WriteLine($"{i++}. {numberone.ShowFraction} + {numbertoo.ShowFraction} = " + (numberone + numbertoo).ShowFraction);
            Console.WriteLine($"   {numberone.ShowDefNumber} + {numbertoo.ShowDefNumber} = " + (numberone + numbertoo).ShowDefNumber + "\n");
            Console.WriteLine($"{i++}. {numberone.ShowFraction} - {numbertoo.ShowFraction} = " + (numberone - numbertoo).ShowFraction);
            Console.WriteLine($"   {numberone.ShowDefNumber} - {numbertoo.ShowDefNumber} = " + (numberone - numbertoo).ShowDefNumber + "\n");
            Console.WriteLine($"{i++}. {numberone.ShowFraction} * {numbertoo.ShowFraction} = " + (numberone * numbertoo).ShowFraction);
            Console.WriteLine($"   {numberone.ShowDefNumber} * {numbertoo.ShowDefNumber} = " + (numberone * numbertoo).ShowDefNumber + "\n");
            if (numbertoo != 0)
            {
                Console.WriteLine($"{i}. {numberone.ShowFraction} / {numbertoo.ShowFraction} = " + (numberone / numbertoo).ShowFraction);
                Console.WriteLine($"   {numberone.ShowDefNumber} / {numbertoo.ShowDefNumber} = " + (numberone / numbertoo).ShowDefNumber + "\n");
            }
        }
    }
}
