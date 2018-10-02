/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:55:28 by llanga            #+#    #+#             */
/*   Updated: 2018/09/28 10:34:00 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# define DEF          "\033[0m"
# define BOLD         "\033[1m"
# define BLACK        "\033[30m"
# define RED          "\033[31m"
# define GREEN        "\033[32m"
# define BROWN        "\033[33m"
# define BLUE         "\033[34m"
# define MAGENTA      "\033[35m"
# define CYAN         "\033[36m"
# define GRAY         "\033[37m"

void    disp(char *str);
void    ft_strarrayiter(char **arr, void(*dsp)(char *str));
int 	get_2darr_len(char **arr2d);
char 	**cpy_2darr(char **src);
char 	**gimme_2darr_space(int size);
char 	*run_exe(char **env, char *exe);

void 	exec_builtin(char **av, char ***envcpy);
void 	echo_str(char *av, char **env);
int 	get_env(char **envcpy, char *key);
void	add_2d_arr_str(char ***env, char **item);
void	rm_2d_arr_str(char ***old, char *item);
void    mk_2D_arr_clean(char ***arr);
void 	exec_sh_fun(char **av, char ***envcpy);
char  	**get_args(void);
int 	just_find_item(char **arr2d, char *item);
int 	find_item(char **arr2d, char **item);
int		ft_indexof(char *str, char c);

#endif
