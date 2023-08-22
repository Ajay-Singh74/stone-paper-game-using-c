#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generaterandom(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int greator(char char1, char char2)
{
    if (char1 == char2)
    {
        return -1;
    }

    if ((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else if ((char2 == 'r') && (char1 == 's'))
    {
        return 0;
    }
    if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char2 == 'p') && (char1 == 'r'))
    {
        return 0;
    }

    if ((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else if ((char2 == 's') && (char1 == 'p'))
    {
        return 0;
    }
}

int main()
{

    int p1score = 0, compscore = 0, temp;
    char p1char, compchar;
    char dict[] = {'r', 'p', 's'};
    printf("Welcome to ajay game\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Players 1 turn : \n");
        printf("Choose 1 rock\n");
        printf("Choose 2 paper\n");
        printf("Choose 3 scissor\n");
        scanf("%d", &temp);
        getchar();
        p1char = dict[temp - 1];
        printf("player 1 choose %c\n", p1char);

        printf("computer turn : \n");

        temp = generaterandom(3) + 1;
        compchar = dict[temp - 1];
        printf("computer choose %c\n", compchar);

        if (greator(compchar, p1char) == 1)
        {
            compscore += 1;
            printf("computer got it\n\n");
        }
        else if (greator(compchar, p1char) == -1)
        {
            compscore += 1;
            p1score += 1;
            printf("draw match\n\n");
        }
        else
        {

            p1score += 1;
            printf("you got it\n\n");

            printf("score:\nYour=%d\n computer=%d\n", p1score, compscore);
        }
    }

    if (p1score > compscore)
    {
        printf("You won the match \n");
    }

    else if (p1score < compscore)
    {
        printf("computer won the match \n");
    }

    else
    {
        printf("draw match \n");
    }

    return 0;
}