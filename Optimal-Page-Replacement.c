#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,size,page,tab = 0,hit = 0,miss = 0;
    
    printf("Enter Total number of pages:- ");
    scanf("%d",&n);
    printf("Enter size of frame:- ");
    scanf("%d",&size);
    int count[n+1];
    for(int i=0;i<=n;i++){
        count[i] = 0;
    }
    int arr[n];
    int table[size];
    for(int i=0;i<n;i++){
        printf("Enter page number:- ");
        scanf("%d",&page);
        arr[i] = page;
    }

    for(int i=0;i<size;i++){
        table[i] = -1;
    }

    
    for(int i=0;i<n;i++){
        if(tab < size){
            miss+=1;
            table[tab] = arr[i];
            tab = tab+1;
            count[arr[i]] = 1;
        }
        else{
            
            if(count[arr[i]] == 0){
                int visited[n+1];
                for(int i=0;i<=n;i++){
                    visited[i] = 0;
                }
                miss+=1;
                int c=0,found,flag=0;
                for(int j=i;j<n;j++){
                    if (count[arr[j]] == 1 && !visited[arr[j]])
                    {
                        /* code */
                        if(c==size-1){
                            found = arr[j];
                            flag = 1;
                            break;
                        }
                        c++;
                        visited[arr[j]] = 1;
                    }
                    
                }
                if(flag==0){
                    if(c==size-1){
                        for(int k=0;k<n;k++){
                            if(count[arr[k]] == 1 && visited[arr[k]] == 0){
                                found = arr[k];
                                break;
                            }
                        }
                    }
                        else if(c==size){
                            continue;
                        }
                    else{
                        found = table[size-1];    
                    }
                    
                }
                for(int j=0;j<size;j++){
                    if(table[j] == found){
                        count[arr[i]] = 1;
                        count[found] = 0;
                        table[j] = arr[i];
                        break;
                    }
                }
            }
            else{
                hit+=1;
            }
        }
    }
    // miss = n-hit;
    printf("Total hit :- %d\n",hit);
    printf("Total Miss :- %d\n",miss);

}
