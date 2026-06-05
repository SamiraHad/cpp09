/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:11:52 by hsamira           #+#    #+#             */
/*   Updated: 2026/06/04 12:06:32 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// fonction qui retourne l'ordre des indices à insérer.
//  Jn ​= Jn−1​ + 2Jn−2
//  Exemple : si tu as n = 8 losers :

// losers : b1 b2 b3 b4 b5 b6 b7 b8
// index  : 1  2  3  4  5  6  7  8

// Jacobsthal donne des bornes :

// 1, 3, 5, 11...

// Donc on fait des groupes :

// b1
// b3 b2
// b5 b4
// b8 b7 b6

// Le 11 dépasse 8, donc on le coupe à 8

std::vector<size_t> PmergeMe::Jacobsthal(size_t n)
{
    std::vector<size_t> jacob;

    jacob.push_back(1);
    jacob.push_back(3);

    while (jacob.back() < n)
    {

        size_t size = jacob.size();
        jacob.push_back(jacob[size - 1] + 2 * jacob[size - 2]);
    }
    return jacob; // retourne 1 3 5 
}

std::vector<size_t> PmergeMe::getJacobSthalOrder(size_t n)
{
    std::vector<size_t> order;

    if (n == 0)
        return order;

    order.push_back(0);

    std::vector<size_t> jacob = Jacobsthal(n);

    size_t previous = 1;

    for (size_t j = 1; j < jacob.size(); ++j)
    {
        size_t current = jacob[j];

        if (current > n)
            current = n;

        for (size_t k = current; k > previous; --k)
            order.push_back(k - 1);

        previous = current;
    }
    for (size_t k = n; k > previous; --k)
        order.push_back(k - 1);
        
    return order; // retourne 0 2 1 4 3 pou n = 5
}



void PmergeMe::fordJohnsonVector()
{
    fordJohnsonRecursivite(_vect);
}

void PmergeMe::fordJohnsonDeque()
{
    fordJohnsonRecursivite(_deq);
}


PmergeMe::PmergeMe() : _vectTime(0), _deqTime(0)
{
    
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vect = other._vect;
        _deq = other._deq;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{

}

bool PmergeMe::parseInput(char **av)
{

    for (int i = 1; av[i]; ++i)
    {
        std::istringstream iss(av[i]);

        long value;
        char notdigital;

        if (!(iss >> value) || iss >> notdigital)
            return false;

        if (value <= 0 || value > INT_MAX)
            return false;

        for (size_t j = 0; j < _vect.size(); ++j)
        {
            if (_vect[j] == value)
                return false;
        }
        _vect.push_back(static_cast<int>(value));
        _deq.push_back(static_cast<int>(value));
    }
    return true;
}

double PmergeMe::sortVector()
{
    clock_t start  = clock();
    
    fordJohnsonVector();

    clock_t end = clock();

    _vectTime = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    //std::cout << "Time to process a range of " << _vect.size() << " elements with std::vector : " << time << " us" << std::endl;
    return _vectTime;
}

double PmergeMe::sortDeque()
{
    clock_t start  = clock();
    
    fordJohnsonDeque();

    clock_t end = clock();

    _deqTime = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    //std::cout << "Time to process a range of " << _vect.size() << " elements with std::vector : " << time << " us" << std::endl;
    return _deqTime;
}

void PmergeMe::printAfterVector() const
{
    for (size_t i = 0; i < _vect.size(); ++i)
        std::cout << _vect[i] << " ";

    std::cout << std::endl;
}

<<<<<<< HEAD





std::vector<size_t> PmergeMe::Jacobsthal(size_t n)
{
    std::vector<size_t> jacob;

    jacob.push_back(1);
    jacob.push_back(3);

    while(jacob.back() < n)
    {
       
       size_t size = jacob.size();
       jacob.push_back(jacob[size - 1] + 2 * jacob[size - 2]);
    }
    return jacob;
}

std::vector<size_t> PmergeMe::getJacobSthalOrder(size_t n)
{
    std::vector<size_t> order;
    
    if(n <= 0)
        return order;
    
    order.push_back(0);
    
    std::vector<size_t> jacob = Jacobsthal(n);

    int previous = 1;
    
    for(size_t j = 1; j < jacob.size(); ++j)
    {
        int current = jacob[j];

        if(current > n)
            current = n;
        
        for(size_t k = current; k > previous; --k)
            order.push_back(k - 1);
        
        previous = current;
    }
    for (size_t k = n; k > previous; --k)
        order.pus
    
}

void PmergeMe::fordJohnsonVectorRecursivite(std::vector<int>& vect)
{
    bool impair = false;
    int oneInt;
    size_t size = vect.size();
    
    if(vect.size() < 2)
    return;
    
    if(vect.size() % 2 != 0)//gestion du cas impair
    {
        oneInt = vect.back();//sauvgarder le dernier element ailleurs
        size--;
        impair = true;
    }
    
    std::vector<int> winnerChain; //création des winners
    std::vector<std::pair<int, int> > loserChain; //création des losers associés
    
    for(size_t i = 0; i + 1 < size; i += 2) // prendre 2 éléments a chaque fois
    {
        
        if(vect[i] > vect[i + 1])
        {
            winnerChain.push_back(vect[i]);//push le grand  ex [7,9]
            loserChain.push_back(std::make_pair(vect[i + 1], vect[i]));// push le petit avec son associe ex [(2,7), (1,9)]
        }
        
        else
        {
            winnerChain.push_back(vect[i + 1]);
            loserChain.push_back(std::make_pair(vect[i], vect[i + 1]));
        }
    }
    fordJohnsonVectorRecursivite(winnerChain); //trier les winners dabord
    
    //
    std::vector<size_t> order = JacobSthalOrder(loserChain.size()); 
       
    for(size_t k = 0; k < order.size(); ++k)
    {
        size_t i = order[k];
        
        int loser = loserChain[i].first;
        int winner = loserChain[i].second; 

        // std::find : Trouver le winner associé/ localiser le winner
        std::vector<int>::iterator winnerPos = std::find(winnerChain.begin(),winnerChain.end(), winner);
    
        // std::lower_bound : Trouver où insérer le loser
        // et pour calculer la position d'insertion du loser.
        std::vector<int>::iterator loserPos = std::lower_bound(winnerChain.begin(), winnerPos, loser);
        winnerChain.insert(loserPos, loser);
    }
    
//traiter l'element qui reste tout seul
    if(impair)
    {
        std::vector<int>::iterator oneIntPos = std::lower_bound(winnerChain.begin(), winnerChain.end(), oneInt);
        winnerChain.insert(oneIntPos, oneInt);
    }
    vect = winnerChain;
}

void PmergeMe::fordJohnsonVector()
// {
//     fordJohnsonVectorRecursivite(_vect);
// }

// PmergeMe::PmergeMe()
// {
    
// }

// PmergeMe::PmergeMe(const PmergeMe& other)
// {
//     *this = other; 
// }

// PmergeMe& PmergeMe::operator=(const PmergeMe& other)
// {
//     if(this != &other)
//     {
//         _vect = other._vect;
//         _deq = other._deq;
//     }
//     return (*this);
// }

// PmergeMe::~PmergeMe()
// {
    
// }

// bool PmergeMe::parseInput(char **av)
// {
    
//     for(int i = 1; av[i]; ++i)
//     {
//         std::istringstream iss(av[i]);
        
//         long value;
//         char notdigital;
        
//         if(!(iss >> value) || iss >> notdigital)
//         return false;
    
//     if(value <= 0 || value > INT_MAX)
//     return false;

// for (size_t j = 0; j < _vect.size(); ++j)
// {
//     if (_vect[j] == value)
//     return false;
// }
// _vect.push_back(static_cast<int>(value));
// _deq.push_back(static_cast<int>(value));
// }
// return true;

// }

// void PmergeMe::sortVector()
// {
//     fordJohnsonVector();
// }

// void PmergeMe::printAfter() const
// {
//     for (size_t i = 0; i < _vect.size(); ++i)
//     std::cout << _vect[i] << " ";

// std::cout << std::endl;
// }

=======
void PmergeMe::printAfterDeque() const
{
    for (size_t i = 0; i < _deq.size(); ++i)
        std::cout << _deq[i] << " ";

    std::cout << std::endl;
}

double PmergeMe::getVectTime() const
{
    return(_vectTime);
}

double PmergeMe::getDeqTime() const
{
    return(_deqTime);
}


size_t PmergeMe::getVectSize() const
{
    return(_vect.size());
}

size_t PmergeMe::getDeqSize() const
{
    return(_deq.size());
}
>>>>>>> 1ca3e09 (cpp09)
