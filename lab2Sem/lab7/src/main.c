#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ADD_NEW_EDGE(graph, x, y, numOfVertices) \
{ graph[(x) * (numOfVertices) + (y)] = GREY; }
#define CHECK_EDGE_COLOR(graph, x, y, numOfVertices,color) (graph[(x) * (numOfVertices)+(y)] == color)

typedef enum _GraphColor {
	WHITE = 0,
	GREY = 1,
	BLACK = 2
}GraphColor;

typedef enum {
	BAD_LINES
	, BAD_VERTICES
	, BAD_VERTEX
	, BAD_EDGES
	, IMP_TO_SORT
	, SUCCESS
}ExitCodes;

char* exitMsg[] =
{
	"bad number of lines" ,
	 "bad number of vertices",
	 "bad vertex",
	 "bad number of edges",
	 "impossible to sort"
};

ExitCodes checkQuantity(int* numOfVertices, int* numOfEdges) {
	if (scanf("%d", numOfVertices) != 1) {
		printf("%s", exitMsg[BAD_LINES]);
		return(BAD_LINES);
	}
	if (scanf("%d", numOfEdges) != 1) {
		printf("%s", exitMsg[BAD_LINES]);
		return(BAD_LINES);
	}
	if (*numOfVertices > 1000 || *numOfVertices < 0) {
		printf("%s", exitMsg[BAD_VERTICES]);
		return(BAD_VERTICES);
	}
	if (*numOfEdges > (*numOfVertices * (*numOfVertices + 1) / 2) || *numOfEdges < 0) {
		printf("%s", exitMsg[BAD_EDGES]);
		return(BAD_EDGES);
	}
	return(SUCCESS);
}


ExitCodes buildGraph(int* graph, int numOfVertices, int numOfEdges) {
	int x = 0, y = 0;
	for (int i = 0; i < numOfEdges; i++) {
		if (2 != (scanf("%d %d", &x, &y))) {
			printf("%s", exitMsg[BAD_LINES]);
			return(BAD_LINES);
		}
		if ((x < 1) || (y < 1) || (x > numOfVertices) || (y > numOfVertices)) {
			printf("%s", exitMsg[BAD_VERTEX]);
			return(BAD_VERTEX);
		}
		ADD_NEW_EDGE(graph, x - 1, y - 1, numOfVertices);
	}
	return(SUCCESS);
}

ExitCodes topologicalSort(int* graph, int* sortedGraph, int numOfVertices, int numOfEdges, int* graphColor, int currentVertex, int* counter) {
	switch (graphColor[currentVertex])
	{
	case BLACK: { return(SUCCESS); }
	case GREY: {
		printf("%s", exitMsg[IMP_TO_SORT]);
		return(IMP_TO_SORT);
	}
	default:
		graphColor[currentVertex] = GREY;
		for (int i = 0; i < numOfVertices; i++) {
			if (CHECK_EDGE_COLOR(graph, i, currentVertex, numOfVertices, GREY))
				if (IMP_TO_SORT == topologicalSort(graph, sortedGraph, numOfVertices, numOfEdges, graphColor, i, counter)) {
					return(IMP_TO_SORT);
				}
		}
		graphColor[currentVertex] = BLACK;
		sortedGraph[*counter] = currentVertex + 1;
		(*counter)++;
		return(SUCCESS);
	}
}


int main() {
	int numOfVertices = 0, numOfEdges = 0;
	if (SUCCESS != checkQuantity(&numOfVertices, &numOfEdges)) return(0);
	int* graph = (int*)malloc(numOfVertices * numOfVertices * sizeof(int));
	if (SUCCESS != buildGraph(graph, numOfVertices, numOfEdges)) {
		free(graph);
		return(0);
	}
	int* graphColor = (int*)malloc(numOfVertices * sizeof(int));
	int* sortedGraph = (int*)malloc(numOfVertices * sizeof(int));
	if (sortedGraph == NULL) exit(0);
	int counter = 0;
	for (int i = 0; i < numOfVertices; i++) {
		if (IMP_TO_SORT == topologicalSort(graph, sortedGraph, numOfVertices, numOfEdges, graphColor, i, &counter)) {
			free(graph);
			free(graphColor);
			free(sortedGraph);
			return(0);
		}
	}
	if (sortedGraph == NULL) return(0);
	for (int i = 0; i < numOfVertices; i++) {
		printf("%d ", sortedGraph[i]);
	}
	free(graph);
	free(graphColor);
	free(sortedGraph);
	return(0);
}
