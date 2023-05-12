#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_STR 65

typedef struct {
    uint64_t data;
    struct node_t *next;
} node;

node *new_node(uint64_t data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
}

node *add_node(node *cur_node, uint64_t data) {
    node *new_node_t = new_node(data);
    new_node_t -> next = cur_node;
    return new_node_t;
}

char* dec2bin(char *str, uint64_t num) {
    int i = 0;
    if (num == 0) {
        str[i++] = '0';
    }
    while (num > 0) {
        str[i++] = (num & 1) + '0';
        num >>= 1;
    }
    str[i] = '\0';
    strrev(str);
    return str;
}

void print_rec(node *cur_node) {
    char *result_str = (char *)malloc(SIZE_OF_STR * sizeof(char));
    if (cur_node == NULL)
        return;
    print_rec(cur_node->next);
    char* binary_str = dec2bin(result_str, cur_node -> data);
    printf("%llu in dec == %s in bin\n", cur_node -> data, binary_str);
    free(binary_str);
}

uint64_t pop(node *cur_node) {
    uint64_t delete_data = cur_node -> data;
    free(cur_node);
    return delete_data;
}

void del_nodes(node *cur_node) {
    if (cur_node == NULL)
        return;
    del_nodes(cur_node -> next);
    pop(cur_node);
}

int main() {
    node *list = NULL;
    uint64_t temp;
    puts("Input unsigned digit to convert into binary: ");
    puts("In the end type any letter");
    while (scanf("%llu", &temp)) {
        list = add_node(list, temp);
    }
    print_rec(list);
    del_nodes(list);
}

Node_t *pop_stack(Node_t *stack_top) {
    if (stack_top == NULL) {
        printf("Stack is empty\n");
        return stack_top;
    }
    Node_t *buf_node = stack_top;
    free(stack_top);
    return buf_node;
}