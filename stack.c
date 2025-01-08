typedef struct {
    int *arr;
    long long size;
    long long top;
} MinStack;


MinStack* minStackCreate() {
    MinStack *stack = (MinStack*)malloc(sizeof(MinStack));
    stack->size = 100;
    stack->arr = (int*)malloc(sizeof(int)*stack->size);
    stack->top = 0;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    if(obj->top>=obj->size){
        obj->size*=2;
        obj->arr = (int*)realloc(obj->arr,sizeof(int)*obj->size); 
    }
    else{
        obj->arr[obj->top]=val;
        obj->top++;
    }
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->arr[obj->top-1];
}

int minStackGetMin(MinStack* obj) {
    int min = obj->arr[0];
    for(long long i=0;i<obj->top;i++){
        if(obj->arr[i]<min){
            min = obj->arr[i];
        }
    }
    return min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}
