#include <stdio.h>

#define OK    1;
#define ERROR 0;

typedef int ElemType;
typedef int Status;

typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node;
typedef struct Node *LinkList;

Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p;
	
	p = L->next;
	j = 1;
	
	while(p && j < i)
	{
		p = p->next;
		++j;
	}	
	
	if(!p || j > i)
	{
		return ERROR;
	}
	
	*e =p->data;
	
	return OK;
}

Status ListInsert(LinkList *L,int i, ElemType e)
{
	int j;
	LinkList p, s;
	
	p = *L;
	j = 1;
	
	while(p && j < i)
	{
		p = p->next;
		j++;
	}	
	
	if(!p || j > i)
	{
		return ERROR;
	}
	
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	
	s->next = p->next;
	p->next = s;
    
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	
	p = *L;
	j = 1;
	
	while(p->next && j < i)
	{
		p = p->next;
		++j;
	}
	
	if(!(p->next) || j > i)
	{
		return ERROR;
	}
	
	q = p->next;
	p->next = q->next;
	
	*e = q->data;
	free(q);
	
	return OK;
}

Status ClearList(LinkList *L)
{
	LinkList p, q;
	
	p = (*L)->next;
	
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	(*L)->next = NULL;
	
	return OK;
}

int main(void)
{
    return OK;
}