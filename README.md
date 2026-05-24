# cpp09
cpp09

Ex02:

Le but de l’algorithme de Ford–Johnson est de trier une liste en utilisant le minimum possible de comparaisons.

Ford–Johnson crée des paires, compare chaque paire, garde les gagnants dans la main chain et les perdants dans une pend chain associée à leurs winners.

Les winners sont triés récursivement.

Ensuite les pend elements sont réinsérés dans un ordre défini par Jacobsthal afin de minimiser les comparaisons.

Chaque insertion utilise une binary search dans une zone limitée, souvent proche des tailles : 2puissancek - 1


1. Création des paires: On prend les éléments 2 par 2 :

[a b c d e f g h]    ==> (a,b) (c,d) (e,f) (g,h)



2. Comparaison des paires: Pour chaque paire :(a,b)
 
on compare les deux éléments.

Si : a<b

alors : 

b devient le winner

a devient le loser


On obtient donc : 

   Winners : [b d f h]

   Losers  : [a c e g]


3. Main chain et pend chain:

Les winners forment la Main chain  :   [b d f h]

Les losers forment la Pend chain   :   [a c e g] 

Mais chaque loser reste associé à son winner :  

a ↔ b

 c ↔ d
 
 e ↔ f
 
 g ↔ h

car on sait déjà que :   a<b   Donc a sera forcément placé avant b.  => Cela réduit énormément la zone de recherche.

4. Tri récursif des winners : La main chain est triée récursivement : [b d f h]  -> [b f d h] -> [b d f h] ->

jusqu’à obtenir une chaîne triée.


5. Réinsertion des losers:

Une fois la main chain triée, les losers sont réinsérés.

Mais ils ne sont PAS insérés dans l’ordre normal.

Ford–Johnson utilise la suite de Jacobsthal pour choisir : quel loser insérer en premier?


6. Suite de Jacobsthal : La suite est définie par Jn ​= Jn−1​ + Jn−2  avec 0,1,1,3,5,11,21,43...

Cette suite permet d’obtenir un ordre d’insertion optimal.


7. Pourquoi Jacobsthal ? Ford–Johnson veut que les recherches binaires se fassent dans des tailles proches de 2k−1

1,3,7,15,31...  car une binary search est parfaitement équilibrée sur ces tailles.


8. Insertion optimisée : Lorsqu’on insère un loser a , on ne cherche PAS dans toute la main chain.

Comme on sait déjà :

a<b

on cherche seulement AVANT b.

Donc :

moins de comparaisons

recherche plus petite

insertion plus optimale.


9. Recherche binaire : L’insertion utilise une binary search O(logn) mais dans une fenêtre limitée grâce au winner associé.

10. Ce qu’on doit faire dans ex02 : Implémenter Ford–Johnson

       *une fois avec std::vector
    
       *une fois avec std::deque

    Puis :

    *comparer les temps d’exécution
    
    *afficher les performances
    
    *montrer que les deux versions fonctionnent.


Résumé final ultra condensé

Ford–Johnson :

1-crée des paires

2-compare chaque paire

3-garde les winners dans la main chain

4-garde les losers dans la pend chain

5-trie récursivement les winners

6-réinsère les losers

7-utilise Jacobsthal pour choisir l’ordre optimal d’insertion

8-utilise des binary searches dans des tailles proches de : 2k − 1 afin de minimiser le nombre total de comparaisons.



