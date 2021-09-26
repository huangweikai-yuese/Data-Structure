#pragma once
#include <iostream>
#include "malloc.h"
namespace DS {
	typedef bool Status;
	typedef char ElemType;
	namespace Sqlist {

#define LIST_INIT_SIZE 100//表储存空间的初始分配量
#define LISTINCREMENT 10//表储存空间的分配增量

			typedef struct {
				ElemType* elem;
				int length;
				int listSize;
			}List;
			Status  InitList(List* L);

			Status InsertElemIntoList(List* L, int i, ElemType e);

			Status DeleteElemFromList(List* L, int i, ElemType& e);

			Status ModifyElem(List* L, int i, ElemType e);

			ElemType GetElemfromList(List L, int i);

			ElemType IsLocalElem(List L, ElemType e);

			ElemType GetElemIndex(List L, ElemType e);

			Status ClearList(List* L);

			Status TraverseList(List L);
	
	}

namespace Linklist {
		typedef struct LNode {
			ElemType data;//数据域
			struct LNode* next;//指针域
		}LinkList;//此结构既表示链式表，又表示链表的头结点
		
		Status InitLinkList(LinkList* L);

		Status InsertElemIntoLinkList(LinkList* L, int i, ElemType e);

		ElemType GetElemFromLinkList(LinkList L, int i, ElemType* e);

		ElemType GetIndexFromLinkList(LinkList L, int* i, ElemType e);

		Status DeleteElemFromLinkList(LinkList* L, int i);

		Status IsElemFromLinkList(LinkList L, ElemType e);

		Status AppendElemForLinkList(LinkList* L, ElemType e);

		ElemType LengthLinkList(LinkList L, int* length);

		Status ClearLinkList(LinkList* L);

		Status DestroyLinkList(LinkList* L);

		Status TraverseLinkList(LinkList L);
	
	}

	namespace Queue {
		//定义一个循环队列
        #define MAXSIZE 100
		typedef struct
		{
			ElemType* base; //用于存放内存分配基地址
							//也可以用数组存放
			int front;
			int rear;
		}cycleQueue;
	   
		//初始化一个队列
		void initQueue(cycleQueue* q)
		{
			q->base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
			if (!q->base)
				exit(0);
			q->front = q->rear = 0;
		}

		//入队列操作
		void InsertQueue(cycleQueue* q, ElemType e)
		{
			if ((q->rear + 1) % MAXSIZE == q->front)
			return;//队列已满
			q->base[q->rear] = e;
			q->rear = (q->rear + 1) % MAXSIZE;
		}

		//出队列操作
		void DeletQueue(cycleQueue* q, ElemType* e)
		{
			if (q->front == q->rear)
				return;//队列为空
			*e = q->base[q->front];
			q->front = (q->front + 1) % MAXSIZE;
		}


	}


	namespace Stack {}



}

