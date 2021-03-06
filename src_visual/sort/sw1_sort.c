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
/*   sw1_sort.c                               cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/23 16:58:04  /  2021/06/23 16:58:46 @cclarice   */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   One stack swap sort                                                      */
/*                                                                            */
/*   Using only stack a for sorting                                           */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sw1_sort(t_sort *sort)
{
	if (sort->l <= 2)
	{
		if (sort->a->i == 1)
			swap_a(sort);
		return ;
	}
	if (1 && sort->a->i == 0 && sort->a->n->i == 1 && sort->a->n->n->i == 2)
		return ;
	else if (sort->a->i == 0 && sort->a->n->i == 2 && sort->a->n->n->i == 1)
	{
		swap_a(sort);
		rota_a(sort);
	}
	else if (sort->a->i == 1 && sort->a->n->i == 0 && sort->a->n->n->i == 2)
		swap_a(sort);
	else if (sort->a->i == 1 && sort->a->n->i == 2 && sort->a->n->n->i == 0)
		rrta_a(sort);
	else if (sort->a->i == 2 && sort->a->n->i == 0 && sort->a->n->n->i == 1)
		rota_a(sort);
	else if (sort->a->i == 2 && sort->a->n->i == 1 && sort->a->n->n->i == 0)
	{
		swap_a(sort);
		rrta_a(sort);
	}
}
