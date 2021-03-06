﻿using System;
namespace LAB8
{
    class Transport : IComparable, IMovable
    {

        public delegate void Handler();
        public delegate void InfoHandler(string message);
        public InfoHandler Message;
        public void RegisterHandler(InfoHandler message)
        {
            Message = message;
        }

        public virtual int CompareTo(object obj)
        {
            Transport p = obj as Transport;
            if (p != null) return this.speed.CompareTo(p.speed);
            else
                throw new NotImplementedException();
        }

        public enum TypeOfMedium : byte
        {
            Ground,
            Air,
            Water,
            Space
        }
        protected virtual TypeOfMedium TypeOfM { get; set; }
        public enum ByAppointment : byte
        {
            Cargo,
            Passenger,
            Any
        }
        protected virtual ByAppointment ByApp { get; set; }
        protected virtual int speed { get; set; }
        protected virtual int procentoffuel { get; set; }
        protected virtual int capasity { get; set; }
        protected virtual bool working { get; set; } = true;

        public static int counter = 0;

        public Transport()
        {
            TypeOfM = TypeOfMedium.Ground;
            ByApp = ByAppointment.Passenger;
            speed = 0;
            working = true;
            procentoffuel = 100;
            capasity = 4;
            counter++;
        }

        public Transport(int speed, int fuel, int capasity, Transport.TypeOfMedium TypeOfM, Transport.ByAppointment ByApp, bool working)
        {
            this.speed = speed;
            procentoffuel = fuel;
            this.capasity = capasity;
            this.TypeOfM = TypeOfM;
            this.ByApp = ByApp;
            this.working = working;
            counter++;
        }

        public override string ToString()
        {
            string returning = $"Транспорт:";
            switch (TypeOfM)
            {
                case TypeOfMedium.Ground: returning += "наземный"; break;
                case TypeOfMedium.Air: returning += "воздушный"; break;
                case TypeOfMedium.Space: returning += "космический"; break;
                case TypeOfMedium.Water: returning += "водный"; break;

            }
            switch (ByApp)
            {
                case ByAppointment.Passenger: returning += ",пассажирский"; break;
                case ByAppointment.Cargo: returning += ",грузовой"; break;
                case ByAppointment.Any: returning += ",любой"; break;
            }
            if (working) { returning += $"\nРаботает"; } else returning += $"\nНе работает";
            returning += $"\nВместимость: {capasity} ";
            returning += $"\nСкорость:{speed}";
            returning += $"\nПроцент топлива:{procentoffuel}";
            return returning;
        }

        public virtual void Move()
        {
            if (working)
            {
                if (speed > 0)
                {
                    while (procentoffuel > 0)
                    {
                        procentoffuel -= (speed / 5);
                        if (TypeOfM == TypeOfMedium.Ground) Message("Едем");
                        if (TypeOfM == TypeOfMedium.Air) Message("Летим");
                        if (TypeOfM == TypeOfMedium.Water) Message("Плывем");
                        if (TypeOfM == TypeOfMedium.Space) Message("Земля в иллюминаторе");
                    }
                    Message("Топливо закончилось");
                }
                else Message("Скорость-0!");

            }
            else Message("Сломан!");
        }
        public virtual void Refueling()
        {
            if (procentoffuel < 100)
            {
                Message("Заправка...\n");
                procentoffuel = 100;
            }
        }

        public event Handler Crasher;
        public void Crash()
        {
            Message("Случилось ужасное(");
            working = false;
            speed = 0;
        }
        public virtual void Crashing() => Crasher?.Invoke();
        

    }
}
