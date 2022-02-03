#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_solong
{
	char	*line;
	char	*string;
	char	**array;
	int		lines;
	int		col;
	int		fd;
	int		x;
	int		y;
	int		pl_x;
	int		pl_y;
	int		player_moves;
	int		ccount;
	void	*mlx;
	void	*win;
	void	*wa;
	void	*pl;
	void	*it;
	void	*fl;
	void	*ex;
}	t_solong;

//vars.img.file = lökdjföalskjg

int		countlines(char *string);
int		countcol(char *string);
int		validchar(char *string);
int		rectangle(char **array);
int		walledin(char **array, int lines, int col);
void	find_player(t_solong *vars);
int		get_map(t_solong *vars);
void	draw_map(t_solong *vars);
void	load_images(t_solong *vars);
void	load_img_wall(t_solong *vars);
void	load_img_player(t_solong *vars);
void	load_img_item(t_solong *vars);
void	load_img_floor(t_solong *vars);
void	load_img_exit(t_solong *vars);
void	endgame(t_solong *vars);
void	imagefail(void);

#endif