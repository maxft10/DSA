# Binary Search (Recherche Binaire)

## Principe

La **recherche binaire** est un algorithme qui permet de trouver un élément dans une structure **triée** en divisant l'espace de recherche par 2 à chaque étape.

L'idée est simple :

> Au lieu de chercher élément par élément (O(n)), on élimine la moitié des éléments à chaque comparaison (O(log n)).

---

## Condition obligatoire

⚠️ La recherche binaire fonctionne uniquement si la structure est :

- **triée**
- ou **monotone (croissante/décroissante)**
- ou transformable en fonction monotone (cas avancé)

---

## Idée générale

On maintient trois indices :

- `left` : début de la zone de recherche
- `right` : fin de la zone
- `mid` : milieu

Puis on réduit la zone selon la comparaison.

```
Tableau : [1, 3, 5, 7, 9, 11]
Recherche : 7

left = 0
right = 5
mid = 2 → 5

7 > 5 → aller à droite

left = 3
right = 5
mid = 4 → 9

7 < 9 → aller à gauche

left = 3
right = 3
mid = 3 → 7 trouvé
```

---

## Les deux variantes principales

### 1. Binary Search classique (recherche d'un élément)

On cherche si une valeur existe.

**Étapes :**
1. Calculer `mid`
2. Comparer `arr[mid]` avec la cible
3. Aller à gauche ou à droite
4. Répéter jusqu'à trouver ou épuiser la zone

---

### 2. Binary Search sur réponse (Binary Search on Answer)

On ne cherche pas un élément, mais une **valeur optimale**.

Exemples :
- minimum possible
- maximum possible
- capacité minimale
- temps optimal

👉 On cherche une valeur qui satisfait une **condition monotone**

---

## Identifier un problème Binary Search

| Signal | Description |
|--------|-------------|
| **Tableau trié** | Cas classique |
| **Recherche rapide O(log n)** | Alternative à O(n) |
| **Fonction monotone** | "si ça marche à x, ça marche à x+1" |
| **Min / max optimal** | Binary Search on Answer |
| **Problème de seuil** | trouver première/dernière occurrence |

---

## Complexité

| | Complexité |
|-|------------|
| **Temporelle** | O(log n) |
| **Spatiale** | O(1) |
| **Précondition** | structure triée ou monotone |

---

## Templates de code

### Binary Search classique

```cpp
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
```

---

### Première occurrence / Lower Bound

```cpp
int lowerBound(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}
```

---

### Upper Bound

```cpp
int upperBound(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}
```

> 💡 Compter les occurrences d'un élément = `upperBound - lowerBound`

---

### Binary Search on Answer

```cpp
bool condition(int mid);

int binarySearchAnswer(int left, int right) {
    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (condition(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}
```

#### Exemple concret : Koko Eating Bananas

> Koko a `n` tas de bananes. Elle doit tout manger en `h` heures. Quelle est la vitesse minimale `k` (bananes/heure) ?

**Pourquoi Binary Search ?**
Si une vitesse `k` permet de finir à temps, alors toute vitesse `k+1` aussi → **condition monotone**.

On applique Binary Search sur l'espace des vitesses `[1, max(piles)]`.

```
piles = [3, 6, 7, 11]
h = 8

Vitesse 1 → 3+6+7+11 = 27h  ❌
Vitesse 6 → 1+1+2+2  = 6h   ✅
Vitesse 4 → 1+2+2+3  = 8h   ✅ ← minimum
```

```cpp
int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int hours = 0;
        for (int p : piles)
            hours += (p + mid - 1) / mid; // ceil(p / mid)

        if (hours <= h) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}
```

Complexité : **O(n log m)** où `m = max(piles)`

---

## Cas d'utilisation classiques

### Recherche dans un tableau trié

```
[1, 3, 5, 7, 9]
target = 7
→ O(log n)
```

---

### Trouver la première position d'un élément

```
[1, 2, 2, 2, 3]
       ^
→ retourner l'index du premier 2
```

---

### Minimum / maximum sous contrainte

Exemples :
- minimum capacité pour transporter des colis
- temps minimal pour finir une tâche
- vitesse optimale

---

### Racine carrée entière

On cherche la plus grande valeur `mid` telle que `mid * mid <= x`.

---

### Search in Rotated Array

Un tableau trié a été **pivoté** à un index inconnu :

```
[4, 5, 6, 7, 0, 1, 2]
         ^
      pivot ici
```

**Intuition clé** : même après rotation, **l'une des deux moitiés est toujours triée**.

On détermine quelle moitié est triée, puis on vérifie si la cible s'y trouve.

```
arr = [4, 5, 6, 7, 0, 1, 2]
target = 0

left = 0, right = 6, mid = 3 → arr[mid] = 7

La moitié gauche [4, 5, 6, 7] est triée.
0 n'est pas dans [4..7] → aller à droite

left = 4, right = 6, mid = 5 → arr[mid] = 1

La moitié droite [1, 2] est triée.
0 n'est pas dans [1..2] → aller à gauche

left = 4, right = 4, mid = 4 → arr[mid] = 0 → trouvé
```

```cpp
int searchRotated(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;

        // Moitié gauche triée
        if (arr[left] <= arr[mid]) {
            if (arr[left] <= target && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        // Moitié droite triée
        else {
            if (arr[mid] < target && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}
```

---

## Types de problèmes Binary Search

| Type | Description |
|------|-------------|
| Standard search | trouver un élément |
| Lower / Upper Bound | première / dernière occurrence |
| Binary Search on Answer | optimisation |
| Search in rotated array | tableau trié pivoté |
| Peak finding | recherche de maximum local |

---

## Pièges courants

### 1. Mauvaise condition de boucle

- `while (left <= right)` → recherche classique
- `while (left < right)` → bounds

### 2. Overflow sur mid

❌ mauvais :
```cpp
mid = (left + right) / 2;
```

✅ correct :
```cpp
mid = left + (right - left) / 2;
```

### 3. Oublier la monotonie

Binary Search on Answer fonctionne uniquement si :

> la condition est monotone — si elle est vraie pour `x`, elle l'est pour tout `x+1` (ou tout `x-1`)

---

## Différence avec Two Pointers

| Binary Search | Two Pointers |
|--------------|-------------|
| Divise l'espace de recherche | Explore séquentiellement |
| O(log n) | O(n) |
| Nécessite tri ou monotonie | Souvent sur tri ou structure locale |
| Réduction par moitié | Déplacement progressif |

---

## Problèmes classiques

| Problème | Type |
|----------|------|
| Binary Search (LC #704) | Standard search |
| Search in Rotated Sorted Array (LC #33) | Rotated array |
| Find First and Last Position (LC #34) | Lower / Upper Bound |
| Koko Eating Bananas (LC #875) | Binary Search on Answer |
| Capacity to Ship Packages (LC #1011) | Binary Search on Answer |
| Find Peak Element (LC #162) | Peak finding |
| Sqrt(x) (LC #69) | Binary Search on Answer |
| Median of Two Sorted Arrays (LC #4) | Avancé |

---

## Résumé

- Binary Search = **réduction par moitié**
- Nécessite **tri ou monotonie**
- Très puissant pour :
  - recherche exacte
  - bornes (lower/upper bound)
  - optimisation (binary search on answer)
  - tableaux pivotés
  - problèmes de décision
