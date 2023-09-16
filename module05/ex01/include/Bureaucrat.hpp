/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:11:28 by babreton          #+#    #+#             */
/*   Updated: 2023/09/16 18:09:06 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <iostream>
#include <string>
#include <stdexcept>
#include <climits>

typedef std::string str;

class Bureaucrat {
	public:
		Bureaucrat(str name, int grade);
		Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat &	operator=(Bureaucrat const &rSym);
		str				getName() const;
		int				getGrade() const;

		void			promote();
		void			demote();

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
	private:
		str const	_name;
		int			_grade;
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const &rSym);

#endif