/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:23:42 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/28 14:46:38 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

#include <iostream>
#include <fstream>
#include <string>

class File
{
	private:
		std::string FileName;
		std::string ToFind;
		std::string ToReplace;
		std::ifstream OriginalFile;
		std::ofstream NewFile;

	public:
		File(char **argv);
		~File ();
		bool OpenFiles();
		void ProcessFiles();
		int	CheckArgs( void );
};

#endif
