/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:43:48 by asirenko          #+#    #+#             */
/*   Updated: 2019/03/10 20:08:40 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# define BUFF_SIZE 100
# define DESCRIPTORS 4864
# define MALCHECKI(x) if (!x) return(-1);
# define MALCHECKC(x) if (!x) return(0);
# define MALCHECKV(x) if (!x) return ;

int				get_next_line(const int fd, char **line);

#endif
