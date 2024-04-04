/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 07:00:11 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/04 10:55:28 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include "Colours.hpp"

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		void SetIdeas(std::string str);
		void GetIdeas(std::string& str);
};

#endif
