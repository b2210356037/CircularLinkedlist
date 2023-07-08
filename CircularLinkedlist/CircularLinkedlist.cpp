#include <iostream>
// circular linkedlist introduction playground
struct n {
    int x;
    n* next;
};
typedef n node;

void print(node* r) {
    node* iter = r;
    printf("%d\n", iter->x);
    iter = iter->next;
    while (iter != r)
    {
        printf("%d\n", iter->x);
        iter = iter->next;
    }
}

node* add(node* r, int x) {
    node* iter = r;
    if (r == NULL) {
        r = (node*)malloc(sizeof(node));
        r->next = r;
        r->x = x;
        return r;
    }
 
    while (iter->next != r) {
        iter = iter->next;
    }

    iter->next = (node*)malloc(sizeof(node));
    iter->next->x = x;
    iter->next->next = r;
    return r;
    
}

node* addAscend(node* r, int x) {
    if (r == NULL) { //if linkedlist is empty
        r = (node*)malloc(sizeof(node));
        r->next = r;
        r->x = x;
        return r;
    }
    if (r->x > x) { //if smaller than 1. value
        node* temp = (node*)malloc(sizeof(node*));
        temp->x = x;
        temp->next = r;
        node* iter = r;
        while (iter->next != r) {
            iter = iter->next;
        }
        iter->next = temp;
        return temp;
    }
    node* iter = r;
    while (iter->next != r && iter-> next -> x < x) {
        iter = iter->next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->x = x;
    return r;
}

node* remove(node* r, int x) {
    node* temp;
    node* iter = r;

    if (r->x == x)
    {
        while (iter -> next != r)
        {
            iter = iter->next;
        }
        iter->next = r->next;
        free(r);
        return iter->next;
    }
    while (iter->next != r && iter->next->x != x)
    {
        iter = iter->next;
    }
    if (iter->next == r) {
        printf("The integer: %d has not found\n", x);
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;
}

int main() {
    node* root;
    root = NULL;
    
    root = add(root, 25);
    //root = NULL;
    root = addAscend(root, 15);
    root = addAscend(root, 10);
    root = addAscend(root, 35);
    root = addAscend(root, 20);
    root = remove(root, 20);
    root = addAscend(root, -10);
    root = add(root, 78);
    root = remove(root, 999);
    root = addAscend(root, 1450);

    print(root);

}