#include <iostream>
// circular linkedlist introduction playground

// Define a struct to represent a node in the linked list
struct n {
    int x; // The data value of the node
    n* next; // The pointer to the next node
};
typedef n node; // Create an alias for the struct

// Define a function to print the values of the nodes in the linked list
void print(node* r) {
    node* iter = r; // Create an iterator to traverse the list
    printf("%d\n", iter->x); // Print the value of the first node
    iter = iter->next; // Move to the next node
    while (iter != r) // Loop until reaching the first node again
    {
        printf("%d\n", iter->x); // Print the value of the current node
        iter = iter->next; // Move to the next node
    }
}

// Define a function to add a new node at the end of the linked list
node* add(node* r, int x) {
    node* iter = r; // Create an iterator to traverse the list
    if (r == NULL) { // If the list is empty
        r = (node*)malloc(sizeof(node)); // Allocate memory for a new node
        r->next = r; // Make the new node point to itself
        r->x = x; // Assign the data value to the new node
        return r; // Return the new node as the head of the list
    }

    while (iter->next != r) { // Loop until reaching the last node
        iter = iter->next; // Move to the next node
    }

    iter->next = (node*)malloc(sizeof(node)); // Allocate memory for a new node after the last node
    iter->next->x = x; // Assign the data value to the new node
    iter->next->next = r; // Make the new node point to the first node
    return r; // Return the original head of the list

}

// Define a function to add a new node in ascending order in the linked list
node* addAscend(node* r, int x) {
    if (r == NULL) { //if linkedlist is empty
        r = (node*)malloc(sizeof(node)); // Allocate memory for a new node
        r->next = r; // Make the new node point to itself
        r->x = x; // Assign the data value to the new node
        return r; // Return the new node as the head of the list
    }
    if (r->x > x) { //if smaller than 1. value
        node* temp = (node*)malloc(sizeof(node*)); // Allocate memory for a new node before the first node
        temp->x = x; // Assign the data value to the new node
        temp->next = r; // Make the new node point to the first node
        node* iter = r;
        while (iter->next != r) { // Loop until reaching the last node
            iter = iter->next;
        }
        iter->next = temp; // Make the last node point to the new node
        return temp; // Return the new node as the head of the list
    }
    node* iter = r;
    while (iter->next != r && iter->next->x < x) { // Loop until reaching a larger value or the end of the list 
        iter = iter->next;
    }
    node* temp = (node*)malloc(sizeof(node)); // Allocate memory for a new node after iter 
    temp->next = iter->next;
    iter->next = temp;
    temp->x = x;
    return r;
}

// Define a function to remove a node with a given value from the linked list
node* remove(node* r, int x) {
    node* temp;
    node* iter = r;

    if (r->x == x) // If the first node has the value to be removed
    {
        while (iter->next != r) // Loop until reaching the last node
        {
            iter = iter->next;
        }
        iter->next = r->next; // Make the last node point to the second node
        free(r); // Free the memory of the first node
        return iter->next; // Return the second node as the new head of the list
    }
    while (iter->next != r && iter->next->x != x) // Loop until reaching the value to be removed or the end of the list
    {
        iter = iter->next;
    }
    if (iter->next == r) { // If the value is not found in the list
        printf("The integer: %d has not found\n", x);
        return r; // Return the original head of the list
    }
    temp = iter->next; // Store the node to be removed in temp
    iter->next = iter->next->next; // Make iter point to the next node after temp
    free(temp); // Free the memory of temp
    return r; // Return the original head of the list
}

int main() {
    node* root;
    root = NULL;

    root = add(root, 25); // Add 25 at the end of the list
    //root = NULL;
    root = addAscend(root, 15); // Add 15 in ascending order in the list
    root = addAscend(root, 10); // Add 10 in ascending order in the list
    root = addAscend(root, 35); // Add 35 in ascending order in the list
    root = addAscend(root, 20); // Add 20 in ascending order in the list
    root = remove(root, 20); // Remove 20 from the list
    root = addAscend(root, -10); // Add -10 in ascending order in the list
    root = add(root, 78); // Add 78 at the end of the list
    root = remove(root, 999); // Try to remove 999 from the list (not found)
    root = addAscend(root, 1450); // Add 1450 in ascending order in the list

    print(root); // Print the values of the nodes in the list

}
