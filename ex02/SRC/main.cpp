/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:11:47 by hsamira           #+#    #+#             */
/*   Updated: 2026/06/05 13:06:38 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe P;
  
    if(!P.parseInput(av))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    std::cout << "Before: ";
    for(int i = 1; av[i]; i++)
    {
         std::cout << av[i] << " ";
    }
    std::cout << std::endl;
    P.sortVector();
    P.sortDeque();
    std::cout << "After: ";
    P.printAfterVector();
    //P.printAfterDeque();

    std::cout << "Time to process a range of " << P.getVectSize() << " elements with std::vector : " << P.getVectTime() << " us" << std::endl;
    std::cout << "Time to process a range of " << P.getDeqSize() << " elements with std::deque : " << P.getDeqTime() << " us" << std::endl;
    
    return 0;
}
