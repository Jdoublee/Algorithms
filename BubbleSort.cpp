#include <iostream>
#include <algorithm> //swap
using namespace std;
void BubbleSort(int n,int arr[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}
void printArr(int n,int arr[]){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int arr[]={1,3,8,2,9,2,5,6};
    printArr(sizeof(arr)/sizeof(int), arr);
    BubbleSort(sizeof(arr)/sizeof(int), arr);
    printArr(sizeof(arr)/sizeof(int), arr);
    
    return 0;
}
//시간복잡도 : o(n^2)
