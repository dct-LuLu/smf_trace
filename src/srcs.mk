# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 17:40:06 by jaubry--          #+#    #+#              #
#    Updated: 2026/01/15 18:58:50 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= smf_detect.cpp \
		  smf_parsing.cpp \
		  smf_style.cpp \
		  smf_kind.cpp \
		  smf_trace.cpp
SRCS	:= $(addprefix $(SRCDIR)/, $(SRCS))

vpath %.cpp $(SRCDIR)
