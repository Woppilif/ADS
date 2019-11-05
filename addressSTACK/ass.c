#include <stdio.h>
#include <stdlib.h>

struct StackItem
{
	int num;
	struct StackItem *prev;
};

struct StackItem *SP =  NULL;

void Out()
{
	struct StackItem *pTemp = malloc(sizeof(struct StackItem));
	pTemp = SP;
	while(pTemp != NULL)
	{
		printf("%d\n",pTemp->num);
		pTemp = pTemp->prev;
	}
}

int AddItem()
{
	struct StackItem *pTemp = malloc(sizeof(struct StackItem));
	pTemp->prev = SP;
	pTemp->num = rand() % 20;
	SP = pTemp;
	return 1;
}

int DeleteItem()
{
	if(SP == NULL)
	{
		printf("Stack is empty!");
		return 0;
	}
	struct StackItem *pTemp = malloc(sizeof(struct StackItem));
	pTemp = SP;
	SP = pTemp->prev;
	free(pTemp);
	return 1;
}

int main()
{
	//SP = NULL;
	
	AddItem();
	AddItem();

	Out();
	printf("-------------\n");

	Out();
	return 0;
	
}
