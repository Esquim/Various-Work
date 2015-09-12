/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_malloc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:30:02 by apilate           #+#    #+#             */
/*   Updated: 2014/04/28 15:50:39 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_MALLOC_H
# define MACROS_MALLOC_H

# include <stddef.h>
# include <stdbool.h>
# include "struct_malloc.h"

# define FT_MALLOC_MAGIC 0x4233
# define FT_MALLOC_CONF_PATH "/etc/malloc.conf"

# define ALIGN4(x) (((((x) - 1) >> 2) << 2) + 4)

# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define MIN(a, b) ((a) <= (b) ? (a) : (b))

# define UNUSED __attribute__((unused))

# define IS_LOWER(c) ((c) >= 'a' && (c) <= 'z')
# define IS_UPPER(c) ((c) >= 'A' && (c) <= 'Z')
# define IS_ALPHA(c) (IS_LOWER(c) || IS_UPPER(c))

#endif
