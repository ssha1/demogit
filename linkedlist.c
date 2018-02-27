/*
--------------------------------------------------------------------
Write a program to create,insert,delete and update linked list
--------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node
{
	int index;
	int data;
	struct node* next;
}node;

typedef struct list
{
	int count;
	node* head;
	node* tail;

}list;

list* createList();
void displayList(list*);
void addInList(list*,int);
void deleteFromList(list*,int);
void updateList(list*,int,int);

int main()
{
	list* newList;
	int choice;
	int index;
	int newData;
	newList=(list*)malloc(sizeof(list*));
	while(1)
	{
		printf("\n-----------------------------------------------------------------------------------------------------------\n");
		printf("-----------------------------------------------------------------------------------------------------------");
		printf("\n Please select any one option \n ");	
		printf("\n 1. Create List \t 2.Add into list \t 3.Delete from list \t 4.Update list \t 5. Display List \t 6. Exit \n ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				newList=createList();
				break;
			}
			case 2: 
			{
				printf(" Enter the index at which the node is to be added: ");
				scanf("%d",&index);
				addInList(newList,index);
				break;
			}
			case 3: 
			{
				printf(" Enter the index of the node that is to be deleted: ");
				scanf("%d",&index);
				deleteFromList(newList,index);
				break;
			}
			case 4:
			{
				printf(" Enter the index of the node at data is to be updated: ");
				scanf("%d",&index);
				printf(" Enter the new value: ");
				scanf("%d",&newData);
				updateList(newList,index,newData);
				break;
			}
			case 5:
			{
				displayList(newList);
				break;
			}
			case 6:
			{
				exit(0);
				break;
			}
			default:
				printf("\n Please enter correct choice \n ");
		}
	}
	return 0;

}
list* createList()
{
	list* newList;	
	node* listNode;
	int data;
	int iCount;
	newList=(list*)malloc(sizeof(list));
	printf("\n Enter the data in the list \n");
	for(iCount=0;iCount<10;iCount++)
	{
		printf(" ");
		scanf("%d",&data);							
		newList->count++;
		listNode=(node*)malloc(sizeof(node));
		listNode->data=data;
		listNode->index=newList->count;
		if(newList->count==1)
		{
			newList->head=listNode;
			newList->tail=listNode;
			newList->head->next=NULL;	

		}
		else
		{			
			newList->tail->next=listNode;
			newList->tail=listNode;
			newList->tail->next=NULL;
		}
	}
	return newList;
}

void displayList(list* newList)
{
	node* currentNode;
	int iCount;
	currentNode=newList->head;
	for(iCount=1;iCount<=newList->count;iCount++)
	{
		printf("\n Node %d : \t Data %d",currentNode->index,currentNode->data);	
		currentNode=currentNode->next;
	}

}

void addInList(list* newList,int indexOfInsertion)
{
	node* currentNode;
	node* tempNode;
	node* newNode;
	int data;
	currentNode=newList->head;	
	printf("\n Enter the data to be inserted in new node: \n");
	scanf("%d",&data);
	newList->count++;
	newNode=(node*)malloc(sizeof(node));	
	newNode->data=data;
	if(indexOfInsertion>newList->count)
	{		
		tempNode=newList->tail;
		newList->tail=newNode;		
		tempNode->next=newNode;
		newNode->next=NULL;		
		newNode->index=newList->count;		
	}
	else
	{	
		if(indexOfInsertion==1)
		{			
			newNode->index=1;
			newNode->next=newList->head;
			newList->head=newNode;
			tempNode=newNode->next;			
		}
		else
		{		
		
			while((currentNode->index) < (indexOfInsertion-1))
			{
				currentNode=currentNode->next;	
			}	
				
			newNode->index=currentNode->next->index;		
			tempNode=currentNode->next;		
			currentNode->next=newNode;
			newNode->next=tempNode;
				
		}
		while(tempNode->index < newList->tail->index)
		{
				tempNode->index++;
				tempNode=tempNode->next;
		}
			newList->tail->index++;	
	}	
}

void deleteFromList(list* newList,int indexOfDeletion)
{
	node* currentNode;
	node* tempNode;	
	currentNode=(node*)malloc(sizeof(node*));
	currentNode=newList->head;
	if(indexOfDeletion>newList->count)
	{
		printf(" No node available at index %d",indexOfDeletion);
	}
	else
	{		
		if(indexOfDeletion==1)
		{
			newList->head=currentNode->next;
			currentNode=newList->head;
			while(currentNode->index < newList->tail->index)
				{
					currentNode->index--;
					currentNode=currentNode->next;
				}
				newList->tail->index--;
		}		
		else
		{
			while((currentNode->index)!=(indexOfDeletion-1))
			{
				currentNode=currentNode->next;					
			}		
		
			tempNode=currentNode->next;
			if(tempNode==newList->tail)
			{
				currentNode->next=NULL;
				newList->tail=currentNode;
			}
			else
			{
				currentNode->next=tempNode->next;
				currentNode=currentNode->next;
			
				while(currentNode->index < newList->tail->index)
				{
					currentNode->index--;
					currentNode=currentNode->next;
				}
				newList->tail->index--;
			}		
		}
		newList->count--;
	}
}

void updateList(list* newList,int index,int newData)
{
	node* currentNode;
	currentNode=newList->head;
	while(currentNode->index!=index)
	{
		currentNode=currentNode->next;
		if(currentNode==NULL)
		{
			break;
		}
	}
	if(currentNode!=NULL)
	{
		currentNode->data=newData;
		printf("\n The updated value of node at index %d is %d \n",currentNode->index,currentNode->data);
	}
	else
	{
		printf("\n Node at index %d not available \n",index);
	}
}
