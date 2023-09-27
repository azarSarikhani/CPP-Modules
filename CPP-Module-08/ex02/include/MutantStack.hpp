/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:16:56 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/27 14:18:04 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <iostream>

template <typename T , typename Container = std::deque<T> >
class MutantStack : public std::stack<T , Container>
{
	
public:
	MutantStack() : std::stack< T , Container >() { std::cout << "MutantStack constructed by default construtor" << std::endl; };
	MutantStack( Container existing ) : std::stack< T , Container >( existing ) { std::cout << "MutantStack constructed by Containes specific construtor" << std::endl; };
	~MutantStack() { std::cout << "MutantStack destructed" << std::endl; };

	MutantStack( const MutantStack<T> &src ) : std::stack< T, Container >( src ) {
		*this = src;
		std::cout << "MutantStack Constructed by copy constructor" << std::endl;
	};

	MutantStack &operator=( const MutantStack< T, Container > &rhs) {
		if (this != &rhs){
			std::stack< T, Container >::operator=( rhs );
			std::cout << "MutantStack Constructed by operator=" << std::endl;
		}
		return *this;
	};
	typedef typename MutantStack< T, Container >::container_type::iterator iterator;
	typedef typename MutantStack< T, Container >::container_type::reverse_iterator reverse_iterator;
	typedef typename MutantStack< T, Container >::container_type::const_iterator const_iterator;
	typedef typename MutantStack< T, Container >::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin(){ return this->c.begin(); }
	iterator end(){ return this->c.end(); }
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
	
};




#endif