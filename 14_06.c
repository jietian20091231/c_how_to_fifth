// 14_06.c 14_07.c
#include <stdio.h>
#define FUNDLEN 50

struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(const struct funds *);
double sum_struct(const struct funds );

int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4023.27,
        "Lucky's Savings and Load",
        8543.94
    };

    printf("Stan has a total of $%.2f.\n", sum(&stan));
    printf("Stan has a total of $%.2f.\n", sum_struct(stan));

    return 0;
}

double sum(const struct funds * pfunds)
{
    return pfunds -> bankfund + pfunds -> savefund;
}

double sum_struct(const struct funds f)
{
    return f.bankfund + f.savefund;
}