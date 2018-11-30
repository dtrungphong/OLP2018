#include <bits/stdc++.h>
typedef unsigned long long int ulli;
using namespace std;
ulli M;
bool visited[50];
bool visited1[50];
bool visited2[50];
string convert(int a){
	if (a==0) return "0";
	if (a==1) return "1";
	return "2";
}

void PlusBase3(string a){
	bool c=0;
	int k=0;
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]=='0'&&!c){ visited2[k++]=0; c=0;}
		if(a[i]=='0'&&c){ visited2[k++]=1; c=0;}
		if(a[i]=='1'&&!c){  visited2[k++]=1; c=0;}
		if(a[i]=='1'&&c){ visited1[k++]=1; c=1;}
		if(a[i]=='2'&&!c){ visited1[k++]=1; c=1;}
		if(a[i]=='2'&&c){ c=1;}
	}
}

string base3(ulli a){
	string total="";
	while(a>0){
		total=convert(a%3)+total;
		a=a/3;
	}
	return total;
}

int main(){
	cin>>M;
	string temp=base3(M);
	bool f=0;
	for(int i=0;i<temp.size();i++){
		if(temp[i]=='2') f=1;
		if(temp[i]=='1') visited[i]=1;
	}
	if(!f){
		cout<<"-1"<<endl;
		for(int i=0;i<temp.size();i++){
			if(visited[i]){cout<<i<<" ";}
		}
		cout<<endl;
	}
	else{
		PlusBase3(temp);
		for(int i=0;i<temp.size();i++){
			if(visited1[i]) cout<<i<<" ";
		}
		cout<<endl;
		for(int i=0;i<temp.size();i++){
			if(visited2[i]) cout<<i<<" ";
		}
		cout<<temp.size()<<endl;
	}
	return 0;
}

