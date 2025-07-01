#include <stdio.h>
#include <stdlib.h>

struct vertex {
    char name;
    struct edge *s;
    struct vertex *next;
} typedef v;

struct edge {
    v *data;
    int weight;  // Weight of the edge
    struct edge *next;
} typedef e;

void Insert(v **);
void CreateEdge(v *);
void DisplayVertex(v *);
void DeleteEdge(v *, char);
void DisplayGraph(v *);

int main() {
    v *head = NULL;
    int ch;

    do {
        printf("\n--- Weighted Graph Menu ---");
        printf("\n1. Insert Vertex");
        printf("\n2. Create Edge");
        printf("\n3. Display Vertices");
        printf("\n4. Delete Edges from a Vertex");
        printf("\n5. Display Graph");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        getchar(); // clear input buffer

        switch (ch) {
            case 1:
                Insert(&head);
                break;
            case 2:
                CreateEdge(head);
                break;
            case 3:
                DisplayVertex(head);
                break;
            case 4: {
                char name;
                printf("Enter the vertex name to delete edges: ");
                scanf(" %c", &name);
                DeleteEdge(head, name);
                break;
            }
            case 5:
                DisplayGraph(head);
                break;
            default:
                printf("Exiting...\n");
                break;
        }
    } while (ch >= 1 && ch <= 5);

    return 0;
}

// Insert a new vertex
void Insert(v **head) {
    v *t = (v *)malloc(sizeof(v));
    printf("Enter the vertex name: ");
    scanf(" %c", &t->name);
    t->s = NULL;
    t->next = NULL;

    if (*head == NULL) {
        *head = t;
    } else {
        v *p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = t;
    }
}

// Create a weighted edge between two vertices
void CreateEdge(v *head) {
    char srcName, destName;
    int weight;

    printf("Enter the source vertex name: ");
    scanf(" %c", &srcName);
    printf("Enter the destination vertex name: ");
    scanf(" %c", &destName);
    printf("Enter the weight of the edge: ");
    scanf("%d", &weight);

    v *src = NULL, *dest = NULL, *temp = head;
    while (temp != NULL) {
        if (temp->name == srcName)
            src = temp;
        if (temp->name == destName)
            dest = temp;
        temp = temp->next;
    }

    if (src == NULL || dest == NULL) {
        printf("One or both vertices not found.\n");
        return;
    }

    e *newEdge = (e *)malloc(sizeof(e));
    newEdge->data = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;

    if (src->s == NULL) {
        src->s = newEdge;
    } else {
        e *tempEdge = src->s;
        while (tempEdge->next != NULL) {
            tempEdge = tempEdge->next;
        }
        tempEdge->next = newEdge;
    }

    printf("Edge created from %c to %c with weight %d\n", srcName, destName, weight);
}

// Display all vertex names
void DisplayVertex(v *head) {
    v *t = head;
    if (t == NULL) {
        printf("Empty\n");
    } else {
        printf("Vertices are:\n");
        while (t != NULL) {
            printf("\t%c\n", t->name);
            t = t->next;
        }
    }
}

// Delete all edges from a vertex
void DeleteEdge(v *head, char name) {
    v *p = head;
    while (p != NULL) {
        if (p->name == name) {
            e *z = p->s;
            while (z != NULL) {
                e *del = z;
                z = z->next;
                free(del);
            }
            p->s = NULL;
            printf("Edges deleted for vertex %c\n", name);
            return;
        }
        p = p->next;
    }
    printf("Vertex %c not found\n", name);
}

// Display the entire graph with edge weights
void DisplayGraph(v *head) {
    v *temp = head;
    if (temp == NULL) {
        printf("Graph is empty.\n");
    } else {
        printf("Graph (Adjacency List with Weights):\n");
        while (temp != NULL) {
            printf("\t%c -> ", temp->name);
            e *edgeList = temp->s;
            while (edgeList != NULL) {
                printf("%c(%d) ", edgeList->data->name, edgeList->weight);
                edgeList = edgeList->next;
            }
            printf("\n");
            temp = temp->next;
        }
    }
}