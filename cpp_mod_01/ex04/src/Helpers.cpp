/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:25:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/28 14:49:06 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int File::CheckArgs()
{
	if (ToFind.empty())
	{
		std::cerr << "Invalid arg!" << std::endl;
		return (1);
	}
	if (ToReplace.empty())
	{
		std::cerr << "Invalid arg!" << std::endl;
		return (1);
	}
	return (0);
}

File::File(char **argv)
{
	this->FileName = argv[1];
	this->ToFind = argv[2];
	this->ToReplace = argv[3];
}

File::~File ( void ) {}
