/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smf_trace.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:07:24 by jaubry--          #+#    #+#             */
/*   Updated: 2026/01/15 17:47:58 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMF_TRACE_HPP
# define SMF_TRACE_HPP

# include <iostream>
# include <string>

# ifndef SMF_LVL
#  define SMF_LVL 0
# endif

# if (!defined(__GNUC__) && !defined(__clang__))
#  define SMF_LVL 0
# endif

# if (SMF_LVL == 0)
#  define SMF_TRACE() do { } while (0)
# else
void	smf_trace(const std::string& str_func);
#  define SMF_TRACE() ::smf_trace(std::string(__PRETTY_FUNCTION__))
# endif

#endif//SMF_TRACE_HPP
