/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:48:02 by omaly             #+#    #+#             */
/*   Updated: 2025/11/20 17:02:19 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# define COPY_XK_ESCAPE 0xff1b
# define COPY_NOEVENTMASK 0L
# define COPY_KEYPRESS 2
# define COPY_DESTRYNOTIFY 17

int	close_window(t_fdf *fdf);
int	escape_press(int keysum, t_fdf *fdf);

#endif
