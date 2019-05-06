#include <stdio.h>
#include <stdlib.h>

#define FUNDLEN 50
#define N 2

struct funds {
    char* bank;
    double bankfund;
    char* save;
    double savefund;
};

typedef struct funds Funds;

double sum(const Funds*, int);

int main(void)
{
    Funds* p = (Funds*)calloc(N, sizeof(Funds));
    p -> bank = "Garlic-Melo Bank";
    p -> save = "Lucky's Savings and Loan";
    p -> bankfund = 4023.27;
    p -> savefund = 8543.94;

    (p + 1) -> bank = "Honest Jack's Bank";
    (p + 1) -> save = "Party Time Saving";
    (p + 1) -> bankfund = 3620.88;
    (p + 1) -> savefund = 3802.91;

    printf("The Joneses have total of $%.2f.\n", sum(p, N));

    return 0;
}

double sum(const Funds* money, int n)
{
    int index;
    double total;
    for(index = 0, total = 0.00; index < n; index++)
    {
        total += (money + index) -> bankfund + (money + index) -> savefund;
    }

    return total;
}