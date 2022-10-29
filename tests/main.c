/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:31:48 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/10/29 14:36:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vlib/sys_arg_parse.h>
#include <stdio.h>

int main(int argc, const char **argv)
{
    if ((sys_arg_start(argc, argv)))
        return (1);

    printf("######################\n");
    
    printf("Executable name : %s\n", sys_arg_get_executable_name());

    const sys_index count = sys_arg_count();
    const sys_index index = sys_arg_index();

    printf("######################\n");

    printf("Count : %d\n", count);
    printf("Index : %d\n", index);

    printf("######################\n");

    const sys_arg_t *arg = NULL;
    arg = sys_arg_get();
    printf("Arg: %s\n", arg == NULL ? "NULL" : arg->arg);
    arg = sys_arg_next();
    printf("Arg: %s\n", arg == NULL ? "NULL" : arg->arg);
    arg = sys_arg_next();
    printf("Arg: %s\n", arg == NULL ? "NULL" : arg->arg);
    arg = sys_arg_next();
    printf("Arg: %s\n", arg == NULL ? "NULL" : arg->arg);
    arg = sys_arg_next();
    printf("Arg: %s\n", arg == NULL ? "NULL" : arg->arg);

    printf("######################\n");

    arg = sys_arg_set(0);

    do
    {
        printf("Arg: %s\n", arg == NULL ? "NULL" : arg->arg);
    } while ((arg = sys_arg_next()));
    
    printf("######################\n");

    sys_arg_end();
    return (0);
}