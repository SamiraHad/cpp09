/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:37:53 by hsamira           #+#    #+#             */
/*   Updated: 2026/05/17 12:38:38 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl; 
        return (1);
    }

    BitcoinExchange bitcoin;

    bitcoin.loadDatabase("data.csv");
    bitcoin.processInputFile(av[1]);
    
    return 0;
}