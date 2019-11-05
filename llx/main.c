#include <stdio.h>
#include <stdlib.h>

int COUNT = 0;

struct Items
{
    /* data */
    int value;
    struct Items *next;
};

struct Items *pFirst;

void init()
{
    pFirst = malloc(sizeof(struct Items));
    pFirst = NULL;
}

void Out()
{
    struct Items *pTemp = pFirst;
    while (pTemp != NULL)
    {
        /* code */
        printf("VALUE: %d\n",pTemp->value);
        pTemp = pTemp->next;
    }
}

int empty()
{
    if(pFirst == NULL)
    {
        return 1;
    }
    return 0;
}

struct Items * Search(int key)
{
    struct Items *pTemp = pFirst;
    while (pTemp != NULL)
    {
        /* code */
        if(pTemp->value == key)
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

struct Items * FindPrevious(struct Items *pSearch)
{
    struct Items *pTemp = pFirst;
    while (pTemp != NULL)
    {
        /* code */
        if(pTemp->next == pSearch || pTemp == pSearch)
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

int AddAfter(int item)
{
    struct Items *pTemp = Search(item);
    struct Items *pNew;
    pNew = malloc(sizeof(struct Items));
    if(empty() == 1)
    {
        pNew->value = COUNT++;
        pNew->next = NULL;
        pFirst = pNew;
        printf("Added item into empty list!\n");
        return 1;
    }
    if(pTemp == NULL)
    {
        printf("No match\n");
        return 1;
    }
    
    pNew->value = COUNT++;
    pNew->next = pTemp->next;
    pTemp->next = pNew;
    printf("Added item into NOT empty list!\n");
    return 1;
}

int AddBefore(int item)
{
    struct Items *pTemp = Search(item);
    struct Items *pNew;
    struct Items *pPrev = FindPrevious(pTemp);
    pNew = malloc(sizeof(struct Items));
    if(empty() == 1)
    {
        pNew->value = COUNT++;
        pNew->next = NULL;
        pFirst = pNew;
        printf("Added item into empty list!\n");
        return 1;
    }
    if(pTemp == NULL)
    {
        printf("No match\n");
        return 1;
    }
    
    if(pFirst == pTemp)
    {
        pNew->value = COUNT++;
        pNew->next = pFirst;
        pFirst = pNew;
    }
    else
    {
        pNew->value = COUNT++;
        pPrev->next = pNew;
        pNew->next = pTemp;
    }
}

int Delete(int item)
{
    if(empty() == 1) return 1;
    struct Items *pDelete = Search(item);
    struct Items *pPrev = FindPrevious(pDelete);
    pPrev->next = pDelete->next;
    if(pFirst == pDelete)
    {
        pFirst = pDelete->next;
    }
}

int main()
{
    int n = 0;
    int item = 0;
    //AddAfter(0);
    for(int i= 0; i< 9;i++)
    {
        AddAfter(i-1);
    }
    while (n != -1)
    {
        scanf("%d",&n);
        /* code */
        switch (n)
        {
        case 1:
            /* code */
            Out();
            break;
        case 2:
            printf("Input val: ");
            scanf("%d",&item);
            AddAfter(item);
            break;
        case 3:
            printf("Input val: ");
            scanf("%d",&item);
            AddBefore(item);
            break;
        case 4:
            printf("Input val: ");
            scanf("%d",&item);
            Delete(item);
            break;
        
        default:
            break;
        }
    }
    return 0;
}