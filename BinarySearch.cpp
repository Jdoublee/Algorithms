#include <iostream>

using namespace std;
int binarySearch(int arr[],int n,int k){
    int a=0,b=n-1;
    while(a<=b){
        int i=(a+b)/2;
        if(arr[i]==k)
            return i;//검색 종료. 해당 인덱스 i return.
        if(arr[i]<k)
            a=i+1;
        else
            b=i-1;
    }
    return -1;//배열에 존재하지 않을 경우
    
}

int main(){
    int arr[]={1,15,3,5,4,12,3,12,5,10,9,6};
    int n=sizeof(arr)/sizeof(int);
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<binarySearch(arr, n, 15)<<endl;
    
    
    return 0;
}
//시간복잡도 : O(logn)
