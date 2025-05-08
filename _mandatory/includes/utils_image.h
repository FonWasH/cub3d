/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:24:33 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 07:57:02 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_IMAGE_H
# define UTILS_IMAGE_H

typedef struct s_image
{
	void		*ptr;
	uint32_t	*data;
}				t_image;

t_image	new_img(void *mlx_ptr, t_vec2 size);
t_image	open_img(void *mlx_ptr, char *path);

#endif
