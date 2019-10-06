/*
** EPITECH PROJECT, 2019
** tree.c
** File description:
** Print a tree the user can choose the size
*/
void my_putchar(char c);

void tree(int size)
{
    int totalline = 4;
    int nbofline = 4;
    int nbspace = 0;
    int maxstars = 1;
    int nbstars = 1;

    for (int i = 0; i < size - 1; i++) {
        nbofline+=1;
        totalline = totalline + nbofline;
    }
    // for (int i = 0; i < size; i++) {

    //     if ((i % 2) == 0) {
    //         printf("\nMOINS\n");
    //         nbstars -= i;
    //     }
    //     printf("\n-----------------\nNB_Stars: %i  MAX: %i\n",nbstars, maxstars);
    //     for (int compt = 0; compt < 3; compt++) {
    //         nbstars += 2;
    //         maxstars = maxstars + nbstars;
    //     printf("NB_Stars: %i  MAX: %i\n",nbstars, maxstars);
    //     }
    // }
    // return;

    // nbspace = (totalline / 2) + 1 -nbstars

    for (int i = 0; i < size; i++) {
        if (i%2 == 0)
            nbstars -= i;
        else {
            nbstars -= (i - 1);
        }
        printf("-------------------------\n");
        for (int compt = 0; compt < nbofline; compt++) {
            nbspace = (totalline / 2) + 1 - nbstars;
            // printf("Stars: %i\nSpace: %i\n", nbstars, nbspace);
            // for (int space = 0; space < nbspace; space++)
            //     my_putchar(' ');
            for (int stars = 0; stars < nbstars; stars++)
                my_putchar('*');
            nbstars+=2;
            my_putchar('\n');
        }
    }
}
