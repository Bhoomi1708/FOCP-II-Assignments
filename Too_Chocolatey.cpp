#include<iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int count_alex=0;
        int count_Bob=0;
        long N;
        cin>>N;
        int* A= new int[N];
        for(int i=0; i<N; i++)
        cin>>A[i];
        
        for(int i=0; i<N-1; i++){
            for(int j=i+1; j<N; j++){
                if(A[j]>A[i]){
                    int temp= A[i];
                    A[i]= A[j];
                    A[j]= temp;
                }
            }
        }
 
        int chance = 0; 
        int alex = -1;
        int bob = -1;
        for(int i=0; i<N; i++)
        {
            if(chance==0){ 
                if(A[i]!=alex)
                {
                    count_alex +=A[i];
                    alex= A[i];
                    chance= 1;
                }
            }
            else
            { 
                if(A[i]!=bob)
                {
                    count_Bob +=A[i];
                    bob= A[i];
                    chance= 0;
                }
            }
        }
        if(count_alex>count_Bob) cout<<"Alex\n";
        else cout<<"Bob\n";
        
        delete[] A;
    }
    
    return 0;
}
