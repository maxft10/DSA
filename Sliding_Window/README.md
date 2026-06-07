# Sliding Window (Fenêtre Glissante)

## Principe

La fenêtre glissante consiste à maintenir un sous-tableau qui **glisse** sur un tableau. Au lieu de recalculer quelque chose sur tout le tableau à chaque étape, on met à jour la fenêtre en :

- **ajoutant** le nouvel élément à droite
- **retirant** l'ancien élément à gauche

Ce mécanisme est la clé de l'efficacité : chaque élément est ajouté **et** retiré au plus une fois, ce qui réduit la complexité de **O(n²) à O(n)**.

---

## Les deux variantes

### 1. Fenêtre de taille fixe

La fenêtre contient toujours **k éléments**. On retire un élément dès que la taille dépasse k.

**Étapes :**
1. Identifier la taille `k` de la fenêtre
2. Calculer le résultat pour la première fenêtre (les `k` premiers éléments)
3. Faire glisser la fenêtre de 1 en 1, en mettant à jour le résultat à chaque étape

```
Tableau : [2, 1, 5, 1, 3, 2], k = 3
Fenêtre 1 : [2, 1, 5] → somme = 8
Fenêtre 2 : [1, 5, 1] → somme = 7  (on retire 2, on ajoute 1)
Fenêtre 3 : [5, 1, 3] → somme = 9  (on retire 1, on ajoute 3)
...
```

### 2. Fenêtre de taille variable

La fenêtre grandit et rétrécit selon une **condition**. On utilise deux pointeurs `left` et `right`.

**Étapes :**
1. Avancer `right` un par un tant que la condition est satisfaite
2. Si la condition n'est plus satisfaite, rétrécir la fenêtre en avançant `left`
3. Quand la condition est à nouveau satisfaite, reprendre l'avancée de `right`
4. Répéter jusqu'à la fin du tableau

> ⚠️ Il existe deux sous-patterns :
> - **Shrink dès que la condition est violée** → pour trouver la fenêtre *maximale*
> - **Shrink tant que la condition est satisfaite** → pour trouver la fenêtre *minimale*

---

## Identifier un problème de fenêtre glissante

| Signal | Description |
|--------|-------------|
| **Contiguïté** | La réponse est un sous-tableau ou une sous-chaîne **contigu(e)** — c'est le signal le plus fiable |
| **Min/Max** | On cherche un sous-tableau/sous-chaîne maximale ou minimale satisfaisant une condition |
| **Taille k donnée** | La taille de la fenêtre est fournie dans l'énoncé |
| **Complexité naïve** | Le problème se résout en O(n²) avec des boucles imbriquées |
| **Contrainte n** | `n <= 10⁶`, la complexité cible est O(n) |

---

## Complexité

| | Complexité |
|-|------------|
| **Temporelle** | O(n) — chaque élément est ajouté et retiré au plus une fois |
| **Spatiale** | O(1) en général, O(k) si on stocke la fenêtre |
| **Avec structure interne** | O(n log n) si la fenêtre utilise un heap ou un deque trié (ex: maximum glissant) |

---

## Template de code

### Taille fixe

```C++
int slidingWindowFixed(const vector<int>& arr, int k) {
    int windowSum = 0;

    // Somme de la première fenêtre
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int result = windowSum;

    // Déplacement de la fenêtre
    for (int i = k; i < arr.size(); i++) {
        windowSum += arr[i] - arr[i - k];
        result = max(result, windowSum);
    }

    return result;
```

### Taille variable

```C++
int slidingWindowVariable(const vector<int>& arr) {
    int left = 0;
    int result = 0;

    for (int right = 0; right < arr.size(); right++) {
        // Agrandir la fenêtre : intégrer arr[right]

        while (/* condition violée */) {
            // Rétrécir la fenêtre : retirer arr[left]
            left++;
        }

        // Mettre à jour le résultat
        result = max(result, right - left + 1);
    }

    return result;
}
```

---

## Problèmes classiques

| Problème | Type |
|----------|------|
| Maximum/minimum d'une somme de k éléments | Taille fixe |
| Plus longue sous-chaîne sans caractère répété | Taille variable |
| Plus petite sous-chaîne contenant tous les caractères cibles | Taille variable (min) |
| Maximum glissant (sliding window maximum) | Taille fixe + deque |
| Sous-tableau de somme égale à k | Taille variable |

