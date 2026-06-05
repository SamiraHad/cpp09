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



//suite de Jacobsthal J0 = 0, J1 = 1, Jn = Jn-1 + 2 × Jn-2    pour n ≥ 2
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
    return jacob; // retourne Suite obtenue : 1, 3, 5, 11, 21, 43, ...   0, 1 sont ignorés.
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



//verifie l'input et remplir vector et deque
bool PmergeMe::parseInput(char **av)
{

    for (int i = 1; av[i]; ++i)
    {
        std::istringstream iss(av[i]);

        long value; //long pour tester un nbr > INT_MAX
        char notdigital;

        if (!(iss >> value) || iss >> notdigital) //nombre
            return false;

        if (value <= 0 || value > INT_MAX) //limits
            return false;

        for (size_t j = 0; j < _vect.size(); ++j) //doublon
        {
            if (_vect[j] == value)
                return false;
        }
        _vect.push_back(static_cast<int>(value)); //conversion en int insersion dans vector
        _deq.push_back(static_cast<int>(value)); //conversion en int et insersion dans deque
    }
    return true;
}


//La fonction mesure le temps d'exécution de l'algorithme Ford–Johnson sur un std::vector.
double PmergeMe::sortVector()
{
    clock_t start  = clock(); //enregistre le temps avant le trie
    
    fordJohnsonVector(); //execute l'algorithe de Ford_Johnson sur_vect

    clock_t end = clock(); //enregistre le temps apres le trie

    _vectTime = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;

    return _vectTime;
}

//La fonction mesure le temps d'exécution de l'algorithme Ford–Johnson sur un std::deque.
double PmergeMe::sortDeque()
{
    clock_t start  = clock();
    
    fordJohnsonDeque();

    clock_t end = clock();

    _deqTime = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;

    return _deqTime;
}


void PmergeMe::printAfterVector() const
{
    for (size_t i = 0; i < _vect.size(); ++i)
        std::cout << _vect[i] << " ";

    std::cout << std::endl;
}

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
