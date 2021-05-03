/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:16:42 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/03 17:25:21 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ret_error(int retval, char **line)
{
	if (retval < 0)
	{
		if (*line)
			ft_strdel(line);
		ft_error_handling(READ_ERR);
	}
}

static void	process_reso(t_data *d, char **line)
{
	char	**resolution;
	char	*tosplit;
	int		i;

	i = 1;
	while ((*line)[i])
	{
		if (!(ft_isspace((*line)[i]) || ft_isdigit((*line)[i])))
		{
			ft_strdel(line);
			ft_error_handling(RES_ERR);
		}
		i++;
	}
	//printf("The resolution line is = %s\n", *line);
	tosplit = *line + 2;
	resolution = ft_split(tosplit, ' ');
	d->mp.res.x = ft_atoi(resolution[0]);
	//printf("%s\n", resolution[0]);
	d->mp.res.y = ft_atoi(resolution[1]);
	//printf("%s\n", resolution[1]);
	i = 0;
	while (i < 2)
		ft_strdel(&resolution[i++]);
	free(resolution);
	resolution = NULL;
	if (d->mp.res.x > MAXRES_X || d->mp.res.y > MAXRES_Y)
	{
		ft_strdel(line);
		ft_error_handling(RES_OVERFLOW);
	}
}

static void	process_line(t_data *d, char **line)
{
	if (!**line)
	{
		printf("I want to delete myself\n");
		ft_strdel(line);
	}
	else if (!ft_strncmp(*line, "R", 1))
		process_reso(d, line);
	else if (!ft_strncmp(*line, "NO", 2))
	{
		printf("North texture = %s\n", *line);
	}
	else if (!ft_strncmp(*line, "SO", 2))
	{
		printf("South texture = %s\n", *line);
	}
	else if (!ft_strncmp(*line, "WE", 2))
	{
		printf("West texture = %s\n", *line);
	}
	else if (!ft_strncmp(*line, "EA", 2))
	{
		printf("South texture = %s\n", *line);
	}
	else if (!ft_strncmp(*line, "S", 1))
	{
		printf("Sprite = %s\n", *line);
	}
	else if (!ft_strncmp(*line, "F", 1))
	{
		printf("Floor = %s\n", *line);
	}
	else if (!ft_strncmp(*line, "C", 1))
	{
		printf("Ceiling = %s\n", *line);
	}
	else if (*line[0] == '\t' || *line[0] == '1')
	{
		printf("Map line\t%s\n", *line);
	}
	if (*line)
		ft_strdel(line);
}

void	parse_map(t_data *d, char *filename)
{
	int		fd;
	int		retval;
	char	*line;

	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_handling(OPEN_ERR);
	retval = get_next_line(fd, &line);
	ret_error(retval, &line);
	process_line(d, &line);
	/*printf("%s\n", line);
	if (line)
		ft_strdel(&line);*/
	while (retval)
	{
		retval = get_next_line(fd, &line);
		ret_error(retval, &line);
		process_line(d, &line);
		/*printf("%s\n", line);
		if (line)
			ft_strdel(&line);*/
	}
}
