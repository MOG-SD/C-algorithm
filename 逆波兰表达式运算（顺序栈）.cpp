#include<bits/stdc++.h>
using namespace std;
typedef struct stack{
	double *top;
	double *base;
	int stacksize;
}sqStack;

void InitStack(sqStack *s){
	s->base = (double*)malloc(10*sizeof(double));
	s->top = s->base;
	s->stacksize = 10;
}

void Push(sqStack *s, double e){
	if(s->top-s->base>=s->stacksize){	
		s->base = (double*)realloc(s->base,(s->stacksize+10)*sizeof(double));
		s->stacksize +=10;
	}
	*(s->top) = e;
	s->top++;
}

void Pop(sqStack *s, double *e){
	if(s->top == s->base){
		return;
	}
	*e = *--(s->top);
}

int StackLen(sqStack s){
	return s.top-s.base;
}

int main(){
	sqStack s;
	double e,f;
	char c[10];
	InitStack(&s);
	printf("按照逆波兰表达式输入（以'#'作为结尾）：");
	scanf("%s",c);
	while(c[0] !='#'){
		switch(c[0]){
			case '+':
				Pop(&s, &e);
				Pop(&s, &f);
				Push(&s, e+f);
				break;
			case '-':
				Pop(&s, &e);
				Pop(&s, &f);
				Push(&s, f-e);
				break;
			case '*':
				Pop(&s, &e);
				Pop(&s, &f);
				Push(&s, e*f);
				break;
			case '/':
				Pop(&s, &e);
				Pop(&s, &f);
				Push(&s, f/e); //这里没有修改，但要注意除数不能为0 
				break;
			default:
				sscanf(c,"%lf",&e);
				Push(&s, e);
				break;
		}
		scanf("%s",c);
	}
	cout<<*(s.base);
	return 0; 
}
