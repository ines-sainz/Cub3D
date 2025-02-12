/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:06:21 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/12 10:06:23 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	errors(char	*str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	return (1);
}

void	free_structure(t_game *game)
{
	int i;

	i = 0;
	if (game->textures)
	{
		if (game->textures->north)
			free(game->textures->north);
		if (game->textures->south)
			free(game->textures->south);
		if (game->textures->east)
			free(game->textures->east);
		if (game->textures->west)
			free(game->textures->west);
		free(game->textures);
	}
	if (game->everything)
	{
		while (game->everything[i])
			free(game->everything[i++]);
		free(game->everything);
	}
}

void	init_structure(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->textures = ft_calloc(1, sizeof(t_textures));
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (errors("Add only one argument ended in .cub\n"));
	init_structure(&game);
	if (parse(&game, argv[1]) == 1)
	{
		free_structure(&game);
		return (1);
	}
	int i = 0;
	printf("everything:\n");
	while (game.everything[i])
	{
		printf("%i: %s\n", i, game.everything[i]);
		i++;
	}
	printf("map_width : %i map_height: %i\n", game.map_width, game.map_height);
	printf("player_x : %i player_y: %i\n", game.player_x, game.player_y);
	printf("textures: %s\n",game.textures->north);
	printf("textures: %s\n",game.textures->south);
	printf("textures: %s\n",game.textures->east);
	printf("textures: %s\n",game.textures->west);
	free_structure(&game);
}
