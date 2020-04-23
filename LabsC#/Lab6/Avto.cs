﻿using System;
using System.Collections.Generic;
using System.Text;

namespace Lab6
{

    abstract class Avto : Transport
    {

        public override int CompareTo(object obj)
        {
            Avto p = obj as Avto;
            if (p != null) return this._Info.price.CompareTo(p._Info.price);
            else
                throw new NotImplementedException();
        }
        public enum Color : byte
        {
            Красный,
            Серый,
            Голубой,
            Синий,
            Зеленый,
            Желтый,
            Розовый,
            Оранжевый,
            Коричневый,
            Белый,
            Черный,
            Фиолетовый
        }

        public struct Info
        {
            public int mileage;
            public int price;
            public DateTime ReleaseDate;
        }
        public Info _Info;

        public Color _color { get; set; }
        public string carmake { get; set; }
        public string country { get; set; }
        protected override TypeOfMedium TypeOfM { get; set; } = TypeOfMedium.Ground;

        public override string ToString()
        {
            return base.ToString() + $"\nМодель:{carmake}\nСтрана производства:{country}" +
                $"\nЦвет:{_color.ToString()}\nПробег:{_Info.mileage}\nЦена:{_Info.price}\nГод выпуска:{_Info.ReleaseDate.Year}";
        }
        public override void Move()
        {
            base.Move();
        }
        public override void Refueling()
        {
            base.Refueling();
        }
    }




    class Jugyli : Avto
    {
        public Jugyli(Color _color, int price, int mileage, DateTime dateRelease)
        {
            carmake = "Jugyli";
            country = "Russia";
            ByApp = ByAppointment.Any;
            working = false;
            speed = 60;
            capasity = 8;
            this._color = _color;
            _Info.price = price;
            _Info.mileage = mileage;
            _Info.ReleaseDate = dateRelease;
        }
        public override string ToString()
        {
            return "\n***Это ЖИГУЛИ***\n" + base.ToString() + "\n***********************\n";
        }
        public override void Move()
        {
            Console.WriteLine("\nТребуется ремонт.");
        }
        public override void Refueling()
        {
            Console.WriteLine("\nДо заправки не доедет.");
        }
    }

    class Audi : Avto
    {
        public Audi(Color _color, int price, int mileage, DateTime dateRelease)
        {
            carmake = "Audi";
            country = "Germany";
            ByApp = ByAppointment.Passenger;
            working = true;
            speed = 250;
            capasity = 4;
            this._color = _color;
            _Info.price = price;
            _Info.mileage = mileage;
            _Info.ReleaseDate = dateRelease;

        }
        public override string ToString()
        {
            return "***Это AUDI***\n" + base.ToString() + "\n*********************\n";
        }
        public override void Move()
        {
            Console.WriteLine("Движется AUDI");
            base.Move();
        }
    }
}
