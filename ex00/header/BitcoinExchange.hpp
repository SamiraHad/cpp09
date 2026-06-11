/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:37:43 by hsamira           #+#    #+#             */
/*   Updated: 2026/06/11 10:32:03 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <sstream> // std::istringstream
#include <iostream>
#include <map>
#include <algorithm>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _databaseMap;
        bool checkDate(const std::string& date) const;//valide les dates.
        bool checkValue(double value) const; //valide les nombres.
        double findPriceForDate(const std::string& date) const;//quel est le prix/taux pour cette date ?
        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange&  other);
        ~BitcoinExchange();
        void loadDatabase(const std::string& filename);//remplit la map.
        void processInputFile(const std::string& filename);//traiter tout le fichier input.txt
};
