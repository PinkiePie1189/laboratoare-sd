#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXBUF 256

void alloc_check_error(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "couldn't allocate memory!\n");
        exit(-1);
    }
}

void print_mat(char **mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                printf("#");
            } else {
                printf("$");
            }
        }
        printf("\n");
    }

    printf("\n");
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    char **mat;
    mat = (char**) malloc(n * sizeof(char*));
    alloc_check_error(mat);

    for (int i = 0; i < n; i++) {
        mat[i] = (char*) malloc(m * sizeof(char));
        alloc_check_error(mat[i]);
    }

    fgetc(stdin);
    char buf[MAXBUF];
    fgets(buf, MAXBUF, stdin);
    int len = strlen(buf);

    if (buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
        len--;
    }

    int rob_x = 0, rob_y = 0;
    for (int i = 0; i < len; i++) {
        mat[rob_x][rob_y] = 0;
        if (buf[i] == 'L') {
            rob_y--;
        } else if (buf[i] == 'R') {
            rob_y++;
        } else if (buf[i] == 'U') {
            rob_x--;
        } else if (buf[i] == 'D') {
            rob_x++;
        }
        mat[rob_x][rob_y] = 1;

        print_mat(mat, n, m);
    }


    if (mat[0][0] == 1) {
        printf("OK!\n");
    }


    for (int i = 0; i < n; i++) {
        free(mat[i]);
        mat[i] = NULL;
    }

    free(mat);
    mat = NULL;
}
