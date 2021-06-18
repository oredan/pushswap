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
/*   main.c                                   cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/17 14:59:44  /  2021/06/17 14:59:46 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	exit_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

t_elem	*ft_newelem(int nbr, unsigned int index)
{
	t_elem	*ptr;

	ptr = malloc(sizeof(t_elem));
	if (!ptr)
		exit_error();
	ptr->n = NULL;
	ptr->d = nbr;
	ptr->i = index;
	ptr->b = 0;
	return (ptr);
}

t_elem	*create_list(int *d, unsigned int *i, int c, unsigned int *l)
{
	t_elem	*ptr;
	t_elem	*ret;
	int		ip;

	ip = 0;
	ret = ft_newelem(d[ip], i[ip]);
	ip++;
	ptr = ret;
	while (ip < c)
	{
		ptr->n = ft_newelem(d[ip], i[ip]);
		ip++;
		ptr = ptr->n;
	}
	ptr->n = NULL;
	*l = ip;
	return (ret);
}

void	clear_sort(t_sort *sort)
{
	t_elem *ptr;
	t_elem *nxt;

	ptr = sort->a;
	while (ptr)
	{
		nxt = ptr->n;
		free(ptr);
		ptr = nxt;
	}
	ptr = sort->b;
	while (ptr)
	{
		nxt = ptr->n;
		free(ptr);
		ptr = nxt;
	}
	sort->a = NULL;
	sort->b = NULL;
}

void	create_sort(t_sort *sort, int *d, unsigned int *i, int c)
{
	clear_sort(sort);
	sort->a = create_list(d, i, c, &sort->l);
	sort->la = sort->l;
	sort->lb = 0;
	sort->op[0] = 0;
	sort->op[1] = 0;
	sort->op[2] = 0;
	sort->op[3] = 0;
}

void	sorting(t_sort *sort, int *d, unsigned int *i, int c)
{
	if (sort->vi == 0)
	{
		create_sort(sort, d, i, c);
		clear_sort(sort);
	}
	else if (sort->vi < 0)
	{
		create_sort(sort, d, i, c);
		visual(sort, "hi\n");
		if (sort->vi == -1)
			p2b_sort(sort);
		else if (sort->vi == -2)
			sw1_sort(sort);
		else if (sort->vi == -3)
			sw2_sort(sort);
		else if (sort->vi == -4)
			qck_sort(sort);
		else if (sort->vi == -5)
			whl_sort(sort);
		else
			write(1, "Visual Error!\n", 14);
		clear_sort(sort);
	}
}

int	main(int c, char *v[])
{
	t_sort				sort;
	unsigned int		*i;
	int					*d;

	sort.a = NULL;
	sort.b = NULL;
	(v++ && c--);
	if (v[0] && v[0][0] && v[0][1] &&
		v[0][0] == '-' && v[0][1] == 'v' && v[0][2] >= '1' && v[0][2] <= '9')
	{
		sort.vi = (v[0][2] - '0') * -1;
		(v++ && c--);
	}
	else
		sort.vi = 0;
	if (c <= 1)
		return (0);
	convert_and_index(c, v, &d, &i);
	sorting(&sort, d, i, c);
	return (0);
}
