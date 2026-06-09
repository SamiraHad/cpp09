# cpp09
cpp09

EX00:
<img width="1183" height="1330" alt="image" src="https://github.com/user-attachments/assets/e37ae80d-e472-4819-8354-f6c4f2692589" />

Ex02:
Le but de l'exercice est d'implémenter l'algorithme de Ford–Johnson.

Cet algorithme cherche à trier une séquence avec un nombre minimal de comparaisons.

Le sujet demande de l'implémenter avec deux conteneurs différents afin de comparer leurs temps d'exécution.

Tout d'abord, je vérifie l'input : je contrôle que les valeurs sont positives, qu'elles ne dépassent pas INT_MAX et qu'il n'y a pas de doublons.

Ensuite, je crée des paires d'éléments et je compare chaque paire.

Le plus grand élément devient un winner et est stocké dans winnerChain.

Le plus petit devient un loser et est stocké dans loserChain avec son winner associé grâce à std::make_pair.

Puis je trie récursivement les winners jusqu'à obtenir une main chain triée.

Après cela, j'utilise la suite de Jacobsthal (1, 3, 5, 11, 21, 43, ...).

Les valeurs 0, 1 et 1 sont ignorées car elles ne sont pas utiles pour l'ordre d'insertion.

La suite de Jacobsthal ne sert pas à trier les losers mais à déterminer dans quel ordre les insérer.

Pour chaque loser, je retrouve son winner associé avec std::find.

Ensuite j'utilise std::lower_bound qui effectue une recherche binaire dans la partie de la chaîne située avant le winner.

Comme je sais déjà que loser < winner, je n'ai pas besoin de chercher dans toute la chaîne.

Une fois tous les losers réinsérés, la séquence est complètement triée.

Enfin, je mesure le temps d'exécution pour le vector et pour le deque afin de comparer leurs performances.


<img width="1024" height="1536" alt="image" src="https://github.com/user-attachments/assets/c0f03953-1c6c-4c17-845c-e188f10677d3" />



<img width="1139" height="1381" alt="image" src="https://github.com/user-attachments/assets/2f92f75e-9164-4afa-98ca-70820e8601c3" />








|                 MutantStack / stack                      | `std::list`    | `std::vector`  | `std::deque`   |
| -------------------------------------------------------- | -------------- | -------------- | -------------- |
| `push(x)`ajoute un élément à la fin (en haut de la pile) | `push_back(x)` | `push_back(x)` | `push_back(x)` |
| `pop()`enlève le dernier élément (le sommet)             | `pop_back()`   | `pop_back()`   | `pop_back()`   |
| `top()` regarde le dernier élément sans le supprimer     | `back()`       | `back()`       | `back()`       |
| `size()` donne le nombre d’éléments                      | `size()`       | `size()`       | `size()`       |
| `begin()` pointe sur le premier élément                  | `begin()`      | `begin()`      | `begin()`      |
| `end()`   pointe après le dernier (fin pour boucle)      | `end()`        | `end()`        | `end()`        |


Remarque:

Jacobsthal mathématique : 0, 1, 1, 3, 5, 11, 21...

Jacobsthal utile pour Ford–Johnson : 1, 3, 5, 11, 21...

Le 0 et le deuxième 1 ne génèrent aucun nouveau groupe :

0 → rien

1 → b1

1 → rien de nouveau

3 → b3 b2

5 → b5 b4

11 → b11 b10 b9 b8 b7 b6

C'est pour ça que beaucoup d'implémentations commencent directement par :

jacob.push_back(1);

jacob.push_back(3);

et ignorent :

0, 1

