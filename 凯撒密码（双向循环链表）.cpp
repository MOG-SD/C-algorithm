#include<bits/stdc++.h>
using namespace std;
typedef struct DualNode{
	char value;
	struct DualNode *prior;
	struct DualNode *next;
}DualNode,*DualLinkList;

void InitList(DualLinkList *L){
	DualLinkList p,q;
	*L = (DualLinkList)malloc(sizeof(DualNode));
	(*L)->next = (*L)->prior = NULL;
	p = (*L);
	for(int i=0;i<26;i++){
		q = (DualLinkList)malloc(sizeof(DualNode));
		q->value = 'A'+i;
		q->prior = p;
		q->next = p->next;
		p->next = q;

		p = q;
	}
	p->next = (*L)->next;
	(*L)->next->prior = p;
}
int main()
{
	DualLinkList L,p;
	int n;
	cout<<"输入一个数:"; 
	cin>>n;
	InitList(&L);
	p = L->next;
	while(n!=0){
		if(n>0){
			p = p->prior;
			n--;
		}
		if(n<0){
			p = p->next;
			n++;
		}
	}
	
	for(int i=0;i<26;i++){
		cout<<p->value;
		p = p->next;
	}
    return 0;
}
