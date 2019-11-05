#include <stdio.h>
#include <stdlib.h>

#define and &&

#define N 5
int list[N];
int count = 0 ;
int main()
{
    int ch = 0;
    int val = 0;
    while (ch != 5)
    {
        printf("1 - OUT, 2 - ADD BEFORE, 3 - ADD AFTER, 4 - DELETE, 5 - EXIT ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            Out();
            break;
        case 2:
            scanf("%d",&val);
            val = Search(val);
            AddBefore(val);
            break;
        case 3:
            scanf("%d",&val);
            val = Search(val);
            AddAfter(val);
            break;
        case 4:
			Delete();
			break;

        }
    }
    return 0;
}

int Delete()
{
	if (is_empty_array() == 1)
    {
        return 0;
    }
    int x  = 0;
    scanf("%d",&x);
    x = Search(x);
    if (x == -1)
    {
		return 0;
	}
	for(int i = x ; i< count; i++)
	{
		list[i] = list[i+1];
	}
	count--;
	return 1;
		
}

void Out()
{
    printf("---------\n");
    for(int i = 0 ; i< count; i++)
    {
        printf("ID: %d Val: %d\n",i,list[i]);
    }
    printf("---------\n");
}

void AddAfter(int after)
{
    if (after == -1) return;
    if(is_full_array() == 1)
    {
        printf("Array is full!\n");
        return;
    }
    for (int i=N; i>after; i--)
        list[i] = list[i-1];
    list[after+1] = rand() % 20;
    count++;

}

void AddBefore(int before)
{
    if (before == -1) return;
    if(is_full_array() == 1)
    {
        printf("Array is full!\n");
        return;
    }
    for (int i=N-1; i>before; i--)
        list[i] = list[i-1];
    list[before] = rand() % 20;
    count++;
}

int Search(int value)
{
    if (is_empty_array() == 1)
    {
        return 0;
    }
    for(int i = 0 ; i< count; i++)
    {
        if (list[i] == value)
        {
            return i;
        }
    }
    printf("Not found!\n");
    return -1;
}

int is_empty_array()
{
    if(count == 0)
    {
        return 1;
    }
    return -1;
}

int is_full_array()
{
    if (count == N)
    {
        return 1;
    }
    return -1;
}

