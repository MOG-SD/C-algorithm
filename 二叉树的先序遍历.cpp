#include <bits/stdc++.h>
using namespace std;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree; 

void CreateBiTree(BiTree *T){
	char c;
	scanf("%c",&c);
	if(' '==c ){
		*T = NULL;
	}else{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	} 
}

void visit(BiTree T,int level){		 //��ӡ��ĸ�ڵڼ��� 
		printf("%c �ڵ� %d ��\n",T->data,level);
}

void qianxu_visit(BiTree T,int level){
	if(T){
		visit(T,level);
		qianxu_visit(T->lchild,level+1);
		qianxu_visit(T->rchild,level+1);
	}
}

int main() {
	BiTree T;
	int level = 1;
	
	CreateBiTree(&T);
	qianxu_visit(T,level);
	return 0;
}
