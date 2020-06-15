#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


typedef struct _Node {
    int x, y;
    struct _Node* parent;
    struct _Node* next;
    int f, g, h;
} node;

typedef struct _List {
    node* head;
};
typedef struct _List* List;

struct _pos
{
    int x;
    int y;
};
typedef struct _pos position;
position* createposition(int x,int y)
{
    position* pos = calloc(1, sizeof(position));

    pos->x = x;
    pos->y = y;


    return pos;
}


node* last(List list)
{
    node* last = list->head;
    // Le dernier element de la liste est celui dont next est null
    while (last && last->next) last = last->next;
    return last;
}

List push(List list, int x,int y,int g,int h ,int f)
{
    node* test = (node*)malloc(sizeof(node));
    test->next = NULL;
    test->x = x;
    test->y = y;
    test->g = g;


    node* last_elt = last(list);
    if (last_elt)                    
        last_elt->next = test;
    else
        list->head = test;

    return list;
}


void freeList(List list)
{
    node* delete = (node*)list;
    while (delete)
    {
        node* suivant  = delete->next;
        free(delete);
        delete = suivant;
    }
}

void main(int argc, char* argv[])
{
    int x, y;
    int h;
	int grille[10][10];
    int tableau[15];
	int departX, departY;
    int arriveX, arriveY;
    int distance;
    List open = NULL; 
    List close = NULL;

	FILE* grid = fopen("..\\..\\grid.txt","r");
    FILE* data = fopen("..\\..\\data.txt", "r");
    if (grid != NULL && data != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            printf("\n");
            for (int j = 0; j < 10; j++)
            {
                fscanf(grid, "%d", &grille[i][j]);
                printf(" %d;%d ", grille[i],grille[j]);
                open = push(open, i,j,???,h,depart+h);
            }
        }

        for (int i = 0; i < 15; i++)
        {
            fscanf(data, "%d", &tableau[i]);
            //printf("%d", tableau[i]);
        }
    }
    else
    {
        printf("Impossible d'ouvrir un fichier...");
    }
    //TEST 1 
    departX = tableau[0];
    departY = tableau[1];
    arriveX = tableau[2];
    arriveY = tableau[3];
    distance = tableau[4];
    
    //freeList(open);
    //freeList(close);
}