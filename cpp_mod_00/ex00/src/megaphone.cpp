/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:27:06 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/23 09:27:42 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	ToUpper(char *str)
{
	for(int i = 0; str[i] != '\0'; i++)
		str[i] = std::toupper(str[i]);
	std::cout <<  str << "";
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for(int i = 1; i < argc; i++)
		{
			ToUpper(argv[i]);
			std::cout << std::endl;
		}
	}
	return (0);
}
