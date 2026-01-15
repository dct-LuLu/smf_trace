/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   smf_style.cpp                                      :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/01/15 16:37:38 by jaubry--		  #+#	#+#			 */
/*   Updated: 2026/01/15 17:06:32 by jaubry--         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "smf_style.hpp"

namespace	smf_ansi
{
   	const std::string	RESET		= "\033[0m";
   	const std::string	BOLD		= "\033[1m";

   	const std::string	RED_256		= "\033[38;5;196m";
   	const std::string	YELLOW_256	= "\033[38;5;220m";
   	const std::string	GREEN_256	= "\033[38;5;40m";
   	const std::string	CYAN_256	= "\033[38;5;51m";
	const std::string	BLUE_256	= "\033[38;5;33m";
	const std::string	ORANGE_256	= "\033[38;5;214m";
	const std::string	PURPLE_256	= "\033[38;5;129m";
	const std::string	WHITE_256	= "\033[38;5;15m";

	const std::string	BG_GREEN_D	= "\033[48;5;22m";
	const std::string	BG_RED_D	= "\033[48;5;52m";
	const std::string	BG_AMBER_D	= "\033[48;5;94m";
	const std::string	BG_BLUE_D	= "\033[48;5;17m";
	
	const std::string	CTOR_FG		= GREEN_256;
	const std::string	CTOR_SUB	= CYAN_256;
	const std::string	CTOR_COPY	= WHITE_256;
	const std::string	CTOR_MOVE	= YELLOW_256;
	
	const std::string	DTOR_FG		= RED_256;

	const std::string	ASSIGN_FG	= ORANGE_256;
	const std::string	ASSIGN_SUB	= YELLOW_256;
   	const std::string	ASSIGN_MOVE	= PURPLE_256;

	const std::string	FUNC_FG		= BLUE_256;
};

const std::string fg_from_kind(kind::KindTypes k)
{
	switch (k) {
	case (kind::DEFAULT_CTOR):
	case (kind::CTOR):
		return (smf_ansi::CTOR_FG);

	case (kind::COPY_CTOR):
		return (smf_ansi::CTOR_COPY);

	case (kind::MOVE_CTOR):
		return (smf_ansi::CTOR_MOVE);

	case (kind::DTOR):
		return (smf_ansi::DTOR_FG);

	case (kind::ASSIGN):
		return (smf_ansi::ASSIGN_FG);

	case (kind::COPY_ASSIGN):
		return (smf_ansi::ASSIGN_SUB);

	case (kind::MOVE_ASSIGN):
		return (smf_ansi::ASSIGN_MOVE);

	case (kind::FUNC):
	case (kind::COUNT):
		break;
	}
	return (smf_ansi::FUNC_FG);
}

const std::string bg_from_kind(kind::KindTypes k)
{
	switch (k) {
	case (kind::DEFAULT_CTOR):
	case (kind::CTOR):
	case (kind::COPY_CTOR):
	case (kind::MOVE_CTOR):
		return (smf_ansi::BG_GREEN_D);

	case (kind::DTOR):
		return (smf_ansi::BG_RED_D);

	case (kind::ASSIGN):
	case (kind::COPY_ASSIGN):
	case (kind::MOVE_ASSIGN):
		return (smf_ansi::BG_AMBER_D);

	case (kind::FUNC):
	case (kind::COUNT):
		break;
	}
	return (smf_ansi::BG_BLUE_D);
}

const std::string	pad_right(const std::string& str, std::size_t width)
{
	std::string	result;

	for (std::size_t i = str.size(); i < width; i++)
		result += ' ';
	return (result);
}
