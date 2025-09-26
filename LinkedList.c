Linked list:
//Linked list

#include <stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
};
//insetion
void insert_begin(struct Node** head, int num)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = num;
	newNode->next = *head;
	*head = newNode;
}
void insert_end(struct Node** head, int num)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=num;
	newNode->next=NULL;
	if(*head==NULL)
	{
		*head =newNode;
		return;
	}
	struct Node* temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;

}
void insert_after(struct Node* head, int target, int value) {
	struct Node* temp = head;

	while (temp != NULL && temp->data != target) {
		temp = temp->next;
	}

	if (temp == NULL) {
		printf("Target value %d not found.\n", target);
		return;
	}

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = temp->next;
	temp->next = newNode;
}

void insert_before(struct Node** head, int target, int value) {
	if (*head == NULL) {
		printf("List is empty.\n");
		return;
	}
	if ((*head)->data == target) {
		insert_begin(head, value);
		return;
	}
	struct Node* temp = *head;
	struct Node* prev = NULL;
	while (temp != NULL && temp->data != target) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		printf("Target value %d not found.\n", target);
		return;
	}
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = temp;
	prev->next = newNode;
}
//deletion
void delete_begin(struct Node** head) {
	if(*head ==NULL)
	{
		printf("list is empty:\n");
		return;
	}
	struct Node *temp= *head;
	* head=(*head)->next;
	printf("%d\n",temp->data);
	free(temp);
}
void delete_end(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        printf("Deleted value: %d\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted value: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}
void delete_spec(struct Node** head,int value)
{
      if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        printf("Deleted value: %d\n", temp->data);
        free(temp);
        return;
    }

    struct Node* prev = *head;
    struct Node* curr = (*head)->next;

    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = curr->next;
    printf("Deleted value: %d\n", curr->data);
    free(curr);
}
//traversing through the list
void travel_forward(struct Node* head) {
	struct Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}
void travel_back(struct Node* head) {
    if (head == NULL)
        return;

    travel_back(head->next);
    printf("%d -> ", head->data);
}


int main()
{
	struct Node* head = NULL;
	int choice,input,target;
	while(1) {
		printf("\n1.insert at begin :\n2.insert at end:\n3.insert after the target element:\n4.insert before the target:\n5.delete beg:\n6.delete end :\n7.delete specific \n8.travel forward list:\n9.travel back\n");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			printf("enter the inserting element:");
			scanf("%d",&input);
			insert_begin(&head, input);
			break;

		case 2:
			printf("\nenter the inserting element at the end :");
			scanf("%d",&input);
			insert_end(&head,input);
			break;
		case 3:
			printf("\nenter the element to be searched:");
			scanf("%d",&target);
			printf("\nenter the element to be inserted:");
			scanf("%d",&input);
			insert_after(head,target,input);
			break;
		case 4:
			printf("\nenter the element to be searched:");
			scanf("%d",&target);
			printf("\nenter the element to be inserted befor:");
			scanf("%d",&input);
			insert_before(&head,target,input);
			break;
		case 5:
			printf("element to be deleted :");
			delete_begin(&head);
			break;
		case 6:
			delete_end(&head);
			break;
		case 7:
		    printf("enter the element to be deleted :");
		    scanf("%d",&input);
		    delete_spec(&head,input);
		    break;
		case 8:
			printf("\ntravelling forward through the list:");
			travel_forward(head);
			break;
		case 9:
		    printf("\ntraversing the list from the backward:");
		    travel_back(head);
		    printf("NULL\n");
		    break;
		default:
		    printf("invalid choice");
			break;

		}
	}
}

