#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _AVLTree {
	int key;
	int height;
	struct _AVLTree* left;
	struct _AVLTree* right;
}AVLTree;

int height(AVLTree* t);
int fixHeight(AVLTree* t);
AVLTree* balance(AVLTree* p);
int bFactor(AVLTree* t);
AVLTree* rotateLeft(AVLTree* p);
AVLTree* rotateRight(AVLTree* p);
AVLTree* insert(AVLTree* root, int newKey);
AVLTree* create(int firstKey);
void freeTree(AVLTree* root);

int main() {
	int number;
	if (1 != scanf("%d", &number))return(0);
	if (number == 0) {
		printf("0");
		return(0);
	}
	AVLTree* root = NULL;
	int key = 0;
	for (int i = 0; i < number; i++) {
		if (1 != scanf("%d", &key)) return(0);
		root = insert(root, key);
	}
	printf("%d", (int)root->height);
	freeTree(root);
	return(0);
}

int fixHeight(AVLTree* t) {
	int hl = height(t->left);
	int hr = height(t->right);
	return ((hl > hr ? hl : hr) + 1);
}

int height(AVLTree* t) {
	return t ? t->height : 0;
}

AVLTree* balance(AVLTree* p) {
	fixHeight(p);
	if (bFactor(p) == 2) {
		if (bFactor(p->right) < 0)
			p->right = rotateRight(p->right);
		return rotateLeft(p);
	}
	if (bFactor(p) == -2) {
		if (bFactor(p->left) > 0)
			p->left = rotateLeft(p->left);
		return rotateRight(p);
	}
	return p;
}

int bFactor(AVLTree* t) {
	return height(t->right) - height(t->left);
}

AVLTree* rotateLeft(AVLTree* p) {
	AVLTree* q = p->right;
	p->right = p->right->left;
	q->left = p;
	p->height = fixHeight(p);
	q->height = fixHeight(q);
	return(q);
}

AVLTree* rotateRight(AVLTree* p) {
	AVLTree* q = p->left;
	p->left = p->left->right;
	q->right = p;
	p->height = fixHeight(p);
	q->height = fixHeight(q);
	return(q);
}

AVLTree* insert(AVLTree* r, int newKey) {
	if (r == NULL) return(create(newKey));
	if (newKey < r->key) {
		r->left = insert(r->left, newKey);
	}
	else {
		r->right = insert(r->right, newKey);
	}
	r->height = fixHeight(r);
	return balance(r);
}

AVLTree* create(int key) {
	AVLTree* p = (AVLTree*)malloc(sizeof(AVLTree));
	p->left = p->right = NULL;
	p->key = key;
	p->height = 1;
	return(p);
}

void freeTree(AVLTree* root) {
	if (root->left != NULL)
		freeTree(root->left);
	if (root->right != NULL)
		freeTree(root->right);
	free(root);
}
