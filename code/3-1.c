#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[100];
    int score;
    struct student *next;
};

void add_student(struct student **head, char *name, int score) {
    struct student *new_node = malloc(sizeof(struct student));
    struct student *cur;

    strcpy(new_node->name, name);
    new_node->score = score;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    cur = *head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = new_node;
}

void delete_student(struct student **head, char *name) {
    struct student *cur = *head;
    struct student *prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) {
                *head = cur->next;
            } else {
                prev->next = cur->next;
            }

            free(cur);
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}

void print_students(struct student *head) {
    struct student *cur = head;

    while (cur != NULL) {
        printf("%s %d\n", cur->name, cur->score);
        cur = cur->next;
    }
}

void free_students(struct student *head) {
    struct student *cur = head;
    struct student *next;

    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }
}

int main(void) {
    struct student *head = NULL;
    char command[100];
    char name[100];
    int score;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            add_student(&head, name, score);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete_student(&head, name);
        } else if (strcmp(command, "print") == 0) {
            print_students(head);
        } else if (strcmp(command, "quit") == 0) {
            free_students(head);
            break;
        }
    }

    return 0;
}