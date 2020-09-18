#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//macros
#define GA(graph, x, y, numOfVertices) \
graph[(x) * (numOfVertices) + (y)]

#define ADD_NEW_EDGE(graph, x, y, numOfVertices,length) \
{ graph[(x) * (numOfVertices) + (y)] = length; }
//const
#define INT_MAX 2147483647
#define MAX_NUMBER_VERTEX 5000
#define MIN_NUMBER_VERTEX 0
#define INFINITY 4294967295
typedef struct _Edge {
    int from;
    int to;
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

typedef enum {
    VERTEX_IN_MST,
    VERTEX_OUTSIDE_MST
} PositionVertex;

char* exitMsg[] =
        {
                "bad length",
                "bad number of lines" ,
                "bad number of vertices",
                "bad vertex",
                "bad number of edges",
                "no spanning tree"
        };

int findMinEdgeFrom(int numOfVertices, unsigned int* distanceToMst) {
    unsigned int min = distanceToMst[0];
    int from = 0;
    for (int j = 1; j < numOfVertices; j++) {
        if (distanceToMst[j] < min) {
            min = distanceToMst[j];
            from = j;
        }
    }
    return(from);
}

ExitCodes prim(Edge* arrayEdgeInMst, unsigned int* adjacencyMatrix, int numOfVertices) {
    unsigned int* distanceToMst = (unsigned int*)malloc(numOfVertices * sizeof(unsigned int));
    int* from = (int*)malloc(numOfVertices * sizeof(int));
    PositionVertex* vertexInMst = (PositionVertex*)malloc(numOfVertices * sizeof(PositionVertex));
    for (int i = 0; i < numOfVertices; i++) {
        distanceToMst[i] = (unsigned int)INT_MAX + 1;
        vertexInMst[i] = VERTEX_OUTSIDE_MST;
    }
    vertexInMst[0] = VERTEX_IN_MST;
    int countEdge = 0;
    int cur = 0;
    for (int i = 0; i < numOfVertices - 1; i++) {
        for (int j = 1; j < numOfVertices; j++) {
            if (GA(adjacencyMatrix, cur, j, numOfVertices) < distanceToMst[j] &&
                GA(adjacencyMatrix, cur, j, numOfVertices) != 0 &&
                distanceToMst[j] != INFINITY)
            {
                distanceToMst[j] = GA(adjacencyMatrix, cur, j, numOfVertices);
                from[j] = cur;
                vertexInMst[j] = VERTEX_IN_MST;
            }
        }
        distanceToMst[cur] = INFINITY;
        int newVertex = findMinEdgeFrom(numOfVertices, distanceToMst);
        arrayEdgeInMst[countEdge].to = from[newVertex] + 1;
        arrayEdgeInMst[countEdge].from = newVertex + 1;
        countEdge++;
        cur = newVertex;
    }
    for (int i = 0; i < numOfVertices; i++) {
        if (vertexInMst[i] == VERTEX_OUTSIDE_MST) {
            free(distanceToMst);
            free(from);
            free(vertexInMst);
            return(NO_SPAN_TREE);
        }
    }
    free(distanceToMst);
    free(from);
    free(vertexInMst);
    return(SUCCESS);
}




ExitCodes checkQuantity(int* vertex, int* edges) {
    if (scanf("%d", vertex) != 1) {
        return(BAD_LINES);
    }
    if (scanf("%d", edges) != 1) {
        return(BAD_LINES);
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
    if (*edges < (*vertex - 1)) {
        return(NO_SPAN_TREE);
    }
    return(SUCCESS);
}



ExitCodes readEdges(unsigned int* adjacencyMatrix, int numOfVertices, int numOfEdges) {
    int x = 0, y = 0, length = 0;
    for (int i = 0; i < numOfEdges; i++) {
        if (3 != (scanf("%d %d %d", &x, &y, &length))) {
            return(BAD_LINES);
        }
        if ((x < 1) || (y < 1) || (x > numOfVertices) || (y > numOfVertices)) {
            return(BAD_VERTEX);
        }
        if ((length < 0) || (length > INT_MAX)) {
            return(BAD_LENGTH);
        }
        ADD_NEW_EDGE(adjacencyMatrix, x - 1, y - 1, numOfVertices, length);
        ADD_NEW_EDGE(adjacencyMatrix, y - 1, x - 1, numOfVertices, length);
    }
    if (numOfEdges == 0) return(SINGLE_VERTEX_GRAPH);
    return(SUCCESS);
}


int main() {
    int numOfVertices = 0, numOfEdges = 0;
    ExitCodes rc;
    if (SUCCESS != (rc = checkQuantity(&numOfVertices, &numOfEdges))) {
        printf("%s", exitMsg[rc]);
        return(0);
    }
    unsigned int* adjacencyMatrix = (unsigned int*)malloc(numOfVertices * numOfVertices * sizeof(unsigned int));
    for (int i = 0; i < numOfVertices; i++) {
        for (int j = 0; j < numOfVertices; j++) {
            GA(adjacencyMatrix, i, j, numOfVertices) = 0;
        }
    }
    if (SUCCESS != (rc = readEdges(adjacencyMatrix, numOfVertices, numOfEdges))) {
        if (rc != SINGLE_VERTEX_GRAPH) printf("%s", exitMsg[rc]);
        free(adjacencyMatrix);
        return(0);
    }
    Edge* arrayEdgeInMst = (Edge*)malloc((numOfVertices - 1) * sizeof(Edge));
    if (SUCCESS != (rc = prim(arrayEdgeInMst, adjacencyMatrix, numOfVertices))) {
        printf("%s", exitMsg[rc]);
        free(arrayEdgeInMst);
        free(adjacencyMatrix);
        return(0);
    }
    for (int i = 0; i < numOfVertices - 1; i++) {
        printf("%d %d\n", arrayEdgeInMst[i].from, arrayEdgeInMst[i].to);
    }
    free(arrayEdgeInMst);
    free(adjacencyMatrix);
    return(0);
}
