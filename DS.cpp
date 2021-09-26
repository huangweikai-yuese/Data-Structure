#include "DS.h"

using namespace DS;
using namespace Sqlist;
using namespace Linklist;
Status Sqlist::InitList(List* L) {
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) {
        return false;
    }
    L->length = 0;
    L->listSize = LIST_INIT_SIZE;
    return true;
}

Status  Sqlist::InsertElemIntoList(List* L, int i, ElemType e) {
    if (i<1 || i>L->length + 1) {
        return false;
    }//���i�Ƿ������Ա���
    if (L->length >= L->listSize) {
        ElemType* newBase = (ElemType*)realloc(L->elem, (L->listSize + LISTINCREMENT) * sizeof(ElemType));
        if (!newBase) {
            return false;
        }
        L->elem = newBase;
        L->listSize += LISTINCREMENT;
    }//������󴢴�ռ��Ƿ��㹻
    ElemType* insert = &L->elem[i - 1];
    for (ElemType* p = &L->elem[L->length - 1]; p >= insert; p--) {
        *(p + 1) = *p;
    }//�ѵ�i��Ԫ�ؼ�֮��Ԫ�����ƽ��һλ
    *insert = e;
    L->length++;
    return true;
}

Status Sqlist::DeleteElemFromList(List* L, int i, ElemType& e) {
    if (i<1 || i>L->length) {
        return false;
    }
    ElemType* target;
    target = &L->elem[i - 1];
    e = *target;
    //�����Ƕ�ָ��ȡַȡֵ�ıȽ�
    //e=target
    //*ȡֵ��ɶҲ�����ǵ�ַ
   // e=L->base[i-1];
   //&ȡַ��ɶҲ������ֵ
    int count = 0;
    for (ElemType* p = &L->elem[L->length - 1]; p >= target; p--) {
        *(target + count) = *(target + 1 + count);
        count++;
    }
    L->length--;
    return e;
}

Status Sqlist::ModifyElem(List* L, int i, ElemType e) {
    if (i<1 || i>L->length) {
        return false;
    }
    L->elem[i - 1] = e;
    return true;
}

ElemType  Sqlist::GetElemfromList(List L, int i) {
    if (i<1 || i>L.length) {
        return false;
    }
    return L.elem[i - 1];
}

ElemType Sqlist::IsLocalElem(List L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return 1;
        }
    }
    return 0;
}

ElemType Sqlist::GetElemIndex(List L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

Status Sqlist::ClearList(List* L) {
    for (int i = 0; i < L->length; i++) {
        L->elem[i] = 0;
    }
    L->length = 0;
    return true;
}

Status Sqlist::TraverseList(List L) {
    for (int i = 0; i < L.length; i++) {
        printf("The %dth elem is %d:", i + 1, L.elem[i]);
    }
    return true;
}

/// <summary>
/// ����
/// </summary>
/// 
Status Linklist::InitLinkList(LinkList* L) {
    L = (LinkList*)malloc(sizeof(LinkList));
    if (!L) {
        return false;
    }
    L->data = 0;
    L->next = NULL;
    return true;
}//����һ��ֻ��ͷ���Ŀ�����

Status  Linklist::InsertElemIntoLinkList(LinkList* L, int i, ElemType e) {
    if (i < 1 || !L) {
        return false;
    }
    LinkList* pointer;
    pointer = L;
    for (int count = 1; count < i; count++) {
        pointer = L->next;
        if (!pointer) {
            return false;
        }
    }//�����ڵ㣬�ҵ���i-1���ڵ�
    LinkList* insert = (LinkList*)malloc(sizeof(LinkList));
    if (!insert) {
        return false;
    }//����һ���½ڵ�
    LinkList* temp = pointer->next;
    pointer->next = insert;
    insert->next = temp;
    insert->data = e;//�ڵ�i���ڵ�ǰ����
    return true;
}

Status  Linklist::DeleteElemFromLinkList(LinkList* L, int i) {
    if (i < 1 || !L) {
        return false;
    }
    LinkList* pointer = L;
    for (int count = 1; count < i; count++) {
        pointer = pointer->next;
        if (!pointer || !pointer->next) {
            return false;
        }
    }//�����ڵ㣬�ҵ���i-1���ڵ�
    LinkList* temp = pointer->next;
    pointer->next = temp->next;
    free(temp);//��յ�i���ڵ�Ĵ���ռ�
    return true;
}

ElemType Linklist::GetElemFromLinkList(LinkList L, int i, ElemType* e) {
    if (i < 1 || !&L) {
        return false;
    }
    LinkList* pointer = L.next;
    for (int count = 1; count < i; count++) {
        pointer = L.next;
        if (!pointer) {
            return false;
        }
    }
    *e = pointer->data;
    return *e;
}

ElemType  Linklist::GetIndexFromLinkList(LinkList L, int* i, ElemType e) {
    LinkList* pointer = L.next;
    int count = 1;
    while (pointer) {
        if (pointer->data == e) {
            *i = count;
            return *i;
        }
        pointer = pointer->next;
        count++;
    }
    return false;
}

Status Linklist::IsElemFromLinkList(LinkList L, ElemType e) {
    LinkList* pointer = L.next;
    while (pointer) {
        if (pointer->data == e) {
            return true;
        }
        pointer = pointer->next;
    }
    return false;
}

Status Linklist::AppendElemForLinkList(LinkList* L, ElemType e) {
    if (!L) {
        return false;
    }
    LinkList* pointer = L;
    while (pointer->next) {
        pointer = pointer->next;
    }//��������ʽ�����һ��Ԫ��
    LinkList* append = (LinkList*)malloc(sizeof(LinkList));
    if (!append) {
        return false;
    }
    pointer->next = append;
    append->data = e;
    append->next = NULL;
    return true;
}

ElemType Linklist::LengthLinkList(LinkList L, int* length) {
    int count = 0;
    LinkList* pointer = L.next;
    while (pointer) {
        count++;
        pointer = pointer->next;
    }
    *length = count;
    return *length;
}

Status  Linklist::ClearLinkList(LinkList* L) {
    if (!L) {
        return false;
    }
    LinkList* pointer = L->next;
    while (pointer) {
        LinkList* temp = pointer;
        pointer = pointer->next;
        free(pointer);
    }
    L->next = NULL;
    return true;
}

Status  Linklist::TraverseLinkList(LinkList L) {
    LinkList* pointer = L.next;
    int count = 1;
    while (pointer) {
        printf("The %dth elem is %d", count, pointer->data);
        count++;
        pointer = pointer->next;
    }
    return true;
}

Status Linklist::DestroyLinkList(LinkList* L) {
    if (L) {
        ClearLinkList(L);
    }
    free(L);//�ͷ�ͷ��㴢��ռ�
    L = NULL;
    return true;
}

int main() {
    List mylist;
    InitList(&mylist);
    InsertElemIntoList(&mylist,1,'a');
    std::cout << GetElemfromList(mylist,1);
}