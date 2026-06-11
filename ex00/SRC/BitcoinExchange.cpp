/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamira <hsamira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:37:49 by hsamira           #+#    #+#             */
/*   Updated: 2026/06/11 10:45:24 by hsamira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <iomanip>

bool BitcoinExchange::checkDate(const std::string& date) const 
{
    //vérifier le format d'une date YYYY-MM-DD
    if(date.length() != 10)
        return false;
    
    for (int i = 0; i < 10; i++)
    {
        if(i == 4 || i == 7)
        {
            if(date[i] != '-')
                return false;
        }
        else
        {
            if(!isdigit(date[i]))
                return(false);
        }
    }
    
    //extraire year/month/day
    std::string year = date.substr(0,4);
    std::string month = date.substr(5,2);
    std::string day = date.substr(8,2);
    
    //convertir en int
    int yearInt;
    int monthInt;
    int dayInt;

    std::istringstream issYear(year);
    issYear >> yearInt;

    std::istringstream issMonth(month);
    issMonth >> monthInt;

    std::istringstream issDay(day);
    issDay >> dayInt;
    
    //vérifier month
    if(monthInt < 1 || monthInt > 12)
        return false;
    
    //vérifier day selon le mois
    if(dayInt < 1 || dayInt > 31)
         return false;
    
    if(monthInt == 2)
    {
        if(yearInt % 4 == 0)
        {
            if(dayInt > 29)
                return false;
        }
        else
        {
            if(dayInt > 28)
                return false;    
        }
    }
    else if(monthInt == 4 || monthInt == 6 || monthInt == 9 ||monthInt == 11)
    {
        if(dayInt > 30)
            return false;
    }
    else
    {
        if(dayInt > 31)
            return false;
    }
    return true;
}

//verifie la valeur entrée par l’utilisateur 2011-01-03 | 3 donc 3
bool BitcoinExchange::checkValue(double value) const
{
    if(value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if(value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;   
}

//chercher un prix dans la map
/*si date exacte existe
    retourner prix
sinon
    lower_bound
    reculer d’un élément
    retourner le prix*/
double BitcoinExchange::findPriceForDate(const std::string& date) const
{ 
    std::map<std::string, double>::const_iterator it;
    
    //date exacte trouvee
    it = _databaseMap.find(date);
    if(it !=_databaseMap.end())
        return (it->second);
    
    // sinon chercher la date la plus proche inférieure
    it = _databaseMap.lower_bound(date);
    
    //si la date avant la 1ere date de la map , elle nexiste pas
    if(it == _databaseMap.begin())
        return (-1);
    it--;
    return(it->second);
}

BitcoinExchange::BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange&  other)
{
    if(this != &other)
        _databaseMap = other._databaseMap;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    
}
/*
| Forme                | Arrêt |
| -------------------- | ----- |
| `getline(a, b)`      | `\n`  |lit et s'arrete a  '\n'
| `getline(a, b, ',')` | `,`   |lit et s'arrete à la virgule*/

/*| Objet                  | Type de flux   |
| ------------------------ | -------------- |
| `std::cin`               | flux clavier   |
| `std::ifstream file`     | flux fichier   |
| `std::istringstream iss` | flux de string |
*/

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    
    std::getline(file, line);
    
    while(std::getline(file, line))
    {
        std::string date;
        std::string exchangeRateStr;
        double exchangeRate;
        
        std::istringstream iss(line);
        
        std::getline(iss, date, ',');
        std::getline(iss, exchangeRateStr);
        
        std::istringstream issRate(exchangeRateStr);
        issRate >> exchangeRate;

        _databaseMap[date] = exchangeRate;
    }
    file.close();
    
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);

    if(line != "date | value")
    {
        std::cerr << "Error : bad header." << std::endl;
        return;
    }
    
    while(std::getline(file, line))
    {
        std::istringstream iss(line);
        
        std::string date;
        std::string pipe;
        std::string valueString;
        
        double value;
        double price;
        char extra;
        
        if(!(iss >> date >> pipe >> valueString))
        {
            std::cerr << "Error: bad input => " << line << std::endl; 
            continue;
        }
        
        if(pipe != "|")
        {
            std::cerr << "Error: bad input => " << line << std::endl; 
            continue;
        }
        std::istringstream issValue(valueString);
        
        if(!(issValue >> value) || (issValue >> extra))
        {
            std::cerr << "Error: bad input => " << line << std::endl; 
            continue;
        }
        
        if(!checkDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl; 
            continue;
        }
        if(!checkValue(value))
            continue;

        price = findPriceForDate(date);
        if(price == -1)
        {
            std::cerr << "Error : no price available ." << price << std::endl;
            continue;
        }
        //std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << value * price << std::endl;
        std::cout << date << " => " << value << " = " << value * price << std::endl;
        
    }

    file.close();
}