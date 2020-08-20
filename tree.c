/*
** EPITECH PROJECT, 2019
** tree.c
** File description:
** Print a tree the user can choose the size
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int count_stars(int nbofline, int size)
{
    int maxstars = 1;
    int nbstars = 1;

    for (int i = 1; i <= size; i++) {
        if (i%2 != 0 && i != 1) {
            nbstars -= 2;
            nbstars -= (i - 1);
        } else if (i != 1) {
            nbstars -= 2;
            nbstars -= i;
        }
        for (int compt = 0; compt < nbofline; compt++)
            nbstars += 2;
        maxstars = nbstars - 2;
        nbofline += 1;
    }
    return (maxstars);
}

int print_leave(int nbofline, int nbstars, int maxstars)
{
    int nbspace = 0;

    for (int compt = 0; compt < nbofline; compt++) {
        nbspace = ((maxstars / 2) + 1 - nbstars / 2) -1;
        for (int space = 0; space < nbspace; space++)
            my_putchar(' ');
        for (int stars = 0; stars < nbstars; stars++)
            my_putchar('*');
        nbstars += 2;
        my_putchar('\n');
    }
    return (nbstars);
}

void print_tree(int size, int maxstars, int nbofline)
{
    int nbstars = 1;

    for (int i = 1; i <= size; i++) {
        if (i%2 != 0 && i != 1) {
            nbstars -= 2;
            nbstars -= (i - 1);
        } else if (i != 1) {
            nbstars -= 2;
            nbstars -= i;
        }
        nbstars = print_leave(nbofline, nbstars, maxstars);
        nbofline += 1;
    }
}

void print_trunk(int maxstars, int size)
{
    int nbspace = 0;

    for (int compt = 1; compt <= size; compt++) {
        nbspace = ((maxstars / 2) + 1 - size / 2) -1;
        for (int space = 0; space < nbspace; space++)
            my_putchar(' ');
        for (int trunk = 1; trunk <= size; trunk++)
            my_putchar('|');
        if (size%2 == 0)
            my_putchar('|');
        my_putchar('\n');
    }
}

void tree(int size)
{
    int totalline = 4;
    int nbofline = 4;
    int maxstars = 1;

    if (size >= 1 && size <= 2147483647) {
        for (int i = 0; i < size - 1; i++) {
            nbofline += 1;
            totalline = totalline + nbofline;
        }
        nbofline = 4;
        maxstars = count_stars(nbofline, size);
        print_tree(size, maxstars, nbofline);
        print_trunk(maxstars, size);
    }
    return;
}

int main(int ac, char **av)
{
    if (ac == 2)
        tree(atoi(av[1]));
    else
        write(1, "I need a size :)!\n", 18);
    return (0);
}