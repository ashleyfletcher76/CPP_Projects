/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:29:25 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/19 14:26:48 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signature;
		const int			_requiredGradeMin;
		const int			_executeGrade;


	public:
		AForm();
		~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		AForm(const std::string &name, int requiredGradeMin, int executeGrade);
		std::string	getName() const;
		int			getRequiredGradeToSign() const;
		int			getRequiredGradeToExecute() const;

		void		beSigned(Bureaucrat& bureaucrat);
		void		setSignature();
		void		checkSigned();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif
