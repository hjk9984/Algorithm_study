# Stack
* push(insert)와 pop(delete) 연산을 사용한다.
* Top 즉, 한쪽 끝에서만 접근할 수 있다.
* 그 외에도 top의 데이터 값을 반환하는 top(), 스택에 원소가 있는지 없는지 bool값을 반환하는 isempty(), isfull() 연산이 있다.

**array로 구현했을 때**
```c
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_LEGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN // 뭐든지 정해놓은 규칙대로 선언하면 된다.

typedef struct {
    int values[STACK_LEGTH];
    int top = EMPTY;
} stack;

bool push(stack *mystack, int value) {
    // STACK_LEGTH - 1 = last element
    if (mystack -> top >= STACK_LEGTH - 1) return false; // stack is full

    mystack -> top++;
    mystack -> values[mystack -> top] = value;
    return true;
}

int pop(stack *mystack) {
    if (mystack -> top == EMPTY) return STACK_EMPTY;

    int result = mystack -> values[mystack -> top];
    mystack -> top--;
    return result;
}

int main() {
    stack s1;
    s1.top = EMPTY;
    stack s2;
    s2.top = EMPTY;
    stack s3;
    s3.top = EMPTY;

    push(&s1, 56);
    push(&s2, 78);
    push(&s3, 13);

    int t;
    while ((t = pop()) != STACK_EMPTY) {
        printf("t = %d\n", t);
    }
}
```
**list로 구현했을 때**
```c
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_LEGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN // 뭐든지 정해놓은 규칙대로 선언하면 된다.

typedef struct node {
    int value;
    struct node *next;
} node;

// 구조체 포인터(스택의 주소를 가리킨다)
typedef node *stack;

// 스택의 주소(구조체 포인터)를 가져오기 위해 이중포인터가 파라미터로 들어간다
bool push(stack *mystack, int value) {
    
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL) return false;

    newnode -> value = value;
    newnode -> next = *mystack; 
    // *mystack은 'node **'(aka 'stack *')의 역참조의 역참조 즉, 스택의 주소값이다.
    *mystack = newnode;
    return true;
}

int pop(stack *mystack) {
    if (*mystack == NULL) return STACK_EMPTY;

    int result = (*mystack) -> value;
    node *tmp = *mystack;
    *mystack = (*mystack) -> next;
    free(tmp);
    return result;
}

int main() {
    stack s1 = NULL, s2 = NULL, s3 = NULL;
    push(&s1, 56);
    push(&s2, 78);
    push(&s2, 13);
    push(&s2, 98);

    int a;
    while ((a = pop(&s2)) != STACK_EMPTY) {
        printf("a = %d\n", a);
    }
    /*
    t = 98
    t = 13
    t = 78
    */
}
```

# Queue
* enqueue(insert)와 dequeue(delete) 연산을 사용한다. 
* insert가 한쪽에서 일어나면, delete는 그 반대쪽에서 일어난다.
* 그 외에도 top의 데이터 값을 반환하는 top(), 스택에 원소가 있는지 없는지 bool값을 반환하는 isempty(), isfull() 연산이 있다.

마찬가지로 array와 list로 큐를 구현할 수 있다.
**list로 구현했을 때**
```c
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
} queue;

void init_queue(queue *q) {
    q -> head = NULL;
    q -> tail = NULL;
}

bool enqueue(queue *q, int value) {
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL) return false;
    newnode -> value = value;
    // newnode의 value는 end of the list여야 함
    newnode -> next = NULL;
    
    // 비어있지 않은 queue였을 경우 원래 tail 끝에 붙여주기
    if (q -> tail != NULL) {
        q -> tail -> next = newnode;
    }
    // newnode를 tail로 만들기
    q -> tail = newnode;

    // 비어있었을 경우 newnodefmf head로 만들기
    if (q -> head == NULL) {
        q -> head = newnode;
    }
    return true;
}

int dequeue(queue *q) {
    // 비어있는지 확인
    if (q -> head == NULL) return QUEUE_EMPTY;
    node *tmp = q -> head;
    int result = tmp -> value;
    q -> head = q -> head -> next;
    // 처리 후 빈 queue가 되었을 때 
    if (q -> head == NULL) {
        q -> tail = NULL;
    }
    free(tmp);
    return result;
}

int main() {
    queue q1, q2, q3;

    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);

    enqueue(&q1, 56);
    enqueue(&q2, 78);
    enqueue(&q2, 13);
    enqueue(&q2, 98);
    int a;
    while ((a = dequeue(&q2)) != QUEUE_EMPTY) {
        printf("a = %d\n", a);
    }
    /*
    a = 78
    a = 13
    a = 98
    */
}
```
**98을 가장 마지막에 insert했을 때 스택의 경우 top에 있고 큐의 경우 tail에 있다는 사실이 재밌다.**