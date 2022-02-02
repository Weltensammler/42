#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_windat
{
	void	*mlx;
	void	*mlx_win;
	void	*img_wall;
	void	*img_char;
	void	*img_item;
	void	*img_floor;
	void	*img_exit;
	char	*relative_path_wall;
	char	*relative_path_char;
	char	*relative_path_item;
	char	*relative_path_floor;
	char	*relative_path_exit;
	int		img_width;
	int		img_height;
	int		y;
	int		x;
	int		c;
	int		l;
	int		i;
	int		j;
}	t_windat;

typedef struct s_solong
{
	char		*line;
	char		*string;
	char		**array;
	int			lines;
	int			col;
	int			fd;
}	t_solong;
//vars.img.file = lökdjföalskjg
int	countlines(char *string);
int	countcol(char *string);
int	validchar(char *string);
int	rectangle(char **array);
int	walledin(char **array, int lines, int col);
int	getmap(t_solong *vars);

#endif