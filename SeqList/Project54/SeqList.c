#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


void SeqListInit(SL* ps)
{
	ps->data = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ",ps->data[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : (ps->capacity * 2);
		SLTypeData* temp = (SLTypeData*)realloc(ps->data,sizeof(SLTypeData) * newcapacity);
		if (temp == NULL)
		{
			printf("malloc fail！\n");
			exit(-1);
		}
		ps->data = temp;
		ps->capacity = newcapacity;
	}
}

void* my_memmove(void* dest, const void* src, int size)
{
	void* ret = dest;
	if (dest <= src || (char*)dest >= ((char*)src + size))
	{
		while (size--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		dest = (char*)dest + size - 1;
		src = (char*)src + size - 1;
		while (size--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}
	return ret;
}

void SeqListPushBack(SL* ps, SLTypeData x)
{
	SeqListCheckCapacity(ps);
	ps->data[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}

void SeqListPushFront(SL* ps, SLTypeData x)
{
	SeqListCheckCapacity(ps);
	my_memmove(ps->data + 1, ps->data, ps->size * sizeof(SLTypeData));
	ps->data[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);
	my_memmove(ps->data, ps->data+1, ps->size * sizeof(SLTypeData));
	ps->size--;
}

int SeqListFind(SL* ps, SLTypeData x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListPushInsert(SL* ps, int pos,SLTypeData x)
{
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);
	my_memmove(ps->data+pos+1, ps->data+pos, (ps->size-pos) * sizeof(SLTypeData));
	ps->data[pos] = x;
	ps->size++;
}
/*
* ps->size - pos-1
* ps->size - pos也可以，但是这样发生越界了
*/
void SeqListPopErase(SL* ps,int pos)
{	
	assert(pos >= 0 && pos < ps->size);
	my_memmove(ps->data + pos, ps->data + pos+1, (ps->size - pos-1) * sizeof(SLTypeData)); 
	ps->size--;
}