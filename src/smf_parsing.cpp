/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   smf_parsing.cpp                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/01/15 17:15:01 by jaubry--		  #+#	#+#			 */
/*   Updated: 2026/01/15 20:53:21 by jaubry--         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "smf_parsing.hpp"

std::string	find_class_name(const std::string& str_func)
{
	const std::string::size_type	open = str_func.find('(');
	const std::string::size_type	class_end = str_func.rfind("::", open);
	std::string::size_type			class_start;
	char							c;

	if ((open == std::string::npos) || (class_end == std::string::npos))
		return (std::string());
	class_start = class_end;
	while (class_start > 0)
	{
		c = str_func[class_start - 1];
		if ((c == ' ') || (c == '&') || (c == '*') || (c == ':'))
			break ;
		--class_start;
	}
	return (str_func.substr(class_start, class_end - class_start));
}
