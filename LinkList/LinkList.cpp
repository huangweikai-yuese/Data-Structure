#include <stdio.h>
#include <iostream>
using namespace std;

struct node{
	int data;
  	node* next;
	int length;
};
typedef node LinkList;

void AddLinklist(LinkList *L,int data) {  //增加
	node* p = L;
	while (p->next!=NULL)
	{
		p = p->next;
	}
	node * r = new node();
	r->data = data;
	p->next = r;
	L->length++;
}
void  DelLinkList(LinkList* L, int i) {  //删除
	node* p = L;
	for (int I = 0; I < i - 1; I++) {
		p = p->next;  //查找到i的前驱节点
	}
	node* q = p->next;
	p->next = p->next->next;
	free(q);
	L->length--;
}
void  ModifyLinkList(LinkList* L, int i,int data) {  //修改
	node* p = L;
	for (int I = 0; I < i; I++) {
		p = p->next;  //查找到节点i
	}
	p->data = data;
}
void  ErgodicLinkList(LinkList *L) {  //遍历
	while (L->next!=NULL)
	{
		cout << L->next->data << endl;
		L = L->next;
	}
}
int main() {
	LinkList* L = new LinkList();  //初始化头节点
	AddLinklist(L, 10);
	AddLinklist(L, 20);
	AddLinklist(L, 30);
	AddLinklist(L, 40);
	AddLinklist(L, 50);
	DelLinkList(L, 2); //删除第二个数据
	ModifyLinkList(L, 1,6666); //修改第一个数据
	ErgodicLinkList(L);
	return 0;
}
