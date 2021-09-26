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
    }//检查i是否在线性表中
    if (L->length >= L->listSize) {
        ElemType* newBase = (ElemType*)realloc(L->elem, (L->listSize + LISTINCREMENT) * sizeof(ElemType));
        if (!newBase) {
            return false;
        }
        L->elem = newBase;
        L->listSize += LISTINCREMENT;
    }//检查插入后储存空间是否足够
    ElemType* insert = &L->elem[i - 1];
    for (ElemType* p = &L->elem[L->length - 1]; p >= insert; p--) {
        *(p + 1) = *p;
    }//把第i个元素及之后元素向后平移一位
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
    //以下是对指针取址取值的比较
    //e=target
    //*取值，啥也不带是地址
   // e=L->base[i-1];
   //&取址，啥也不带是值
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
/// 链表
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
}//创建一个只有头结点的空链表

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
    }//遍历节点，找到第i-1个节点
    LinkList* insert = (LinkList*)malloc(sizeof(LinkList));
    if (!insert) {
        return false;
    }//创建一个新节点
    LinkList* temp = pointer->next;
    pointer->next = insert;
    insert->next = temp;
    insert->data = e;//在第i个节点前插入
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
    }//遍历节点，找到第i-1个节点
    LinkList* temp = pointer->next;
    pointer->next = temp->next;
    free(temp);//清空第i个节点的储存空间
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
    }//遍历到链式表最后一个元素
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
    free(L);//释放头结点储存空间
    L = NULL;
    return true;
}

int main() {
    List mylist;
    InitList(&mylist);
    InsertElemIntoList(&mylist,1,'a');
    std::cout << GetElemfromList(mylist,1);
}