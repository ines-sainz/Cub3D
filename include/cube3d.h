/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:06:10 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/12 10:06:13 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# include <stdint.h>
# include <limits.h>
# include <stdio.h> //printf, perror
# include <stdlib.h> //malloc, free, exit
# include <unistd.h> //close, read, write
# include <fcntl.h> //open
# include <string.h> //strerror
# include <sys/time.h> //gettimeofday
# include <math.h>

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor[3];
	int		celing[3];
}			t_textures;

typedef struct s_game
{
	char		*everything_line;
	char		**everything;
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	t_textures	*textures;
}				t_game;

//MAIN
int	errors(char	*str);

//PARSE
int	parse(t_game *game, char *argv);

#endif