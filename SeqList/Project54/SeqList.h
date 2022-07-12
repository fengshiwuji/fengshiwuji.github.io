#pragma once

typedef int SLTypeData;
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

typedef struct SeqList
{
	SLTypeData * data;
	int size;
	int capacity;
}SL;

void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListPushBack(SL* ps, SLTypeData x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLTypeData x);
void SeqListPopFront(SL* ps);
int SeqListFind(SL* ps, SLTypeData x);
void SeqListPushInsert(SL* ps,int pos,SLTypeData x);
void SeqListPopErase(SL* ps, int pos);
void SeqListCheckCapacity(SL* ps);