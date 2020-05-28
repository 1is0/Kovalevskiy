#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int sheeps(int pole[10][10]) {
	int i, j, f, k, r;
	int rand_chislo, rand_chislo1, ts, s;


	srand(time(NULL));

	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			pole[i][j] = 0;

	do {
		f = 0;
		rand_chislo = 0 + rand() % 10;
		rand_chislo1 = 0 + rand() % 10;

		ts = 1 + rand() % 4;

		if (ts == 1) {
			for (i = 0; i < 3; i++)
				if (rand_chislo == i)
					f = 1;
		}
		if (ts == 2) {
			for (i = 7; i < 10; i++)
				if (rand_chislo == i)
					f = 1;
		}
		if (ts == 3) {
			for (i = 0; i < 3; i++)
				if (rand_chislo1 == i)
					f = 1;
		}
		if (ts == 4) {
			for (i = 7; i < 10; i++)
				if (rand_chislo1 == i)
					f = 1;
		}
	} while (f == 1);
	switch (ts) {
	case 1:
		pole[rand_chislo][rand_chislo1] = 1;
		pole[rand_chislo - 1][rand_chislo1] = 1;
		pole[rand_chislo - 2][rand_chislo1] = 1;
		pole[rand_chislo - 3][rand_chislo1] = 1;
		break;
	case 2:
		pole[rand_chislo][rand_chislo1] = 1;
		pole[rand_chislo + 1][rand_chislo1] = 1;
		pole[rand_chislo + 2][rand_chislo1] = 1;
		pole[rand_chislo + 3][rand_chislo1] = 1;
		break;
	case 3:
		pole[rand_chislo][rand_chislo1] = 1;
		pole[rand_chislo][rand_chislo1 - 1] = 1;
		pole[rand_chislo][rand_chislo1 - 2] = 1;
		pole[rand_chislo][rand_chislo1 - 3] = 1;
		break;
	case 4:
		pole[rand_chislo][rand_chislo1] = 1;
		pole[rand_chislo][rand_chislo1 + 1] = 1;
		pole[rand_chislo][rand_chislo1 + 2] = 1;
		pole[rand_chislo][rand_chislo1 + 3] = 1;
		break;
	}

	for (k = 0; k < 3; k++)
	{
		do {
			f = 0;
			rand_chislo = 0 + rand() % 10;
			rand_chislo1 = 0 + rand() % 10;

			ts = 1 + rand() % 4;

			if (ts == 1) {
				if (rand_chislo != 0) {
					for (i = rand_chislo - 2; i < rand_chislo + 2; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else
					f = 1;
			}
			if (ts == 2) {
				if (rand_chislo != 9) {
					for (i = rand_chislo - 1; i <= rand_chislo + 2; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else
					f = 1;
			}
			if (ts == 3) {
				if (rand_chislo1 != 0) {
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 2; j <= rand_chislo1 + 1; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else
					f = 1;
			}
			if (ts == 4) {
				if (rand_chislo1 != 9) {
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 2; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else
					f = 1;
			}
		} while (f == 1);
		switch (ts) {
		case 1:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo - 1][rand_chislo1] = 1;
			break;
		case 2:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo + 1][rand_chislo1] = 1;
			break;
		case 3:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo][rand_chislo1 - 1] = 1;
			break;
		case 4:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo][rand_chislo1 + 1] = 1;
			break;
		}

	}

	for (k = 0; k < 2; k++)
	{
		do {
			f = 0;
			rand_chislo = 0 + rand() % 10;
			rand_chislo1 = 0 + rand() % 10;

			ts = 1 + rand() % 4;

			if (ts == 1) {
				if (rand_chislo != 0 && rand_chislo != 1) {
					for (i = rand_chislo - 3; i < rand_chislo + 2; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else
					f = 1;
			}
			if (ts == 2) {
				if (rand_chislo != 9 && rand_chislo != 8) {
					for (i = rand_chislo - 1; i <= rand_chislo + 3; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 1; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else
					f = 1;
			}
			if (ts == 3) {
				if (rand_chislo1 != 0 && rand_chislo1 != 1) {
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 3; j <= rand_chislo1 + 1; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else
					f = 1;
			}
			if (ts == 4) {
				if (rand_chislo1 != 9 && rand_chislo1 != 8) {
					for (i = rand_chislo - 1; i <= rand_chislo + 1; i++)
						for (j = rand_chislo1 - 1; j <= rand_chislo1 + 3; j++) {
							if (pole[i][j] != 0) {
								f = 1;
							}
						}
				}
				else
					f = 1;
			}
		} while (f == 1);
		switch (ts) {
		case 1:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo - 1][rand_chislo1] = 1;
			pole[rand_chislo - 2][rand_chislo1] = 1;
			break;
		case 2:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo + 1][rand_chislo1] = 1;
			pole[rand_chislo + 2][rand_chislo1] = 1;
			break;
		case 3:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo][rand_chislo1 - 1] = 1;
			pole[rand_chislo][rand_chislo1 - 2] = 1;
			break;
		case 4:
			pole[rand_chislo][rand_chislo1] = 1;
			pole[rand_chislo][rand_chislo1 + 1] = 1;
			pole[rand_chislo][rand_chislo1 + 2] = 1;
			break;
		}
	}

	for (i = 0; i < 4; i++)
	{
		do {
			rand_chislo = 0 + rand() % 10;
			rand_chislo1 = 0 + rand() % 10;
		} while (pole[rand_chislo][rand_chislo1] != 0 ||
			pole[rand_chislo + 1][rand_chislo1] != 0 ||
			pole[rand_chislo - 1][rand_chislo1] != 0 ||
			pole[rand_chislo][rand_chislo1 + 1] != 0 ||
			pole[rand_chislo][rand_chislo1 - 1] != 0 ||
			pole[rand_chislo + 1][rand_chislo1 + 1] != 0 ||
			pole[rand_chislo - 1][rand_chislo1 - 1] != 0 ||
			pole[rand_chislo + 1][rand_chislo1 - 1] != 0 ||
			pole[rand_chislo - 1][rand_chislo1 + 1] != 0);

		pole[rand_chislo][rand_chislo1] = 1;
	}
	return pole[10][10];
}
int main(void)
{
	int pole[10][10];
	int i = 0;
	int j = 0;
	sheeps(pole);
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%d ", pole[i][j]);
		}
		printf("\n");
	}
	(void)_getch();
}
