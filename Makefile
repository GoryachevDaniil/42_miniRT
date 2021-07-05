# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 16:57:10 by mturquin          #+#    #+#              #
#    Updated: 2021/02/12 04:40:14 by mturquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

LIBMLX	=	mlx/libmlx.dylib

SRCS	:=	$(addprefix srcs/,\
			ft_bmp.c\
			ft_calc_normal.c\
			ft_check.c\
			ft_minirt.c\
			ft_parser.c\
			ft_raytracing.c\
			ft_camera.c\
			ft_light.c\
			ft_color_utils.c\
			ft_ku_objs_part_1.c\
			ft_ku_objs_part_2.c\
			ft_mlx_utils.c\
			ft_parser_obj.c\
			ft_parser_scene.c\
			ft_vector_utils_part_1.c\
			ft_vector_utils_part_2.c\
			ft_free.c)

UTILS	:=	$(addprefix utils/,\
			ft_atof.c\
			ft_bzero.c\
			ft_isalpha.c\
			ft_lstadd_back.c\
			ft_lstsize.c\
			ft_lstclear.c\
			ft_split.c\
			ft_strcmp.c\
			ft_substr.c\
			get_next_line_utils.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_isdigit.c\
			ft_lstnew.c\
			ft_putstr.c\
			ft_split_set.c\
			ft_strlen.c\
			get_next_line.c)

HEADER	:=	$(addprefix includes/,\
			t_minirt.h)

ALLOBJS	=	${SRCS} ${UTILS}

OBJS	=	${ALLOBJS:.c=.o}

CC		=	gcc -Wall -Wextra -Werror -Iincludes -Imlx 

all		:	$(NAME)

%.o		:	%.c $(HEADER)

$(LIBMLX):
			$(MAKE) -C mlx

$(NAME)	:	$(OBJS) $(LIBMLX)
			$(CC) -lmlx -framework OpenGL \
				-framework AppKit -o $(NAME) $(OBJS) $(LIBMLX)
			cp mlx/libmlx.dylib ./

clean:
			-rm -f $(OBJS)

fclean:		clean
			-rm -f $(NAME)
			-rm -f libmlx.dylib
			-rm -f *.bmp

re:			fclean all

.PHONY:		all clean fclean re
