#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
	bool isword;
	TrieNode *children[5];
};

TrieNode root;

//��trie�������һ���ؼ���s
void insert(string s){
	TrieNode *p = &root;
	for(int i=0;s[i];i++){
		if(p->children[s[i]-'a'] == NULL){
			p->children[s[i]-'a'] = new TrieNode();
		}
		p = p->children[s[i]-'a'];
	}
	p->isword = true;
}

//��ѯtrie���Ƿ��йؼ���s 
bool search(string s){
	TrieNode *p = &root;
	for(int i=0;s[i];i++){
		if(p->children[s[i]-'a'] == NULL){
			return false;
		}
		p = p->children[s[i]-'a'];
	}
	return p->isword;
}

//��ѯtrie�����Ƿ���ǰ׺prefix 
bool startWith(string prefix){
	TrieNode *p = &root;
	for(int i=0;prefix[i];i++){
		if(p->children[prefix[i]-'a'] == NULL){
			return false;
		}
		p = p->children[prefix[i]-'a'];
	}
	return true;
}

int main(){
	string s;
	int n,m;
	cin>>n>>m;
	while(n--){
		cin>>s;
		insert(s);
	}
	while(m--){
		cin>>s;
		if(search(s)) 	cout<<"yes"<<endl;
		else			cout<<"no"<<endl;
	}
	return 0;
}
