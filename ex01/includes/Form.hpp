/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:29:25 by asfletch          #+#    #+#             */
/*   Updated: 2024/06/18 16:28:06 by asfletch         ###   ########.fr       */
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
		bool				_sign;
		const int			_requiredGradeMin;
		const int			_executeGrade;


	public:
		Form();
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		Form(const std::string &name, int requiredGradeMin, int executeGrade);
		std::string	getName() const;
		int			getGrade() const;
		int			getExecute() const;

		void		beSigned(Bureaucrat& bureaucrat);
		void		signForm();

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
