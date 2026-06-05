# cpp09
cpp09



Ex02:


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

