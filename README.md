# push_swap
## Language : C
Ce projet a été réalisé dans le cardre du cursus de l'école **42**.

Le but du projet **push_swap** est de trier une pile d'entiers en utilisant un nombre minimal d'opérations spécifiques. Il s'agit d'un défi algorithmique où il faut trouver la meilleure stratégie de tri tout en respectant les contraintes imposées par les règles du projet.

Ce programme implémente un algorithme combinant **Quick Sort Dynamique** et **Insertion Sort** pour optimiser les déplacements d'éléments entre les deux piles (`a` et `b`).

---

## Installation et compilation

La commande suivante compile le projet et génére le programme **push_swap** :

```sh
make
```

Pour nettoyer les fichiers objets :

```sh
make clean
```

Pour supprimer les fichiers objets et l'exécutable :

```sh
make fclean
```

Pour recompiler depuis zéro :
```sh
make re
```

---

## Utilisation

Le programme prend en argument une liste d'entiers et génère une séquence d'opérations pour les trier dans l'ordre croissant.

```sh
./push_swap [liste d'entiers]
```

### Exemples d'utilisation

Entrée valide :

```sh
./push_swap 4 3 2 1
pb
pb
pb
sa
pa
pa
pa
```

Entrée invalide :

```sh
./push_swap 4 3 deux 1
Error
```

---

## Fonctionnement de l'algorithme

L'algorithme de push_swap repose sur plusieurs étapes d'optimisation :

1. **Détermination des meilleurs pivots pour la distribution**
  - Analyse et teste plusieurs pivots pour un **Quick Sort**.
  - Sélectionne les pivots minimisant le nombres d'opérations à l'étape suivante.
  - Nous arrêtons la recherche des pivots lorsqu'ils permettent de respecter la contrainte suivante : $N < n * [3+log_2(n)]$, avec n la taille de la liste, et N le nombre d'opérations.

2. **Application du Quick Sort**
  - On applique le **Quick Sort** avec les paramètres trouvés.
  - On s'arrète lorsqu'il reste 3 éléments dans la pile 'a'.

3. **Tri des derniers éléments de la pile 'a'**
  - Tri simple, nombres de combinaisons fini.

4. **Insertion optimisée des éléments de `b` dans 'a'**
  - On regarde le nombre d'opérations nécessaires pour placer un élément de 'b' à sa place dans 'a' et on déplace celui dont le coût est le plus bas.

5. **Réorganisation finale de 'a'**
  - On fait rotate la pile 'a' pour la replacer dans l'ordre si besoin, on prends le plus petit élément comme repère.

6. **Validation et optimisations**
  - Chaque étape stocke les opérations dans un journal (log). Ensuite, on parcourt ce journal pour vérifier si des opérations inutiles, redondantes ou optimisables ont été effectuées.
  - Exemples : `ra + rra = 0`, `ra + rb = rr`, `ra + pb + rra = sa + pb`

---

## Règles du projet

- **Aucune valeur dupliquée** dans l'entrée.
- **Uniquement des entiers valides** dans l'entrée.
- Si l'entrée est invalide le programme affiche `"Error"` sur **stderr**.
- **Aucune sortie** si l'entrée est déjà triée ou si la taille de la liste est 1.
- **Respect de la norm 42**.
- **Aucune fuite de mémoire**.

### Opérations

| Commande  | Action |
|-----------|--------|
| `sa` | Échange les deux premiers éléments de `a` |
| `sb` | Échange les deux premiers éléments de `b` |
| `ss` | Effectue `sa` et `sb` simultanément |
| `pa` | Déplace le premier élément de `b` vers `a` |
| `pb` | Déplace le premier élément de `a` vers `b` |
| `ra` | Fait pivoter `a` vers le haut |
| `rb` | Fait pivoter `b` vers le haut |
| `rr` | Effectue `ra` et `rb` en même temps |
| `rra` | Fait pivoter `a` vers le bas |
| `rrb` | Fait pivoter `b` vers le bas |
| `rrr` | Effectue `rra` et `rrb` en même temps |

---

## Performances

Le programme est évalué selon son **efficacité** :

- **$n = 100$ : $\bar{N} \leq 700$**.
- **$n = 500$ : $\bar{N} \leq 5500$**.

Les valeurs indiquées sont des moyennes basées sur des tests standardisés.

---

# Bonus : programme Checker

Il est proposé, en bonus, de créer un programme **checker**.

Le programme vérifie si la suite d'opérations fournie trie correctement une liste d'entiers donnée. Il attend les opérations en entrée standard (stdin), les applique en simulant l'exécution, et renvoie "OK" si la liste est triée, "KO" sinon, ou "Error" en cas d'entrée invalide.
## Installation et compilation

La commande suivante compile le bonus et génére le programme **checker** :

```sh
make bonus
```

Pour recompiler le bonus depuis zéro :

```sh
make re_bonus
```

## Utilisation

Le programme prends en argument une liste d'entiers puis une fois éxectuer attends des opérations valides dans l'entrée standard.

```sh
./checker [liste d'entiers]
[opération]
[opération]
[...]
```

### Exemples d'utilisation

Si le tri est correct :

```sh
./checker 2 1 3
sa
OK
```

Si le tri est incorrect :

```sh
./checker 2 1 3
ra
KO
```

Si une erreur est détéctée :

```sh
./checker 2 1 3
bonjour
Error
```

```sh
./checker 2 un 3
Error
```

Peut s'utiliser avec push_swap :

```sh
./push_swap 3 2 1 | ./checker 3 2 1
OK
```

---

## Auteur

Projet réalisé par **[@eraad](mailto:eraad@student.42.fr)** dans le cadre du cursus de l'**Ecole 42**.

---

## Ressources utiles

🔹 [Push Swap Visualiser](https://github.com/o-reo/push_swap_visualizer)
🔹 [Complexity](https://github.com/SimonCROS/push_swap_tester)
🔹 [Complexité des algorithmes](https://en.wikipedia.org/wiki/Analysis_of_algorithms)  
🔹 [Algorithme de tri](https://fr.wikipedia.org/wiki/Algorithme_de_tri)
