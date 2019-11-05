#include <stdio.h>
#include <stdlib.h>

struct StackItem
{
	int num;
	struct StackItem *prev;
	struct StackItem *next;
};

int x = 0;

struct StackItem *pLast =  NULL;
struct StackItem *pFirst =  NULL;

void Out()
{
	struct StackItem *pTemp = malloc(sizeof(struct StackItem));
	pTemp = pFirst;
	while(pTemp != NULL)
	{
		printf("%d\n",pTemp->num);
		pTemp = pTemp->next;
	}
	
	printf("NEXT: %d C: %d\n",pFirst->next->num, pFirst->num);
}

int AddItem()
{
	struct StackItem *pTemp = malloc(sizeof(struct StackItem));
	
	pTemp->num = x++;
	pTemp->next = NULL;
	if (pLast == NULL && pFirst == NULL)
	{
		pLast = pTemp;
		pFirst = pLast;
	}
	else
	{
		pTemp->prev = pLast;
		pLast->next = pTemp;
		pLast = pTemp;
	}
	
	
	
	return 1;
}

int DeleteItem()
{
	struct StackItem *pTemp = malloc(sizeof(struct StackItem));
	pTemp = pFirst;
	pFirst = pFirst->next;
	free(pTemp);
	printf("Okay\n");
	return 1;
}

int main()
{
	//SP = NULL;
	
	AddItem();
	AddItem();
	AddItem();
	AddItem();
	AddItem();
	AddItem();
	AddItem();
	AddItem();
	Out();
	printf("-------------\n");
	DeleteItem();
	DeleteItem();
	AddItem();
	Out();
	return 0;
	
}
