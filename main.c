/*
** test.c for  in /home/bartholomew/programmation/c/binf
**
** Made by Bartholomew
** Bartholomew de la Villardiere <exabot@gmail.com>
**
** Started on  mer. juin 25 12:29:08 2014
** Last update mer. juin 25 12:29:08 2014
*/

#include <stdio.h>
#include "bind.h"

int add(int a,int b, int c)
{
    return (a + b + c);
}

int main(int argc, char** argv)
{
    t_closure* add_1_2 = 0;
    t_closure* add_2_3 = 0;
    t_closure* print_error = 0;
    int c = 0;

    if (argc != 2)
    {
        print_error = BIND(0, printf, "%s: %s\n");
        BIND(print_error, 0, "usage");
        CALL(print_error, argv[0]);
        return (1);
    }

    add_1_2 = BIND(0, add, 1);
    BIND(add_1_2, 0, 2);

    add_2_3 = BIND(0, add, 2);
    BIND(add_2_3, 0, 3);

    c = atoi(argv[1]);
    printf("1 + 2 + %d = %d\n", c, CALL(add_1_2, c));
    printf("2 + 3 + %d = %d\n", c, CALL(add_2_3, c));
    return (0);
}


