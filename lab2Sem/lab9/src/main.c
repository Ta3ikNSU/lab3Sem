#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
//macros
#define GA(graph, x, y, numOfVertices) \
graph[(x) * (numOfVertices) + (y)]

#define ADD_NEW_EDGE(graph, x, y, numOfVertices,length) \
{ graph[(x) * (numOfVertices) + (y)] = length; }
//const
#define MAX_NUMBER_VERTEX 5000
#define MIN_NUMBER_VERTEX 0
#define INFINITY  LLONG_MAX
#define ll long long

typedef enum {
    PATH_FOUND,
    PATH_NOT_FOUND
} PathAvailability;

typedef enum {
    BAD_LENGTH
    , BAD_LINES
    , BAD_VERTICES
    , BAD_VERTEX
    , BAD_EDGES
    , OUT_MEMORY
    , BAD_INPUT_VERTEX
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
                "out of memory"
        };


ExitCodes chechVertex(int val, int maxBorder, int minBorder) {
    if (val > maxBorder || val < minBorder) {
        return(BAD_INPUT_VERTEX);
    }
    else {
        return(SUCCESS);
    }
}

ExitCodes checkQuantity(int* vertex, int* edges, int* from, int* to) {
    if (scanf("%d %d %d %d", vertex, from, to, edges) != 4) {
        return(BAD_LINES);
    }
    if (SUCCESS != chechVertex(*vertex, MAX_NUMBER_VERTEX, MIN_NUMBER_VERTEX)) {
        return(BAD_VERTICES);
    }
    if (SUCCESS != chechVertex(*from, *vertex, 1) || SUCCESS != chechVertex(*to, *vertex, 1)) {
        return(BAD_VERTEX);
    }
    if (*edges > (*vertex * (*vertex + 1) / 2) || *edges < 0) {
        return(BAD_EDGES);
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


int findMinEdgeFrom(int numOfVertices, ll* distanceToMst, PathAvailability* ar) {
    ll min = INFINITY;
    int from = 0;
    for (int j = 0; j < numOfVertices; j++) {
        if (distanceToMst[j] < min && ar[j] != PATH_FOUND) {
            min = distanceToMst[j];
            from = j;
        }
    }
    return(from);
}

void print(ll* distance, int* parents, int numOfVertex, bool requirementOverflow, int to) {
    for (int i = 0; i < numOfVertex; i++) {
        if (distance[i] <= INT_MAX) {
            printf("%lli", distance[i]);
        }
        else {
            if (distance[i] != INFINITY) {
                printf("INT_MAX+");
            }
            else {
                printf("oo");
            }
        }
        printf(" ");
    }
    printf("\n");
    if (requirementOverflow == true) {
        printf("overflow");
    }
    else {
        if (distance[to - 1] == INFINITY) {
            printf("no path");
        }
        else {
            int current = to - 1;
            printf("%d ", to);
            while (current != parents[current]) {
                current = parents[current];
                printf("%d ", current + 1);
            }
        }
    }
}

ExitCodes dijkstraSP(unsigned int* adjacencyMatrix, int numOfVertex, int from, int to) {
    ll* distance = (ll*)malloc(numOfVertex * sizeof(ll));
    if (distance == NULL) {
        return(OUT_MEMORY);
    }
    PathAvailability* pathToVertex = (PathAvailability*)malloc(numOfVertex * sizeof(numOfVertex));
    if (pathToVertex == NULL) {
        free(distance);
        return(OUT_MEMORY);
    }
    int* parents = (int*)malloc(numOfVertex * sizeof(int));
    if (parents == NULL) {
        free(distance);
        free(pathToVertex);
        return(OUT_MEMORY);
    }
    for (int i = 0; i < numOfVertex; i++) {
        if (i == from - 1) {
            distance[i] = 0;
        }
        else {
            distance[i] = INFINITY;
        }
        pathToVertex[i] = PATH_NOT_FOUND;
        parents[i] = i;
    }
    distance[from - 1] = 0;
    bool requirementOverflow = false;
    int current = from - 1;
    for (int i = 0; i < numOfVertex; i++) {
        pathToVertex[current] = PATH_FOUND;
        for (int j = 0; j < numOfVertex; j++) {
            if ((GA(adjacencyMatrix, current, j, numOfVertex)) && (distance[j] >= distance[current] + (ll)GA(adjacencyMatrix, current, j, numOfVertex)) && (pathToVertex[j] == PATH_NOT_FOUND)) {
                if (distance[j] > INT_MAX && distance[j] != INFINITY && j == to - 1) {
                    requirementOverflow = true;
                }
                distance[j] = distance[current] + (ll)GA(adjacencyMatrix, current, j, numOfVertex);

                parents[j] = current;
            }
        }
        current = findMinEdgeFrom(numOfVertex, distance, pathToVertex);
    }
    print(distance, parents, numOfVertex, requirementOverflow, to);
    free(parents);
    free(pathToVertex);
    free(distance);
    return(SUCCESS);
}

int main() {
    int numOfVertices = 0, numOfEdges = 0, from = 0, to = 0;
    ExitCodes rc;
    if (SUCCESS != (rc = checkQuantity(&numOfVertices, &numOfEdges, &from, &to))) {
        printf("%s", exitMsg[rc]);
        return(0);
    }
    if (numOfEdges == 0) {
        if (from != to) {
            for (int i = 0; i < numOfVertices; i++) {
                if (i != from - 1) { printf("oo "); }
                else { printf("0 "); }
            }
            printf("\nno path");
        }
        else {
            printf("0\n%d", to);
        }
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
    if (SUCCESS != (rc = dijkstraSP(adjacencyMatrix, numOfVertices, from, to))) {
        printf("%s", exitMsg[rc]);
    }
    free(adjacencyMatrix);
    return(0);
}
