#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,start,dir,before,begin;
    printf("Enter total number of processes :- ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the starting process :- ");
    scanf("%d",&start);
    printf("Enter the previous process :- ");
    scanf("%d",&before);

    for(int i=0;i<n;i++){
        printf("Enter size of process %d:- ",i+1);
        scanf("%d",&arr[i]);
        if(arr[i] == start){
            begin = i;
        }
    }

    if(before > start){
        dir = 1;
    }
    else{
        dir = -1;
    }


    int ans = 0;
    if(dir == -1){
        for(int i=begin+1;i<n;i++){
            ans+=abs(arr[i]-start);
            start = arr[i];
        }
        start = arr[0];
        ans+=abs(arr[n-1]-arr[0]);
        for(int i=1;i<begin;i++){
            ans+=abs(start-arr[i]);
            start = arr[i];
        }

    }
    else{
        for(int i=begin-1;i>0;i--){
            ans+=abs(arr[i]-start);
            start = arr[i];
        }
        start = arr[0];
        ans+=abs(arr[n-1]-arr[0]);
        for(int i=n-1;i<=begin;i--){
            ans+=abs(start-arr[i]);
            start = arr[i];
        }
    }

    printf("Ans :- %d\n",ans);
}