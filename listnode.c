typedef struct ListNode ListNode;
// struct ListNode{

//     int val;
//     ListNode * next;
// }

typedef struct vec vec;
struct vec{
    int size;
    int index;
    ListNode ** data; //list array
};

typedef struct {
    vec * v;
} MyHashSet;

int get_hash(int key, int mv_size){
    return (key+1)%mv_size;
}


void add_node(ListNode * head, int val){

    ListNode * cur = head, *prev = NULL;
    while(cur != NULL){
        prev = cur;
        cur = cur->next;
    }

    ListNode * temp = calloc(1, sizeof(ListNode));
    temp->val = val;
    temp->next = NULL;

    prev->next = temp;
}

void remove_node(ListNode * head, ListNode * node){

    if(head == NULL || node == NULL) return;
    ListNode * cur = head, *prev = head;
    while(cur != node){
        prev = cur;
        cur = cur->next;
    }

    prev->next = cur->next;
    free(node);
    node = NULL;
}

bool check_list_is_null(ListNode * head){

    if(head == NULL) return true; //assert
    if(head->next == NULL) return true;
    else return false;
}

MyHashSet* myHashSetCreate(void) {

    vec * mv = calloc(1, sizeof(vec));
    mv->size = 100000;
    mv->index= 0;
    mv->data = calloc(mv->size, sizeof(ListNode*));
    
    for(int i = 0; i < mv->size; i++){
        mv->data[i] = calloc(1, sizeof(ListNode));
        mv->data[i]->val = -1;
    }
    
    MyHashSet * mh = calloc(1, sizeof(MyHashSet));
    mh->v = mv;

    return mh;
}
ListNode * find_node(ListNode * head, int key){
    ListNode * cur = head, *n = NULL;
    while(cur != NULL){
        if(cur->val == key) {n = cur; break;}
        cur = cur->next;
    }
    return n;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int hash = get_hash(key, obj->v->size);
    ListNode * head = obj->v->data[hash];
    bool res = check_list_is_null(head);
    ListNode * n = find_node(head, key);
    if(n == NULL) return false;
    else return true;

}

void myHashSetAdd(MyHashSet* obj, int key) {
    
    int hash = get_hash(key, obj->v->size);
    printf("%d, ", hash);
    
    if(myHashSetContains(obj, key)) return;
    ListNode *head;
    head= obj->v->data[hash];
    add_node(head, key);
    
}
void myHashSetRemove(MyHashSet* obj, int key) {
    int hash = get_hash(key, obj->v->size);
    ListNode * head = obj->v->data[hash];   
    if(myHashSetContains(obj, key)){
        ListNode * n = find_node(head, key);
        remove_node(head, n);
    }
    else return;
        
}
void myHashSetFree(MyHashSet* obj) {
    free(obj);
}
