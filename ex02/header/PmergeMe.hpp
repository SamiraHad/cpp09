/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:11:38 by hsamira           #+#    #+#             */
/*   Updated: 2026/06/04 12:00:07 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <limits.h>
#include <ctime>


class PmergeMe
{
    private:
        std::vector<int> _vect;
        std::deque<int> _deq;

        double _vectTime;
        double _deqTime;

        
        std::vector<size_t> Jacobsthal(size_t n);
        std::vector<size_t> getJacobSthalOrder(size_t loserchain);

        template<typename Container> 
        void fordJohnsonRecursivite(Container &container)
        /*  Cette fonction implémente l'algorithme Ford–Johnson.

            1. Je crée des paires.
            2. Je compare chaque paire.
            3. Je garde les plus grands dans winnerChain.
            4. Je garde les plus petits dans loserChain.
            5. Je trie récursivement les winners.
            6. Je réinsère les losers selon l'ordre Jacobsthal.
            7. J'utilise lower_bound pour trouver la bonne position.*/
        {
            bool impair = false;
            int oneInt;
            size_t size = container.size();

            if (container.size() < 2)
                return;

            if (container.size() % 2 != 0) // gestion du cas impair
            {
                oneInt = container.back(); // sauvgarder le dernier element ailleurs
                size--;
                impair = true;
            }

            Container winnerChain;  // création des winners
            std::vector<std::pair<int, int> > loserChain; // création des losers associés

            for (size_t i = 0; i + 1 < size; i += 2) // prendre 2 éléments a chaque fois
            {

                if (container[i] > container[i + 1])
                {
                    winnerChain.push_back(container[i]);  // push le grand  ex [7,9]
                    loserChain.push_back(std::make_pair(container[i + 1], container[i])); // push le petit avec son associe ex [(2,7), (1,9)]
                }

                else
                {
                    winnerChain.push_back(container[i + 1]);
                    loserChain.push_back(std::make_pair(container[i], container[i + 1]));
                }
            }
            fordJohnsonRecursivite(winnerChain); // trier les winners dabord

            std::vector<size_t> order = getJacobSthalOrder(loserChain.size());

            for (size_t k = 0; k < order.size(); ++k) // utiliser ordre pour insérer les losers
            {
                size_t i = order[k];

                int loser = loserChain[i].first;
                int winner = loserChain[i].second;

                // std::find : Trouver le winner associé/ localiser le winner
                typename Container::iterator winnerPos = std::find(winnerChain.begin(), winnerChain.end(), winner);

                // std::lower_bound : Trouver où insérer le loser
                // et pour calculer la position d'insertion du loser.
                typename Container::iterator loserPos = std::lower_bound(winnerChain.begin(), winnerPos, loser);
                winnerChain.insert(loserPos, loser);
            }

            // traiter l'element qui reste tout seul
            if (impair)
            {
                typename Container::iterator oneIntPos = std::lower_bound(winnerChain.begin(), winnerChain.end(), oneInt);
                winnerChain.insert(oneIntPos, oneInt);
            }
            container = winnerChain; // retourne 0 1 2 3 4 
        }

        void fordJohnsonVector();
        void fordJohnsonDeque();
        


    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        bool parseInput(char **av);

        double sortVector(); //start chrono -> fordJohnsonVector() -> end chrono -> print timing
        double sortDeque();

        void printAfterVector() const;
        void printAfterDeque() const;


        double getVectTime() const;
        double getDeqTime() const;

        size_t getVectSize() const;
        size_t getDeqSize() const;
        
};