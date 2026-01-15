/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smf_trace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:10:41 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/15 19:23:34 by jaubry--         ###   ########.fr       */
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
	const std::string		padding = pad_right(class_name + kind_name, padding_size);

	std::cout	<< fg << bg << smf_ansi::BOLD 
				<< class_name
				<< smf_ansi::RESET << fg << " "
				<< kind_name
				<< padding 
				<< str_func
				<< smf_ansi::RESET << std::endl;
}
