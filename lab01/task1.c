#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r;
    int x, y;
} cerc;


void alloc_check_error(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "couldn't allocate memory!\n");
        exit(-1);
    }
}

int dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int intersect(cerc c1, cerc c2) {
    if (dist(c1.x, c1.y, c2.x, c2.y) <= ((c1.r + c2.r) * (c1.r + c2.r))) {
        return 1;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    cerc *v = (cerc*) malloc(n * sizeof(cerc));
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].r);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (intersect(v[i], v[j])) {
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);
    free(v);

    return 0;
}
