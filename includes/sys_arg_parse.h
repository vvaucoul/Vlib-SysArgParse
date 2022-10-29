/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_arg_parse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:29:38 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/10/29 14:39:49 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_ARG_PARSE_H
#define SYS_ARG_PARSE_H

#include <stdlib.h>

typedef unsigned int sys_index; // Index of the argument

typedef struct __s_sys_arg_t
{
    sys_index index;
    char *arg;
} __t_sys_arg;

#define __SYS_ARG __t_sys_arg
typedef __t_sys_arg sys_arg_t;

typedef struct __s_sys_args
{
    sys_arg_t *sys_args;
    struct __s_sys_args *next;
    struct __s_sys_args *prev;
} __attribute((packed, aligned(8))) __t_sys_args;

#define __SYS_ARGS __t_sys_args
#define __GET_SYS_ARG(arg) arg == NULL ? NULL : arg->sys_args

extern __SYS_ARGS *__sys_args;
extern __SYS_ARGS *__current_arg;
extern char *__executable_name;
extern sys_index __sys_count;

/*******************************************************************************
 *                             INTERFACE FUNCTIONS                             *
 ******************************************************************************/

/**
 * @brief Parse System Arguments
 *
 * @param argc
 * @param argv
 * @return int
 */
extern int sys_arg_start(int argc, const char **argv);

/**
 * @brief Get the Executable Name object
 *
 */
extern void sys_arg_end(void);

/**
 * @brief Get the executable name
 *
 * @return const char*
 */
extern const char *sys_arg_get_executable_name(void);

/**
 * @brief Set the next argument and return it
 *
 * @return const sys_arg_t*
 */
extern const sys_arg_t *sys_arg_next(void);

/**
 * @brief Set the previous argument and return it
 *
 * @return const sys_arg_t*
 */
extern const sys_arg_t *sys_arg_prev(void);

/**
 * @brief Set the current argument and return it
 *
 * @param index
 * @return const sys_arg_t*
 */
extern const sys_arg_t *sys_arg_set(const sys_index index);

/**
 * @brief Get the current argument
 *
 * @return const sys_arg_t*
 */
extern const sys_arg_t *sys_arg_get(void);

/**
 * @brief Get the argument at index
 *
 * @return sys_index
 */
extern sys_index sys_arg_index(void);

/**
 * @brief Get the argument at index
 *
 * @param index
 * @return sys_arg_t*
 */
extern sys_index sys_arg_count(void);

/*******************************************************************************
 *                                LIB FUNCTIONS                                *
 ******************************************************************************/

extern int __sys_arg_add_arg(__SYS_ARGS **args, __SYS_ARGS *new_arg);
extern __SYS_ARGS *__sys_arg_create_arg(int index, char *arg, __SYS_ARGS *prev);

#endif /* SYS_ARG_PARSE_H */