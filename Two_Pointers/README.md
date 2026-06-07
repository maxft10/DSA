# Two Pointers (Deux Pointeurs)

## Principe

La technique des **deux pointeurs** consiste à utiliser deux indices qui parcourent une structure (généralement un tableau ou une chaîne de caractères) afin d'éviter les boucles imbriquées.

L'idée est de remplacer un parcours naïf en **O(n²)** par un parcours plus efficace en **O(n)** ou **O(n log n)**.

Les deux pointeurs peuvent :

- se rapprocher l'un de l'autre
- avancer dans la même direction
- partir d'extrémités opposées
- représenter une fenêtre ou un intervalle
- parcourir deux structures différentes en parallèle

> ⚠️ Sliding Window est un **cas particulier** de Two Pointers :  
> contrainte de contiguïté + mise à jour d'une fenêtre glissante.

---

## Les deux variantes principales

### 1. Pointeurs convergents

Les pointeurs partent des extrémités et se rapprochent progressivement.

**Étapes :**
1. Initialiser `left` au début
2. Initialiser `right` à la fin
3. Comparer les valeurs
4. Déplacer l'un des pointeurs selon la condition
5. Répéter jusqu'à ce qu'ils se croisent

```
Tableau trié : [1, 2, 4, 7, 11, 15]
Somme cible : 15

left = 1
right = 15

1 + 15 = 16 → trop grand → right--

1 + 11 = 12 → trop petit → left++

2 + 11 = 13 → trop petit → left++

4 + 11 = 15 → trouvé
```

---

### 2. Pointeurs dans le même sens

Les deux pointeurs avancent de gauche à droite.

Un pointeur explore tandis que l'autre délimite une zone valide.

**Étapes :**
1. Initialiser `left` et `right`
2. Avancer `right`
3. Déplacer `left` lorsque nécessaire
4. Mettre à jour la réponse
5. Continuer jusqu'à la fin

```
Tableau : [1, 1, 2, 2, 3]

left  = 0
right = 1

Objectif : supprimer les doublons

[1, 2, 3, _, _]
```

👉 Cette variante est très proche de Sliding Window (mais sans forcément maintenir une contrainte explicite de validité).

---

## 3. Deux pointeurs sur deux structures

Les deux pointeurs parcourent **deux tableaux / listes / chaînes** en parallèle.

**Étapes :**
1. Initialiser `i` sur A et `j` sur B
2. Comparer A[i] et B[j]
3. Avancer le pointeur du plus petit élément
4. Construire un résultat ou détecter une condition

```
A = [1, 4, 7]
B = [2, 3, 6]

i → 1
j → 2

→ avancer i ou j selon comparaison
```

---

## Identifier un problème Two Pointers

| Signal | Description |
|----------|-------------|
| **Tableau trié** | Le signal le plus fréquent |
| **Recherche de paire** | Trouver deux éléments vérifiant une condition |
| **Palindrome** | Comparaison symétrique début/fin |
| **Fusion** | Parcours simultané de deux tableaux |
| **Sous-tableau contigu** | Souvent résoluble avec Sliding Window |
| **Suppression en place** | Retirer doublons, valeurs spécifiques, etc. |
| **Complexité naïve O(n²)** | Optimisable en O(n) |

---

## Cas d'utilisation classiques

### Trouver une paire dans un tableau trié

```
[1, 2, 4, 7, 11, 15]
target = 15
```

Au lieu de tester toutes les paires :

```text
O(n²)
```

on utilise :

```
left  → début
right → fin
```

Complexité :

```text
O(n)
```

---

### Vérifier un palindrome

```
"radar"
 ^   ^
```

Comparer les caractères aux extrémités :

```
r == r
a == a
d
```

Si toutes les comparaisons réussissent :

```
Palindrome
```

---

### Supprimer les doublons d'un tableau trié

```
[1, 1, 2, 2, 3]

Résultat :

[1, 2, 3]
```

Un pointeur lit, l'autre écrit les valeurs uniques.

---

### Fusion de deux tableaux triés

```
A = [1, 4, 7]
B = [2, 3, 6]

Résultat :

[1, 2, 3, 4, 6, 7]
```

On avance le pointeur correspondant à la plus petite valeur.

---

## Complexité

| | Complexité |
|-|------------|
| **Temporelle** | O(n) dans la majorité des cas |
| **Spatiale** | O(1) |
| **Avec tri préalable** | O(n log n) |

---

## Template de code

### Pointeurs convergents

```C++
int left = 0;
int right = arr.size() - 1;

while (left < right) {

    if (/* condition trouvée */) {
        return true;
    }

    if (/* somme trop petite */) {
        left++;
    } else {
        right--;
    }
}
```

---

### Pointeurs dans le même sens

```C++
int left = 0;

for (int right = 0; right < arr.size(); right++) {

    while (/* condition invalide */) {
        left++;
    }

    // Mise à jour du résultat
}
```

---

## Exemple : Two Sum dans un tableau trié

```C++
bool twoSumSorted(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;

        if (sum < target)
            left++;
        else
            right--;
    }

    return false;
}
```

---

## Exemple : Vérification d'un palindrome

```C++
bool isPalindrome(const string& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right])
            return false;

        left++;
        right--;
    }

    return true;
}
```

---

## Différence avec Sliding Window

| Two Pointers | Sliding Window |
|--------------|----------------|
| Technique générale | Cas particulier de Two Pointers |
| Les pointeurs peuvent converger | Les pointeurs avancent généralement dans le même sens |
| Peut travailler sur 2 structures | Souvent sur une seule structure contiguë |
| Recherche de paires, palindromes, fusion | Recherche de fenêtres valides |

---

## Problèmes classiques

| Problème | Type |
|----------|------|
| Two Sum II (tableau trié) | Pointeurs convergents |
| Valid Palindrome | Pointeurs convergents |
| Container With Most Water | Pointeurs convergents |
| 3Sum | Convergents + tri |
| Remove Duplicates from Sorted Array | Même direction |
| Merge Sorted Arrays | Deux structures |
| Move Zeroes | Même direction |
| Squared Sorted Array | Convergents |
| Trapping Rain Water | Convergents |
| Longest Substring Without Repeating Characters | Sliding Window (cas particulier Two Pointers) |
```
