/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:11:52 by hsamira           #+#    #+#             */
/*   Updated: 2026/06/08 17:14:54 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Le but de l'exercice est d'implémenter l'algorithme Ford–Johnson.

Cet algorithme cherche à trier une séquence avec un nombre minimal de comparaisons.

Je dois l'implémenter une fois avec std::vector et une fois avec std::deque puis comparer leurs performances.*/



#include "PmergeMe.hpp"

std::vector<size_t> PmergeMe::Jacobsthal(size_t n) 
/*  Cette fonction génère seulement la suite/les nombres de Jacobsthal qui est definit par:  J0 = 0,
                                                                        J1 = 1, 
                                                                        Jn = Jn-1 + 2 × Jn-2    pour n ≥ 2*/
{
    std::vector<size_t> jacob;

    jacob.push_back(1);
    jacob.push_back(3);

    while (jacob.back() < n)
    {

        size_t size = jacob.size();
        jacob.push_back(jacob[size - 1] + 2 * jacob[size - 2]);
    }
    return jacob; // retourne Suite obtenue : 1, 3, 5, 11, 21, 43, ...   0, 1 sont ignorés car ils ne sont pas utiles pour pour construire l'ordre d'insertion.
}

std::vector<size_t> PmergeMe::getJacobSthalOrder(size_t n)
/*  Cette fonction transforme la suite de Jacobsthal en ordre d'insertion

    Cela indique quel loser doit être inséré en premier, puis en deuxième, etc.
    
    exemple: loserChain     :   index : 0 1 2 3 4
                                        A B C D E */
{
    std::vector<size_t> order;

    if (n == 0) //S'il n'y a aucun loser,
        return order; //il n'y a aucun ordre d'insertion à construire donc return un vecteur vide..

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
/*  Cette fonction vérifie tous les arguments. 

    Je contrôle que chaque argument est un nombre positif, 
    qu'il ne dépasse pas INT_MAX et qu'il n'y a pas de doublons.
    Ensuite j'insère les valeurs dans le vector et le deque.*/  
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
        _vect.push_back(static_cast<int>(value)); //conversion en int et insersion dans vector
        _deq.push_back(static_cast<int>(value)); //conversion en int et insersion dans deque
    }
    return true;
}


double PmergeMe::sortVector()
/*  Cette fonction mesure le temps d'exécution du tri de l'algorithme Ford–Johnson sur le vector.

    Je démarre le chrono,
    j'appelle Ford–Johnson,
    j'arrête le chrono,
    puis je convertis le résultat en microsecondes.*/
{
    clock_t start  = clock(); //enregistre le temps avant le trie
    
    fordJohnsonVector(); //execute l'algorithe de Ford_Johnson sur_vect

    clock_t end = clock(); //enregistre le temps apres le trie

    _vectTime = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;

    return _vectTime;
}

double PmergeMe::sortDeque()
/*  La fonction mesure le temps d'exécution de l'algorithme Ford–Johnson sur un std::deque. */
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
    return(_vectTime); //retourne  la durée du tri de vector
}

double PmergeMe::getDeqTime() const
{
    return(_deqTime); //retourne  la durée du tri de deque
}

size_t PmergeMe::getVectSize() const
{
    return(_vect.size()); //C'est un getter qui retourne le nombre d'éléments.
}

size_t PmergeMe::getDeqSize() const
{
    return(_deq.size());
}


/*lower_bound ne compare pas avec tous les éléments.

Il compare avec le milieu,
puis le milieu de la moitié restante,
puis encore le milieu : O(log n)*/