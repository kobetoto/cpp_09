# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kobe <kobe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 10:21:59 by thodavid          #+#    #+#              #
#    Updated: 2026/01/29 11:37:33 by kobe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####
#Var#
#####
NAME		= btc
FLAGS		= -Wall -Wextra -Werror -std=c++98 -MMD -MP
DEP			= ($(OBJ):.o=.d)
SRCDIR		= src
OBJDIR		= obj
INCLUDES	= -I.

#####
#Src#
#####
SRC			= main BitcoinExchange
SRCS		= $(addprefix $(SRCDIR)/,$(addsuffix .cpp,$(SRC)))
OBJ			= $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

#######
#Rules#
#######
all: $(NAME)

$(NAME): $(OBJ)
		c++ $(FLAGS) $(OBJ) -o $(NAME)
		@echo "✅ ready ✅"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
		@mkdir -p $(dir $@)
		c++ $(FLAGS) $(INCLUDES) -c $< -o $@

-include $(DEP)

clean:
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
