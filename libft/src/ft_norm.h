/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:06:59 by marvin            #+#    #+#             */
/*   Updated: 2021/09/29 17:07:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NORM_H
# define FT_NORM_H

# include <stdint.h>

int8_t			ft_ternary8(int flag, int8_t a, int8_t b);
int16_t			ft_ternary16(int flag, int16_t a, int16_t b);
int32_t			ft_ternary32(int flag, int32_t a, int32_t b);
int64_t			ft_ternary64(int flag, int64_t a, int64_t b);
int8_t			ft_set8(int8_t *a, int8_t b);
int16_t			ft_set16(int16_t *a, int16_t b);
int32_t			ft_set32(int32_t *a, int32_t b);
int64_t			ft_set64(int64_t *a, int64_t b);

#endif
