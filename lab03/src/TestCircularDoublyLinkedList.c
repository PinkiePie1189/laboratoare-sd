#include <stdio.h>
#include <stdlib.h>
#include "CircularDoublyLinkedList.h"

int main() {
    struct CircularDoublyLinkedList *list;
    struct Node *currNode;
    int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    list = malloc(sizeof(struct CircularDoublyLinkedList));
    init_list(list);
    
    add_nth_node(list, 0, &numbers[10]);
    currNode = remove_nth_node(list, 0);
    printf("#1:\n");
    printf("Output: %d\n", *((int*)(currNode->data)));
    printf("Output asteptat: 10\n\n");
    free(currNode);

    add_nth_node(list, 0, &numbers[8]);
    currNode = remove_nth_node(list, 0);
    printf("#2:\n");
    printf("Output: %d\n", *((int*)(currNode->data)));
    printf("Output asteptat: 8\n\n");
    free(currNode);

    add_nth_node(list, 0, &numbers[0]);
    add_nth_node(list, 1, &numbers[1]);
    add_nth_node(list, 2, &numbers[2]);
    add_nth_node(list, 3, &numbers[3]);
    add_nth_node(list, 4, &numbers[4]);
    printf("#3:\n");
    printf("Output: ");
    print_int_list(list);
    printf("Output asteptat: 0 1 2 3 4\n\n");

    add_nth_node(list, 0, &numbers[0]);
    add_nth_node(list, 0, &numbers[1]);
    add_nth_node(list, 0, &numbers[2]);
    add_nth_node(list, 0, &numbers[3]);
    add_nth_node(list, 0, &numbers[4]);
    printf("#4:\n");
    printf("Output: ");
    print_int_list(list);
    printf("Output asteptat: 4 3 2 1 0 0 1 2 3 4\n\n");

    currNode = remove_nth_node(list, 0);
    free(currNode);
    printf("#5:\n");
    printf("Output: ");
    print_int_list(list);
    printf("Output asteptat: 3 2 1 0 0 1 2 3 4\n\n");

    currNode = remove_nth_node(list, 8);
    free(currNode);
    printf("#6:\n");
    printf("Output: ");
    print_int_list(list);
    printf("Output asteptat: 3 2 1 0 0 1 2 3\n\n");

    currNode = remove_nth_node(list, 0);
    free(currNode);
    currNode = remove_nth_node(list, 0);
    free(currNode);
    currNode = remove_nth_node(list, 0);
    printf("#7:\n");
    printf("Output: ");
    printf("%d\n", *((int*)currNode->data));
    free(currNode);
    printf("Output asteptat: 1\n\n");

    currNode = remove_nth_node(list, 4);
    free(currNode);
    currNode = remove_nth_node(list, 3);
    free(currNode);
    currNode = remove_nth_node(list, 2);
    free(currNode);
    currNode = remove_nth_node(list, 1);
    free(currNode);
    currNode = remove_nth_node(list, 0);
    free(currNode);
    add_nth_node(list, 0, &numbers[3]);
    add_nth_node(list, 1, &numbers[3]);
    add_nth_node(list, 2, &numbers[7]);
    add_nth_node(list, 0, &numbers[1]);
    printf("#8:\n");
    printf("Output: ");
    print_int_list(list);
    printf("Output asteptat: 1 3 3 7\n\n");

    currNode = remove_nth_node(list, 2);
    free(currNode);
    currNode = remove_nth_node(list, 1);
    free(currNode);
    printf("#9:\n");
    printf("Output: ");
    print_int_list(list);
    printf("Output asteptat: 1 7\n\n");

    add_nth_node(list, 2, &numbers[8]);
    add_nth_node(list, 1, &numbers[2]);
    add_nth_node(list, 0, &numbers[0]);
    add_nth_node(list, 5, &numbers[9]);
    add_nth_node(list, 3, &numbers[3]);
    printf("#10:\n");
    printf("Output: ");
    print_int_list(list);
    printf("Output asteptat: 0 1 2 3 7 8 9\n\n");
    
    currNode = get_nth_node(list, 4);
    printf("#11:\n");
    printf("Output: ");
    print_ints_left_circular(currNode);
    printf("Output asteptat: 7 3 2 1 0 9 8\n\n");

    currNode = get_nth_node(list, 2);
    printf("#12:\n");
    printf("Output: ");
    print_ints_right_circular(currNode);
    printf("Output asteptat: 2 3 7 8 9 0 1\n\n");

    free_list(&list);

    list = malloc(sizeof(struct CircularDoublyLinkedList));
    init_list(list);

    add_nth_node(list, 0, "mere");
    add_nth_node(list, 0, "are");
    add_nth_node(list, 0, "Ana");
    printf("#13:\n");
    printf("Output: ");
    print_string_list(list);
    printf("Output asteptat: Ana are mere\n");

    free_list(&list);

    return 0;
}
