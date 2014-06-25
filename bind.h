/*
** bind.h for  in /home/bartholomew/programmation/c/binf
**
** Made by Bartholomew
** Bartholomew de la Villardiere <exabot@gmail.com>
**
** Started on  mer. juin 25 19:09:57 2014
** Last update mer. juin 25 19:09:57 2014
*/

#include <stdlib.h>
#include <stdint.h>

#ifndef         BIND_H_
# define        BIND_H_

#define BIND(closure, fct, param)\
    bind(closure, (t_ptr (*)(t_ptr))fct, (t_ptr)param)

#define CALL(closure, param)\
    call(closure, (t_ptr)param)

typedef unsigned long t_ptr;

typedef struct s_list
{
    t_ptr val;
    struct s_list* next;
} t_list;

typedef struct
{
    t_ptr (*fct)(t_ptr);
    t_list* env;
} t_closure;

extern t_ptr _call(t_ptr (*)(t_ptr), t_list*, t_ptr);

t_closure* bind(t_closure* closure, t_ptr (*fct)(t_ptr), t_ptr param);
t_ptr call(t_closure* closure, t_ptr param);

#endif          /* !BIND_H_*/
