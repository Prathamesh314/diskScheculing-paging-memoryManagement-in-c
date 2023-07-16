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

void display(ListNode *head){
    ListNode *temp = head;
    while(temp->next){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}



int main()
{
    int n,p=0,data,choice;
    ListNode* head = NULL;
    ListNode* notMarked = NULL;
    printf("Enter number of blocks:- ");
    scanf("%d",&n);
    int arr[n];
    printf("Time to take size of each block....\n");
    for(int i=0;i<n;i++){
        printf("Enter memory size of block %d:- ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("Time to take size of each process coming in....\n");
    while(1){
        printf("Enter size of process %d:- ",p+1);
        scanf("%d",&data);
        p++;
        head = append(head,data);
        printf("Do you want to add more process [1/0]:- ");
        scanf("%d",&choice);
        if(choice == 0){
            break;
        }
    }

    ListNode *temp = head;
    int marked[n];
    int If[n];
    for(int i=0;i<n;i++){
        marked[i] = 0;
    }
    int travel = 0,process=1;
    while(temp){
        int flag = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > temp->data && marked[i] == 0){
                arr[i] -= temp->data;
                marked[i] = 1;
                flag = 1;
                break;
            }
        }
        if(flag==0){
            notMarked = append(notMarked,process);
        }
        temp = temp->next;
        process++;
    }

    int internalFrag = 0;
    int externalFrag = 0;
    for(int i=0;i<n;i++){
        if(marked[i]){
            internalFrag+=arr[i];
        }
        else{
            externalFrag+=arr[i];
        }
    }

    printf("\nTotal Internal Fragmentation :- %d\n",internalFrag);
    printf("\nTotal External Fragmentation :- %d\n",externalFrag);
    
    printf("\nTotal Processes....\n");
    display(head);
    printf("\nProcesses that are not allocated...\n");
    display(notMarked);
    
    return 0;

}
