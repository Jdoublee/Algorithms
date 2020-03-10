#include <iostream>

using namespace std;
int sorted[8];//정렬된 원소 저장할 임시 배열
void merge(int arr[],int l,int m,int r){
    int i=l,j=m+1;
    int k=l;//정렬된 배열 인덱스
    //합병
    while(i<=m&&j<=r){
        if(arr[i]<=arr[j])
            sorted[k++]=arr[i++];
        else
            sorted[k++]=arr[j++];
    }
    //합병후 남은 값들 뒤에 다 붙여줌
    if(i>m)
        for(int n=j;n<=r;n++)
            sorted[k++]=arr[n];
    else
        for(int n=i;n<=m;n++)
            sorted[k++]=arr[n];
    //원래 arr에 정렬된 배열 다시 복사
    for(int n=l;n<=r;n++)
        arr[n]=sorted[n];
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        //배열 중간 기준으로 균등 분할 후 정렬
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        //다시 합병
        merge(arr,l,m,r);
    }
}
void printArr(int n,int arr[]){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int arr[]={1,3,8,2,9,2,5,6};
    int arr_size=sizeof(arr)/sizeof(int);
    
    printArr(arr_size, arr);
    mergeSort(arr,0,arr_size-1);
    printArr(arr_size, arr);
    
    return 0;
}
//시간복잡도 : o(nlogn)
