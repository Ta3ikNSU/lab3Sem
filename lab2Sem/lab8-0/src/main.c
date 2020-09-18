#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define MAX_NUMBER_VERTEX 5000
#define MIN_NUMBER_VERTEX 0
#define LENGTH_SPAN_VERTEX -1 

typedef struct Node {
	short int firstPoint;
	short int secondPoint;
	int length;
} Edge;

typedef enum {
	BAD_LENGTH
	, BAD_LINES
	, BAD_VERTICES
	, BAD_VERTEX
	, BAD_EDGES
	, NO_SPAN_TREE
	, SINGLE_VERTEX_GRAPH
	, SUCCESS
}ExitCodes;

char* exitMsg[] =
{
	"bad length",
	"bad number of lines" ,
	 "bad number of vertices",
	 "bad vertex",
	 "bad number of edges",
	 "no spanning tree"
};

ExitCodes readRibs(Edge* array, int numOfVertices, int numOfEdges, int* counterRead);
ExitCodes checkQuantity(int* quantity, int* edges);
void freeMemory(Edge* array, int* dsu);
void freeArray(Edge* array);
int compare(const void* p1, const void* p2);
void initSets(int* array, int numOfVertices);
void buildMST(int* dsu, Edge* arrayToSort, int numOfEdges);
int findSet(int vertice, int* dsu);
void unionSet(int arg1, int arg2, int* dsu);
ExitCodes printMST(int* dsu, Edge* arrayToSort, int numOfEdges, int numOfVertices);
void swap(int* v1, int* v2);

int main() {
	int numOfVertices, numOfEdges;
	ExitCodes rc;
	if (SUCCESS != (rc = checkQuantity(&numOfVertices, &numOfEdges))) {
		printf("%s", exitMsg[rc]);
		return(0);
	}

	Edge* arrayToSort = (Edge*)malloc(numOfEdges * sizeof(Edge));
	int counterRead = 0;
	if (SUCCESS != (rc = readRibs(arrayToSort, numOfVertices, numOfEdges, &counterRead))) {
		if (rc != SINGLE_VERTEX_GRAPH) printf("%s", exitMsg[rc]);
		freeArray(arrayToSort);
		return(0);
	}
	qsort(arrayToSort, numOfEdges, sizeof(arrayToSort[0]), compare);
	int* dsu = (int*)malloc((numOfVertices + 1) * sizeof(int));
	initSets(dsu, numOfVertices);
	buildMST(dsu, arrayToSort, numOfEdges);
	if (SUCCESS != (rc = printMST(dsu, arrayToSort, numOfEdges, numOfVertices))) {
		printf("%s", exitMsg[rc]);
		freeMemory(arrayToSort, dsu);
		return(0);
	}
	freeMemory(arrayToSort, dsu);
}

ExitCodes checkQuantity(int* vertex, int* edges) {
	if (scanf("%d", vertex) != 1) {
		return(BAD_LINES);
	}
	if (scanf("%d", edges) != 1) {
		return(BAD_LINES);;
	}
	if (*vertex > MAX_NUMBER_VERTEX || *vertex < MIN_NUMBER_VERTEX) {
		return(BAD_VERTICES);
	}
	if (*edges > (*vertex * (*vertex + 1) / 2) || *edges < 0) {
		return(BAD_EDGES);
	}
	if (*edges == 0 && *vertex != 1) {
		return(NO_SPAN_TREE);
	}
	return(SUCCESS);
}

ExitCodes readRibs(Edge* array, int numOfVertices, int numOfEdges, int* counterRead) {
	int x = 0, y = 0, length = 0;
	for (int i = 0; i < numOfEdges; i++) {
		if (3 != (scanf("%d %d %d", &x, &y, &length))) {
			return(BAD_LINES);
		}
		if ((x < 1) || (y < 1) || (x > numOfVertices) || (y > numOfVertices)) {
			return(BAD_VERTEX);
		}
		if ((length < 0) || (length > INT_MAX)) {
			;
			return(BAD_LENGTH);
		}
		array[i].firstPoint = (short int)x;
		array[i].secondPoint = (short int)y;
		array[i].length = length;

		(*counterRead)++;
	}
	if (numOfEdges == 0) return(SINGLE_VERTEX_GRAPH);
	return(SUCCESS);
}

void freeArray(Edge* array) {
	free(array);
}

void freeMemory(Edge* array, int* dsu) {
	freeArray(array);
	free(dsu);
}

int compare(const void* p1, const void* p2) {
	int arg1 = (((Edge*)p1)->length) + 1;
	int arg2 = (((Edge*)p2)->length);
	return  arg1 - arg2;
}

void initSets(int* dsu, int numOfVertices) {
	for (int i = 1; i <= numOfVertices; i++) {
		dsu[i] = i;
	}
}

void buildMST(int* dsu, Edge* arrayToSort, int numOfEdges) {
	for (int i = 0; i < numOfEdges; i++) {
		if (findSet(arrayToSort[i].firstPoint, dsu) != findSet(arrayToSort[i].secondPoint, dsu)) {
			unionSet(arrayToSort[i].firstPoint, arrayToSort[i].secondPoint, dsu);
		}
		else {
			arrayToSort[i].length = LENGTH_SPAN_VERTEX;
		}
	}
}

int findSet(int vertice, int* dsu) {
	if (dsu[vertice] == vertice) return(vertice);
	dsu[vertice] = findSet(dsu[vertice], dsu);
	return(dsu[vertice]);
}

ExitCodes printMST(int* dsu, Edge* arrayToSort, int numOfEdges, int numOfVertices) {
	for (int i = 2; i <= numOfVertices; i++) {
		if (findSet(i - 1, dsu) != findSet(i, dsu)) {
			return(NO_SPAN_TREE);
		}
	}
	for (int i = 0; i < numOfEdges; i++) {
		if ((arrayToSort[i].length) != LENGTH_SPAN_VERTEX) {
			printf("%d %d\n", (arrayToSort[i].firstPoint), (arrayToSort[i].secondPoint));
		}
	}
	return(SUCCESS);
}

void unionSet(int arg1, int arg2, int* dsu) {
	int arg1F = findSet(arg1, dsu);
	int arg2F = findSet(arg2, dsu);
	if (arg2F < arg1F) {
		swap(&arg1F, &arg2F);
	}
	dsu[arg2F] = arg1F;
}

void swap(int* v1, int* v2) {
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}
