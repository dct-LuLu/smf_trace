/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   smf_style.cpp                                      :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/01/15 16:37:38 by jaubry--		  #+#	#+#			 */
/*   Updated: 2026/01/18 16:21:50 by jaubry--         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "smf_style.hpp"

namespace	smf_ansi
{
   	const std::string	RESET			= "\033[0m";
   	const std::string	BOLD			= "\033[1m";

   	const std::string	RED				= "\033[38;5;196m";
	const std::string	BG_RED_D		= "\033[48;5;52m";

   	const std::string	GREEN_1			= "\033[38;5;40m";
   	const std::string	GREEN_2			= "\033[38;5;34m";
   	const std::string	GREEN_3			= "\033[38;5;41m";
   	const std::string	GREEN_4			= "\033[38;5;76m";
   	const std::string	GREEN_5			= "\033[38;5;82m";
	const std::string	BG_GREEN_D		= "\033[48;5;22m";

	const std::string	BLUE_1			= "\033[38;5;33m";
	const std::string	BLUE_2			= "\033[38;5;32m";
	const std::string	BLUE_3			= "\033[38;5;34m";
	const std::string	BG_BLUE_D		= "\033[48;5;17m";

	const std::string	PURPLE			= "\033[38;5;177m";
	const std::string	BG_PURPLE_D		= "\033[48;5;97m";
	

	const std::string	DTOR_FG			= RED;

	const std::string	CTOR_FG			= GREEN_1;
	const std::string	CTOR_DFLT_FG	= GREEN_2;
	const std::string	CTOR_SUB_FG		= GREEN_3;
	const std::string	CTOR_COPY_FG	= GREEN_4;
	const std::string	CTOR_MOVE_FG	= GREEN_5;	

	const std::string	ASSIGN_FG		= BLUE_1;
	const std::string	ASSIGN_SUB_FG	= BLUE_2;
   	const std::string	ASSIGN_MOVE_FG	= BLUE_3;

	const std::string	FUNC_FG			= PURPLE;
};

const std::string fg_from_kind(kind::KindTypes k)
{
	switch (k) {
	case (kind::DEFAULT_CTOR):
		return (smf_ansi::CTOR_DFLT_FG);

	case (kind::CTOR):
		return (smf_ansi::CTOR_FG);

	case (kind::COPY_CTOR):
		return (smf_ansi::CTOR_COPY_FG);

	case (kind::MOVE_CTOR):
		return (smf_ansi::CTOR_MOVE_FG);

	case (kind::DTOR):
		return (smf_ansi::DTOR_FG);

	case (kind::ASSIGN):
		return (smf_ansi::ASSIGN_FG);

	case (kind::COPY_ASSIGN):
		return (smf_ansi::ASSIGN_SUB_FG);

	case (kind::MOVE_ASSIGN):
		return (smf_ansi::ASSIGN_MOVE_FG);

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
		return (smf_ansi::BG_BLUE_D);

	case (kind::FUNC):
	case (kind::COUNT):
		break;
	}
	return (smf_ansi::BG_PURPLE_D);
}

const std::string	pad_right(const std::string& str, std::size_t width)
{
	std::string	result;

	for (std::size_t i = str.size(); i < width; i++)
		result += ' ';
	return (result);
}
