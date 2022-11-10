#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int mass;
    struct node* next;
    struct node* prev;
} node;

node* burn(node* head);
node* get_node_with_lowest_mass(node* head);
node* transfer_mass_and_delete(node* head, node* lowest_mass_point);
node* delete_node(node* head, node* node_to_delete);
node* create_points_list(int masses[], int points_count);
void print_points(node* head);

int main(int argc, char** argv){
    int masses[8] = {20, 100, 50, 46, 69, 2, 41, 34};
    
    node* head = create_points_list(masses, 8);
    print_points(head);
    while(head->next != head){
        head = burn(head);
        print_points(head);
    }
}

node* burn(node* head){
    node* lowest_mass_point = get_node_with_lowest_mass(head);
    return transfer_mass_and_delete(head, lowest_mass_point);
}

node* get_node_with_lowest_mass(node* head){
    node* current = head;
    node* lowest = current;
    do
    {
        if (current->mass < lowest->mass)
        {
            lowest = current;
        }
        current = current->next;
    } while (current != head);
    
    return lowest;
}

node* transfer_mass_and_delete(node* head, node* lowest_mass_point){
    lowest_mass_point->next->mass += lowest_mass_point->mass;
    return delete_node(head, lowest_mass_point);
}

node* delete_node(node* head, node* node_to_delete){
    node* return_val = head;

    if (node_to_delete->prev != NULL)
    {
        node_to_delete->prev->next = node_to_delete->next;
    }
    if (node_to_delete->next != NULL)
    {
        node_to_delete->next->prev = node_to_delete->prev;
    }

    if (node_to_delete == head)
    {
        return_val = node_to_delete->next;
    }

    head = return_val;
    free(node_to_delete);
    return head;
}

node* create_points_list(int masses[], int points_count){    
    node* prev = NULL;
    node* current;
    node* head;

    for (int i = 0; i < points_count; i++)
    {
        current = malloc(sizeof(node));
        current->mass = masses[i];
        current->prev = prev;
        if (prev != NULL)
        {
            prev->next = current;
        }
        
        prev = current;
        if (i==0)
        {
            head = current;
        }
        if (i == points_count-1)
        {
            head->prev = current;
        }
        
    }
    return current->next = head;
}

void print_points(node* head){
    node* current = head;
    printf("Points: ");

    do
    {
        printf("%d ", current->mass);
        current = current->next;
    } while (current != head);
    
    printf("\n");
}