/*
 원소가 n개인 집합의 모든 부분집합 생성 후 출력
 재귀 호출 트리 - search 함수의 인자가 k일때 원소 k를 부분집합에 포함할지 안할지 나누어 결정, 인자 k+1 주고 재귀 호출 진행
 k==n+1이 되면 해당 부분집합 원소 출력
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> subset;
int n=3;
void search(int k){
    if(k==n+1){
        if(subset.size()==0)//공집합
            cout<<"empty";
        else
            for(int i=0;i<subset.size();i++)
                cout<<subset[i]<<" ";
        cout<<endl;
    }else{
        //k포함
        subset.push_back(k);
        search(k+1);
        //k비포함
        subset.pop_back();
        search(k+1);
    }
}
int main() {
    search(1);
    return 0;
}
