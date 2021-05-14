/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:43:04 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/14 17:51:20 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_opengl/mlx.h"

/*
**	DEFINES
*/

# define MAXRES_X 2560
# define MAXRES_Y 1440
# define DEFAULT_TILE_SIZE 32
# define SCALE 64
# define FOV 60
# define ESCAPE_KEY 53
# define LEFT_ARR_KEY 123
# define RIGHT_ARR_KEY 124
# define UP_ARR_KEY 126
# define DOWN_ARR_KEY 125
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
enum	e_error_msg
{
	NO_CUB_FILE_TYPE,
	INVALID_FILE,
	NOT_ENOUGH_ARGS,
	TOO_MANY_ARGS,
	INVALID_FLAG,
	OPEN_ERR,
	READ_ERR,
	RES_ERR,
	INVALID_PATH_CHR,
	RGB_ERR,
	OVERWRITE_ERR,
	DATA_ERR,
	MAP_ERR
};
# define NO_ERROR -1
# define TRUE 1
# define FALSE 0

/*
**	GAME STRUCTS
*/

typedef struct s_keys
{
	t_bool	w;
	t_bool	a;
	t_bool	s;
	t_bool	d;
	t_bool	l_arr;
	t_bool	r_arr;
	t_bool	u_arr;
	t_bool	d_arr;
}			t_keys;

typedef struct s_image
{
	void	*ptr;
	int		*addr;
	int		bpp;
	int		line_len;
	int		end;
}			t_image;

typedef struct s_col
{
	int		r;
	int		g;
	int		b;
	int		argb;
}			t_col;

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_ray
{
	t_point	pos;
	double	len;
	double	angle;
	t_point	step;
	char	dir;
	char	side;
	char	obst;
}			t_ray;

typedef struct s_rays
{
	t_ray	*array;
	double	fov;
	double	dist_proj_plane;
}			t_rays;

typedef struct s_text
{
	char	*path;
	t_image	img;
	int		img_w;
	int		img_h;
}			t_text;

typedef struct s_sprite
{
	t_point	pos;
	t_text	text;
	double	dist;
	double	rotation;
	t_bool	is_visible;
}			t_sprite;

typedef struct s_scene
{
	char		*gnl;
	t_text		n_text;
	t_text		s_text;
	t_text		w_text;
	t_text		e_text;
	t_text		sprite;
	int			sprite_count;
	int			floor_col;
	int			ceil_col;
	t_sprite	*sprites;
}				t_scene;

typedef struct s_map
{
	int		x;
	int		y;
	int		x_off;
	int		y_off;
	int		tile_size;
	int		max_x;
	int		max_y;
	char	player_dir;
	char	**grid;
}			t_map;

typedef struct s_player
{
	t_point	map_pos;
	t_point	grid_pos;
	t_point	delta;
	double	angle;
}			t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		win_h;
	int		win_w;
	t_image	img;
}			t_mlx;

/*
**	GRAPH STRUCTS
*/

typedef struct s_rect
{
	int		x;
	int		y;
	double	width;
	double	height;
	int		fill_col;
	t_text	tex;
}			t_rect;

typedef struct s_triangle
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
	int		fill_col;
}			t_triangle;

typedef struct s_circle
{
	int		x;
	int		y;
	double	radius;
	int		fill_col;
}			t_circle;

typedef struct s_line
{
	double	start_x;
	double	start_y;
	double	end_x;
	double	end_y;
	int		colour;
	int		width;
}			t_line;

/*
**	MASTER STRUCT
*/

typedef struct s_data
{
	t_mlx		m;
	t_keys		key;
	t_scene		sc;
	t_map		mp;
	t_player	pl;
	t_rays		rays;
}				t_data;

/*
**		PROTOTYPES
*/

/*
**	MATH
*/

double	area_triangle_bh(t_point p1, t_point p2, t_point p3);
float	area_triangle_pyth(t_point p1, t_point p2, t_point p3);
t_bool	ft_is_in_rect_triangle(t_point px, t_point p1, t_point p2, t_point p3);
t_bool	ft_is_in_triangle(t_point px, t_point p1, t_point p2, t_point p3);
double	ft_max(double a, double b, double c);
double	ft_min(double a, double b, double c);
double	degree_to_radian(double degrees);
double	radian_to_degree(double radian);
double	radian_within_circle(double radian);
int		create_inverse_trgb(int colour);
int		create_trgb(int t, int r, int g, int b);

/*
**	PARSING
*/

int		get_colour(int	floor_col, char gridchar);
void	ft_error_handling(int errnum);
void	parse_file(t_data *d, char *filename);
void	free_matrix(char ***split);
void	process_reso(t_data *d);
void	process_texture(t_data *d, char *text_name);
void	process_floor_ceil(t_data *d, char *name);
int		process_map(t_data *d, int fd, int retval);
int		create_matrix(t_data *d, t_list *game_map);

/*
**	DRAWING
*/

void	fill_circle(t_circle *circle, int *imgaddr, int screen_width);
void	fill_rect(t_rect *rect, int *imgaddr, int screen_width);
void	fill_rect_triangle(t_image *img, int width, int height, int colour);
void	fill_triangle(t_triangle *tri, int *imgaddr, int screen_width);
void	fill_minimap(t_data *d);
void	draw_line(t_line *line, int *imgaddr, int screen_width);
void	draw_rays(t_data *d);
void	draw_ceiling(t_data *d);
void	draw_floor(t_data *d);
void	draw_walls(t_data *d);

/*
**	GAME
*/

void	game_data_init(t_data *d, char *cubfilename);
void	setup_player_data(t_data *d, int x, int y);
void	init_texts_rays(t_data *d);
void	init_sprites(t_data *d);
int		*image_data(t_image *i);
void	flush_data(t_data *d, int errnum, t_bool totalclean);
void	destroy_image(t_image *i, void *mlx);
int		close_window(t_data *d);
int		key_press(int keycode, t_data *d);
int		key_release(int keycode, t_data *d);
void	movement(t_data *d);
void	refresh_screen(t_data *d);
void	refresh_player(t_data *d);
void	cast_rays(t_data *d);
void	refresh_sprites(t_data *d);

/*
**	RAYCASTING
*/

t_bool	is_facing_south(double angle);
t_bool	is_facing_west(double angle);
char	get_wall_dir(t_ray *ray, t_map *map, int x, int y);
t_bool	is_wall(t_ray *ray, t_map *map, double x, double y);
void	get_horiz_intersect_south(t_ray *ray, t_map *map, t_player *play);
void	get_horiz_intersect_north(t_ray *ray, t_map *map, t_player *play);
void	get_vert_intersect_east(t_ray *ray, t_map *map, t_player *play);
void	get_vert_intersect_west(t_ray *ray, t_map *map, t_player *play);
void	get_shortest_ray_len(t_ray *ray, t_map *map, t_player *play);

#endif