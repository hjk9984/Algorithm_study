#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 20
#define TABLE_SIZE 100000

typedef struct person {
    char name[MAX_NAME];
    struct person *next;
} person;

person *hash_table[TABLE_SIZE]; //person's truck

void init_hash_table() {
    for (int i=0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
} // 비어있는 테이블 완성

unsigned int hash(char *name) {
    int length = strlen(name);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void enrollment(char *name) {
    person *newperson = malloc(sizeof(person));
    int index = hash(name);
    newperson -> next = hash_table[index]; // chaining
    hash_table[index] = newperson; 
    strcpy(newperson -> name, name);
}

bool deleteWhenComplete(char *name) {
    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;
    while (tmp != NULL && strncmp(tmp -> name, name, 20) != 0) {
        prev = tmp;
        tmp = tmp -> next;
    }
    // 삭제
    if (prev == NULL) {
        hash_table[index] = tmp -> next;
    } else {
        prev -> next = tmp -> next;
    }
    free(tmp);
    return true;
}

void whoLeft() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            person *tmp = hash_table[i];
            printf("%s\n", tmp -> name);
            return ;
        }
    }
    printf("no one");
}

void print_table() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            printf("\t%d\t", i);
            person *tmp = hash_table[i];
            while (tmp != NULL) {
                printf(" %s -", tmp -> name);
                tmp = tmp -> next;
            }
            printf("\n");
        }
    }
}

int main() {
    init_hash_table();

    char participants[][MAX_NAME] = {"mislav", "stanko", "mislav", "ana"};
    char completion[][MAX_NAME] = {"stanko", "ana", "mislav"};

    int name_cnt = sizeof(participants)/ sizeof(participants[0]);
    for (int i = 0; i < name_cnt; i++) {
        enrollment(participants[i]);
    }
    print_table();
    printf("\n");
    name_cnt = sizeof(completion) / sizeof(completion[0]);
    for (int i = 0; i < name_cnt; i++) {
        deleteWhenComplete(completion[i]);
    }
    print_table();
    printf("\n");

    whoLeft();
    
    /* 결과
    41130    stanko -
    51730    mislav - mislav -
    77139    ana -

    51730    mislav -

    mislav
    */
}

