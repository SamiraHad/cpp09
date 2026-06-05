/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:28:48 by hsamira           #+#    #+#             */
/*   Updated: 2026/05/22 10:25:22 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error"  << std::endl;
        return 1; 
    }

    RPN rpn;
    
    rpn.processInput(av[1]);
    
    return 0;
    
}