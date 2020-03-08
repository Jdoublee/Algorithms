/*
 원소가 n개인 집합의 모든 순열 생성 후 출력
 search 함수 호출시마다 새로운 원소 순열에 추가하고 chosen에 기록.
 permutation 크기가 n과 같아지면 순열 출력
 */
#include <iostream>
#include <vector>
using namespace std;
int n=3;
vector<int> permutation;
bool chosen[3];// 각 원소를 순열에 포함했는지 여부
void search(){
    if(permutation.size()==n){
        for(int i=0;i<3;i++)
            cout<<permutation[i]<<" ";
        cout<<endl;
    }else{
        for(int i=0;i<n;i++){
            if(chosen[i])
                continue;
            //i+1 추가
            chosen[i]=true;
            permutation.push_back(i+1);
            search();
            //i+1 지금 추가 안 함
            chosen[i]=false;
            permutation.pop_back();
        }
    }
    
    
}
int main(){
    search();
    
    
}
