#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CAR 1000
#define MAX_CAR_NUM 10

typedef struct car {
    char *num;
    struct car *next;
} car;

// liked list
typedef struct List {
    car *head;
    car *tail;
} List;

void init_list(List *L) {
    L -> head = NULL;
    L -> tail = NULL;
}

bool putIntoList(List *carlist, char *carnum) {
    car *newcar = malloc(sizeof(car));
    if (newcar == NULL) return false;
    newcar -> num = carnum;
    newcar -> next = NULL;

    if (carlist -> head == NULL) { // 비어있었으면
        carlist -> head = newcar;
    } 
    if (carlist -> tail != NULL) { // 비어있지 않았으면
        carlist -> tail -> next = newcar;
    }
    carlist -> tail = newcar;
    return true;
}

bool deleteCar(List *carlist, char *carnum) {
    if (carlist -> head == NULL) return false;
    car *tmp = carlist -> head;
    car *prev = NULL;
    while (tmp != NULL && strncmp(tmp -> num, carnum, MAX_CAR) != 0) {
        prev = tmp;
        tmp = tmp -> next;
    }
    // delete 하려는 차 번호가 없을 때
    // if (tmp == NULL) return false;

    // delete하려는 car node가 맨 앞에 있었을 때
    if (prev == NULL) {
        carlist -> head = tmp -> next;
    } else { // 맨 앞 외
        // 맨 뒤
        if (tmp -> next == NULL) {
            carlist -> tail = prev;
            prev -> next = NULL;
        } else { // 중간 어딘가
            prev -> next = tmp -> next;
        } 
    }
    free(tmp);
    return true;
}

bool printList(List *carlist) {
    if (carlist -> head == NULL) return false;
    car *current = carlist -> head;
    while (current != NULL) {
        if (current != carlist -> tail) {
            printf("%s - ", current -> num);
        } else {
            printf("%s\n", current -> num);
        }
        current = current -> next;
    }
    return true;
}

int compareTwoList(List *in, List *out) {
    int bad_car = 0;
    while (in -> head != NULL && out -> head != NULL) {
        car *inCur = in -> head;
        car *outCur = out -> head;
        if (strncmp(outCur -> num, inCur -> num, MAX_CAR) != 0) {
            deleteCar(out, outCur -> num);
            deleteCar(in, outCur -> num);
            
            bad_car++;
        } else {
            deleteCar(out, outCur -> num);
            deleteCar(in, outCur -> num);
        }
    }
    return bad_car;
}


int main() {
    List in;
    List out;

    init_list(&in);
    init_list(&out);

    int N = 5;
    char arr_num[][MAX_CAR_NUM] = {"ZG206A", "PU234Q", "OS945CK", "ZG431SN", "ZG5962J", "ZG5962J", "OS945CK", "ZG206A", "PU234Q", "ZG431SN"};
    for (int i = 0; i < N; i++) {
        putIntoList(&in, arr_num[i]);
    }
    for (int i = N; i < N * 2; i++) {
        putIntoList(&out, arr_num[i]);
    }
    printf("--------\n");
    printList(&in); printf("\n");
    printList(&out); printf("\n");
    printf("--------\n");

    int result = compareTwoList(&in, &out);
    // 확인용
    printf("%d\n", result);
    return result;
}