#include "Lab7.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

OList* Owners = NULL;
BList* Buyers = NULL;
Buyer* buyer = NULL;
Owner* owner = NULL;

int CheckInt() {
	int choice;
	while (!(scanf("%d", &choice)) || choice < 1) {
		printf("\nError,please try again!");
		rewind(stdin);
	}
	return choice;
}

OList* CreateOList() {
	OList* Temp = (OList*)malloc(sizeof(OList));
	if (Temp)
	{
		Temp->head = NULL;
		Temp->size = 0;
		return Temp;
	}
	else {
		printf("\nError!");
		return NULL;
	}
}

BList* CreateBList() {
	BList* Temp = (BList*)malloc(sizeof(BList));
	if (Temp)
	{
		Temp->head = NULL;
		Temp->size = 0;
		return Temp;
	}
	else {
		printf("\nError!");
		return NULL;
	}
}

Owner* CreateOwner()
{
	Owner* Temp = (Owner*)malloc(sizeof(Owner));
	if (Temp)
	{
		return Temp;
	}
	else {
		printf("\nError!");
		return NULL;
	}
}

Buyer* CreateBuyer()
{
	Buyer* Temp = (Buyer*)malloc(sizeof(Buyer));
	if (Temp)
	{
		return Temp;
	}
	else {
		printf("\nError!");
		return NULL;
	}
}

void push_Buyer(Buyer* data) {

	if (Buyers->head == NULL) {
		buyer = CreateBuyer();
		buyer = data;
		Buyers->head = buyer;
		buyer->next = NULL;

	}
	else {

		while (buyer->next != NULL) {
			buyer = buyer->next;
		}

		buyer->next = data;
		buyer->next->next = NULL;
		buyer = Buyers->head;
	}
	Buyers->size++;
}

void push_Owner(Owner* data) {

	if (Owners->head == NULL) {
		owner = CreateOwner();
		owner = data;
		Owners->head = owner;
		owner->next = NULL;

	}
	else {

		while (owner->next != NULL) {
			owner = owner->next;
		}

		owner->next = data;
		owner->next->next = NULL;
		owner = Owners->head;
	}
	Owners->size++;
}

void AddBuyer()
{
	Buyer* tmp = (Buyer*)malloc(sizeof(Buyer));
	if (tmp) {
		printf("\n%s", "Input phonenomber:");
		(void)scanf("%s", &tmp->phonenomber);
		printf("\n%s", "Input email:");
		(void)scanf("%s", &tmp->email);
		printf("\n%s", "Input max price of flat :");
		tmp->maxprice = CheckInt();
		printf("\n%s", "Input min price of flat :");
		tmp->minprice = CheckInt();
		printf("\n%s", "Input max area of flat:");
		tmp->maxarea = CheckInt();
		printf("\n%s", "Input min area of flat:");
		tmp->minarea = CheckInt();
		printf("\n%s", "Input type:");
		printf("\n%s\n", "1.Studio 2.IsolatedRooms 3.ConnectingRooms 4.FreeLayout");
		int i = 0;
		do
		{
			(void)scanf("%d", &i);
			if (i <= 0 || i > 4)printf("\n%s\n", "Error.Try again.");
		} while (i <= 0 || i > 4);

		switch (i)
		{
		case 1:tmp->type = Studio; break;
		case 2:tmp->type = IsolatedRooms; break;
		case 3:tmp->type = ConnecRooms; break;
		case 4: tmp->type = FreeLayout; break;
		}
		push_Buyer(tmp);
		printf("%s", "Input any key to return in menu.");
		(void)_getch();
	}
}

void AddOwner()
{
	Owner* tmp = (Owner*)malloc(sizeof(Owner));
	if (tmp) {
		printf("\n%s", "Input region:");
		(void)scanf("%s", &tmp->region);
		printf("\n%s", "Input adress:");
		(void)scanf("%s", &tmp->adress);
		printf("\n%s", "Input floor:");
		tmp->floor = CheckInt();
		printf("\n%s", "Input area:");
		tmp->area = CheckInt();
		printf("\n%s", "Input type:");
		printf("\n%s\n", "1.Studio 2.IsolatedRooms 3.ConnectingRooms 4.FreeLayout");
		int i = 0;
		do
		{
			(void)scanf("%d", &i);
			if (i <= 0 || i > 4)printf("\n%s\n", "Error.Try again.");
		} while (i <= 0 || i > 4);

		switch (i)
		{
		case 1:tmp->type = Studio; break;
		case 2:tmp->type = IsolatedRooms; break;
		case 3:tmp->type = ConnecRooms; break;
		case 4: tmp->type = FreeLayout; break;
		}
		printf("\n%s", "Input price:");
		tmp->price = CheckInt();
		push_Owner(tmp);
		printf("%s", "Input any key to return in menu.");
		(void)_getch();
	}
}

void delfirstB() {
	Buyer* tmp = Buyers->head;
	Buyers->head = Buyers->head->next;
	free(tmp);
	Buyers->size--;
}

void deleteindexB(int index) {
	if (!Buyers->head) {
		return;
	}
	if (index == 0) {
		delfirstB();
	}
	else {
		Buyer* previous = Buyers->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->next;
		}

		Buyer* toDelete = previous->next;

		previous->next = toDelete->next;

		free(toDelete);

		Buyers->size--;
	}
}

void clearBuyers() {
	while (Buyers->size) {
		delfirstB();
	}
}

void ListBFromFile() {
	FILE* fout = fopen("Buyers.bin", "rb");
	if (fout) {
		int count = 0;
		while (!feof(fout)) {
			if (fgetc(fout) == '\n')
				count++;
		}
		fseek(fout, 0, 0);
		for (int i = 0; i < count; i++) {
			Buyer* TEMP = CreateBuyer();
			fread(TEMP, sizeof(Buyer), 1, fout);
			push_Buyer(TEMP);
			fgetc(fout);
		}
		fseek(fout, 0, 0);

		fclose(fout);
	}
}

void ListInFileB() {
	FILE* fin = fopen("Buyers.bin", "wb");
	if (fin) {
		while (buyer) {
			fwrite(buyer, sizeof(Buyer), 1, fin);
			fputc('\n', fin);
			buyer = buyer->next;
		}
		buyer = Buyers->head;
		fclose(fin);
	}

}

void delfirst() {
	Owner* tmp = Owners->head;
	Owners->head = Owners->head->next;
	free(tmp);
	Owners->size--;
}

void deleteindex(int index) {
	if (!Owners->head) {
		return;
	}
	if (index == 0) {
		delfirst();
	}
	else {
		Owner* previous = Owners->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->next;
		}

		Owner* toDelete = previous->next;

		previous->next = toDelete->next;

		free(toDelete);

		Owners->size--;
	}
}

void clearOwners() {
	while (Owners->size) {
		delfirst();
	}
}

void ListFromFile() {
	FILE* fout = fopen("Owners.bin", "rb");
	if (fout) {
		int count = 0;
		while (!feof(fout)) {
			if (fgetc(fout) == '\n')
				count++;
		}
		fseek(fout, 0, 0);
		for (int i = 0; i < count; i++) {
			Owner* TEMP = CreateOwner();
			fread(TEMP, sizeof(Owner), 1, fout);
			push_Owner(TEMP);
			fgetc(fout);
		}
		fseek(fout, 0, 0);

		fclose(fout);
	}
}

void ListInFile() {
	FILE* fin = fopen("Owners.bin", "wb");
	if (fin) {
		while (owner) {
			fwrite(owner, sizeof(Owner), 1, fin);

			fputc('\n', fin);
			owner = owner->next;
		}
		owner = Owners->head;
		fclose(fin);
	}
}

void PrintBuyer(Buyer* data)
{
	//printf("\n%s", "************************");
	printf("\n%s%s", "Phonenomber:", data->phonenomber);
	printf("\n%s%s", "Email:", data->email);
	printf("\n%s%d", "Max area:", data->maxarea);
	printf("\n%s%d", "Min area:", data->minarea);
	printf("\n%s%d", "Max price:", data->maxprice);
	printf("\n%s%d", "Min price:", data->minprice);

	switch (data->type)
	{
	case Studio:printf("\n%s", "Type:Studio"); break;
	case IsolatedRooms:printf("\n%s", "Type:IsolatedRooms "); break;
	case ConnecRooms:printf("\n%s", "Type:ConnectingRooms"); break;
	case FreeLayout:printf("\n%s", "Type:FreeLayout"); break;
	}
	printf("\n");
}

void PrintOwner(Owner* data)
{
	//printf("\n%s", "************************");
	printf("\n%s%s", "Region:", data->region);
	printf("\n%s%s", "Adress:", data->adress);
	printf("\n%s%d", "Floor:", data->floor);
	printf("\n%s%d", "Area:", data->area);
	printf("\n%s%d", "Price:", data->price);
	switch (data->type)
	{
	case Studio:printf("\n%s", "Type:Studio"); break;
	case IsolatedRooms:printf("\n%s", "Type:IsolatedRooms "); break;
	case ConnecRooms:printf("\n%s", "Type:ConnectingRooms"); break;
	case FreeLayout:printf("\n%s", "Type:FreeLayout"); break;
	}
	printf("\n");
}



void PrintBuyers()
{
	int index = 1;
	if (Owners->size > 0) {
		printf("%s", "Buyers:");
		Buyer* tmp = Buyers->head;
		while (Buyers->head != NULL)
		{
			printf("\n************%d************", index);
			PrintBuyer(Buyers->head);
			Buyers->head = Buyers->head->next;
			index++;
		}
		Buyers->head = tmp;
	}
	else printf("\n%s", "List is empty!");
	printf("\n%s\n", "Input any key to return in menu.");
	(void)_getch();
}

void PrintOwners()
{
	int index = 1;
	if (Owners->size > 0) {
		printf("%s", "Owners:");
		Owner* tmp = Owners->head;
		while (Owners->head != NULL)
		{
			printf("\n************%d************", index);
			PrintOwner(Owners->head);
			Owners->head = Owners->head->next;
			index++;
		}
		Owners->head = tmp;
	}
	else printf("%s", "List is empty!");
	printf("%s\n", "Input any key to return in menu.");
	(void)_getch();
}

void SearchOwner()
{
	Owner* hd = Owners->head;
	int i = 0;
	printf("\n%s", "Choose field to search:");
	printf("\n%s", "1.Region.");
	printf("\n%s", "2.Adress.");
	printf("\n%s", "3.Area.");
	printf("\n%s", "4.Price.");
	printf("\n%s\n", "Type.");
	do
	{
		(void)scanf("%d", &i);
		if (i <= 0 || i > 5)printf("\n%s\n", "Error.Try again.");
	} while (i <= 0 || i > 5);
	switch (i)
	{
		char buff[20];

		Type temp;
		int find = 0;
	case 1:
		find = 0;
		printf("\n%s\n", "Input region to find:");
		(void)scanf("%s", buff);

		while (Owners->head)
		{
			if (strcmp(buff, Owners->head->region) == 0)
			{
				if (find == 0)
					printf("\n%s\n", "Find:");
				PrintOwner(Owners->head);
				find = 1;
			}
			Owners->head = Owners->head->next;
		}
		if (find == 0)printf("\n%s\n", "Not found.Change info to search.");
		break;
	case 2:
		find = 0;
		printf("\n%s\n", "Input adress to find:");
		(void)scanf("%s", buff);
		while (Owners->head)
		{
			if (strcmp(buff, Owners->head->adress) == 0)
			{
				if (find == 0)
					printf("\n%s\n", "Find:");
				PrintOwner(Owners->head);
				find = 1;
			}
			Owners->head = Owners->head->next;
		}
		if (find == 0)printf("\n%s\n", "Not found.Change info to search.");
		break;
		int tmp = 0;
	case 3:
		find = 0;
		printf("\n%s\n", "Input area of flat to find:");
		(void)scanf("%d", &tmp);
		while (Owners->head)
		{
			if (Owners->head->area == tmp)
			{
				if (find == 0)
					printf("\n%s\n", "Find:");
				PrintOwner(Owners->head);
				find = 1;
			}
			Owners->head = Owners->head->next;
		}
		if (find == 0)printf("\n%s\n", "Not found.Change info to search.");
		break;
	case 4:
		find = 0;
		printf("\n%s\n", "Input price of flat to find:");
		(void)scanf("%d", &tmp);
		while (Owners->head)
		{
			if (Owners->head->price == tmp)
			{
				if (find == 0)
					printf("\n%s\n", "Find:");
				PrintOwner(Owners->head);
				find = 1;
			}
			Owners->head = Owners->head->next;
		}
		if (find == 0)printf("\n%s\n", "Not found.Change info to search.");
		break;
	case 5:
		find = 0;
		printf("\n%s", "Input type to find:");
		printf("\n%s\n", "1.Studio 2.IsolatedRooms 3.ConnectingRooms 4.FreeLayout");
		int i = 0;
		do
		{
			(void)scanf("%d", &i);
			if (i <= 0 || i > 4)printf("\n%s\n", "Error.Try again.");
		} while (i <= 0 || i > 4);
		switch (i)
		{
		case 1:temp = Studio; break;
		case 2:temp = IsolatedRooms; break;
		case 3:temp = ConnecRooms; break;
		case 4:temp = FreeLayout; break;
		}
		while (Owners->head)
		{
			if (Owners->head->type == temp)
			{
				if (find == 0)
					printf("\n%s\n", "Find:");
				PrintOwner(Owners->head);
				find = 1;
			}
			Owners->head = Owners->head->next;
		}
		if (find == 0)printf("\n%s\n", "Not found.Change info to search.");
		break;
	}
	Owners->head = hd;
}

void SearchBuyer()
{
	int i = 0;
	Buyer* hd = Buyers->head;
	printf("\n%s", "Choose field to search:");
	printf("\n%s", "1.Phonenomber:");
	printf("\n%s", "2.Email:");
	printf("\n%s", "3.Maxprice:");
	printf("\n%s", "4.Minprice:");
	printf("\n%s", "5.Maxarea:");
	printf("\n%s", "6.Minarea:");
	printf("\n%s", "7.Type:");
	do
	{
		(void)scanf("%d", &i);
		if (i <= 0 || i > 6)printf("\n%s\n", "Error.Try again.");
	} while (i <= 0 || i > 6);
	switch (i)
	{
		char buff[20];

		Type temp;
		int find = 0;
	case 1:
		find = 0;
		printf("\n%s\n", "Input phone to find:");
		(void)scanf("%s", buff);

		while (Buyers->head)
		{
			if (strcmp(buff, Buyers->head->phonenomber) == 0)
			{
				if (find == 0)
					printf("\n%s\n", "Find:");
				PrintBuyer(Buyers->head);
				find = 1;
			}
			Buyers->head = Buyers->head->next;
		}
		if (find == 0)printf("\n%s\n", "Not found.Change info to search.");
		break;
	case 2:
		find = 0;
		printf("\n%s\n", "Input email to find:");
		(void)scanf("%s", buff);
		while (Buyers->head)
		{
			if (strcmp(buff, Buyers->head->email) == 0)
			{
				if (find == 0)
					printf("\n%s\n", "Find:");
				PrintBuyer(Buyers->head);
				find = 1;
			}
			Buyers->head = Buyers->head->next;
		}
		if (find == 0)printf("\n%s\n", "Not found.Change info to search.");
		break;
		int tmp = 0;
	case 3:
		find = 0;
		printf("\n%s\n", "Input maxprice of flat to find:");
		(void)scanf("%d", &tmp);
		while (Buyers->head)
		{
			if (Buyers->head->maxprice == tmp)
			{
				if (find == 0)
					printf("\n%s\n", "Find:");
				PrintBuyer(Buyers->head);
				find = 1;
			}
			Buyers->head = Buyers->head->next;
		}
		if (find == 0)printf("\n%s\n", "Not found.Change info to search.");
		break;
	case 4:
		find = 0;
		printf("\n%s\n", "Input minprice of flat to find:");
		(void)scanf("%d", &tmp);
		while (Buyers->head)
		{
			if (Buyers->head->minprice == tmp)
			{
				if (find == 0)
					printf("\n%s\n", "Find:");
				PrintBuyer(Buyers->head);
				find = 1;
			}
			Buyers->head = Buyers->head->next;
		}
		if (find == 0)printf("\n%s\n", "Not found.Change info to search.");
		break;
	case 5:
		find = 0;
		printf("\n%s\n", "Input maxarea of flat to find:");
		(void)scanf("%d", &tmp);
		while (Buyers->head)
		{
			if (Buyers->head->maxarea == tmp)
			{
				if (find == 0)
					printf("\n%s\n", "Find:");
				PrintBuyer(Buyers->head);
				find = 1;
			}
			Buyers->head = Buyers->head->next;
		}
		if (find == 0)printf("\n%s\n", "Not found.Change info to search.");
		break;
	case 6:
		find = 0;
		printf("\n%s\n", "Input minarea of flat to find:");
		(void)scanf("%d", &tmp);
		while (Buyers->head)
		{
			if (Buyers->head->minarea == tmp)
			{
				if (find == 0)
					printf("\n%s\n", "Find:");
				PrintBuyer(Buyers->head);
				find = 1;
			}
			Buyers->head = Buyers->head->next;
		}
		if (find == 0)printf("\n%s\n", "Not found.Change info to search.");
		break;
	case 7:
		find = 0;
		printf("\n%s", "Input type to find:");
		printf("\n%s\n", "1.Studio 2.IsolatedRooms 3.ConnectingRooms 4.FreeLayout");
		int i = 0;
		do
		{
			(void)scanf("%d", &i);
			if (i <= 0 || i > 4)printf("\n%s\n", "Error.Try again.");
		} while (i <= 0 || i > 4);
		switch (i)
		{
		case 1:temp = Studio; break;
		case 2:temp = IsolatedRooms; break;
		case 3:temp = ConnecRooms; break;
		case 4:temp = FreeLayout; break;
		}
		while (Buyers->head)
		{
			if (Buyers->head->type == temp) {
				if (find == 0)
					printf("\n%s\n", "Find:");
				PrintBuyer(Buyers->head);
				find = 1;
			}
			Buyers->head = Buyers->head->next;
		}
		if (find == 0)printf("\n%s\n", "Not found.Change info to search.");
		break;
	}
	Buyers->head = hd;
}

void FinfOwnersToBuyers()
{
	Owner* tmp = Owners->head;
	Buyer* temp = Buyers->head;
	int found = 0;
	int i = 0;
	int k = 0;
	int true = 1;
	for (i = 0; i < Buyers->size; i++)
	{
		for (k = 0; k < Owners->size; k++)
		{
			true = 1;
			if (!(Owners->head->price<Buyers->head->maxprice &&
				Owners->head->price>Buyers->head->minprice))
			{
				true = 0; Owners->head = Owners->head->next; continue;
			}
			if (!(Owners->head->area<Buyers->head->maxarea &&
				Owners->head->area>Buyers->head->minarea))
			{
				true = 0; Owners->head = Owners->head->next; continue;
			}
			if (Owners->head->type != Buyers->head->type)
			{
				true = 0; Owners->head = Owners->head->next; continue;
			}
			if (true)
			{
				found = 1;
				printf("\n%s%d%s%d", "Find owner ", k + 1, " to buyer ", i + 1);
				printf("\n%s", "Accept deal:");
				printf("\n%s", "1.Yes.");
				printf("\n%s", "2.The deal fell through.Continue search.");
				int i = 0;
				do
				{
					(void)scanf("%d", &i);
					if (i <= 0 || i > 2)printf("\n%s\n", "Error Input.Try again.");
				} while (i <= 0 || i > 2);
				switch (i)
				{
				case 1:
					Owners->head = tmp;
					Buyers->head = temp;
					deleteindex(k);
					deleteindexB(i);
					i--;
					k--;
					break;
				case 2:
					Owners->head = Owners->head->next;
					continue;
					break;
				}
			}

		}
		Owners->head = tmp;
		Buyers->head = Buyers->head->next;
	}


	Buyers->head = temp;
	if (found == 0)printf("\n%s\n", "Owners to buyers not found.");
}

void FindExchanges()
{
	Owner* tmp = Owners->head;
	Owner* head = Owners->head->next;
	if (tmp && head) {
		int i = 0;
		int j = 0;
		int found = 0;
		int true = 1;
		for (i = 0; i < Owners->size; i++)
		{
			j = i + 1;
			head = Owners->head->next;
			while (head)
			{

				true = 1;
				//сделал границы в 10% для увеличения вариантов переселения
				//и также поиск только по 2ум критериям
				if (!((Owners->head->area + (Owners->head->area / 10)) > head->area &&
					(Owners->head->area - (Owners->head->area / 10)) < head->area))
				{
					j++; true = 0; head = head->next; continue;
				}
				if (!((Owners->head->price + (Owners->head->price / 10)) > head->price &&
					(Owners->head->price - (Owners->head->price / 10)) < head->price))
				{
					j++; true = 0; head = head->next; continue;
				}
				if (true)
				{
					found = 1;
					printf("\n%s", "Find possible housing exchange.");
					printf("\n%s", "Accept deal:");
					printf("\n%s", "1.Yes.");
					printf("\n%s\n", "2.The deal fell through.Continue search.");
					int k = 0;
					do
					{
						(void)scanf("%d", &k);
						if (k <= 0 || k > 2)printf("\n%s\n", "Error Input.Try again.");
					} while (k <= 0 || k > 2);
					Owner* buff = Owners->head->next;
					switch (k)
					{

					case 1:
						Owners->head = tmp;
						deleteindex(i);
						j--;

						deleteindex(j);
						j -= 2;
						i++;
						Owners->head = buff;
						head = Owners->head->next;
						break;
					case 2:
						j++;
						head = head->next;
						continue;
						break;
					}
				}
			}
			head = tmp;
			Owners->head = Owners->head->next;
		}
		Owners->head = tmp;
		if (found == 0)printf("\n%s\n", "Possible housing exchange not found.");
	}
	else printf("%s", "Error of memory!");
}

void menu()
{
	int index = 0;
	int i = -1;
	int k = 0;
	printf("\n%s", "*************************");
	printf("\n%s", "1.Print lists.");
	printf("\n%s", "2.Add element.");
	printf("\n%s", "3.Save to files.");
	printf("\n%s", "4.Clear lists.");
	printf("\n%s", "5.Search");
	printf("\n%s", "6.Delete one element with index.");
	printf("\n%s", "7.Search for possible deals.");
	printf("\n%s\n", "8.Find a possible housing exchange.");

	printf("\n%s", "0.Exit");
	printf("\n%s\n", "*************************");
	do
	{
		(void)scanf("%d", &i);
		if (i < 0 || i > 8)printf("\n%s\n", "Error.Try again.");
	} while (i < 0 || i > 8);
	switch (i)
	{
	case 1:
		printf("\n%s", "Choose list(s) to print:");
		printf("\n%s", "1.Owners.");
		printf("\n%s", "2.Buyers.");
		printf("\n%s\n", "3.Both.");
		do
		{
			(void)scanf("%d", &k);
			if (k <= 0 || k > 3)printf("\n%s\n", "Error.Try again.");
		} while (k <= 0 || k > 3);
		switch (k)
		{
		case 1:PrintOwners(); break;
		case 2:PrintBuyers(); break;
		case 3:PrintOwners(); PrintBuyers(); break;
		}
		break;
	case 2:
		printf("\n%s", "Choose element to add:");
		printf("\n%s", "1.Owner.");
		printf("\n%s\n", "2.Buyer.");
		do
		{
			(void)scanf("%d", &k);
			if (k <= 0 || k > 2)printf("\n%s\n", "Error.Try again.");
		} while (k <= 0 || k > 2);
		switch (k)
		{
		case 1:
			AddOwner();
			break;
		case 2:
			AddBuyer();
			break;
		}
		break;
	case 3:
		printf("\n%s", "Choose list(s) to save:");
		printf("\n%s", "1.Owners.");
		printf("\n%s", "2.Buyers.");
		printf("\n%s\n", "3.Both");
		do
		{
			(void)scanf("%d", &k);
			if (k <= 0 || k > 3)printf("\n%s\n", "Error.Try again.");
		} while (k <= 0 || k > 3);
		switch (k)
		{
		case 1:
			ListInFile();
			break;
		case 2:
			ListInFileB();
			break;
		case 3:
			ListInFile();
			ListInFileB();
			break;
		}
		break;
	case 4:
		printf("\n%s", "Choose list(s) to clear:");
		printf("\n%s", "1.Owners.");
		printf("\n%s", "2.Buyers.");
		printf("\n%s\n", "3.Both");
		do
		{
			(void)scanf("%d", &k);
			if (k <= 0 || k > 3)printf("\n%s\n", "Error.Try again.");
		} while (k <= 0 || k > 3);
		switch (k)
		{
		case 1:
			clearOwners();
			break;
		case 2:
			clearBuyers();
			break;
		case 3:
			clearOwners();
			clearBuyers();
			break;
		}
		break;
	case 5:
		printf("\n%s", "Choose from to seach:");
		printf("\n%s", "1.Owners.");
		printf("\n%s\n", "2.Buyers.");
		do
		{
			(void)scanf("%d", &k);
			if (k <= 0 || k > 2)printf("\n%s\n", "Error.Try again.");
		} while (k <= 0 || k > 2);
		switch (k)
		{
		case 1:SearchOwner(); break;
		case 2:SearchBuyer(); break;
		}
		break;
	case 6:
		printf("\n%s", "1.Delete one owner.");
		printf("\n%s\n", "2.Delete one buyer.");
		do
		{
			(void)scanf("%d", &k);
			if (k <= 0 || k > 2)printf("\n%s\n", "Error.Try again.");
		} while (k <= 0 || k > 2);
		printf("\n%s\n", "Input index of deliting element:");
		do
		{
			index = CheckInt();
			if (index<1 || index>Owners->size) printf("\n%s\n", "Incorrect index.Try again.");
		} while (index<1 || index>Owners->size);
		index--;
		switch (k)
		{
		case 1:deleteindex(index); break;
		case 2:deleteindexB(index); break;
		}
		break;
	case 7:FinfOwnersToBuyers(); break;
	case 8:FindExchanges(); break;
	case 0:exit(0); break;
	}
}

int main()
{
	Owners = CreateOList();
	Buyers = CreateBList();
	ListFromFile();
	ListBFromFile();
	int i = 1;
	while (i)
	{
		menu();
	}
}