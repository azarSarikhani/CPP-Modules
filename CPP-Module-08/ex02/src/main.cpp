/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:03:02 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/27 14:21:52 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>

int main(void){
	MutantStack<int> muteStack;
	std::stack<int> stack;
	std::cout << "Mute stack is empty-> " << muteStack.empty() << " | stack is empty->" << stack.empty() << std::endl;
	muteStack.push(9);
	muteStack.push(89);
	muteStack.push(79);
	muteStack.push(849);

	stack.push(9);
	stack.push(89);
	stack.push(79);
	stack.push(849);
	std::cout << "Mute stack is empty-> " << muteStack.empty() << " | stack is empty->" << stack.empty() << std::endl;
	std::cout << "Mute stack top-> " << muteStack.top() << " | stack top->" << stack.top() << std::endl;
	std::cout << "Ms size-> " << muteStack.size() << " | stack size->" << stack.size() << std::endl;
	std::cout << "Mute stack begin-> " << *muteStack.begin() << std::endl;
	//std::cout << "Mute stack end-> " << *muteStack.end() << std::endl;
	std::cout << "Mute stack one before end-> " << *(muteStack.end() - 1) << std::endl;
	std::cout << "Mute stack  one after reverse end-> " << *(muteStack.rend() - 1) << std::endl;
	std::cout << "Mute stack  reverse begin-> " << *muteStack.rbegin() << std::endl;
	
	muteStack.pop();
	stack.pop();
	std::cout << "Mute stack is empty-> " << muteStack.empty() << " | stack is empty->" << stack.empty() << std::endl;
	std::cout << "Mute stack top-> " << muteStack.top() << " | stack top->" << stack.top() << std::endl;
	std::cout << "Ms size-> " << muteStack.size() << " | stack size->" << stack.size() << std::endl;
	//muteStack.push(849);
	MutantStack<int> copyMuteStack(muteStack);
	
	std::cout << "Copy Mute stack top-> " << copyMuteStack.top() << " | stack top->" << muteStack.top() << std::endl;
	std::cout << "Copy Mute stack size-> " << copyMuteStack.size() << " | stack size->" << muteStack.size() << std::endl;
	std::cout << "Copy Mute stack begin-> " << *copyMuteStack.begin() << std::endl;
	std::cout << "Copy Mute stack one before end-> " << *(copyMuteStack.end() - 1) << std::endl;
	std::cout << "Copy Mute stack  one after reverse end-> " << *(copyMuteStack.rend() - 1) << std::endl;
	std::cout << "Copy Mute stack  reverse begin-> " << *copyMuteStack.rbegin() << std::endl;
	
	MutantStack<int>::iterator MuteStackIt = muteStack.begin();
	
	std::cout << *MuteStackIt << "  " << *(MuteStackIt + 1) << std::endl;
	
	std::vector<float> vect;
	vect.push_back(8.9f);
	vect.push_back(82.9f);
	vect.push_back(18.9f);
	vect.push_back(8.49f);
	
	MutantStack< float, std::vector<float> > vectStack(vect);
	
	std::cout << "Vect stack is empty-> " << vectStack.empty() << std::endl;
	std::cout << "Vect stack top-> " << vectStack.top() << std::endl;
	std::cout << "Vect Stack size-> " << vectStack.size() << std::endl;
	std::cout << "Vect stack begin-> " << *vectStack.begin() << std::endl;
	std::cout << "Vect stack one before end-> " << *(vectStack.end() - 1) << std::endl;
	std::cout << "Vect stack  one after reverse end-> " << *(vectStack.rend() - 1) << std::endl;
	std::cout << "Vect stack  reverse begin-> " << *vectStack.rbegin() << std::endl;
	
	MutantStack<float, std::vector<float> >::const_iterator vectStackIt = vectStack.begin();
	std::cout << *vectStackIt << std::endl;
	// *vectStackIt +=1;
	// std::cout << *(vectStackIt + 1) << std::endl;
	
	
}