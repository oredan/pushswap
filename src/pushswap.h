/* ************************************************************************** */
/*                                                                            */
/*       ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::  */
/*     :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+: */
/*    +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+  */
/*   +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:   */
/*  +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+           */
/* #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#     */
/*  ######    ######  ############## ###    ### ###   ######    #######       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   pushswap.h                               cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/29 19:13:45  /  2021/05/31 18:04:17 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>
#include <time.h>

// includes:
//     unistd: read() write()
//     stdlib: malloc() free()
//     exit()

//	Struct Element
//	
//	d - (Digit) integer
//	i - (Index) index of number
//	n - (Next) next element

typedef struct s_elem
{
	int					d;
	unsigned int		i;
	struct s_elem		*n;
}				t_elem;

//	struct Sort
//
//	*a - start of a stack
//	*b - start of b stack
//	l  - len all
//	la - len a
//	lb - len b
//	sa - smallest index of a
//	sb - smallest index of b
//	ba - biggest index of a
//	bb - biggest index of b
//	op - Operations of 
//	vi - Visual:  1 - just return amount of opertaions.
//                2 - put only output.
//	              0 - just return amount of opertaions for next advanced visual.
//	             -1 - put advanced output for p2b_sort method
//	             -2 - put advanced output for 1sw_sort method
//	             -3 - put advanced output for 2sw_sort method
//	             -4 - put advanced output for best algoritm.

typedef struct s_sort
{
	t_elem			*a;
	t_elem			*b;
	unsigned int	l;
	unsigned int	la;
	unsigned int	lb;
	int				sf;
	int				ss;
	int				fr;
	int				sr;
	unsigned int	op[3];
	int				vi;
}				t_sort;

// Utils

unsigned int			ft_strlen(const char *str);
int						ft_atoi(const char *str);
void					ft_putint(int i);
void					visual(t_sort *sort);
void					init_sort(t_sort *sort);

// Sorting Algoritms

void	sw1_sort(t_sort *sort);
void	sw2_sort(t_sort *sort);
void	p2b_sort(t_sort *sort);

// game rules

void	swap_a(t_sort *sort);
void	swap_b(t_sort *sort);
void	swap_s(t_sort *sort);
void	push_a(t_sort *sort);
void	push_b(t_sort *sort);
void	rota_a(t_sort *sort);
void	rota_b(t_sort *sort);
void	rota_r(t_sort *sort);
void	rrta_a(t_sort *sort);
void	rrta_b(t_sort *sort);

#endif
