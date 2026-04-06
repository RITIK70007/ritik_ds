#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
} node;

node *create(int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void display(node *head)
{
    node* curr = head;
    while(curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Insert at beginning
node* insert_b(node* head, int x)
{
    node* temp = create(x);
    if(head != NULL)
    {
        temp->next = head;
        head->prev = temp;
    }
    return temp;
}

// Insert at last
node* insert_l(node* head, int x)
{
    node* temp = create(x);
    if(head == NULL)
        return temp;

    node* c = head;
    while(c->next)
    {
        c = c->next;
    }

    c->next = temp;
    temp->prev = c;
    return head;
}

// Insert at position
node* insert_p(node* head, int x, int pos)
{
    if(pos == 1)
        return insert_b(head, x);

    node* temp = create(x);
    node* c = head;

    for(int i = 1; i <= pos - 2; i++)
    {
        c = c->next;
    }

    temp->next = c->next;
    temp->prev = c;

    if(c->next != NULL)
        c->next->prev = temp;

    c->next = temp;

    return head;
}

// Delete beginning
node* delete_b(node* head)
{
    if(head == NULL)
        return NULL;

    node* temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
    return head;
}

// Delete last
node* delete_l(node* head)
{
    if(head == NULL)
        return NULL;

    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }

    node* c = head;
    while(c->next)
    {
        c = c->next;
    }

    c->prev->next = NULL;
    free(c);

    return head;
}

// Delete at position
node* delete_p(node* head, int pos)
{
    if(pos == 1)
        return delete_b(head);

    node* c = head;

    for(int i = 1; i <= pos - 1; i++)
    {
        c = c->next;
    }

    if(c->prev != NULL)
        c->prev->next = c->next;

    if(c->next != NULL)
        c->next->prev = c->prev;

    free(c);
    return head;
}

// Find median
void getMedian(node* head)
{
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Median: %d\n", slow->data);
}

int main()
{
    node *head = create(10);
    node *first = create(20);
    node *second = create(30);
    node *third = create(40);

    // Proper linking (both next and prev)
    head->next = first;
    first->prev = head;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    printf("Initial list: ");
    display(head);

    getMedian(head);

    head = insert_b(head, 5);
    printf("After insert at beginning: ");
    display(head);

    head = insert_l(head, 50);
    printf("After insert at last: ");
    display(head);

    head = insert_p(head, 25, 3);
    printf("After insert at position 3: ");
    display(head);

    head = delete_b(head);
    printf("After delete beginning: ");
    display(head);

    head = delete_l(head);
    printf("After delete last: ");
    display(head);

    head = delete_p(head, 3);
    printf("After delete position 3: ");
    display(head);

    return 0;
}