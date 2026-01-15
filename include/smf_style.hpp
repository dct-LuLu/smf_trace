/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smf_style.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:48:10 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/15 17:46:22 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMF_STYLE_HPP
# define SMF_STYLE_HPP

# include "smf_kind.hpp"
# include <string>

namespace	smf_ansi
{
   	extern const std::string	RESET;
   	extern const std::string	BOLD;

   	extern const std::string	RED_256;
   	extern const std::string	YELLOW_256;
   	extern const std::string	GREEN_256;
   	extern const std::string	CYAN_256;
	extern const std::string	BLUE_256;
	extern const std::string	ORANGE_256;
	extern const std::string	PURPLE_256;
	extern const std::string	WHITE_256;

	extern const std::string	BG_GREEN_D;
	extern const std::string	BG_RED_D;
	extern const std::string	BG_AMBER_D;
	extern const std::string	BG_BLUE_D;
	
	extern const std::string	CTOR_FG;
	extern const std::string	CTOR_SUB;
	extern const std::string	CTOR_COPY;
	extern const std::string	CTOR_MOVE;
	
	extern const std::string	DTOR_FG;

	extern const std::string	ASSIGN_FG;
	extern const std::string	ASSIGN_SUB;
   	extern const std::string	ASSIGN_MOVE;

	extern const std::string	FUNC_FG;
};

const std::string	pad_right(const std::string& s, std::size_t width);

const std::string	fg_from_kind(kind::KindTypes kind);
const std::string	bg_from_kind(kind::KindTypes kind);

#endif//SMF_STYLE_HPP
