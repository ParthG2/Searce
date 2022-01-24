#include <stdio.h>
#include <stdlib.h>
typedef struct myNode
{
    int val;
    struct myNode *next;
} Node;
void insert(Node **head, int val)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->val = val;
    tmp->next = NULL;
    if(*head == NULL)
    {
        *head = tmp;
    }
    else
    {
        Node *curr = *head;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = tmp;
    }
}
int main(void){
    int p, i;
    printf("Number of linked list entries : ");
    scanf("%d", &p);
    if (p<1)
    {
        printf("P cannot be less than 1");
        exit(1);
    }
    if (p>1000)
    {
        printf("P cannot be greater than 1000");
        exit(1);
    }
    Node *myList = NULL;
    for(i = 0; i < p; i++)
    {
       
        int val;
        printf("Input data for node: ");
    Entries:
        scanf("%d", &val);
        if (val<1 || val >1000)
        {
            printf("Value Out of Range\n");
            printf("Please re-enter data\n");
            goto Entries;
        }
        insert(&myList, val);
    }
    printf("Data entered in the list : \n");
    while(myList != NULL)
    {
        printf("%d\n", myList->val);
        myList = myList->next;
    }
}