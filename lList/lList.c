#include <stdio.h>
#include <stdlib.h>


struct ListItem
{
	int num;
	struct ListItem *next;
};

int x = 0;
struct ListItem *pFirst;

struct ListItem * Search(int item)
{
	struct ListItem *pTemp = malloc(sizeof(struct ListItem));
	pTemp = pFirst;
	while(pTemp != NULL)
	{
		if(pTemp->num == item)
		{
			return pTemp;
		}
		else
		{
			pTemp = pTemp->next;
		}
	}
	return NULL;
}

struct ListItem * DeleteSearch(int item)
{
	struct ListItem *pTemp = malloc(sizeof(struct ListItem));
	pTemp = pFirst;
	while(pTemp != NULL)
	{
		if(pTemp->next->num == item)
		{
			return pTemp;
		}
		else
		{
			pTemp = pTemp->next;
		}
	}
	return NULL;
}

void OutAddress()
{
	struct ListItem *pTemp = malloc(sizeof(struct ListItem));
	pTemp = pFirst;
	printf("-------------\n");
	while(pTemp != NULL)
	{
		printf("%p\n",pTemp);
		pTemp = pTemp->next;
	}
	printf("-------------\n");
}

void Out()
{
	struct ListItem *pTemp = malloc(sizeof(struct ListItem));
	pTemp = pFirst;
	printf("-------------\n");
	while(pTemp != NULL)
	{
		printf("%d\n",pTemp->num);
		pTemp = pTemp->next;
	}
	printf("-------------\n");
}

int AddItem()
{
	struct ListItem *pTemp = malloc(sizeof(struct ListItem));
	struct ListItem *pPrev = malloc(sizeof(struct ListItem));
	if (pFirst == NULL)
	{
		//pTemp = pFirst;
		pTemp->num = x++;
		pTemp->next = NULL;
		pFirst = pTemp;
		printf("Here\n");
	}
	else
	{
		/*Add After*/
		int y =  0;
		printf("give me: \n");
		scanf("%d",&y);
		pPrev = Search(y);
		if (pTemp == NULL)
		{
			printf("Not match!\n");
			return 0;
		}
		//pFirst->next = pTemp;
		pTemp->next = pPrev->next;
		pTemp->num = x++;
		pPrev->next = pTemp;
		
		printf("Here 2\n");
		return 1;
	}
	return 1;	
}

int Delete()
{
	struct ListItem *pPrev = malloc(sizeof(struct ListItem));
	struct ListItem *pTemp = malloc(sizeof(struct ListItem));
	int y = 0;
	scanf("%d",&y);
	pPrev = DeleteSearch(y); // before
	pTemp = pPrev->next; //delete
	//pPrev->next->next; // after
	pPrev->next = pPrev->next->next;
	free(pTemp);
	return 1;
}

int main()
{
	int ch = 0;
	while (ch != 4)
	{
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			Out();
			break;
		case 2:
			AddItem();
			break;
		case 3:
			Delete();
			break;
		case 5:
			OutAddress();
			break;
		}
		
	}
	
	return 0;
	
}

