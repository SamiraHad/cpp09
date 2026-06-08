/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:28:54 by hsamira           #+#    #+#             */
/*   Updated: 2026/05/22 11:55:10 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool RPN::calculate(char op)
{
    if(_RPNstack.size() < 2)
    {
        std::cerr << "Error" << std::endl;
        return false;
    }
   
    int b = _RPNstack.top();
    _RPNstack.pop();

    int a = _RPNstack.top();
    _RPNstack.pop();

    if(op == '+')
        _RPNstack.push(a + b);
    else if(op == '-')
        _RPNstack.push(a - b);
    else if(op == '*')
        _RPNstack.push(a * b);
    else if(op == '/')
    {
        if(b == 0)
        {
            std::cerr << "Error" << std::endl;
            return false;
        }
        _RPNstack.push(a / b);
    }
    return true;
}

RPN::RPN()
{
    
}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if(this != &other)
        _RPNstack = other._RPNstack;
    return(*this);
    
}

void RPN::processInput(const std::string& input)
{
    std::istringstream iss(input);
    
    std::string token;
    
    while(iss >> token) //Lit chaque morceau séparé par espace.
    {
        if(isdigit(token[0]) && token.length() == 1)
        {
            int number = token[0] - '0';
            _RPNstack.push(number);
        }

        else if(token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            if(!calculate(token[0]))
                return;
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return;
        }
            
    }
    if(_RPNstack.size() != 1) //Trop de nombres ou Pas assez d’opérateurs a la fin.
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    
    std::cout << _RPNstack.top() << std::endl;
}

RPN::~RPN()
{
    
}