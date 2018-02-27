/*
------------------------------------------------------------------------
Write a program to sort an array
------------------------------------------------------------------------
*/
#include<stdio.h>

#define SIZE 10
#define size_t unsigned long

void sortAscArray(int*,int);
void sortDescArray(int*,int);
typedef void (*funcSort)(int*,int);

int main()
{
	int inputArray[SIZE]={0};
	//int outputArray[SIZE]={0};
	int iterate=0;
	int funcChoice;	
	printf("\n Enter the data in array to be sorted : \n");
	for(iterate=0;iterate<SIZE;iterate++)
	{
		printf("\n Array[%d]= ",iterate);
		scanf("%d",inputArray+iterate);
	}
	printf("\n Enter 1 to sort in ascending and 2 to sort in descending: ");
	scanf("%d",&funcChoice);
	switch(funcChoice)
	{
		case 1:
		{
			funcSort function=sortAscArray;
			function(inputArray,SIZE);
			break;
		}
		case 2:
		{
			funcSort function=sortDescArray;
			function(inputArray,SIZE);
			break;
		}
	}
	
	printf("\n The sorted array is: \n");
	for(iterate=0;iterate<SIZE;iterate++)
	{
		printf("\n Array[%d]=%d \n",iterate,inputArray[iterate]);
	}

	return 0;

}

void sortAscArray(int* arrayPointer,int arraySize)
{
	int outerIterate;
	int innerIterate;
	int* pointerToArray=arrayPointer;
	for(outerIterate=0;outerIterate<arraySize;outerIterate++)
	{
		for(innerIterate=0; innerIterate<arraySize-outerIterate-1; innerIterate++)
		{
		
			if(*(pointerToArray+1)<*(pointerToArray))
			{
				int temp=*pointerToArray;
				*pointerToArray = *(pointerToArray+1);
				*(pointerToArray+1)=temp;
			}
			pointerToArray++;
		}
		pointerToArray=pointerToArray-innerIterate;
	}
	pointerToArray=NULL;
}

void sortDescArray(int* arrayPointer,int arraySize)
{
	int outerIterate;
	int innerIterate;
	int* pointerToArray=arrayPointer;
	for(outerIterate=0;outerIterate<arraySize;outerIterate++)
	{
		for(innerIterate=0; innerIterate<arraySize-outerIterate-1; innerIterate++)
		{
		
			if(*(pointerToArray+1)>*(pointerToArray))
			{
				int temp=*pointerToArray;
				*pointerToArray = *(pointerToArray+1);
				*(pointerToArray+1)=temp;
			}
			pointerToArray++;
		}
		pointerToArray=pointerToArray-innerIterate;
	}
	pointerToArray=NULL;
}
