/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:35:35 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/07 12:54:46 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "Utils.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define MaxTemplates 4

class AMateria;

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _Templates[MaxTemplates];

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);

		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};

#endif
