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
}

int	check_line(char *temp, char **texture, t_game *game)
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

}

int	set_in_struct(t_game *game)
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

int	open_save_all(char *argv, t_game *game, int n_bytes)
{
	int		fd;
	int		error;
	char	line[2];

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (errors("Can't open .cub file\n"));
	while (1)
	{
		line[0] = get_next_line(fd);
		if (!line)
			break ;
		line[1] = ft_split(line[0], ' ');
		if (set_line_in_struct(line, game, error) == 1)
			error = 1;
		printf("line = %s, split_line = %s", line[0], line[1]);
		free(line[0]);
		free(line[1]);
	}
	if (error)
		return(errors("Textures or map aren't written correctly\n"));
	return (0);
}

int	check_cub(char *argv)
{
	char	*extension;
	int		len_extension;

	len_extension = ft_strlen(argv);
	extension = ft_substr(argv, len_extension - 4, 4);
	if (!extension)
		return (errors("Add only one argument ended in .cub\n"));
	if (ft_strncmp(".cub", extension, 4) == 0
		&& len_extension > 4 && argv[len_extension - 5] != '/')
	{
		free(extension);
		return (0);
	}
	free(extension);
	return (errors("Add only one argument ended in .cub\n"));
}

int	parse(t_game *game, char *argv)
{
	(void)game;
	if (check_cub(argv) == 1)
		return (1);
	if (open_save_all(argv, game, 1) == 1)
		return (1);
//	if (set_in_struct(game) == 1)
//		return (1);
	return (0);
}
