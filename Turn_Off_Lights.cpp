#include <iostream>
#include <string>
using namespace std;
int main(){
	long n, k, l;
	cin>>n>>k;
	string bulbs;
	cin>>bulbs;
	long count;
	for(l=1; l<=n; l++){
		count=0;
		for(int i=0; i<n; i++){
			if(bulbs[i]=='1'){ count++;
			i= i+l-1;
			}
		}
		if(count<=k){
			cout<<l;
			break;
		}
	}
	return 0;
}