/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __sys_args_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:43:22 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/10/29 14:13:35 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys_arg_parse.h>

extern int __sys_arg_add_arg(__SYS_ARGS **args, __SYS_ARGS *new_arg)
{
    __SYS_ARGS *tmp = *args;

    if (!tmp)
    {
        *args = new_arg;
        return (0);
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_arg;
    new_arg->prev = tmp;
    return (0);
}

extern __SYS_ARGS *__sys_arg_create_arg(int index, char *arg, __SYS_ARGS *prev)
{
    __SYS_ARGS *new_arg = malloc(sizeof(__SYS_ARGS));

    if (!new_arg)
        return (NULL);
    new_arg->sys_args = (sys_arg_t *)malloc(sizeof(sys_arg_t));
    if (!new_arg->sys_args)
        return (NULL);
    new_arg->sys_args->index = index;
    new_arg->sys_args->arg = arg;
    new_arg->next = NULL;
    new_arg->prev = prev;
    return (new_arg);
}