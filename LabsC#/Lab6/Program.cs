using System;

namespace Lab6
{
    class Program
    {
        static void Moving(IMovable movable)
        {
            movable.Move();
        }
        struct nonMove : IMovable
        {
            public void Move() { Console.WriteLine("GG"); }
        }

        static void Main()
        {
            Jugyli j1 = new Jugyli(Avto.Color.Белый, 500, 400, DateTime.Now);
            Jugyli j2 = new Jugyli(Avto.Color.Желтый, 400, 4000, DateTime.Now);
            Jugyli j3 = new Jugyli(Avto.Color.Розовый, 300, 300, DateTime.Now);
            Audi a1 = new Audi(Avto.Color.Красный, 300, 400, DateTime.Now);


            Jugyli[] jugylis = new Jugyli[] { j1, j2, j3 };
            for (int i = 0; i < jugylis.Length; i++)
            {
                Console.WriteLine(jugylis[i].ToString());
            }
            Console.WriteLine("Сортировка по цене.....\n");
            Array.Sort(jugylis);
            for (int i = 0; i < jugylis.Length; i++)
            {
                Console.WriteLine(jugylis[i].ToString());
            }
            Moving(a1);
            for (int i = 0; i < jugylis.Length; i++)
            {
                Moving(jugylis[i]);
            }
            nonMove nonMove = new nonMove();
            Moving(nonMove);
        }
    }
}
