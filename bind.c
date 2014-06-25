/*
** bind.c for  in /home/bartholomew/programmation/c/binf
**
** Made by Bartholomew
** Bartholomew de la Villardiere <exabot@gmail.com>
**
** Started on  mer. juin 25 19:09:37 2014
** Last update mer. juin 25 19:09:37 2014
*/

#include "bind.h"

t_closure* bind(t_closure* closure, t_ptr (*fct)(t_ptr), t_ptr param)
{
    t_closure* new_closure = 0;
    t_list* list = 0;
    t_list* cursor = 0;

    /*
     * Creation du nouvel element a placer dans l'environnement.
     */
    list = malloc(sizeof(t_list));
    if (list == 0)
        return (0);
    list->val = param;
    list->next = 0;
    if (closure == 0)
    {
        /*
         * Creation d'une nouvelle closure.
         */
        new_closure = malloc(sizeof(t_closure));
        if (new_closure == 0)
        {
            free(list);
            return (0);
        }
        new_closure->fct = fct;
        new_closure->env = list;
        return (new_closure);
    }
    /*
     * Remplissage d'une closure deja existante en y placant un nouvel element
     * dans son environnement.
     */
    for (cursor = closure->env; cursor->next != 0; cursor = cursor->next);
    cursor->next = list;
    return (closure);
}

t_ptr call(t_closure* closure, t_ptr param)
{
    t_list* list = 0;
    t_list* cursor = 0;

    list = malloc(sizeof(t_list));
    if (list == 0)
        return (0);
    list->val = param;
    list->next = 0;
    for (cursor = closure->env; cursor->next != 0; cursor = cursor->next);
    cursor->next = list;
    return (_call(closure->fct, closure->env, param));
}

