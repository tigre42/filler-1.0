/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigre <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:02:32 by tigre             #+#    #+#             */
/*   Updated: 2019/02/12 14:39:24 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		print_result(t_struct s)
{
	ft_putnbr(s.y_sol - s.min_yp);
	write(1, " ", 1);
	ft_putnbr(s.x_sol - s.min_xp);
	write(1, "\n", 1);
}

static void		free_tabs(t_struct *s)
{
	int			i;

	i = 0;
	while (i < s->h_map)
		free(s->map[i++]);
	free(s->map);
	i = 0;
	while (i < s->h_piece)
		free(s->piece[i++]);
	free(s->piece);
}

int				main(void)
{
	char		*line;
	t_struct	s;

	line = NULL;
	get_player_info(&s, line);
	while (1)
	{
		get_map_info(&s, line);
		gen_map(&s, line);
		get_piece(&s, line);
		weight_filler(&s);
		if (find_pos(&s) < 1)
			break ;
		print_result(s);
		free_tabs(&s);		
	}
	write(1, "0 0\n", 4);
	free_tabs(&s);
	return (0);
}
