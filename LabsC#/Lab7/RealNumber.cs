using System;

namespace Lab7
{
    class RealNumber : IEquatable<RealNumber>, IComparable
    {
        public int IntegerNomber { get; set; }
        public int NaturalNomber { get; set; }
        double number;

        public RealNumber()
        {
            IntegerNomber = 1;
            NaturalNomber = 1;
        }

        public RealNumber(int i, int n)
        {
            IntegerNomber = i;
            NaturalNomber = n;
            number = (double)IntegerNomber / NaturalNomber;
        }

        public RealNumber(double num)
        {
            number = num;
            int count = -1;
            if (num % 10 == 0)
            {
                IntegerNomber = (int)num;
                NaturalNomber = 1;
                number = num;
            }
            else
            {
                for (int i = 0; (float)num % 10 != 0 || Math.Abs(num) < 1; i++)
                {
                    num *= 10;
                    count++;
                }
                num /= 10;
                IntegerNomber = (int)num;
                NaturalNomber = (int)Math.Pow(10, count);
            }
        }

        public string ShowDefNumber => $"{number}";

        public string ShowFraction => $"{IntegerNomber}/{NaturalNomber}";

        public override string ToString()
        {
            return "Number: " + ShowDefNumber + "\nFraction: " + ShowFraction + "\n";
        }

        public static bool operator >(RealNumber num1, RealNumber num2) => num1.number > num2.number;

        public static bool operator <(RealNumber num1, RealNumber num2) => num1.number < num2.number;

        public static bool operator ==(RealNumber num1, RealNumber num2) => num1.Equals(num2);

        public static bool operator !=(RealNumber num1, RealNumber num2) => !num1.Equals(num2);

        public static RealNumber operator +(RealNumber num1, RealNumber num2)
        {
            RealNumber num = new RealNumber();
            num.IntegerNomber = num1.IntegerNomber * num2.NaturalNomber + num2.IntegerNomber * num1.NaturalNomber;
            num.NaturalNomber = num1.NaturalNomber * num2.NaturalNomber;
            num.number = num1.number + num2.number;
            return num;
        }

        public static RealNumber operator -(RealNumber num1, RealNumber num2)
        {
            RealNumber num = new RealNumber();
            num.IntegerNomber = num1.IntegerNomber * num2.NaturalNomber - num2.IntegerNomber * num1.NaturalNomber;
            num.NaturalNomber = num1.NaturalNomber * num2.NaturalNomber;
            num.number = num1.number - num2.number;
            return num;
        }

        public static RealNumber operator *(RealNumber num1, RealNumber num2)
        {
            RealNumber num = new RealNumber();
            num.IntegerNomber = num1.IntegerNomber * num2.IntegerNomber;
            num.NaturalNomber = num1.NaturalNomber * num2.NaturalNomber;
            num.number = num1.number * num2.number;
            return num;
        }

        public static RealNumber operator /(RealNumber num1, RealNumber num2)
        {
            RealNumber num = new RealNumber();
            num.IntegerNomber = num1.IntegerNomber * num2.NaturalNomber;
            num.NaturalNomber = num1.NaturalNomber * num2.IntegerNomber;
            if (num1 < 0 || num2 < 0)
            {
                num.IntegerNomber = -num.IntegerNomber;
                num.NaturalNomber = Math.Abs(num.NaturalNomber);
            }
            num.number = num1.number / num2.number;
            return num;
        }

        public override bool Equals(object obj) => ((RealNumber)obj).number == this.number;

        public override int GetHashCode() => this.ToString().GetHashCode();

        public static implicit operator int(RealNumber num) => (int)num.number;

        public static implicit operator double(RealNumber num) => num.number;

        bool IEquatable<RealNumber>.Equals(RealNumber num) => this.number == num.number;

        int IComparable.CompareTo(object obj)
        {
            if (this.number > ((RealNumber)obj).number) return 1;
            if (this.number < ((RealNumber)obj).number) return -1;
            else return 0;
        }
    }
}
