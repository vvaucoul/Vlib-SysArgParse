/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_arg_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:25:52 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/10/29 14:40:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys_arg_parse.h>
#include <stdio.h>

__SYS_ARGS *__sys_args = NULL;
__SYS_ARGS *__current_arg = NULL;
char *__executable_name = NULL;
sys_index __sys_count = 0;

static int __sys_arg_start(int argc, char **argv)
{
    __SYS_ARGS *prev = NULL;

    __executable_name = argv[0];
    int i = 1;
    if (argc < 2)
    {
        __current_arg = NULL;
        __sys_count = 0;
        return (0);
    }
    while (i < argc)
    {
        printf("%s\n", argv[i]);
        prev = __sys_arg_create_arg(i - 1, argv[i], prev);
        if (!prev)
            return (1);
        __sys_arg_add_arg(&__sys_args, prev);
        ++i;
    }
    __current_arg = __sys_args;
    __sys_count = i - 1;
    return (0);
}

static void __sys_arg_free_args(__SYS_ARGS *args)
{
    if (args)
    {
        __sys_arg_free_args(args->next);
        free(args->sys_args);
        free(args);
    }
}

static char * __sys_arg_get_executable_name(void)
{
    char *name = __executable_name;
    int i = 0;

    while (name[i])
    {
        if (name[i] == '/')
            name = &name[i + 1];
        ++i;
    }
    return (name);
}

static const sys_arg_t *__sys_arg_next(void)
{
    if (!__current_arg || !__current_arg->next)
        return (NULL);
    __current_arg = __current_arg->next;
    return (__GET_SYS_ARG(__current_arg));
}

static const sys_arg_t *__sys_arg_prev(void)
{
    if (!__current_arg || !__current_arg->prev)
        return (NULL);
    __current_arg = __current_arg->prev;
    return (__GET_SYS_ARG(__current_arg));
}

static const sys_arg_t *__sys_arg_set(const sys_index index)
{
    __SYS_ARGS *tmp = __sys_args;

    while (tmp)
    {
        if (tmp->sys_args->index == index)
        {
            __current_arg = tmp;
            return (__GET_SYS_ARG(tmp));
        }
        tmp = tmp->next;
    }
    return (NULL);
}

/*******************************************************************************
 *                             INTERFACE FUNCTIONS                             *
 ******************************************************************************/

int sys_arg_start(int argc, const char **argv)
{
    return (__sys_arg_start(argc, (char **)argv));
}

void sys_arg_end(void)
{
    __sys_arg_free_args(__sys_args);
}

const char *sys_arg_get_executable_name(void)
{
    return (__sys_arg_get_executable_name());
}

const __SYS_ARG *sys_arg_next(void)
{
    return (__sys_arg_next());
}

const __SYS_ARG *sys_arg_prev(void)
{
    return (__sys_arg_prev());
}

const __SYS_ARG *sys_arg_set(const sys_index index)
{
    return (__sys_arg_set(index));
}

const sys_arg_t *sys_arg_get(void)
{
    return (__GET_SYS_ARG(__current_arg));
}

sys_index sys_arg_count(void)
{
    return (__sys_count);
}

sys_index sys_arg_index(void)
{
    if (!__current_arg)
        return (0);
    return (__current_arg->sys_args->index);
}