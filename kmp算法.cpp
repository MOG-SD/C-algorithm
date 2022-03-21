#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

void getnext(string s,int *next){
	int i=0,j=-1;
	next[0]=-1,next[1]=0;
	while(i<s.length()){
		if(j == -1||s[i] == s[j]){
			i++;
			j++;
			next[i]=j;
		}else{
			j=next[j];
		}
	}
}

//返回字符串s2在s1中pos后的位置
//若不存在，返回-1
int find_kmp(string s1,string s2,int pos){
	int i=pos;
	int j=0;
	int next[10001];
	getnext(s2,next);
	while(i<(int)s1.length()&&j<(int)s2.length()){
		if(s1[i] == s2[j]||j == -1){
			i++;
			j++;
		}else{
			j=next[j];
		}	
	}
	if(j>=s2.length()){
		return i-s2.length();
	}else{
		return -1;
	}
}


int main(){
	string s1,s2;
	int n,cnt,i;
	cin>>n;
	while(n--){
		cnt = 0;
		cin>>s1>>s1;
		
	return 0;
}
