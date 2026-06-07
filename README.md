# Core Data Structures

Ce document présente les **structures de données fondamentales** en algorithmique.

Elles constituent la base de presque tous les patterns DSA (Two Pointers, Sliding Window, Graphs, DP, etc.).

---

# 1. Arrays & Strings

## Principe

Les **tableaux (arrays)** et les **chaînes de caractères (strings)** sont des structures linéaires où les éléments sont stockés de manière contiguë en mémoire.

- Accès direct en O(1)
- Parcours séquentiel
- Base de la majorité des problèmes algorithmiques

---

## Propriétés importantes

| Opération | Complexité |
|-----------|------------|
| Accès index | O(1) |
| Recherche | O(n) |
| Insertion (milieu) | O(n) |
| Suppression (milieu) | O(n) |

---

## Concepts associés

- Two Pointers
- Sliding Window
- Prefix Sum
- Binary Search (sur tableau trié)

---

## Cas d'utilisation classiques

- Recherche / tri
- Manipulation de sous-tableaux
- Problèmes de strings (palindromes, anagrammes)
- Fenêtres glissantes

---

## Templates C++

```cpp
// Parcours simple
for (int i = 0; i < arr.size(); i++) { }

// Parcours inverse
for (int i = arr.size() - 1; i >= 0; i--) { }

// Substring
string sub = s.substr(start, length);

// Comparaison de strings
s1 == s2

// Conversion char → int
int d = c - '0';

// Fréquence des caractères
int freq[26] = {0};
freq[c - 'a']++;
```

---

## Prefix Sum

> Permet de calculer la somme d'un sous-tableau en O(1) après un preprocessing O(n).

```
arr     = [2, 4, 1, 3, 5]
prefix  = [0, 2, 6, 7, 10, 15]

Somme de arr[1..3] = prefix[4] - prefix[1] = 10 - 2 = 8
```

```cpp
vector<int> buildPrefix(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + arr[i];
    return prefix;
}

// Somme de arr[l..r] inclus
int rangeSum(vector<int>& prefix, int l, int r) {
    return prefix[r + 1] - prefix[l];
}
```

---

# 2. Linked List (Listes chaînées)

## Principe

Une **linked list** est une structure composée de nœuds, où chaque nœud contient :

- une valeur
- un pointeur vers le suivant (et parfois précédent)

---

## Types

- Singly Linked List
- Doubly Linked List
- Circular Linked List

---

## Propriétés

| Opération | Complexité |
|-----------|------------|
| Accès | O(n) |
| Insertion tête | O(1) |
| Suppression tête | O(1) |
| Recherche | O(n) |

---

## Avantages

- Insertion/suppression efficaces
- Taille dynamique

## Inconvénients

- Pas d'accès direct
- Pas de cache locality (plus lent que arrays)

---

## Cas d'utilisation classiques

- Reverse linked list
- Cycle detection (Floyd)
- Merge two sorted lists
- LRU cache (avec hashmap)

---

## Templates C++

```cpp
// Définition d'un nœud
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Parcours
ListNode* curr = head;
while (curr != nullptr) {
    curr = curr->next;
}

// Reverse linked list
ListNode* prev = nullptr;
ListNode* curr = head;

while (curr != nullptr) {
    ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
// prev est la nouvelle tête
```

---

## Floyd's Cycle Detection

> Deux pointeurs avancent à des vitesses différentes. S'il y a un cycle, ils se retrouveront forcément.

```
Liste : A → B → C → D → B (cycle)

slow : avance de 1
fast : avance de 2

Si fast == slow → cycle détecté
```

```cpp
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}
```

---

# 3. Stack & Queue

## Stack (Pile)

### Principe

Structure **LIFO** (Last In First Out)

```
Dernier entré → premier sorti
```

### Opérations

| Opération | Complexité |
|-----------|------------|
| push | O(1) |
| pop | O(1) |
| top | O(1) |

### Cas d'utilisation

- Parenthèses valides
- DFS (récursif ou itératif)
- Undo / redo
- Expression parsing

---

## Queue (File)

### Principe

Structure **FIFO** (First In First Out)

```
Premier entré → premier sorti
```

### Opérations

| Opération | Complexité |
|-----------|------------|
| enqueue | O(1) |
| dequeue | O(1) |
| front | O(1) |

### Cas d'utilisation

- BFS (graphes)
- Scheduling
- Simulation de files d'attente

---

## Templates C++

```cpp
// Stack (STL)
stack<int> st;
st.push(x);
st.pop();
int top = st.top();
bool empty = st.empty();

// Queue (STL)
queue<int> q;
q.push(x);
q.pop();
int front = q.front();

// Deque (double-ended)
deque<int> dq;
dq.push_back(x);
dq.push_front(x);
dq.pop_back();
dq.pop_front();
int front = dq.front();
int back = dq.back();
```

---

## Variantes importantes

- **Deque** (double-ended queue) : insertion/suppression aux deux extrémités en O(1)
- **Priority Queue** : voir section Heap

---

## Monotonic Stack

> Une stack dont les éléments sont toujours dans un ordre croissant ou décroissant.

**Signal** : "next greater element", "largest rectangle", "stock span"

```
arr = [2, 1, 5, 3, 4]

Objectif : trouver le prochain élément plus grand pour chaque index

i=0 : stack vide → push 2       → stack: [2]
i=1 : 1 < 2     → push 1       → stack: [2, 1]
i=2 : 5 > 1 → pop 1, next[1]=5
      5 > 2 → pop 2, next[0]=5
              push 5            → stack: [5]
i=3 : 3 < 5     → push 3       → stack: [5, 3]
i=4 : 4 > 3 → pop 3, next[3]=4
              push 4            → stack: [5, 4]

Résultat : [5, 5, -1, 4, -1]
```

```cpp
vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // stocke les indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}
```

---

# 4. Hashing (Map / Set)

## Principe

Le **hashing** permet d'associer une clé à une valeur via une fonction de hachage.

Objectif :

> Accès rapide O(1) en moyenne

---

## Structures principales

### HashMap (unordered_map)

- clé → valeur
- accès rapide

```
"apple"  → 5
"banana" → 3
```

### HashSet (unordered_set)

- stockage de valeurs uniques
- vérification d'existence rapide

```
{1, 2, 3, 4}
```

---

## Complexité

| Opération | Complexité |
|-----------|------------|
| Insertion | O(1) avg |
| Recherche | O(1) avg |
| Suppression | O(1) avg |

⚠️ Worst case : O(n)

### Pourquoi le worst case est O(n) ?

En cas de **collisions** (plusieurs clés mappées au même bucket), la hashmap dégrade en liste chaînée. Toutes les opérations deviennent O(n).

```
Cas normal    : "apple" → bucket 3                        → O(1)
Cas collision : "apple", "mango", "grape" → tous bucket 3 → O(n)
```

En pratique, avec une bonne fonction de hachage, ce cas est rarissime. En compétition, si un juge adversarial force des collisions sur `unordered_map`, préférer `map` (O(log n) garanti).

---

## Cas d'utilisation classiques

- Two Sum
- Détection de doublons
- Frequency counting
- Sliding Window optimisé
- Group anagrams

---

## Templates C++

```cpp
// HashMap
unordered_map<int, int> freq;
freq[x]++;
if (freq.count(x)) { } // existe ?

// HashSet
unordered_set<int> seen;
seen.insert(x);
if (seen.count(x)) { } // existe ?

// Fréquence de mots
unordered_map<string, int> wordCount;
wordCount[word]++;

// Si risque de collision en compétition
map<int, int> safe; // O(log n) garanti
```

---

# 5. Trees (Arbres)

## Principe

Un **arbre** est une structure hiérarchique composée de nœuds reliés par des arêtes, sans cycle.

- Un nœud **racine** (root) au sommet
- Chaque nœud a zéro ou plusieurs **enfants**
- Les nœuds sans enfant sont des **feuilles**

---

## Terminologie

```
        1          ← racine (root)
       / \
      2   3        ← nœuds internes
     / \
    4   5          ← feuilles (leaves)

profondeur de 4 : 2
hauteur de l'arbre : 2
```

---

## Binary Tree (Arbre binaire)

Chaque nœud a au maximum **deux enfants** : gauche et droit.

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

---

## Binary Search Tree (BST)

> Pour tout nœud : valeurs à gauche < nœud < valeurs à droite.

```
        5
       / \
      3   7
     / \ / \
    2  4 6  8
```

| Opération | Complexité (équilibré) | Complexité (dégénéré) |
|-----------|------------------------|------------------------|
| Recherche | O(log n) | O(n) |
| Insertion | O(log n) | O(n) |
| Suppression | O(log n) | O(n) |

---

## Parcours (Traversals)

```
        1
       / \
      2   3
     / \
    4   5
```

| Ordre | Séquence | Principe |
|-------|----------|----------|
| Inorder | 4 2 5 1 3 | gauche → nœud → droite |
| Preorder | 1 2 4 5 3 | nœud → gauche → droite |
| Postorder | 4 5 2 3 1 | gauche → droite → nœud |
| Level-order | 1 2 3 4 5 | BFS niveau par niveau |

```cpp
// Inorder (récursif)
void inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);
    // traiter node->val
    inorder(node->right);
}

// Level-order (BFS)
void levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        // traiter node->val
        if (node->left)  q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// DFS itératif (preorder)
void dfs(TreeNode* root) {
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        // traiter node->val
        if (node->right) st.push(node->right);
        if (node->left)  st.push(node->left);
    }
}
```

---

## Cas d'utilisation classiques

- Lowest Common Ancestor (LCA)
- Validate BST
- Max depth / diameter
- Path sum
- Serialize / deserialize

---

# 6. Heap / Priority Queue

## Principe

Un **heap** est un arbre binaire complet qui respecte la propriété de tas :

- **Min-heap** : le parent est toujours ≤ ses enfants → le minimum est à la racine
- **Max-heap** : le parent est toujours ≥ ses enfants → le maximum est à la racine

En C++, `priority_queue` est un **max-heap** par défaut.

---

## Propriétés

| Opération | Complexité |
|-----------|------------|
| Insertion | O(log n) |
| Suppression du min/max | O(log n) |
| Accès au min/max | O(1) |
| Construction depuis array | O(n) |

---

## Cas d'utilisation classiques

- Top K elements
- K closest points
- Median of data stream
- Dijkstra (plus court chemin)
- Merge K sorted lists

---

## Templates C++

```cpp
// Max-heap (défaut)
priority_queue<int> maxH;
maxH.push(x);
int top = maxH.top();
maxH.pop();

// Min-heap
priority_queue<int, vector<int>, greater<int>> minH;
minH.push(x);
int smallest = minH.top();

// Min-heap de paires (val, index)
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
pq.push({val, idx});

// Top K elements (garder les K plus grands)
priority_queue<int, vector<int>, greater<int>> minH; // taille max K
for (int x : arr) {
    minH.push(x);
    if (minH.size() > k) minH.pop(); // éjecte le plus petit
}
// minH contient les K plus grands
```

---

## Pattern : deux heaps pour la médiane

> Maintenir un max-heap (moitié gauche) et un min-heap (moitié droite) équilibrés.

```cpp
priority_queue<int> lower;                          // max-heap
priority_queue<int, vector<int>, greater<int>> upper; // min-heap

void addNum(int num) {
    lower.push(num);
    upper.push(lower.top()); lower.pop();
    if (upper.size() > lower.size()) {
        lower.push(upper.top()); upper.pop();
    }
}

double getMedian() {
    if (lower.size() > upper.size()) return lower.top();
    return (lower.top() + upper.top()) / 2.0;
}
```

---

# 7. Graphs (Graphes)

## Principe

Un **graphe** est un ensemble de **nœuds** (sommets) reliés par des **arêtes** (edges).

Contrairement à un arbre :
- il n'y a pas de racine
- il peut y avoir des cycles
- un nœud peut avoir un nombre quelconque de voisins

---

## Terminologie

```
    0 --- 1
    |     |
    2 --- 3 --- 4
```

- **Sommet (vertex)** : un nœud (0, 1, 2, 3, 4)
- **Arête (edge)** : lien entre deux sommets
- **Degré** : nombre de voisins d'un sommet
- **Chemin** : séquence de sommets reliés
- **Cycle** : chemin qui revient au point de départ
- **Composante connexe** : sous-ensemble de sommets tous reliés entre eux

---

## Types de graphes

| Type | Description |
|------|-------------|
| **Non orienté** | les arêtes n'ont pas de direction |
| **Orienté (digraphe)** | les arêtes ont une direction (A → B) |
| **Pondéré** | chaque arête a un poids |
| **Non pondéré** | toutes les arêtes ont le même poids |
| **Acyclique** | sans cycle |
| **DAG** | Directed Acyclic Graph — orienté sans cycle |

---

## Représentations

### Liste d'adjacence

> Chaque sommet stocke la liste de ses voisins.

```
0 → [1, 2]
1 → [0, 3]
2 → [0, 3]
3 → [1, 2, 4]
4 → [3]
```

```cpp
// n sommets
vector<vector<int>> adj(n);

// Ajouter une arête non orientée
adj[u].push_back(v);
adj[v].push_back(u);

// Ajouter une arête orientée
adj[u].push_back(v);
```

✅ Recommandé dans la majorité des cas.

---

### Matrice d'adjacence

> Une matrice n×n où `matrix[i][j] = 1` si l'arête (i, j) existe.

```
   0  1  2  3  4
0 [0, 1, 1, 0, 0]
1 [1, 0, 0, 1, 0]
2 [1, 0, 0, 1, 0]
3 [0, 1, 1, 0, 1]
4 [0, 0, 0, 1, 0]
```

```cpp
vector<vector<int>> matrix(n, vector<int>(n, 0));

// Ajouter une arête
matrix[u][v] = 1;
matrix[v][u] = 1; // si non orienté
```

✅ Utile pour vérifier l'existence d'une arête en O(1).  
❌ Coûteux en mémoire : O(n²).

---

## BFS (Breadth-First Search)

> Explore les voisins niveau par niveau.

**Utilisation :**
- Plus court chemin (graphe non pondéré)
- Détection de cycles
- Composantes connexes

```
Graphe :
0 --- 1 --- 3
|
2

BFS depuis 0 :
Niveau 0 : [0]
Niveau 1 : [1, 2]
Niveau 2 : [3]
```

```cpp
void bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        // traiter node

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

---

## DFS (Depth-First Search)

> Explore aussi loin que possible avant de revenir en arrière.

**Utilisation :**
- Détection de cycles
- Composantes connexes
- Topological Sort
- Backtracking

```
Graphe :
0 --- 1 --- 3
|
2

DFS depuis 0 :
0 → 1 → 3 → retour → retour → 2
```

```cpp
// DFS récursif
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    // traiter node

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

// DFS itératif
void dfsIterative(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (visited[node]) continue;
        visited[node] = true;
        // traiter node

        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                st.push(neighbor);
        }
    }
}
```

---

## Graphes sur grille (Grid Graphs)

> Une grille 2D est un graphe implicite : chaque cellule est un sommet, ses voisins sont les 4 cases adjacentes.

```
. . . .
. # . .
. . . #
. . . .

# = obstacle
. = cellule libre
```

```cpp
// Les 4 directions
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// BFS sur grille
void bfsGrid(vector<vector<int>>& grid, int startX, int startY) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<int,int>> q;

    visited[startX][startY] = true;
    q.push({startX, startY});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        // traiter (x, y)

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < rows &&
                ny >= 0 && ny < cols &&
                !visited[nx][ny] &&
                grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
```

---

## Complexité

| Algorithme | Temporelle | Spatiale |
|------------|------------|----------|
| BFS | O(V + E) | O(V) |
| DFS | O(V + E) | O(V) |

où V = nombre de sommets, E = nombre d'arêtes.

---

## Pièges courants

### 1. Oublier le tableau `visited`

Sans `visited`, on boucle indéfiniment sur les cycles.

### 2. Marquer `visited` au mauvais moment (BFS)

❌ mauvais — peut enqueuer le même nœud plusieurs fois :
```cpp
if (!visited[neighbor]) {
    q.push(neighbor);
}
visited[neighbor] = true; // trop tard
```

✅ correct — marquer avant d'enqueuer :
```cpp
if (!visited[neighbor]) {
    visited[neighbor] = true;
    q.push(neighbor);
}
```

### 3. Confondre graphe et arbre

Un arbre est un graphe acyclique connexe. Le DFS sur un arbre n'a pas besoin de `visited` (pas de cycle). Sur un graphe général, `visited` est obligatoire.

### 4. Graphe non connexe

BFS/DFS depuis un seul sommet ne garantit pas de visiter tous les nœuds. Pour couvrir tout le graphe :

```cpp
for (int i = 0; i < n; i++) {
    if (!visited[i])
        dfs(i, adj, visited);
}
```

---

## Cas d'utilisation classiques

| Problème | Algorithme |
|----------|------------|
| Plus court chemin (non pondéré) | BFS |
| Composantes connexes | BFS ou DFS |
| Détection de cycle | DFS |
| Flood fill | BFS ou DFS sur grille |
| Nombre d'îles | DFS sur grille |
| Topological Sort | DFS ou BFS (Kahn) |
| Bipartite check | BFS avec 2-coloring |

---

## Résumé

- **BFS** → niveau par niveau → plus court chemin
- **DFS** → en profondeur → exploration exhaustive
- **Liste d'adjacence** → représentation standard
- **Grille 2D** → graphe implicite, même logique BFS/DFS
- Toujours maintenir un tableau `visited`
- Toujours itérer sur tous les sommets pour les graphes non connexes
---

# Résumé global

| Structure | Usage principal |
|-----------|----------------|
| Arrays & Strings | base de tous les problèmes |
| Prefix Sum | sommes de sous-tableaux en O(1) |
| Linked List | structures dynamiques |
| Stack | LIFO, parsing, DFS |
| Queue | FIFO, BFS |
| Monotonic Stack | next greater element, histogrammes |
| Hashing | recherche rapide, comptage |
| Trees / BST | hiérarchies, recherche ordonnée |
| Heap | min/max dynamique, Top K |
| Graphs | BFS/DFS, composantes connexes, grilles |
---

## Conclusion

Ces structures sont la **base de tout DSA** :

- Arrays & Strings → manipulation directe
- Prefix Sum → optimisation des sommes de ranges
- Linked List → structures dynamiques
- Stack / Queue → ordre contrôlé
- Monotonic Stack → optimisation de patterns séquentiels
- Hashing → optimisation des recherches
- Trees → hiérarchies et recherche ordonnée
- Heap → accès rapide au min/max, problèmes de classement
- Graphs → exploration de réseaux et de grilles
