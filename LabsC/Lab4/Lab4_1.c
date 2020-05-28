#include <stdio.h>
#include <conio.h>
#define size 256

void main()
{
	char stop[] = "stop";
	char str[size] = { 0 };
	char slova[size * 5] = { 0 };
	int Slov = 0;
	int flag, flags, i, j, k, slovaindex;
	printf("\nInput text ,for end write stop with a new line :");
	slovaindex = 0;
	while (strcmp(str, stop))
	{
		gets(str);
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == ' ') continue;     // ������� ��������

			flag = 0;
			j = i;
			for (; str[i + 1] != ' ' && str[i + 1] != '\0'; i++)   //�������� �� ���������������
				if (tolower(str[i]) > tolower(str[i + 1])) { flag = 1; break; }
			if (!flag)
			{
				for (; j <= i; j++)
				{
					slova[slovaindex] = str[j];
					slovaindex++;
				}
				slova[slovaindex] = ' ';
				slovaindex++;
			}
			while (str[i] != ' ' && str[i] != '\0') i++; i--;
		}
	}
	printf("%s", slova);
	(void)_getch();
}
