#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

/*
 * Functie care trebuie apelata dupa alocarea unei liste simplu inlantuite, pentru a o initializa.
 * (Setare valori initiale pentru campurile specifice structurii LinkedList).
 */
void init_list(struct LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/*
 * Pe baza datelor trimise prin pointerul new_data, se creeaza un nou nod care e adaugat pe pozitia n a listei
 * reprezentata de pointerul list. Pozitiile din lista sunt indexate incepand cu 0 (i.e. primul nod din lista se afla
 * pe pozitia n=0). Daca n >= nr_noduri, noul nod se adauga la finalul listei. Daca n < 0, eroare.
 */
void add_nth_node(struct LinkedList *list, int n, void *new_data) {
    struct Node *newborn = (struct Node*) malloc(sizeof(struct Node));
    newborn->data = new_data;
    if (n >= list->size) {
        if (list->tail != NULL) {
            list->tail->next = newborn;
        } else {
            list->head = newborn;
        }
        list->tail = newborn;
        newborn->next = NULL;
    } else if (n < 0) {
        fprintf(stderr, "Invalid index!\n");
    } else if (n == 0) {
        struct Node *to_next = list->head;
        list->head = newborn;
        list->head->next = to_next;
    } else {
        struct Node *curr = list->head;
        for (int i = 0; i < n - 1; i++) {
            curr = curr->next;
        }
        newborn->next = curr->next;
        curr->next = newborn;
    }
    list->size++;
}

/*
 * Elimina nodul de pe pozitia n din lista al carei pointer este trimis ca parametru.
 * Pozitiile din lista se indexeaza de la 0 (i.e. primul nod din lista se afla pe pozitia n=0). Daca n >= nr_noduri - 1,
 * se elimina nodul de la finalul listei. Daca n < 0, eroare.
 * Functia intoarce un pointer spre acest nod proaspat eliminat din lista.
 * Este responsabilitatea apelantului sa elibereze memoria acestui nod.
 */
struct Node* remove_nth_node(struct LinkedList *list, int n) {
    if (list->size == 1) {
        list->size--;
	struct Node *to_remove = list->head;
	list->head = NULL;
	list->tail = NULL;
        return to_remove;
    }
    if (n >= (list->size - 1)) {
        struct Node *curr = list->head;
        for (int i = 0; i < (list->size - 1); i++) {
            curr = curr->next;
        }
        struct Node *toremove = curr->next;
        curr->next = NULL;
        list->tail = curr;
        list->size--;
        return toremove;
    } else if (n == 0) {
        struct Node *to_next = list->head;
        list->head = list->head->next;
        list->size--;
        return to_next;
    } else {
        struct Node *curr = list->head;
        for (int i = 0; i < (n - 1); i++) {
            curr = curr->next;
        }
        struct Node *toremove = curr->next;
        curr->next = curr->next->next;
        list->size--;
        return toremove;
    }
}

/*
 * Functia intoarce numarul de noduri din lista al carei pointer este trimis ca parametru.
 */
int get_size(struct LinkedList *list) {
    return list->size;
}

/*
 * Procedura elibereaza memoria folosita de toate nodurile din lista, iar la sfarsit, elibereaza memoria folosita
 * de structura lista si actualizeaza la NULL valoarea pointerului la care pointeaza argumentul (argumentul este un
 * pointer la un pointer).
 */
void free_list(struct LinkedList **pp_list) {

    /* TODO */
    struct LinkedList *list = *pp_list;
    struct Node *curr = list->head;
    for (int i = 0; i < (list->size); i++) {
        struct Node *next = curr->next;
        free(curr);
        curr = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    free(list);
    *pp_list = NULL;
}

/*
 * Atentie! Aceasta functie poate fi apelata doar pe liste ale caror noduri STIM ca stocheaza int-uri.
 * Functia afiseaza toate valorile int stocate in nodurile din lista inlantuita separate printr-un spatiu.
 */
void print_int_linkedlist(struct LinkedList *list) {
    /* TODO */
    struct Node *curr = list->head;
    for (int i = 0; i < (list->size); i++) {
        printf("%d ", *(int*) curr->data);
        curr = curr->next;
    }

    printf("\n");
}

/*
 * Atentie! Aceasta functie poate fi apelata doar pe liste ale caror noduri STIM ca stocheaza string-uri.
 * Functia afiseaza toate string-urile stocate in nodurile din lista inlantuita, separate printr-un spatiu.
 */
void print_string_linkedlist(struct LinkedList *list) {
    struct Node *curr = list->head;
    for (int i = 0; i < (list->size); i++) {
        printf("%s ", (char*) curr->data);
        curr = curr->next;
    }

    printf("\n");
}
