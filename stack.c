#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

c_Node* c_init_node(const T* val) {
    c_Node* head = (c_Node*)malloc(sizeof(c_Node));
    head->val = *val;
    head->next = NULL;
    return head;
}

c_Node* c_add_node(c_Node* elem, const T* val) {
    if (elem == NULL) {
        return NULL;
    } else {
        c_Node* new = c_init_node(val);
        new->next = elem->next;
        elem->next = new;
        return new;
    }
}

c_Node* c_remove_node(const c_Node* elem, c_Node* root) {
    while (root->next && root->next != elem) {
        root = root->next;
    }
    c_Node* ptr = root->next;
    if (root->next) {
        root->next = root->next->next;
        free(ptr);
    }
    return root->next;
}

void c_destroy_list(c_Node* root) {
    while (root->next != NULL) {
        c_Node* ptr = root;
        root = root->next;
        free(ptr);
    }
    free(root);
}

c_Stack c_init() {
    c_Stack ret;
    T n = '\0';
    ret.head = c_init_node(&n);
    return ret;
}

void c_push(c_Stack* stack, T val) { c_add_node(stack->head, &val); }

void c_pop(c_Stack* stack) {
    if (!c_empty(stack)) {
        c_Node* ptr = c_remove_node(stack->head->next, stack->head);
        stack->head->next = ptr;
    }
}

int c_empty(c_Stack* stack) { return stack->head->next == NULL; }

T c_top(c_Stack* stack) { return stack->head->next->val; }

void c_destroy(c_Stack* stack) { c_destroy_list(stack->head); }

Node* init_node(const M* val) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->val = *val;
    head->next = NULL;
    return head;
}

Node* add_node(Node* elem, const M* val) {
    if (elem == NULL) {
        return NULL;
    } else {
        Node* new = init_node(val);
        new->next = elem->next;
        elem->next = new;
        return new;
    }
}

Node* remove_node(const Node* elem, Node* root) {
    while (root->next && root->next != elem) {
        root = root->next;
    }
    Node* ptr = root->next;
    if (root->next) {
        root->next = root->next->next;
        free(ptr);
    }
    return root->next;
}

void destroy_list(Node* root) {
    while (root->next != NULL) {
        Node* ptr = root;
        root = root->next;
        free(ptr);
    }
    free(root);
}

Stack init() {
    Stack ret;
    M n = 0;
    ret.head = init_node(&n);
    return ret;
}

void push(Stack* stack, M val) { add_node(stack->head, &val); }

void pop(Stack* stack) {
    if (!empty(stack)) {
        Node* ptr = remove_node(stack->head->next, stack->head);
        stack->head->next = ptr;
    }
}

M top(Stack* stack) { return stack->head->next->val; }

int empty(Stack* stack) { return stack->head->next == NULL; }

void destroy(Stack* stack) { destroy_list(stack->head); }
