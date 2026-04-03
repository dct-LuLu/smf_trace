/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   smf_parsing.cpp                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/01/15 17:15:01 by jaubry--		  #+#	#+#			 */
/*   Updated: 2026/04/03 15:53:58 by jaubry--         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "smf_parsing.hpp"

std::string	find_class_name(const std::string& str_func)
{
	const std::string::size_type	open = str_func.find('(');
	const std::string::size_type	class_end = str_func.rfind("::", open);
	std::string::size_type			class_start;
	char							c;
	size_t							template_num;

	if ((open == std::string::npos) || (class_end == std::string::npos))
		return (std::string());
	template_num = 0;
	class_start = class_end;
	while (class_start > 0)
	{
		c = str_func[class_start - 1];
		if (c == '>')
			template_num += 1;
		else if (c == '<')
			template_num -= 1;
		if ((template_num == 0) && ((c == ' ') || (c == '&') || (c == '*') || (c == ':')))
			break ;
		--class_start;
	}
	return (str_func.substr(class_start, class_end - class_start));
}
