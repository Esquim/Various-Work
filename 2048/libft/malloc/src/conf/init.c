/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/05/04 17:54:10 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ft_malloc.h"
#include <libft.h>

static bool	check_other_param(char *tmp, t_cfg *cfg)
{
	if (ft_strncmp(tmp, "PA", 2) == 0)
		cfg->print_allocated = true;
	else if (ft_strncmp(tmp, "PU", 2) == 0)
		cfg->print_unallocated = true;
	else if (ft_strncmp(tmp, "PB", 2) == 0)
		cfg->print_nb_blocks = true;
	else if (ft_strncmp(tmp, "PM", 2) == 0)
		cfg->print_max_nb_blocks = true;
	else if (ft_strncmp(tmp, "O1", 2) == 0)
		cfg->algo_type = FIRST_FIT;
	else if (ft_strncmp(tmp, "O2", 2) == 0)
		cfg->algo_type = BEST_FIT;
	else
		return (false);
	return (true);
}

static bool	check_param(char *tmp, t_cfg *cfg)
{
	if (ft_strncmp(tmp, "EN", 2) == 0)
		cfg->log_level = NOTHING;
	else if (ft_strncmp(tmp, "ED", 2) == 0)
		cfg->log_level = DEBUG;
	else if (ft_strncmp(tmp, "EI", 2) == 0)
		cfg->log_level = INFO;
	else if (ft_strncmp(tmp, "EW", 2) == 0)
		cfg->log_level = WARNING;
	else if (ft_strncmp(tmp, "EE", 2) == 0)
		cfg->log_level = ERROR;
	else if (ft_strncmp(tmp, "EA", 2) == 0)
		cfg->log_level = ALL;
	else if (ft_strncmp(tmp, "AE", 2) == 0)
		cfg->abort_error = true;
	else if (ft_strncmp(tmp, "IB", 2) == 0)
		cfg->init_block = true;
	else if (ft_strncmp(tmp, "LM", 2) == 0)
		cfg->abort_on_low_memory = true;
	else
		return (check_other_param(tmp, cfg));
	return (true);
}

static void	init_by_conf(int fd, t_cfg *cfg)
{
	char	tmp[3];

	while (read(fd, tmp, 3) == 3)
	{
		if (IS_UPPER(tmp[0]))
			if (check_param(tmp, cfg) == false)
				return ;
	}
}

static void	init_by_env(t_cfg *cfg)
{
	const char	*value;

	value = getenv("MALLOC_CHECK");
	if (value && strcmp(value, "0") != 0)
		cfg->log_level = WARNING;
}

void		ft_conf_init(t_ctx *ctx)
{
	int		fd;

	if ((fd = open(FT_MALLOC_CONF_PATH, O_RDONLY)) > 0)
	{
		init_by_conf(fd, &(ctx->cfg));
		close(fd);
	}
	init_by_env(&(ctx->cfg));
}
