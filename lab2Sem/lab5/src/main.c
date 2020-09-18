#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#define SIZE_ALPHABET 256
#define LEAF 1
#define NON_LEAF 0
#define SIZE_OF_BYTE 8
#define uc unsigned char

FILE* in;
FILE* out;

typedef enum {
	SUCCESS,
	OUT_OF_MEMORY,
	WRONG_INPUT,
	WRONG_OUTPUT,
	FILE_ERROR
} ExitCode;

char* exitMsg[] = {
		"success",
		"out of memory",
		"wrong input",
		"wrong output",
		"file error"
};

typedef struct _TreeEncode {
	uc value;
	int frequency;
	struct _TreeEncode* left;
	struct _TreeEncode* right;
}TreeEncode;

typedef struct _TreeDecode {
	uc value;
	struct _TreeDecode* left;
	struct _TreeDecode* right;
}TreeDecode;

typedef struct _Table {
	unsigned char symbol;
	int frequency;
}Table;

typedef struct _Queue {
	TreeEncode* val;
	struct _Queue* next;
}Queue;

int compareTable(const void* a, const void* b) {
	int arg1 = (*(Table*)a).frequency;
	int arg2 = (*(Table*)b).frequency;
	if (arg2 == arg1) {
		return((*(Table*)b).symbol - (*(Table*)a).symbol);
	}
	else {
		return(arg2 - arg1);
	}
}

void skipSymbols(int n) {
	char get;
	for (int i = 0; i < n; ++i) {
		if (1 != fread(&get, sizeof(char), 1, in))
			exit(0);
	}
}

void freeTreeD(TreeDecode * root) {
	if (root->left != NULL)
		freeTreeD(root->left);
	if (root->right != NULL)
		freeTreeD(root->right);
	free(root);
}

void freeTreeE(TreeEncode * root) {
	if (root->left != NULL)
		freeTreeE(root->left);
	if (root->right != NULL)
		freeTreeE(root->right);
	free(root);
}

ExitCode readFileToEncode(Table * tableFrequency, int* count) {
	for (int i = 0; i < SIZE_ALPHABET; i++)
		tableFrequency[i].frequency = 0;
	skipSymbols(2);
	uc get = 0;
	int clearFile = 0;
	while (!feof(in)) {
		clearFile++;
		int rc = fread(&get, sizeof(uc), 1, in);
		tableFrequency[get].frequency++;
		if (rc != 1) break;
	}
	if (clearFile == 1)
		exit(0);
	tableFrequency[get].frequency--;
	for (int i = 0; i < SIZE_ALPHABET; i++) {
		tableFrequency[i].symbol = (char)i;
		if (tableFrequency[i].frequency != 0)
			(*count)++;
	}
	return(SUCCESS);
}

TreeEncode* pop(Queue * *head) {
	Queue* prev = (*head);
	TreeEncode* value = prev->val;
	(*head) = (*head)->next;
	free(prev);
	return value;
}

Queue* merge(TreeEncode * arg1, TreeEncode * arg2) {
	Queue* merged = (Queue*)malloc(sizeof(Queue));
	merged->val = (TreeEncode*)malloc(sizeof(TreeEncode));
	merged->val->frequency = arg1->frequency + arg2->frequency;
	merged->val->left = arg1;
	merged->val->right = arg2;
	merged->val->value = 0;
	return(merged);
}

Queue* insert(Queue * head, Queue * newNode) {
	if (head->val->frequency > newNode->val->frequency) {
		newNode->next = head;
		return(head);
	}
	else {
		Queue* ptr = head;
		while (ptr->next != NULL && ptr->next->val->frequency <= newNode->val->frequency) {
			ptr = ptr->next;
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
		return(head);
	}
}

TreeEncode* buildTree(int countDiffSymbol, Table * tableFrequency) {
	qsort(tableFrequency, SIZE_ALPHABET, sizeof(Table), compareTable);
	if (countDiffSymbol == 1) {
		TreeEncode* root = (TreeEncode*)malloc(sizeof(TreeEncode));
		root->frequency = tableFrequency[0].frequency;
		root->value = tableFrequency[0].symbol;
		root->right = root->left = NULL;
		return(root);
	}
	Queue* head = (Queue*)malloc(sizeof(Queue));
	head->next = NULL;
	head->val = (TreeEncode*)malloc(sizeof(TreeEncode));
	head->val->frequency = -1;

	for (int i = 0; i < SIZE_ALPHABET; i++) {
		if (tableFrequency[i].frequency == 0) {
			continue;
		}
		else {
			if (head->val->frequency == -1) {
				head->val->left = head->val->right = NULL;
				head->val->frequency = tableFrequency[i].frequency;
				head->val->value = tableFrequency[i].symbol;
			}
			else {
				Queue* newElement = (Queue*)malloc(sizeof(Queue));
				newElement->val = (TreeEncode*)malloc(sizeof(TreeEncode));
				newElement->val->left = newElement->val->right = NULL;
				newElement->val->frequency = tableFrequency[i].frequency;
				newElement->val->value = tableFrequency[i].symbol;
				newElement->next = head;
				head = newElement;
			}
		}
	}
	if (head->next) {
		while (head->next->next != NULL) {
			TreeEncode* arg1 = pop(&head);
			TreeEncode* arg2 = pop(&head);
			Queue* mergedVertex = merge(arg1, arg2);
			head = insert(head, mergedVertex);
		}
	}
	TreeEncode* arg1 = pop(&head);
	TreeEncode* arg2 = pop(&head);
	TreeEncode* root = (TreeEncode*)malloc(sizeof(TreeEncode));
	root->frequency = arg1->frequency + arg2->frequency;
	root->left = arg1;
	root->right = arg2;
	root->value = 0;
	return(root);
}

int isLeafE(TreeEncode * ptr) {
	return((!ptr->left && !ptr->right) ? LEAF : NON_LEAF);
}

int isLeafD(TreeDecode * ptr) {
	return((!ptr->left && !ptr->right) ? LEAF : NON_LEAF);
}

ExitCode makeCodes(TreeEncode * ptr, char* curCode, char** table) {
	ExitCode rc;
	int l = strlen(curCode);
	if (isLeafE(ptr)) {
		table[ptr->value] = (char*)malloc(strlen(curCode) + 1);
		if (table[ptr->value] == NULL) return(OUT_OF_MEMORY);
		strcpy(table[ptr->value], curCode);
	}
	else {
		curCode[l] = '0';
		curCode[l + 1] = '\0';
		if (ptr->left) {
			if (SUCCESS != (rc = (makeCodes(ptr->left, curCode, table)))) return(rc);
		}
		curCode[l] = '1';
		curCode[l + 1] = '\0';
		if (ptr->right) {
			if (SUCCESS != (rc = (makeCodes(ptr->right, curCode, table)))) return(rc);
		}
	}
	return(SUCCESS);
}

void bitWrite(int* pos, uc * byte, uc bit) {
	if (bit == '1') {
		*byte = (*byte) | (1 << ((SIZE_OF_BYTE - 1) - (*pos)));
	}
	(*pos)++;
	if (*pos == SIZE_OF_BYTE) {
		fwrite(byte, sizeof(uc), 1, out);
		*pos = 0;
		*byte = 0;
	}
}

void printTree(int* pos, uc * byte, TreeEncode * ptr) {
	if (isLeafE(ptr)) {
		bitWrite(pos, byte, '1');
		for (int i = 0; i < SIZE_OF_BYTE; i++) {
			bitWrite(pos, byte, (((ptr->value) >> (7 - i)) & 1) + '0');
		}
	}
	else {
		bitWrite(pos, byte, '0');
		if (ptr->left) printTree(pos, byte, ptr->left);
		if (ptr->right) printTree(pos, byte, ptr->right);
	}
}

void printOUT(int* pos, uc * byte, char** codesTable) {
	uc get;
	fseek(in, 3, SEEK_SET);
	while (!feof(in)) {
		int rc = fread(&get, sizeof(uc), 1, in);
		if (1 != rc) break;
		for (unsigned int i = 0; i < strlen(codesTable[get]); i++) {
			bitWrite(pos, byte, codesTable[get][i]);
		}
	}
	if ((*pos) != 0) fwrite(byte, sizeof(uc), 1, out);
}

void freeMemoryEncode(TreeEncode * ptr, char** codes) {
	for (int i = 0; i < SIZE_ALPHABET; i++) {
		if (codes[i] != NULL) free(codes[i]);
	}
	freeTreeE(ptr);
}

ExitCode encode() {
	ExitCode rc;
	int countDiffSymbol = 0;
	Table tableFrequency[SIZE_ALPHABET];
	if (SUCCESS != (rc = readFileToEncode(tableFrequency, &countDiffSymbol))) {
		return(rc);
	}
	TreeEncode* root = buildTree(countDiffSymbol, tableFrequency);
	if (root == NULL) return(OUT_OF_MEMORY);
	char curCode[SIZE_ALPHABET] = { 0 };
	char* codes[SIZE_ALPHABET] = { NULL };
	if (SUCCESS != (rc = makeCodes(root, curCode, codes))) {
		freeMemoryEncode(root, codes);
		return(rc);
	};
	fwrite(&(root->frequency), sizeof(int), 1, out);
	int pos = 0;
	uc byte = 0;
	printTree(&pos, &byte, root);
	printOUT(&pos, &byte, codes);
	freeMemoryEncode(root, codes);
	return(SUCCESS);
}

void readBit(int* byte) {
	uc get;
	if (1 != fread(&get, sizeof(uc), 1, in))
		return;
	for (int i = 0; i < SIZE_OF_BYTE; i++) {
		int hash = get & (1 << (SIZE_OF_BYTE - 1 - i));
		if (hash) {
			byte[i] = 1;
		}
		else {
			byte[i] = 0;
		}
	}
}

int bitReader(int* pos, int* byte) {
	if (!((*pos) % SIZE_OF_BYTE)) {
		(*pos) %= SIZE_OF_BYTE;
		readBit(byte);
	}
	return ((*pos) == 8 ? 0 : byte[(*pos)++]);
}

uc createSymbol(int* pos, int* byte) {
	uc symbol = 0;
	for (int i = 0; i < SIZE_OF_BYTE; i++) {
		if (bitReader(pos, byte)) {
			symbol = symbol | (1 << (SIZE_OF_BYTE - 1 - i));
		}
	}
	return(symbol);
}

TreeDecode* addNewVertex() {
	TreeDecode* new = (TreeDecode*)malloc(sizeof(TreeDecode));
	new->left = new->right = NULL;
	new->value = 0;
	return new;
}

ExitCode recoveryTree(TreeDecode * ptr, int* pos, int* byte) {
	ExitCode rc = SUCCESS;
	if (bitReader(pos, byte)) {
		ptr->value = createSymbol(pos, byte);
	}
	else {
		if (!ptr->left) {
			ptr->left = addNewVertex();
			if (ptr->left == NULL) return(OUT_OF_MEMORY);
		}
		if (SUCCESS != (rc = recoveryTree(ptr->left, pos, byte))) return(rc);
		if (!ptr->right) {
			ptr->right = addNewVertex();
			if (ptr->right == NULL) return(OUT_OF_MEMORY);
		}
		if (SUCCESS != (rc = recoveryTree(ptr->right, pos, byte))) return(rc);
	}
	return(rc);
}


void decodeText(TreeDecode * ptr, int* pos, int* byte, int* i, int numSymbol) {
	if (isLeafD(ptr)) {
		fwrite(&(ptr->value), sizeof(uc), 1, out);
		(*i)++;
	}
	else {
		if ((*i) == numSymbol) return;
		int temp = bitReader(pos, byte);
		if (!temp) {
			decodeText(ptr->left, pos, byte, i, numSymbol);
		}
		else {
			decodeText(ptr->right, pos, byte, i, numSymbol);
		}
	}
}

void freeMemoryDecode(int* byte, TreeDecode * root) {
	free(byte);
	freeTreeD(root);
}

ExitCode decode() {
	ExitCode rc = SUCCESS;
	skipSymbols(2);
	int numSymbol = 0;
	if (1 != fread(&numSymbol, sizeof(int), 1, in))
		return(SUCCESS);
	int pos = 8;
	int* byte = (int*)malloc(8 * sizeof(int));
	TreeDecode * root = (TreeDecode*)malloc(sizeof(TreeDecode));
	root->left = root->right = NULL;
	if (SUCCESS != (rc = recoveryTree(root, &pos, byte))) return(rc);
	int i = 0;
	while (i != numSymbol) {
		decodeText(root, &pos, byte, &i, numSymbol);
	}
	freeMemoryDecode(byte, root);
	return(SUCCESS);
}


int main() {
	char option = 0;

	if (NULL == (in = fopen("in.txt", "rb"))) {
		fclose(in);
		printf("%s", exitMsg[FILE_ERROR]);
		return(FILE_ERROR);
	}
	if (NULL == (out = fopen("out.txt", "wb"))) {
		fclose(in);
		fclose(out);
		printf("%s", exitMsg[FILE_ERROR]);
		return(FILE_ERROR);
	}
	if (1 != fread(&option, sizeof(uc), 1, in)) {
		fclose(in);
		fclose(out);
		printf("%s", exitMsg[WRONG_INPUT]);
		return(WRONG_INPUT);
	}
	ExitCode rc = SUCCESS;
	switch (option)
	{
	case 'c': {
		if (SUCCESS != (rc = encode())) printf("%s", exitMsg[rc]);
		break;
	}
	case 'd': {
		if (SUCCESS != (rc = decode())) printf("%s", exitMsg[rc]);
		break;
	}
	default:
		return(0);
	}
	fclose(in);
	fclose(out);
}
