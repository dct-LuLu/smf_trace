/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smf_trace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:10:41 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/15 21:10:22 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smf_trace.hpp"
#include "smf_kind.hpp"
#include "smf_style.hpp"
#include "smf_parsing.hpp"

void	smf_trace(const std::string& str_func)
{
	if ((SMF_LVL != 1) && (SMF_LVL != 2))
		return ;
	const std::string		class_name = find_class_name(str_func);
	const kind::KindTypes	kind = detect_kind(str_func, class_name);
	const std::string		kind_name = get_kind_name(kind);

	const std::size_t		padding_size = (30 / SMF_LVL) + 15;
	const std::string		fg = fg_from_kind(kind);
	const std::string		bg = bg_from_kind(kind);
	std::string				padding;

	if (SMF_LVL == 1)
		padding = pad_right(class_name + kind_name, padding_size);
	else if (SMF_LVL == 2)
		padding = pad_right(class_name, padding_size / 2);

	std::cout	<< fg << bg << smf_ansi::BOLD 
				<< class_name
				<< smf_ansi::RESET << fg
#if (SMF_LVL == 2)
				<< padding
#else
				<< " "
#endif
				<< kind_name
#if (SMF_LVL == 1)
				<< padding
				<< str_func
#endif
				<< smf_ansi::RESET << std::endl;
}
