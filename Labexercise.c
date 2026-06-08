/*
Lambe Emmanuel SC24C246
Tcheptang Leonel SC24B209
Tonifar Godwill SC24B217
Tony Daniel Ngwese SC24B588
*/

//Question 5

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;

typedef struct PQNode {
    Item data;
    int priority;
    struct PQNode *next;
} PQNode;

typedef struct PriorityQueue {
    PQNode *head;
} PriorityQueue;

PriorityQueue* pq_create(void) {
    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    if (!pq) return NULL;
    pq->head = NULL;
    return pq;
}

bool pq_is_empty(PriorityQueue *pq) {
    return pq->head == NULL;
}

void pq_enqueue(PriorityQueue *pq, Item item, int priority) {
    if (!pq) return;
    PQNode *node = malloc(sizeof(PQNode));
    if (!node) return;
    node->data = item;
    node->priority = priority;
    node->next = NULL;


    if (pq->head == NULL || priority > pq->head->priority) {
        node->next = pq->head;
        pq->head = node;
        return;
    }


    PQNode *cur = pq->head;
    while (cur->next && cur->next->priority >= priority) {
        cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
}

Item pq_dequeue(PriorityQueue *pq, bool *ok) {
    if (!pq || pq_is_empty(pq)) {
        if (ok) *ok = false;
        return (Item)0;
    }
    PQNode *node = pq->head;
    Item val = node->data;
    pq->head = node->next;
    free(node);
    if (ok) *ok = true;
    return val;
}

Item pq_peek(PriorityQueue *pq, bool *ok) {
    if (!pq || pq_is_empty(pq)) { if (ok) *ok = false; return (Item)0; }
    if (ok) *ok = true;
    return pq->head->data;
}

void pq_free(PriorityQueue *pq) {
    if (!pq) return;
    PQNode *cur = pq->head;
    while (cur) {
        PQNode *t = cur;
        cur = cur->next;
        free(t);
    }
    free(pq);
}

// Example usage:
int main() {
    PriorityQueue *pq = pq_create();
    pq_enqueue(pq, 10, 1);
    pq_enqueue(pq, 20, 3);
    pq_enqueue(pq, 30, 2);
    pq_enqueue(pq, 40, 3);   // same priority as 20, stable order preserved

    bool ok;
    while (!pq_is_empty(pq)) {
        int v = pq_dequeue(pq, &ok);
        if (ok) printf("Dequeued: %d\n", v);
    }
    pq_free(pq);
    return 0;
}


// Question 6

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef int Item;

typedef struct Deque {
    Item arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void deque_init(Deque *d) {
    d->front = 0;
    d->rear = -1;
    d->size = 0;
}

bool deque_is_empty(Deque *d) { return d->size == 0; }
bool deque_is_full(Deque *d) { return d->size == MAX; }

bool enqueue_rear(Deque *d, Item x) {
    if (deque_is_full(d)) return false;
    d->rear = (d->rear + 1) % MAX;
    d->arr[d->rear] = x;
    d->size++;
    return true;
}

bool enqueue_front(Deque *d, Item x) {
    if (deque_is_full(d)) return false;
    d->front = (d->front - 1 + MAX) % MAX;
    d->arr[d->front] = x;
    d->size++;
    if (d->size == 1) d->rear = d->front;
    return true;
}

bool dequeue_front(Deque *d, Item *out) {
    if (deque_is_empty(d)) return false;
    if (out) *out = d->arr[d->front];
    d->front = (d->front + 1) % MAX;
    d->size--;
    if (d->size == 0) { d->front = 0; d->rear = -1; }
    return true;
}

bool dequeue_rear(Deque *d, Item *out) {
    if (deque_is_empty(d)) return false;
    if (out) *out = d->arr[d->rear];
    d->rear = (d->rear - 1 + MAX) % MAX;
    d->size--;
    if (d->size == 0) { d->front = 0; d->rear = -1; }
    return true;
}

bool peek_front(Deque *d, Item *out) {
    if (deque_is_empty(d)) return false;
    if (out) *out = d->arr[d->front];
    return true;
}

bool peek_rear(Deque *d, Item *out) {
    if (deque_is_empty(d)) return false;
    if (out) *out = d->arr[d->rear];
    return true;
}

// Example usage:

int main() {
    Deque d;
    deque_init(&d);
    enqueue_rear(&d, 10);
    enqueue_front(&d, 5);
    enqueue_rear(&d, 20);

    int x;
    peek_front(&d, &x); printf("Front: %d\n", x);
    peek_rear(&d, &x); printf("Rear: %d\n", x);

    while (!deque_is_empty(&d)) {
        dequeue_front(&d, &x);
        printf("Removed front: %d\n", x);
    }
    return 0;
}


// Question 8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *data;
    size_t len;
    size_t cap;
} String;


void s_init(String *s) {    // initialize empty string
    s->len = 0;
    s->cap = 16;
    s->data = malloc(s->cap);
    if (s->data) s->data[0] = '\0';
}


void s_init_c(String *s, const char *cstr) {
    if (!cstr) {
        s_init(s);
        return;
    }
    s->len = strlen(cstr);
    s->cap = s->len + 1;
    s->data = malloc(s->cap);
    if (s->data) memcpy(s->data, cstr, s->len + 1);
}


bool s_reserve(String *s, size_t new_cap) {
    if (new_cap <= s->cap) return true;
    char *p = realloc(s->data, new_cap);
    if (!p) return false;
    s->data = p;
    s->cap = new_cap;
    return true;
}


bool s_append(String *s, const char *str1) {    // append string
    if (!s || !str1) return false;
    size_t add = strlen(str1);
    size_t need = s->len + add + 1;
    if (need > s->cap) {
        size_t newcap = s->cap ? s->cap : 16;
        while (newcap < need) newcap *= 2;
        if (!s_reserve(s, newcap)) return false;
    }
    memcpy(s->data + s->len, str1, add);
    s->len += add;
    s->data[s->len] = '\0';
    return true;
}

void s_free(String *s) {
    if (!s) return;
    free(s->data);
    s->data = NULL;
    s->len = 0;
    s->cap = 0;
}

// Example usage:
int main() {
    String s;
    s_init_c(&s, "Hello");
    s_append(&s, ", ");
    s_append(&s, "world!");
    printf("%s (len=%zu)\n", s.data, s.len);
    s_free(&s);
    return 0;
}
