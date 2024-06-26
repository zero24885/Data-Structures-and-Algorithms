#include <stdio.h>

#define OK    1;
#define ERROR 0;

#define MAXSIZE 1000

typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType data;
	int cur;
}Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)
{
	int i;
	for(i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
	
	return OK;
}

int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	if(space[0].cur)
		space[0].cur = space[i].cur;
		
	return i;
}

Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int j, k ,l;
	
	k = MAXSIZE - 1;
	if(i < 1 || i > ListLength(L))
	{
		return ERROR;
	}
	
	j = Malloc_SLL(L);
	if(j)
	{
		L[j].data = e;
		for(l = 1; l <= i -1; l++)
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
		
		return OK;
	}
}

Status ListDelete(StaticLinkList L, int i)
{
	int j, k;
	
	if(i < 1 || i > ListLength(L))
		return ERROR;
	
	k = MAXSIZE - 1;
	
	for(j = 1; j <= i - 1; j++)
		k = L[k].cur;
	
	j = L[k].cur;
	L[k].cur = L[j].cur;
	
	Free_SLL(L,j);
	
	return OK;
}

void Free_SLL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	
	while(i)
	{
		i = L[i].cur;
		j++;
	}
	
	return j;
}

int main(void)
{
    return OK;
}
