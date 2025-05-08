/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:10:00 by juperez           #+#    #+#             */
/*   Updated: 2025/04/22 10:17:10 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_TIME_H
# define UTILS_TIME_H

# include <sys/time.h>

long	get_time(void);
float	delta_time(long time, long old_time);
float	fps(float delta_time);

#endif
