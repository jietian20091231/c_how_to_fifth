#include <stdio.h>
#define LEN 20

struct names {
    char first[LEN];
    char last[LEN];
};

struct guy {
    struct names handle;
    char favfood[LEN];
    char jon[LEN];
    float income;
};

int main(void)
{

    struct guy fellow[2] = {
        { { "Ewen", "Villard" },
          "grilled salmon",
          "personality coach",
          68112.00
        },
        { { "Rodney", "Swillbelly" },
          "tripe",
          "tabloid editor",
          432400.00
        }
    };

    struct guy* him;

    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = fellow;
    printf("sizeof(struct guy) = %ld\n", sizeof(struct guy));
    printf("him -> income is %.2f: (*him).income is %.2f\n", him ->income, (*him).income);
    him++;
    printf("him -> favfood is %s: him->handel.last is %s\n", him -> favfood, him ->handle.last);

    struct guy* ptr;
    ptr = fellow;
    printf("ptr = %p, fellow = %p\n", ptr, fellow);

    return 0;
}