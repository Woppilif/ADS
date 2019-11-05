#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int COUNT = 0;

struct Items
{
    /* data */
    int value;
    struct Items *prev;
    struct Items *next;
};

struct Items *pFirst;

void OutFFTL()
{
    struct Items *pTemp = pFirst;
    while(pTemp != pFirst->prev)
    {
        printf("%d\n",pTemp->value);
        pTemp = pTemp->next;
    }
}

void OutFLTF()
{
    struct Items *pTemp = pFirst;
    while(pTemp != pFirst->prev)
    {
        printf("%d\n",pTemp->value);
        pTemp = pTemp->next;
    }
}

bool empty()
{
    if(pFirst == NULL) return true;
    return false;
}

struct Items * Search(int key)
{
    struct Items *pTemp = pFirst;
    while(pTemp != NULL)
    {
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

int AddAfter(int item)
{
    struct Items *pTemp = Search(item);
    struct Items *pNew = malloc(sizeof(struct Items));
    if(empty())
    {
        pNew->value = COUNT++;
        pNew->prev = NULL;
        pNew->next = NULL;
        pFirst = pNew;
        return 1;
    }
    if(pTemp == NULL)
    {
        printf("No macth!\n");
        return 1;
    }
    pNew->value = COUNT++;  
    if(pTemp->prev == NULL)
    {
        pTemp->prev = pFirst;
    }
    pNew->prev = pTemp;
    pNew->next = pTemp->next;
    pTemp->next = pNew;
    if(pNew->next == NULL)
    {
        pNew->next = pFirst;
    }
    
    

}

int main()
{
    for(int i = 0; i < 10; i++)
    {
        AddAfter(i-1);
    }
    OutFFTL();
    printf("pref:%d",pFirst->prev->value);
    printf("-----------------\n");
    //OutFLTF();
    return 1;
}