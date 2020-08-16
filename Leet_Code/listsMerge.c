#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

typedef struct ListNode List;
struct ListNode{
    int val;
    struct ListNode *next;
};

List* createList(int A[], int N)
{
    List* head = (List*)malloc(sizeof(List));
    head->val = A[0]; head->next = NULL;
    List* tmp = head;
    for(int i = 1; i < N; i++)
    {
        List* node = (List*)malloc(sizeof(List));
        node->val = A[i];
        node->next = NULL;
        tmp->next = node;
        tmp = node;
    }
    return head;
}

void insertHeap(List** heap, List* list, int* size)
{   
    int i;
    List* tmp = list;
    while(tmp != NULL){
        for(i = ++(*size);  tmp->val < heap[i/2]->val; i/=2)
            heap[i] = heap[i/2];
        heap[i] = tmp;
        tmp = tmp->next;
    }
}

List* deleteHeap(List** heap, int* size)
{
    if(*size < 1)
        return NULL;
    List* min = heap[1];
    List* last = heap[(*size)--];
    
    int i, child;
    for(i = 1; i*2 <= *size; i = child){
        child = i*2;
        if(child+1 <= *size && heap[child+1]->val < heap[child]->val)
            child++;
        if(last->val > heap[child]->val)
            heap[i] = heap[child];
        else
            break;
    }
    heap[i] = last;
    return min;
}

void percDown(List** heap, int size, int i)
{
    int parent, child;
    List* root = heap[i];
    for(parent = i; parent*2 <= size; parent = child){
        child = parent * 2;
        if(child+1 <= size && heap[child+1]->val < heap[child]->val)
            child++;
        if(root->val > heap[child]->val)
            heap[parent] = heap[child];
        else
            break;
    }
    heap[parent] = root;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{  
    if(listsSize < 1 || lists == NULL) 
        return NULL;
    else if(listsSize == 1)
        return *lists;
    else
        for(int i = 0; i < listsSize;){
            if(!lists[i])
                lists[i] = lists[--listsSize];
            else
                i++;
        }

    List** heap = (List**)malloc(MAX_SIZE * sizeof(List*));
    heap[0] = (List*)malloc(sizeof(List));
    heap[0]->val = -1000; // as sentinel
    int size = 0;
    List* tmp;
    for(int i = 0; i < listsSize; i++){
        tmp = lists[i];
        while(tmp != NULL){
            heap[++size] = tmp;
            tmp = tmp->next;
        }
    }

    // for(int i = 1; i < listsSize; i++)
    //     insertHeap(heap, lists[i], &size);
    
    /* initialize heap */
    for(int i = size/2; i > 0; i--)
        percDown(heap, size, i);

    List* head = (List*)malloc(sizeof(List));
    head->next = NULL; //set NULL temporarily
    tmp = head;
    for(int i = size; i > 0; i--){
        tmp->next = deleteHeap(heap, &size);
        tmp = tmp->next;
        tmp->next = NULL;
    }

    return head->next;
}

int main()
{
    int N = 3;
    List** L = (List**)malloc(N*sizeof(List*));
    int A1[] = {1,4,5};
    int A2[] = {1,3,4};
    int A3[] = {2,6};
    List* l1 = createList(A1, sizeof(A1)/sizeof(*A1));
    List* l2 = createList(A2, sizeof(A2)/sizeof(*A2));
    List* l3 = createList(A3, sizeof(A3)/sizeof(*A3));
    *L = l1; *(L+1) = l2, *(L+2) = l3;
    
    List* ret = mergeKLists(L, N);
    List* tmp = ret;
    while(tmp){
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");

    return 0;
}