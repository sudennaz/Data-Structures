#include <stdio.h>
#include <stdlib.h>

	struct Node{
		int data;
		struct Node *next;	
	};
	
	void insertNode(struct Node **head,int value)
	{
		struct Node *newNode=(struct Node*)malloc(sizeof(struct Node)); //first node
		
		newNode->data = value;
		newNode->next = NULL;
		
		if(head == NULL )
		{
			*head = newNode; 
		}
		else if(newNode->data %2 != 0) // odd number
		{
			struct Node *current = newNode;
			current->data = value;
			current->next = *head;
			*head= current;
		}
		else // even number 
		{
			struct Node *current = *head; // current en sonu gösteriyor
			
			while(current->next != NULL ) // sonuna gelene kadar
			{
				current=current->next;
			}
			current->next = newNode;
		}
	}
	
int main()
	{
	int value;
	struct Node *head = NULL;
		
	printf("Enters datas to add the list(for exit -1) :\n");
	
	while(1)
	{
		scanf("%d",&value);
		if(value == -1)
		{
			break;
		}
		insertNode(&head,value);
	}

	struct Node *current = head;
	
	printf("List star with : ");
	
	while(current != NULL)
	{
		printf("%d->",current->data);
		current= current->next;
	}
	
	printf("End of the list/n");
	
	
}
