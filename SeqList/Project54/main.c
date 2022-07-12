#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "SeqList.h"

void SeqListTest1(void)
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl,1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);
}

void SeqListTest2(void)
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
}

void SeqListTest3(void)
{
	SL sl;
	SeqListInit(&sl);
	//SeqListPushBack(&sl, 1);
	//SeqListPushBack(&sl, 2);

	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 8);
	SeqListPushFront(&sl, 10);

	//SeqListPopFront(&sl);
	//SeqListPopFront(&sl);
	//SeqListPopFront(&sl);
	//SeqListPopFront(&sl);
	//SeqListPopFront(&sl);
	//SeqListPopFront(&sl);
	SeqListPrint(&sl);
}

void SeqListTest4(void)
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushFront(&sl, 5);
	
	SeqListPushInsert(&sl, 0, 200);
	SeqListPrint(&sl);
	SeqListPopErase(&sl, 3);
	SeqListPrint(&sl);
}

int main(void)
{
	//SeqListTest1();
	//SeqListTest2();
	//SeqListTest3();
	SeqListTest4();


	return 0;
}
