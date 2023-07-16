#include<stdio.h>
#include<stdlib.h>

typedef struct FirstFit
{
    /* data */
    int data;
    struct FirstFit* next;
}ListNode;

ListNode* initialize(int data){
    ListNode* newnode = (ListNode* )malloc(sizeof(ListNode));
    newnode->data = data;
    newnode->next = NULL;
}

ListNode *append(ListNode *head,int data){
    ListNode* newnode = initialize(data);

    if(head==NULL){
        return newnode;
    }
    ListNode* temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = newnode;
    return head;
}

void sort(int *arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]<arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main()
{
    int n,data,choice;
    ListNode* head = NULL;
    printf("Enter number of blocks:- ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter size of each block:- ");
        scanf("%d",&arr[i]);
    }

    while(1){
        printf("Enter size of process 1:- ");
        scanf("%d",&data);
        head = append(head,data);
        printf("Do you want to add [1/0]:- ");
        scanf("%d",&choice);
        if(choice == 0){
            break;
        }
    }

    sort(&arr,n);
    display(arr,n);

    int marked[n+1];
    for(int i=0;i<=n;i++){
        marked[i] = 0;
    }

    int ans = 0;
    ListNode* temp = head;
    while(temp){
        for(int i=0;i<n;i++){
            if(arr[i]>temp->data){
                arr[i]-=temp->data;
                marked[i] = 1;
                break;
            }
        }
        temp = temp->next;
    }
    int internal_frag=0;
    int external_frag=0;

    for(int i=0;i<n;i++){
        if(marked[i]==1){
            internal_frag+=arr[i];
        }
        else{
            external_frag+=arr[i];
        }
    }

    printf("Internal_frag :- %d\n",internal_frag);
    printf("External_frag :-%d",external_frag);

}