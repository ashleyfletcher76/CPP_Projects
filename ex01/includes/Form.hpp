/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:29:25 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/20 12:25:12 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signature;
		const int			_requiredGradeMin;
		const int			_executeGrade;


	public:
		Form();
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		Form(const std::string &name, int requiredGradeMin, int executeGrade);
		std::string	getName() const;
		int			getRequiredGradeToSign() const;
		int			getRequiredGradeToExecute() const;

		void		beSigned(Bureaucrat& bureaucrat);
		void		setSignature();
		bool		checkSigned() const;

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

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
