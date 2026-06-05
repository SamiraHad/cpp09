# cpp09
cpp09



Ex02:

<img width="1024" height="1536" alt="ChatGPT Image Jun 2, 2026, 11_36_05 AM" src="https://github.com/user-attachments/assets/130fd33b-cbfa-49d8-9232-8b2926060cd9" />


<img width="1139" height="1381" alt="image" src="https://github.com/user-attachments/assets/30530e6f-1b5b-4e38-a913-0bb673643756" />




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

