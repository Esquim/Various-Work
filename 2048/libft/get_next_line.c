/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <apilate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 13:16:45 by apilate           #+#    #+#             */
/*   Updated: 2013/12/31 14:45:01 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

int		buffer_write(t_buffer *buf, char c)
{
	char	*newbuf;
	int		i;

	if (buf->index + 1 > buf->size)
	{
		newbuf = (char*)malloc(buf->size + READ_SIZE + 1);
		if (newbuf == NULL)
			return (-1);
		i = 0;
		while (i < buf->size)
		{
			newbuf[i] = buf->buf[i];
			i++;
		}
		if (buf->buf != NULL)
			free(buf->buf);
		buf->size += READ_SIZE;
		buf->buf = newbuf;
	}
	buf->buf[buf->index++] = c;
	buf->buf[buf->index] = 0;
	return (1);
}

char	reader_read(const int fd, t_reader *reader)
{
	char	c;

	if (reader->size == 0)
		reader->size = read(fd, reader->buf, READ_SIZE);
	if (reader->size == 0)
		return (0);
	c = reader->buf[reader->index++];
	if (reader->index >= reader->size)
	{
		reader->size = 0;
		reader->index = 0;
	}
	return (c);
}

int		init_line(char ***line, t_buffer *buffer)
{
	if (*line == NULL)
	{
		*line = (char**)malloc(sizeof(**line));
		if (*line == NULL)
			return (1);
	}
	if (buffer->buf != NULL)
	{
		**line = buffer->buf;
		(**line)[buffer->index] = '\0';
	}
	return (0);
}

void	get_next_line2(t_buffer *buffer, t_reader *reader, int c, int writed)
{
	if (c == -1 || writed == -1)
	{
		if (buffer->buf != NULL)
			free(buffer->buf);
		buffer->buf = NULL;
		reader->to_return = -1;
	}
	else if (c != 0 && buffer->size == 0)
	{
		if (buffer->buf != NULL)
			free(buffer->buf);
		buffer->buf = (char*)malloc(1);
		buffer->buf[0] = 0;
		reader->to_return = 1;
	}
	else if (c == 0 && buffer->size == 0)
	{
		if (buffer->buf != NULL)
			free(buffer->buf);
		buffer->buf = (char*)malloc(1);
		buffer->buf[0] = 0;
		reader->to_return = 0;
	}
	else
		reader->to_return = 1;
}

int		get_next_line(const int fd, char **line)
{
	static t_reader	reader = { { 0 }, 0, 0, -42, 0};
	t_buffer		buffer;
	int				writed;
	char			c;

	if (reader.fd == -42)
		reader.fd = fd;
	else if (reader.fd != fd)
	{
		ft_bzero(reader.buf, READ_SIZE);
		reader.index = 0;
		reader.size = 0;
		reader.fd = fd;
	}
	buffer.buf = NULL;
	buffer.size = 0;
	buffer.index = 0;
	writed = 1;
	while ((c = reader_read(fd, &reader)) != 0 && c != '\n'
		&& (writed = buffer_write(&buffer, c)))
		;
	get_next_line2(&buffer, &reader, c, writed);
	if (init_line(&line, &buffer))
		return (-1);
	return (reader.to_return);
}
