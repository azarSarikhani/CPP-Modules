/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:14:20 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/26 16:57:06 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>

class Span
{
private:
	std::vector<int>	vector_;
	unsigned int maxElements_;
	Span();
	
public:
	Span( unsigned int N );
	Span( const Span &src );
	~Span();
	Span& operator=( const Span &rhs );
	
	void		addNumber(int x);
	void		addNumber( unsigned int size, int x );
	long int 	shortestSpan(void);
	long int 	longestSpan(void);
	void		printVector(void);
	void		printVector(int index);

};

std::ostream & operator<<( std::ostream & outputStream, Span const & instance );

#endif