/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:48:15 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/03 13:52:05 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define LIGHT_RED     "\x1b[91m"
#define LIGHT_GREEN   "\x1b[92m"
#define LIGHT_YELLOW  "\x1b[93m"
#define LIGHT_BLUE    "\x1b[94m"
#define LIGHT_MAGENTA "\x1b[95m"
#define LIGHT_CYAN    "\x1b[96m"
#define RESET   "\x1b[0m"

#include <iostream>
#include <string>

class WrongCat
{
	private:

	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
};

#endif
