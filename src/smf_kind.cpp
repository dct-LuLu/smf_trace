/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smf_kind.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:55:25 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/15 19:00:21 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smf_trace.hpp"
#include "smf_kind.hpp"

namespace	kind
{
	const std::string	names[kind::COUNT] =
	{
# if (SMF_LVL == 1)
		"funcion",
		"default constructor",
		"constructor",
		"destructor",
		"copy constructor",
		"copy assignment",
		"move constructor",
		"move assignment",
		"assignment"
# else
		"func",
		"default-ctor",
		"ctor",
		"dtor",
		"copy-ctor",
		"copy-assign",
		"move-ctor",
		"move-assign",
		"assign"
# endif
	};

	const std::string&	get_kind_name(kind::KindTypes kind)
	{
		return (names[static_cast<int>(kind)]);
	}
}
