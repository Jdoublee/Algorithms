//삽입정렬 정의 :https://terms.naver.com/entry.nhn?docId=2270436&cid=51173&categoryId=51173

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000000
int arr[N];
void insertionSort(int arr[],int n){
    int key,i,j;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int i=0;

    FILE *fp=fopen("example.txt","r");
    if(fp==NULL){
        printf("can't read file\n");
        return 1;
    }
    while(fscanf(fp,"%d",&arr[i])!=EOF){
        i++;
    }
    clock_t start=clock();//정렬시간측정
    insertionSort(arr,N);
    clock_t end=clock();
    
    for(int k=0;k<N;k++)
        printf("%d ",arr[k]);
    printf("\n");
    
    printf("\n");
    fclose(fp);
    
    printf("동작시간 : %lf s\n",(double)(end-start)/CLOCKS_PER_SEC);//
    return 0;
}
