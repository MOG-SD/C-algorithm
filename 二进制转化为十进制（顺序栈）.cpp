#include<bits/stdc++.h>
using namespace std;
typedef struct stack{
	char *top;
	char *base;
	int stacksize;
}sqStack;

void InitStack(sqStack *s){
	s->base = (char*)malloc(10*sizeof(char));
	s->top = s->base;
	s->stacksize = 10;
}

void Push(sqStack *s, char e){
	if(s->top-s->base>=s->stacksize){	
		s->base = (char*)realloc(s->base,(s->stacksize+10)*sizeof(char));
		s->stacksize +=10;
	}
	*(s->top) = e;
	s->top++;
}

void Pop(sqStack *s, char *e){
	if(s->top == s->base){
		return;
	}
	*e = *--(s->top);
}

int StackLen(sqStack s){
	return s.top-s.base;
}

int main(){
	char c;
	int len,a,figure=0;
	sqStack s;
	InitStack(&s);
	printf("请输入二进制数(输入'#'表示结束):");
	scanf("%c",&c);
	while( c != '#'){
		Push(&s,c);
		scanf("%c",&c);
	}
	getchar();
	len = StackLen(s);
	for(int i=0;i<len;i++){
		Pop(&s,&c);
		figure += (c-48)*pow(2,i);
	}
	cout<<"其十进制为:"<<figure;
	return 0; 
}
