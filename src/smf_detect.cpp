/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smf_detect.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:22:00 by jaubry--          #+#    #+#             */
/*   Updated: 2026/04/03 15:52:51 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smf_kind.hpp"
#include "smf_parsing.hpp"

static kind::KindTypes detect_dtor(const std::string& str_func, const std::string&)
{
	if (str_func.find("::~") != std::string::npos)
		return (kind::DTOR);
	return (kind::FUNC);
}

static kind::KindTypes detect_assign(const std::string& str_func, const std::string&)
{
	
	if (str_func.find("operator=") != std::string::npos)
	{
		if ((str_func.find("const ") != std::string::npos)
			&& (str_func.find("&") != std::string::npos))
			return (kind::COPY_ASSIGN);
		if (str_func.find("&&") != std::string::npos)
			return (kind::MOVE_ASSIGN);
		return (kind::ASSIGN);
	}
	return (kind::FUNC);
}

static kind::KindTypes detect_ctor(const std::string& str_func, const std::string& class_name)
{
	const std::string	stripped_class_name = class_name.substr(0, class_name.find('<'));
	const std::string	ctor_pattern = class_name + "::" + stripped_class_name;
	const std::string	ccopy_pattern = "(const " + class_name + " &)";
	const std::string	copy_pattern = "(" + class_name + " &)";
	const std::string	move_pattern = "(" + class_name + " &&)";

	if (str_func.find(ctor_pattern) == std::string::npos)
		return (kind::FUNC);
	else if (str_func.find("()") != std::string::npos)
		return (kind::DEFAULT_CTOR);
	else if ((str_func.find(ccopy_pattern) != std::string::npos)
			|| (str_func.find(copy_pattern) != std::string::npos))
		return (kind::COPY_CTOR);
	else if (str_func.find(move_pattern) != std::string::npos)
		return (kind::MOVE_CTOR);
	return (kind::CTOR);
}

kind::KindTypes	detect_kind(const std::string& str_func, const std::string& class_name)
{
	kind::KindTypes	(*detectors[3])(const std::string&, const std::string&) =
	{
		&detect_dtor,
		&detect_assign,
		&detect_ctor
	};
	kind::KindTypes	kind;

	if (class_name.empty() == true)
		return (kind::FUNC);
	for (std::size_t i = 0; i < 3; i++)
	{
		kind = detectors[i](str_func, class_name);
		if (kind != kind::FUNC)
			return (kind);
	}
	return (kind::FUNC);
}
