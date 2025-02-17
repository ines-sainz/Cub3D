/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:06:36 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/12 10:06:37 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

int	parse(t_game *game, char *argv)
{
	if (check_cub(argv) == 1)
		return (1);
	if (open_save_all(argv, game, 0) == 1)
		return (1);
	if (check_textures(game) == 1)
		return (1);
	if (check_map(game) == 1)
		return (1);
	if (rectangular_map(game) == 1)
		return (1);
	if (check_rectangle(game) == 1)
		return (1);
	return (0);
}
