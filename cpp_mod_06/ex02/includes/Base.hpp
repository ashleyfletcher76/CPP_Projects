/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:36:14 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/24 13:57:58 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <ctime>
#include <cstdlib>
#include <iostream>

class Base
{
	public:
		virtual ~Base();
};

class Test : public Base {};

Base *	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
