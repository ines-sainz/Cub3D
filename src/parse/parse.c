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

int	check_character(char c, int i, int j, t_game *game)
{
	if (!ft_strchr("1 0NSEW", c))
		return (errors("Character not valid\n"));
	if ((i == 0 || j == 0 || i == game->map_height - 1) && c != '1' && c != ' ')
		return (errors("Map not surrounded by 1\n"));
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (game->player_x != 0 || game->player_y != 0)
			return (errors("More than one player\n"));
		game->player_y = i;
		game->player_x = j;
		game->player_dir = c;
	}
	if (game->map_width <= j)
		game->map_width = j + 1;
	return (0);
}

int	check_map(t_game *game)
{
	char	**temp_map;
	int		i;
	int		j;

	temp_map = ft_split(game->is_map, '\n');
	while (temp_map[game->map_height])
		game->map_height++;
	i = 0;
	while (temp_map[i])
	{
		j = 0;
		while (temp_map[i][j])
		{
			if (check_character(temp_map[i][j], i, j, game) == 1)
				return (free_matrix(temp_map), 1);
			j++;
		}
		if (temp_map[i][j - 1] != '1' && temp_map[i][j - 1] != ' ')
			return (free_matrix(temp_map), errors("Map not surrounded by 1\n"));
		i++;
	}
	if (game->player_x == 0 || game->player_y == 0)
		return (free_matrix(temp_map), errors("The player isn't correct\n"));
	return (free_matrix(temp_map), 0);
}

int	rectangular_map(t_game *game)
{
	game->map = ft_calloc(game->map_height + 1, sizeof(char *));
	if (!game->map)
		return (errors("Wrong map\n"));
	return (0);
}

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
	return (0);
}
