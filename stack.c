#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"
#include "mem.h"
#include "log.h"

#define STACK_SIZE 512

static void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(-1);
}

stack* stack_new() {
    stack_elem *p;
    stack *s;

    p = sc_malloc(sizeof(stack_elem) * STACK_SIZE);
    if (p == NULL) {
        error("no memory for stack\n");
    }
    memset(p, 0, sizeof(stack_elem) * STACK_SIZE);
    s = sc_malloc(sizeof(stack));
    if (s == NULL) {
        sc_free(p);
        error("no memory for stack\n");
    }

    s->elems = p;
    s->capacity = STACK_SIZE;
    s->size = 0;
    return s;
}

void stack_dispose(stack *s) {
    if (s == NULL) {
        return;
    }

    sc_free(s->elems);
    sc_free(s);
}

void stack_push(stack *s, stack_elem obj) {
    int i;

    if (s == NULL) {
        return;
    }

    if (s->size == s->capacity) {
        stack_elem *p;
        int cap = s->capacity * 2;
        p = sc_realloc(s->elems, cap * sizeof(stack_elem));
        if (p == NULL) {
            error("no memory for stack\n");
        }
        s->capacity = cap;
        s->elems = p;
    }

    i = s->size;
    s->elems[i] = obj;
    i++;
    s->size = i;
}

void stack_pop(stack *s) {
    int i;

    if (s == NULL) {
        return;
    }
    i = s->size;
    assert(i != 0);
    if (i == 0) {
        sc_log("%s", "no elements in stack");
        return;
    }

    i--;
    s->elems[i] = NULL;
    s->size = i;
}

void stack_for_each(stack *s, visitor_fn fn) {
    stack_elem *p = s->elems;
    stack_elem *q = p + s->size;

    if (s == NULL || fn == NULL) {
        return;
    }

    for (; p != q; p++) {
        fn(*p);
    }
}

object** stack_deepcopy(stack *s) {
    stack_elem *p = s->elems;
    stack_elem *q = p + s->size;
    object **buf, **base;

    if (s == NULL) {
        return NULL;
    }

    buf = sc_malloc(sizeof(object*) * s->size);
    if (buf == NULL) {
        return NULL;
    }
    base = buf;
    for (; p != q; p++, buf++) {
        *buf = **p;
    }
    return base;
}

int stack_swap(stack *this, stack *src) {
    stack_elem *buf;

    if (this == NULL || src == NULL) {
        return -1;
    }

    buf = sc_malloc(src->capacity * sizeof(stack_elem));
    if (buf == NULL) {
        return -1;
    }
    memcpy(buf, src->elems, sizeof(stack_elem) * src->size);
    sc_free(this->elems);
    this->elems = buf;
    this->capacity = src->capacity;
    this->size = src->size;
    return 0;
}

int stack_copy(stack *this, stack *dst) {
    stack_elem *buf;

    if (this == NULL || dst == NULL) {
        return -1;
    }

    buf = sc_malloc(this->size * sizeof(stack_elem));
    if (buf == NULL) {
        return -1;
    }
    memcpy(buf, this->elems, this->size * sizeof(stack_elem));
    dst->elems = buf;
    dst->capacity = dst->size = this->size;
    return 0;
}

