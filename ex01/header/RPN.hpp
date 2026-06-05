/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:28:43 by hsamira           #+#    #+#             */
/*   Updated: 2026/05/22 10:31:35 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <list>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cctype>


/*std::stack<int> _RPNstack <===> std::stack<int, std::deque<int> > par defaut*/
/*
_RPNstack.push(x) : ajouter un élément au sommet de la pile.
_RPNstack.pop() : supprimer l’élément au sommet.
_RPNstack.top() : regarde à la valeur au sommet sans la supprimer.
_RPNstack.empty() : vérifier si la pile est vide.
_RPNstack.size() : connaître le nombre d’éléments dans la pile.
*/

class RPN
{
    private:
        std::stack<int, std::list<int> > _RPNstack;
        bool calculate(char op);
          
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        void processInput(const std::string& input);
        ~RPN();
};