using System;

namespace LAB8
{
    class Program
    {
        static void STO(Audi car)
        {
            car.STOandTwistMileage += delegate
            {
                car.STOandTwistingMiliage();
            };
            car.STO();
        }

        static void Crash(Audi car)
        {
            car.Crasher += delegate
            {
                car.Crash();
            };
            car.Crashing();
        }

        static void Main(string[] args)
        {
            DateTime yearofcreate = new DateTime(2013, 7, 20);
            Audi audi = new Audi(Audi.Color.Синий, 30000, 200, yearofcreate);
            audi.Message += ShowInfo;
            audi.RegisterHandler(new Transport.InfoHandler(ShowInfo));
            audi.Move();
            audi.Refueling();
            Console.WriteLine(audi.ToString());
            Crash(audi);
            STO(audi);
            Console.WriteLine(audi.ToString());
        }

        static void ShowInfo(string message)
        {
            Console.WriteLine(message);
        }
    }
}
