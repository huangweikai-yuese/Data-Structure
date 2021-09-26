#pragma once
#include <iostream>
#include "malloc.h"
namespace DS {
	typedef bool Status;
	typedef char ElemType;
	namespace Sqlist {

#define LIST_INIT_SIZE 100//����ռ�ĳ�ʼ������
#define LISTINCREMENT 10//����ռ�ķ�������

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
			ElemType data;//������
			struct LNode* next;//ָ����
		}LinkList;//�˽ṹ�ȱ�ʾ��ʽ���ֱ�ʾ�����ͷ���
		
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
		//����һ��ѭ������
        #define MAXSIZE 100
		typedef struct
		{
			ElemType* base; //���ڴ���ڴ�������ַ
							//Ҳ������������
			int front;
			int rear;
		}cycleQueue;
	   
		//��ʼ��һ������
		void initQueue(cycleQueue* q)
		{
			q->base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
			if (!q->base)
				exit(0);
			q->front = q->rear = 0;
		}

		//����в���
		void InsertQueue(cycleQueue* q, ElemType e)
		{
			if ((q->rear + 1) % MAXSIZE == q->front)
			return;//��������
			q->base[q->rear] = e;
			q->rear = (q->rear + 1) % MAXSIZE;
		}

		//�����в���
		void DeletQueue(cycleQueue* q, ElemType* e)
		{
			if (q->front == q->rear)
				return;//����Ϊ��
			*e = q->base[q->front];
			q->front = (q->front + 1) % MAXSIZE;
		}


	}


	namespace Stack {}



}

