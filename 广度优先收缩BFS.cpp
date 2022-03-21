#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>
#include<deque>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<algorithm>
#define endl '\n';
#define sup 1<<30;
using namespace std;

map<int,int> mp;

class number{
public:
	int value;
	int cnt;
}now;

void change(int &res){
	int temp = res,dig = res%10;
	while(temp){
		temp /= 10;
		dig *= 10;
	}
	res = res/10+dig/10;
}

int bfs(int a,int n){
	queue<number> que;
	now.value = 1,now.cnt = 0;
	que.push(now);
	while(!que.empty()){
		now = que.front();
		number temp = now;
		que.pop();
		for(int i=0;i<2;i++){
			now = temp;
			if(i == 0){
				if(mp[now.value] == 0&&to_string(now.value).length() <= to_string(n).length()){
					now.value *= a;
					now.cnt++;
					que.push(now);
					if(now.value == n) return now.cnt;	
				}
			}else{
				if(now.value>=10&&now.value%10!=0&&mp[now.value] == 0&&to_string(now.value).length()<=to_string(n).length()){
					change(now.value);
					now.cnt++;
					que.push(now); 
					if(now.value == n) return now.cnt;
				} 
			}
		}
		mp[temp.value] = 1;
	}
	return -1;
}

int main(){
	int a,n;
	cin>>a>>n;
	cout<<bfs(a,n);
	return 0;
}


