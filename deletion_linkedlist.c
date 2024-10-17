#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *first = NULL;

void create(int A[], int n) {
    int i;
    struct node *t, *last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for (i = 1; i < n; i++) {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void rdisplay(struct node *p) {
    if (p != NULL) {
        rdisplay(p->next);
        printf("%d ", p->data);
    }
}

int count(struct node *p) {
    int length = 0;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

int delete(struct node *p, int index) {
    struct node *q = NULL;
    int x = -1, i;

    if (index < 1 || index > count(p)) {
        return -1;
    }

    if (index == 1) {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    } else {
        for (i = 0; i < index - 1 && p; i++) {
            q = p;
            p = p->next;
        }
        
        if (p) {
            q->next = p->next;
            x = p->data;
            free(p);
        }
        return x;
    }
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    
    printf("Deleted element: %d\n", delete(first, 2));
    rdisplay(first);
    
    return 0;
}
