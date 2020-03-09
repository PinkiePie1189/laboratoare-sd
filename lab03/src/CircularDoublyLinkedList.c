#include <stdio.h>
#include <stdlib.h>

#include "CircularDoublyLinkedList.h"
/*
 * Functie care trebuie apelata dupa alocarea unei liste, pentru a o initializa.
 * (Setare valori initiale pentru campurile specifice structurii LinkedList).
 */
void init_list(struct CircularDoublyLinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/*
 * Functia intoarce un pointer la nodul de pe pozitia n din lista.
 * Pozitiile din lista sunt indexate incepand cu 0 (i.e. primul nod din lista se afla pe pozitia n=0).
 * Daca n >= nr_noduri, atunci se intoarce nodul de pe pozitia rezultata daca am "cicla" (posibil de mai multe ori) pe
 * lista si am trece de la ultimul nod, inapoi la primul si am continua de acolo. Cum putem afla pozitia dorita fara sa
 * simulam intreaga parcurgere?
 * Daca n < 0, eroare.
 */
struct Node* get_nth_node(struct CircularDoublyLinkedList *list, int n) {
    if (n >= list->size) {
        n %= list->size;
    } else if (n < 0) {
        fprintf(stderr, "Invalid index!\n");
    }

    struct Node *curr = list->head;
    for (int i = 0; i < n; i++) {
        curr = curr->next;
    }

    return curr;
}

/*
 * Pe baza datelor trimise prin pointerul new_data, se creeaza un nou nod care e adaugat pe pozitia n a listei
 * reprezentata de pointerul list. Pozitiile din lista sunt indexate incepand cu 0 (i.e. primul nod din lista se afla
 * pe pozitia n=0).
 * Cand indexam pozitiile nu "ciclam" pe lista circulara ca la get, ci consideram nodurile in ordinea de la head la
 * ultimul (adica acel nod care pointeaza la head ca nod urmator in lista). Daca n >= nr_noduri, atunci adaugam nodul
 * nou la finalul listei. Daca n < 0, eroare.
 */
void add_nth_node(struct CircularDoublyLinkedList *list, int n, void *new_data) {
    struct Node *newborn = (struct Node*) calloc(1, sizeof(struct Node));
    newborn->data = new_data;
    if (list->size == 0) {
        list->head = newborn;
        list->tail = newborn;
        list->head->prev = newborn;
        list->tail->next = newborn;
    } else if (n >= list->size) {
        list->tail->next = newborn;
        newborn->prev = list->tail;
        newborn->next = list->head;
        list->head->prev = newborn;
        list->tail = newborn;
    } else if (n == 0) {
        newborn->next = list->head;
        newborn->prev = list->tail;
        list->tail->next = newborn;
        list->head->prev = newborn;
        list->head = newborn;
    } else {
        struct Node *curr = list->head;
        for (int i = 0; i < (n - 1); i++) {
            curr = curr->next;
        }
        newborn->prev = curr;
        newborn->next = curr->next;
        curr->next->prev = newborn;
        curr->next = newborn;
    }
    list->size++;
}

/*
 * Elimina nodul de pe pozitia n din lista al carei pointer este trimis ca parametru.
 * Pozitiile din lista se indexeaza de la 0 (i.e. primul nod din lista se afla pe pozitia n=0).
 * Functia intoarce un pointer spre acest nod proaspat eliminat din lista. Daca n >= nr_noduri - 1, se elimina nodul de
 * la finalul listei. Daca n < 0, eroare.
 * Este responsabilitatea apelantului sa elibereze memoria acestui nod.
 */
struct Node* remove_nth_node(struct CircularDoublyLinkedList *list, int n) {
    struct Node *to_delete = NULL;
    if (n >= list->size - 1) {
        struct Node *new_tail = list->tail->prev;
        to_delete = list->tail;
        new_tail->next = list->head;
        list->head->prev = new_tail;
        list->tail = new_tail;
    } else if (n == 0) {
        struct Node *new_head = list->head->next;
        to_delete = list->head;
        new_head->prev = list->tail;
        list->tail->next = new_head;
        list->head = new_head;
    } else {
        struct Node *curr = list->head;
        for (int i = 0; i < (n - 1); i++) {
            curr = curr->next;
        }
        to_delete = curr->next;
        struct Node *new_next = curr->next->next;
        new_next->prev = curr;
        curr->next = new_next;
    }
    list->size--;
    return to_delete;
}

/*
 * Functia intoarce numarul de noduri din lista al carei pointer este trimis ca parametru.
 */
int get_size(struct CircularDoublyLinkedList *list) {
    return (int) list->size;
}

/*
 * Procedura elibereaza memoria folosita de toate nodurile din lista, iar la sfarsit, elibereaza memoria folosita
 * de structura lista.
 */
void free_list(struct CircularDoublyLinkedList **pp_list) {
    struct CircularDoublyLinkedList *list = *pp_list;
    struct Node *curr = list->head;
    for (int i = 0; i < list->size; i++) {
        struct Node *next = curr->next;
        free(curr);
        curr = next;
    }
    list->size = 0;
    free(*pp_list);
    *pp_list = NULL;
}

/*
 * Atentie! Aceasta functie poate fi apelata doar pe liste ale caror noduri STIM ca stocheaza int-uri.
 * Functia afiseaza toate valorile int stocate in nodurile din lista separate printr-un spatiu, incepand de la primul
 * nod din lista.
 */
void print_int_list(struct CircularDoublyLinkedList *list) {
    struct Node *curr = list->head;

    for (int i = 0; i < list->size; i++) {
        printf("%d ", *(int*) curr->data);
        curr = curr->next;
    }

    printf("\n");
}

/*
 * Atentie! Aceasta functie poate fi apelata doar pe liste ale caror noduri STIM ca stocheaza string-uri.
 * Functia afiseaza toate string-urile stocate in nodurile din lista separate printr-un spatiu, incepand de la primul
 * nod din lista.
 */
void print_string_list(struct CircularDoublyLinkedList *list) {
    struct Node *curr = list->head;
    for (int i = 0; i < list->size; i++) {
        printf("%s ", (char*) curr->data);
        curr = curr->next;
    }
    printf("\n");
}

/*
 * Atentie! Aceasta functie poate fi apelata doar pe liste ale caror noduri STIM ca stocheaza int-uri.
 * Functia afiseaza o singura data toate valorile int stocate in nodurile din lista, separate printr-un spatiu, incepand
 * de la nodul dat ca parametru si continuand la stanga in lista dublu inlantuita circulara, pana cand sunt afisate
 * valorile tuturor nodurilor.
 */
void print_ints_left_circular(struct Node *start) {
    struct Node *curr = start;

    do {
        printf("%d ", *(int*) curr->data);
        curr = curr->prev;
    } while (curr != start);

    printf("\n");
}

/*
 * Atentie! Aceasta functie poate fi apelata doar pe liste ale caror noduri STIM ca stocheaza int-uri.
 * Functia afiseaza o singura data toate valorile int stocate in nodurile din lista, separate printr-un spatiu, incepand
 * de la nodul dat ca parametru si continuand la dreapta in lista dublu inlantuita circulara, pana cand sunt afisate
 * valorile tuturor nodurilor.
 */
void print_ints_right_circular(struct Node *start) {
    struct Node *curr = start;

    do {
        printf("%d ", *(int*) curr->data);
        curr = curr->next;
    } while (curr != start);

    printf("\n");
}
