/*
** EPITECH PROJECT, 2019
** tree.c
** File description:
** Print a tree the user can choose the size
*/
#include <stdio.h>

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
    nbofline = 4;

    for (int i = 1; i <= size; i++) {
        if (i%2 != 0 && i != 1) {
            nbstars-=2;
            nbstars -= (i - 1);
        } else if (i != 1) {
            nbstars-=2;
            nbstars -= i;
        }
        for (int compt = 0; compt < nbofline; compt++) {
            nbspace = ((maxstars / 2) + 1 - nbstars / 2) -1;
            nbstars+=2;
        }
        maxstars = nbstars - 2;
        nbofline += 1;
    }

    nbofline = 4;
    nbspace = 0;
    nbstars = 1;

    for (int i = 1; i <= size; i++) {
        if (i%2 != 0 && i != 1) {
            nbstars-=2;
            nbstars -= (i - 1);
        } else if (i != 1) {
            nbstars-=2;
            nbstars -= i;
        }
        for (int compt = 0; compt < nbofline; compt++) {
            nbspace = ((maxstars / 2) + 1 - nbstars / 2) -1;
            for (int space = 0; space < nbspace; space++)
                my_putchar(' ');
            for (int stars = 0; stars < nbstars; stars++)
                my_putchar('*');
            nbstars+=2;
            my_putchar('\n');
        }
        nbofline += 1;
    }    
}
