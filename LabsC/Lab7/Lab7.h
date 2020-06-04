#pragma once
typedef enum TypeOfFlat
{
	Studio,
	IsolatedRooms,
	ConnecRooms,
	FreeLayout
}Type;

typedef struct owner {
	struct owner* next;
	int floor;
	char region[30];
	char adress[30];
	int area;
	Type type;
	int price;
}Owner;

typedef struct buyer {
	struct buyer* next;
	char phonenomber[20];
	char email[20];
	int maxprice;
	int minprice;
	int minarea;
	int maxarea;
	Type type;
}Buyer;
typedef struct buyerlist {
	int size;
	struct buyer* head;
}BList;

typedef struct ownerlist {
	int size;
	struct owner* head;
}OList;
