#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
typedef struct Tree {
	int key;
	struct Tree* left;
	struct Tree* right;
	struct Tree* parent;
} simpletree;

typedef struct SearchTree {
	int key;
	struct SearchTree* left;
	struct SearchTree* right;
	struct SearchTree* parent;
}tree;

int Create(struct SearchTree* root, int key) {
	struct SearchTree* mytree = root;
	while (mytree != NULL) {
		if (mytree->key == key) {
			return 1;
		}
		else if (key < mytree->key) {
			mytree = mytree->left;
		}
		else {
			mytree = mytree->right;
		}
	}
	return 0;
}

struct SearchTree* CreateRoot(struct SearchTree* root, int key) {
	struct SearchTree* tmp = (struct SearchTree*)malloc(sizeof(struct SearchTree));
	tmp->left = tmp->right = NULL;
	tmp->key = key;
	tmp->parent = NULL;
	root = tmp;
	return root;
}

void AddKey(struct SearchTree* root, int key) {
	struct SearchTree* mytree = root;
	struct SearchTree* current_parent = NULL;
	struct SearchTree* tmp = (struct SearchTree*)malloc(sizeof(struct SearchTree));
	tmp->key = key;


	while (mytree != NULL) {
		current_parent = mytree;
		if (key < mytree->key) {
			mytree = mytree->left;
		}
		else {
			mytree = mytree->right;
		}
	}
	tmp->parent = current_parent;
	tmp->left = NULL;
	tmp->right = NULL;

	if (key < current_parent->key) {
		current_parent->left = tmp;
	}
	else {
		current_parent->right = tmp;
	}

}

/*struct SearchTree* Search(struct SearchTree* root, int key) {
	if ((root == NULL) || (root->key == key)) {
		return root;
	}
	if (key < root->key) {
		return Search(root->left, key);
	}
	else {
		return Search(root->right, key);
	}
}*/

void Print(struct SearchTree* root)
{
	if (root->left)
		Print(root->left);
	printf("%d ", root->key);
	if (root->right)
		Print(root->right);
}

int get_rand_range_int(const int min, const int max) {
	return rand() % (max - min + 1) + min;
}

struct SearchTree* Delete(struct Tree* simpleroot_lab, struct SearchTree* root_lab) {
	if (simpleroot_lab) {
		root_lab = Delete(simpleroot_lab->left, root_lab);
		root_lab = Delete(simpleroot_lab->right, root_lab);
		if (root_lab == NULL) {
			root_lab = CreateRoot(root_lab, simpleroot_lab->key);
		}
		else {
			if (!Create(root_lab, simpleroot_lab->key)) {
				AddKey(root_lab, simpleroot_lab->key);
			}
		}
		free(simpleroot_lab);
	}
	return root_lab;
}

struct Tree* CreateRootofTree(struct Tree* root, int key) {
	struct Tree* tmp = (struct Tree*)malloc(sizeof(struct Tree));
	tmp->left = tmp->right = NULL;
	tmp->key = key;
	tmp->parent = NULL;
	root = tmp;
	return root;
}

struct Tree* AddKeytoTree(struct Tree* root, int key) {


	struct Tree* mytree = root;
	struct Tree* current_parent = NULL;
	struct Tree* tmp = (struct Tree*) malloc(sizeof(struct Tree));
	tmp->key = key;
	int hod = 0;
	while (mytree != NULL) {
		hod = rand() % 2;
		current_parent = mytree;
		if (hod == 0) {
			mytree = mytree->left;
		}
		else {
			mytree = mytree->right;
		}
	}
	tmp->parent = current_parent;
	tmp->left = NULL;
	tmp->right = NULL;

	if (hod == 0) {
		current_parent->left = tmp;
	}
	else {
		current_parent->right = tmp;
	}
	return root;
}

void PrintTree(struct Tree* root)
{
	if (root->left)
		PrintTree(root->left);
	printf("%d ", root->key);
	if (root->right)
		PrintTree(root->right);
}

int main()
{
	int i = 0;
	struct SearchTree* searchtree = NULL;
	struct Tree* tree = NULL;
	tree = CreateRootofTree(tree, get_rand_range_int(1, 10));
	for (i = 0; i < 25; i++) {
		tree = AddKeytoTree(tree, get_rand_range_int(-10, 10));
	}
	PrintTree(tree);
	printf("\n");
	searchtree = Delete(tree, searchtree);
	Print(searchtree);
	(void)_getch();
	return 0;
}