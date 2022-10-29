/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check-install.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:29:34 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/10/29 14:31:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vlib/sys_arg_parse.h>
#include <stdio.h>

#define COLOR_LIGHT_GREEN "\033[92m"
#define COLOR_LIGHT_RED "\033[91m"
#define COLOR_RESET "\033[0m"
#define __STR__ ((char *)"SUCESS !")

int main(int argc, const char **argv)
{
    if ((sys_arg_start(argc, argv)))
        return (1);
    else
        sys_arg_end();
    printf(COLOR_LIGHT_GREEN "%s\n" COLOR_RESET, (char *)__STR__);
    return (0);
}