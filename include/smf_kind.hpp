/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smf_kind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:21:20 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/15 19:18:14 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMF_KIND_HPP
# define SMF_KIND_HPP

# include <string>

namespace	kind
{
	enum	KindTypes
	{
		FUNC = 0,
		DEFAULT_CTOR,
		CTOR,
		DTOR,
		COPY_CTOR,
		COPY_ASSIGN,
		MOVE_CTOR,
		MOVE_ASSIGN,
		ASSIGN,
		COUNT
	};

	extern const std::string	names[kind::COUNT];
	extern const std::string&	get_kind_name(kind::KindTypes kind);
};

kind::KindTypes	detect_kind(const std::string& str_func, const std::string& class_name);

#endif//SMF_KIND_HPP
