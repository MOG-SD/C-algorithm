#include<iostream>
#include<cstring>
#include<cstdlib>
//INSERT id name 代表向表末尾插入一条 ID 为 id，NAME 为 name 的数据。
//DELETE ID id 代表删除表中 ID 为 id 的数据。
//DELETE NAME name 代表删除表中 NAME 为 name 的数据。
//UPDATE ID id1 id2 代表将表中 ID 为 id1 的数据的 ID修改为 id2。
//UPDATE NAME name1 name2 代表将表中 NAME 为 name1 的数据的 NAME 修改为 name2。
//SELECT ID id 代表查找表中 ID 为 id 的数据。
//SELECT NAME name 代表查找表中 NAME 为 name 的数据。
//SELECT ? 代表查找表中所有数据。
using namespace std;
typedef struct excel{
	char id[51];
	char a[51];
	struct excel *next;
}excel;
typedef struct _list{
	excel *head;
}List;

void inseat(List *);
void delete1(List *);
void delete2(List *);
void update1(List *);
void update2(List *);
void select1(List *);
void select2(List *);
void select3(List *);
int cnt=0;
int main(){
	int n,m;
	List list;
	list.head=NULL;
	string order;
	cin>>n;
	excel array[2000];
	for(int i=0;i<n;i++)
		inseat(&list);
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>order;
		if(order.find("INSERT")!=-1) inseat(&list);
		else if(order.find("DELETE")!=-1){
			cin>>order;
			if(order.find("ID")!=-1) delete1(&list);
			else delete2(&list);
		}
		else if(order.find("UPDATE")!=-1){
			cin>>order;
			if(order.find("ID")!=-1) update1(&list);
			else update2(&list);
		}
		else if(order.find("SELECT")!=-1){
			cin>>order;
			if(order.find("ID")!=-1) select1(&list);
			else if(order.find("NAME")!=-1) select2(&list);
			else select3(&list); 
		}
	}
	return 0;
}

void inseat(List *plist){
	excel *p=(excel *)malloc(sizeof(excel));
	cin>>p->id>>p->a;
	p->next = NULL;
	excel *last=plist->head;
	if(last){
		while(last->next)
			last=last->next;
		last->next=p;
	}else{
		plist->head=p;
	}
}

void delete1(List *plist){
	char id[51];
	cin>>id;
	excel *p,*q;
	for(q=NULL,p=plist->head;p;q=p,p=p->next){
		if(strcmp(p->id,id)==0){
			if(q){
				q->next=p->next;
				free(p);
			}else{
				plist->head=p->next;
				free(p);
			}
		}
	}
}

void delete2(List *plist){
	char name[51];
	cin>>name;
	excel *p,*q;
	for(q=NULL,p=plist->head;p;q=p,p=p->next){
		if(strcmp(p->a,name)==0){
			if(q){
				q->next=p->next;
				free(p);
			}else{
				plist->head=p->next;
				free(p);
			}
		}
	}
}

void update1(List *plist){
	char id1[51],id2[51];
	cin>>id1>>id2;
	excel *p=plist->head;
	while(p){
		if(strcmp(p->id,id1)==0){
			strcpy(p->id,id2);
		}
		p=p->next;
	}
}

void update2(List *plist){
	char name1[51],name2[51];
	cin>>name1>>name2;
	excel *p=plist->head;
	while(p){
		if(strcmp(p->a,name1)==0){
			strcpy(p->a,name2);
		}
		p=p->next;
	}
}

void select1(List *plist){
	char id[51];int flag=0;
	cin>>id;
	excel *p=plist->head;
	while(p){
		if(strcmp(p->id,id)==0){
			cout<<p->id<<" "<<p->a<<endl;
			flag = 1;
		}
		p=p->next;
	}
	if(!flag)
	cout<<endl;
}

void select2(List *plist){
	int flag=0;
	char name[51];
	cin>>name;
	excel *p=plist->head;
	while(p){
		if(strcmp(p->a,name)==0){
			cout<<p->id<<" "<<p->a<<endl;
			flag = 1;
		}
		p=p->next;
	}
	if(!flag)
	cout<<endl;
}

void select3(List *plist){
	excel *p=plist->head;
	while(p){
			cout<<p->id<<" "<<p->a;
			p=p->next;
			if(p)
				cout<<endl;
	}
}

