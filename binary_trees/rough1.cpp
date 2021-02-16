#include<bits/stdc++.h>
using namespace std;
int main()
{
int T,i;
cin>>T;
for(i=0;i<T;i++)
{ long long m,n,s,t;
	cin>>n>>m>>s;
	t=(m+s-1)%n;
	if(t==0)
	cout<<n;
	else
	cout<<t;
	cout<<endl;
}
}