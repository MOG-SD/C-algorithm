#include<iostream>
using namespace std;
void micifang(int n);
int main(){
	int n;
	cin>>n;
	micifang(n);
	return 0;
}

void micifang(int n){
	int i=0,u=0,h[100]={0},k=n;
	while(k){
		if(k&1) h[++u]=i;
		k>>=1;
		i++;
	}
	while(u){
		if(h[u]<3){
			if(h[u]==2){
				if(u>1) cout<<"2(2)+";
				else cout<<"2(2)";	
			}
			else if(h[u]==1){
				if(u>1) cout<<"2+";
				else cout<<"2";
			}
			else{
				cout<<"2(0)";
			}
			u--;
		}else{
			cout<<"2(";
			micifang(h[u]);
			if(u>1) cout<<")+";
			else cout<<")"; 
			u--;
		}
	}
}
