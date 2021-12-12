# Hash
* Hash Table: key를 value에 mapping하는 자료구조.
* 일반적인 배열과는 달리 O(1)의 시간복잡도를 가진다.
* 기본적으로 insert, lookup(search), delete 연산을 사용한다.
### Hash Function
해시 함수는 주어진 키에 대한 해시 테이블의 인덱스를 생성하는 함수이다.

### Collision Resolution Method
많은 수의 키를 매핑할 때 인덱스 중복 즉, 충돌을 막기 위해서는 대체 위치를 찾아야 한다. 
대표적으로 **open addressing** 기법과 **chaining** 기법이 있다.

#### 1. Open Addressing 
open addressing에도 여러가지 방법이 있다. 가장 대표적인 선형 탐사(Linear Probing) 방식을 이용하여 해시테이블을 구현하면
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFUL)

/* 구조체 선언 */
typedef struct {
    char name[MAX_NAME];
    int age;
} person;
/* 자료형이 구조체인 해시테이블 생성, NULL로 초기화 */
person *hash_table[TABLE_SIZE];

void init_hash_table() {
    for (int i=0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

/* 해시 함수 */
unsigned int hash(char *name) {
    int length = strlen(name);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

/* 기본 기능 1)insert */
bool hash_table_insert(person *p) {
    if (p == NULL) return false;
    int index = hash(p -> name);
    // 해당 인덱스부터 한칸씩 이동하면서 비어있는지 확인
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        // 비어있으면 삽입
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE) {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

/* 기본 기능 2)lookup */
person *hash_table_lookup(char *name) {
    int index = hash(name);
    // 해당 인덱스부터 한칸씩 이동하면서 insert하려는 name이 이미 있는지 확인
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        // 아직 없는 경우 
        if (hash_table[try] == NULL) {
            return false;
        }
        // 원래 있던 데이터가 삭제된 자리인 경우 
        /* 이 부분이 없다면, 뒤에 있을 수 있는 중복 데이터를 발견하지 못한채 
        앞의 '아직 없는 경우'로 인식, false를 return하고 끝나버리는 불상사 발생 */
        if (hash_table[try] == DELETED_NODE) continue;
        // 이미 있는 경우
        if (strncmp(hash_table[try] -> name, name, TABLE_SIZE) == 0) {
            return hash_table[try];
        }
    }
    return NULL;
}

/* 기본 기능 3)delete */
person *hash_table_delete(char *name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try] -> name, name, TABLE_SIZE) == 0) {
            person *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}
void print_table() {
    printf("Start\n");
    for(int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t---<deleted>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i] -> name);
        }
    }
    printf("End\n");
}

int main(){

    init_hash_table();
    print_table();

    person jacob = {.name="Jacob", .age=256};
    person kate = {.name="Kate", .age=27};
    person mpho = {.name="Mpho", .age=14};
    person sarah = {.name="Sarah", .age=54};
    person edna = {.name="Edna", .age=15};
    person maren = {.name="Maren", .age=25};
    person eliza = {.name="Eliza", .age=34};
    person robert = {.name="Robert", .age=1};
    person jane = {.name="Jane", .age=75};
    

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&maren);
    hash_table_insert(&eliza);
    hash_table_insert(&robert);
    hash_table_insert(&jane);
    print_table();

    person *tmp = hash_table_lookup("Mpho");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp -> name);
    }

    hash_table_delete("Mpho");
    tmp = hash_table_lookup("George");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp -> name);
    }

    print_table();
    /* 
        0       Maren
        1       Kate
        2       Jacob
        3       Robert
        4       Sarah
        5       ---<deleted>
        6       Jane
        7       Eliza
        8       ---
        9       Edna
    */
    return 0;
}
```
DELETED_NODE가 키포인트

### 2. Chaining
chaining 방식을 이용하여 해시 테이블을 구현하면
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

/* 구조체 선언 */
typedef struct person {
    char name[MAX_NAME];
    int age;
    struct person *next; // 구조체 포인터 변수 추가
} person;
/* 자료형이 구조체인 해시테이블 생성, NULL로 초기화 */
person *hash_table[TABLE_SIZE];

void init_hash_table() {
    for (int i=0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

/* 해시 함수 */
unsigned int hash(char *name) {
    int length = strlen(name);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

/* 기본 기능 1)insert */
bool hash_table_insert(person *p) {
    if (p == NULL) return false;
    int index = hash(p -> name);
    p -> next = hash_table[index]; // 앞에 삽입
    hash_table[index] = p;
    return true;
}

/* 기본 기능 2)lookup */
person *hash_table_lookup(char *name) {
    int index = hash(name);
    person *tmp = hash_table[index];
    // 해당 인덱스의 리스트를 이동
    while (tmp != NULL && strncmp(tmp -> name, name, TABLE_SIZE) != 0) {
        tmp = tmp -> next;
    }
    // 없으면 tmp == NULL
    return tmp;
}

/* 기본 기능 3)delete */
person *hash_table_delete(char *name) {
    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;
    // 해당 인덱스가 비어있지 않은 경우, 해당 인덱스의 리스트를 이동
    while (tmp != NULL && strncmp(tmp -> name, name, TABLE_SIZE) != 0) {
        prev = tmp;
        tmp = tmp -> next;
    } 
    // 해당 인덱스가 비어있거나 리스트에 delete하려는 name이 없는 경우
    if (tmp == NULL) return NULL;
    // delete하려는 name이 리스트 맨 앞에 있는 경우(loop에 진입조차 하지 않은)
    if (prev == NULL) {
        // 삭제
        hash_table[index] = tmp -> next;
    } else { // 중간 등 어딘가에 있는 경우(loop가 멈춘 그 위치)
        // 삭제
        prev -> next = tmp -> next;
    }
    return tmp;
}
void print_table() {
    printf("Start\n");
    for(int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t", i);
            person *tmp = hash_table[i];
            while (tmp != NULL) {
                printf("%s - ", tmp -> name);
                tmp = tmp -> next;
            }
            printf("\n");
        }
    }
    printf("End\n");
}

int main(){

    init_hash_table();
    print_table();

    person jacob = {.name="Jacob", .age=256};
    person kate = {.name="Kate", .age=27};
    person mpho = {.name="Mpho", .age=14};
    person sarah = {.name="Sarah", .age=54};
    person edna = {.name="Edna", .age=15};
    person maren = {.name="Maren", .age=25};
    person eliza = {.name="Eliza", .age=34};
    person robert = {.name="Robert", .age=1};
    person jane = {.name="Jane", .age=75};
    

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&maren);
    hash_table_insert(&eliza);
    hash_table_insert(&robert);
    hash_table_insert(&jane);
    print_table();

    person *tmp = hash_table_lookup("Jacob");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp -> name);
    }

    hash_table_delete("Mpho");
    tmp = hash_table_lookup("George");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp -> name);
    }

    print_table();
    /* 
        0       Maren - 
        1       Jane - Kate - 
        2       Robert - Jacob - 
        3       ---
        4       Sarah - 
        5       ---
        6       ---
        7       Eliza - 
        8       ---
        9       Edna - 
    */
    return 0;
}

```

**chaining 기법이 구현하기 훨씬 간단했으나, open addressing 기법보다 메모리 효율이 낮다는 단점이 있다.**