#pragma once
#include <stdio.h>
#include <stdlib.h>

#define T char
#define M double

typedef struct c_node {
    T val;
    struct c_node* next;
} c_Node;

typedef struct c_Stack {
    c_Node* head;
} c_Stack;

c_Node* c_init_node(const T* val);

c_Node* c_add_node(c_Node* elem, const T* val);

c_Node* c_remove_node(const c_Node* elem, c_Node* root);

void c_destroy_list(c_Node* root);

c_Stack c_init();

void c_push(c_Stack* stack, const T val);

void c_pop(c_Stack* stack);

int c_empty(c_Stack* stack);

T c_top(c_Stack* stack);

void c_destroy(c_Stack* stack);

typedef struct node {
    M val;
    struct node* next;
} Node;

typedef struct Stack {
    Node* head;
} Stack;

Node* init_node(const M* val);

Node* add_node(Node* elem, const M* val);

Node* remove_node(const Node* elem, Node* root);

void destroy_list(Node* root);

Stack init();

void push(Stack* stack, const M val);

void pop(Stack* stack);

int empty(Stack* stack);

M top(Stack* stack);

void destroy(Stack* stack);
