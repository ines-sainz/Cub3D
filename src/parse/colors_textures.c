/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:22:33 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/14 17:22:35 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

/*int	check_texture(char **texture, t_game *game)
{
	if (ft_strncmp(texture[0], "NO", 2) && ft_strlen(texture) == 2)
	{
		if (!texture[1] || texture[2])
			return (errors("Textures aren't written correctly\n"));
		game->textures->north = ft_strdup(texture[1]);
	}
	if (ft_strncmp(texture[0], "SO", 2) && ft_strlen(texture) == 2)
	{
		if (!texture[1] || texture[2])
			return (errors("Textures aren't written correctly\n"));
		game->textures->south = ft_strdup(texture[1]);
	}
	if (ft_strncmp(texture[0], "EA", 2) && ft_strlen(texture) == 2)
	{
		if (!texture[1] || texture[2])
			return (errors("Textures aren't written correctly\n"));
		game->textures->east = ft_strdup(texture[1]);
	}
	if (ft_strncmp(texture[0], "WE", 2) && ft_strlen(texture) == 2)
	{
		if (!texture[1] || texture[2])
			return (errors("Textures aren't written correctly\n"));
		game->textures->west = ft_strdup(texture[1]);
	}
	return (0);
}*/

/*int	check_line(char *temp, char **texture, t_game *game)
{
	static int	line_break = 0;
	static int	map = 0;

	if ((temp[0] == ' ' && (!texture || !*texture)) || texture[0] == '1'
		|| texture[0] == '0')
		map = 1;
	if (temp[0] == '\n' && map == 1)
		line_break++;
	if (ft_strncmp(texture[0], "NO", 2) && ft_strlen(temp) == 2)
		return(check_texture(texture, game));
	if (ft_strncmp(texture[0], "SO", 2) && ft_strlen(temp) == 2)
		return(check_texture(texture, game));
	if (ft_strncmp(texture[0], "EA", 2) && ft_strlen(temp) == 2)
		return(check_texture(texture, game));
	if (ft_strncmp(texture[0], "WE", 2) && ft_strlen(temp) == 2)
		return(check_texture(texture, game));

}*/

/*int	set_in_struct(t_game *game)
{
	int		i;
	int		start;
	int		textures;
	char	*temp;

	i = 0;
	textures = 0;
	while (game->everything_line[i])
	{
		start = i;
		while (game->everything_line[i] && game->everything_line[i] != '\n')
			i++;
		temp = ft_substr(game->everything_line, start, i - start + 1);
		if (check_line(temp, ft_split(temp, ' '), game) == 1)
			return (free(temp), 1);
		//printf("line(%zu) = %s", ft_strlen(temp), temp);
		free(temp);
		i++;
	}
	return (0);
}*/

/*int	open_save_all(char *argv, t_game *game, int n_bytes)
{
	int		fd;
	char	*temp;
	char	*buffer;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (errors("Can't open .cub file\n"));
	buffer = ft_calloc(101, sizeof(char));
	if (!buffer)
		return (errors("Can't open .cub file\n"));
	while (n_bytes)
	{
		n_bytes = read(fd, buffer, 100);
		if (n_bytes < 0)
			return (free(buffer), errors("Can't read .cub file\n"));
		buffer[n_bytes] = '\0';
		temp = game->everything_line;
		game->everything_line = ft_strjoin(temp, buffer);
		free(temp);
		if (!game->everything_line)
			return (free(buffer), errors("Can't read .cub file\n"));
	}
//	printf("everything line: %s", game->everything_line);
	game->everything = ft_split(game->everything_line, '\n');
	return (free(buffer), free(game->everything_line), 0);
}*/

int	check_colors(char **split_line, t_game *game)
{
	if ((!game->textures->north || !game->textures->south
			|| !game->textures->east || !game->textures->west))
	{
		return (errors("Textures aren't written correctly\n"));
	}
	if ((!ft_strncmp(split_line[0], "F", 1)
			|| !ft_strncmp(split_line[0], "C", 1))
		&& ft_strlen(split_line[0]) == 1)
	{
		if (!split_line[0] || !split_line[1] || split_line[2])
			return (errors("Colors aren't written correctly\n"));
	}
	if (!ft_strncmp(split_line[0], "C", 1) && ft_strlen(split_line[0]) == 1)
		game->textures->celing[3] = 255;
	if (!ft_strncmp(split_line[0], "F", 1) && ft_strlen(split_line[0]) == 1)
		game->textures->floor[3] = 255;
	return (0);
}

int	set_texture(char **splitted, t_game *game)
{
	if (((!ft_strncmp(splitted[0], "NO", 2)
				|| !ft_strncmp(splitted[0], "SO", 2)
				|| !ft_strncmp(splitted[0], "EA", 2)
				|| !ft_strncmp(splitted[0], "WE", 2))
			&& ft_strlen(splitted[0]) == 2)
		|| ((!ft_strncmp(splitted[0], "F", 1)
				|| !ft_strncmp(splitted[0], "C", 1))
			&& ft_strlen(splitted[0]) == 1))
	{
		if (!splitted[0] || !splitted[1] || splitted[2])
			return (free_matrix(splitted), errors("Incorrect textures\n"));
	}
	if (!ft_strncmp(splitted[0], "NO", 2) && ft_strlen(splitted[0]) == 2)
		game->textures->north = ft_strdup(splitted[1]);
	else if (!ft_strncmp(splitted[0], "SO", 2) && ft_strlen(splitted[0]) == 2)
		game->textures->south = ft_strdup(splitted[1]);
	else if (!ft_strncmp(splitted[0], "EA", 2) && ft_strlen(splitted[0]) == 2)
		game->textures->east = ft_strdup(splitted[1]);
	else if (!ft_strncmp(splitted[0], "WE", 2) && ft_strlen(splitted[0]) == 2)
		game->textures->west = ft_strdup(splitted[1]);
	else if (check_colors(splitted, game) == 1)
		return (free_matrix(splitted), 1);
	return (free_matrix(splitted), 0);
}

int	check_textures(t_game *game)
{
	int		i;
	char	**split_textures;

	i = 0;
	split_textures = ft_split(game->is_texture, '\n');
	while (split_textures[i])
	{
		if (set_texture(ft_split(split_textures[i], ' '), game) == 1)
			return (free_matrix(split_textures), 1);
		i++;
	}
	if (!game->textures->celing[3] || !game->textures->floor[3])
		return (free_matrix(split_textures), errors("Not celing or floor\n"));
	if (!game->is_map)
		return (free_matrix(split_textures), errors("Map not added\n"));
	return (free_matrix(split_textures), 0);
}
