/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:08:23 by geonwkim          #+#    #+#             */
/*   Updated: 2024/09/06 19:08:23 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifdef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);

#endif
