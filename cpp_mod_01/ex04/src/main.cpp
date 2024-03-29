/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:34:33 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/29 09:23:43 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

bool File::OpenFiles( void )
{
	OriginalFile.open(FileName.c_str());
	if (!OriginalFile.is_open())
	{
		std::cerr << "Failed to open [ " << FileName << " ]!" << std::endl;
		return (false);
	}
	std::string NewFileName = FileName + ".replace";
	NewFile.open(NewFileName.c_str());
	if (!NewFile.is_open())
	{
		std::cerr << "New file failed to open." << std::endl;
		return (false);
	}
	return (true);
}

void File::ProcessFiles( void )
{
	std::string line;
	while (getline(OriginalFile, line))
	{
		size_t	position = 0;
		while ((position = line.find(ToFind, position)) != std::string::npos)
		{
			line.replace(position, ToFind.length(), ToReplace);
			position += ToReplace.length();
		}
		NewFile << line << std::endl;
	}
	if (std::cin.fail())
		std::cerr << "Read error." << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Incorrect args!" << std::endl;
		return (1);
	}
	File instance(argv);
	if (instance.CheckArgs() == 1)
		return (1);
	if (!instance.OpenFiles())
		return (2);
	instance.ProcessFiles();
	return (0);
}
