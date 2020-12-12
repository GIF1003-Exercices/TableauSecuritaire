# GIF1003-Revision-finale-Templates

Notions révisées:

Templates
Allocation dynamique
Exception
Méthodes virtuelles
Contrat 
Unit tests

NB: Je ne suis pas le professeur et ne prétends pas le remplacer.  J'ai fait cet exerice pour mon propre bénéfice et il me fait plaisir de le 
partager.  Mes solutions sont peut-être imparfaites, j'ai surement commis des erreurs et je serai heureux de connaitre vos critiques et corrections!
Mais ultimement, la validité de cet exercice n'est pas garantie.

Aussi, j'ai gardé les algorithmes les plus simples: donc pas de sémantique "copy-swap" ou "move", juste du barebone

## Énoncé de l'exercice:  commencez en copiant TableauSecuritaire.h

On désire implémenter un patron de classe TableauSecuritaire qui sera, comme son nom l'indique, une version plus sécuritaire des tableaux du C.
Cette classe aura les fonctionnalités suivantes:

Constructeur par défaut: vide!
Constructeur permettant d'initialiser un tableau contenant n fois une valeur donnée v.

Opérateur == retournant true si les deux tableaux ont les mêmes valeurs dans le même ordre
Opérateur [n] permettant de lire et modifier la valeur au rang n

Le membre taille, retournant le nombre d'éléments
Le membre retirer() permettant de retirer le dernier élément et le retourner
Le membre annexer() équivalent de push_back
Le membre req(i) permettant de lire le rang i

De plus, vu que l'allocation du tableau se fera sur le tas, avec l'opérateur new, il faudra prévoir que cette classe devra avoir la forme canonique de Coplien 
on devra donc implémenter:

Le constructeur de copie
L'opérateur d'assignation
Le destructeur

De plus, vu que notre classe est sécuritaire, il faudra penser à protéger la classe contre des index hors-limite, toute tentative de lire ou écrire out
of bounds devrait lancer une exception appropriée, et on ne devrait pas non plus tenter de retirer un élément d'un tableau vide.

Il faudra donc aussi écrire une classe TSTLogicException dérivée de logic_error.  Celle-ci aura deux classe dérivées: TSTIndiceHorsLimiteException et 
TSTEffacerTableauVideException.  Le rôle de ces exceptions est de donner au caller le contexte adéquat des erreurs (quelle erreur a été commise, valeur de l'indice 
fautif)

Notre classe TableauSecuritaire devra de plus être écrite en version de développement, avec contrat a l'appui, en utilisant les outils ContratException du 
cours.

Pour développer un invariant qui soit utile, nous allons imposer la convention suivante: le cardinal d'un tableau est positif ou nul.  S'il est nul, l'adresse des 
données devrait être le pointeur nul, si le cardinal est positif, l'adresse ne devrait pas être le pointeur nul.

ATTENTION: Il y a une différence entre les exceptions du contrat, qui sont éventuellement désactivées, et les exceptions TSTException qui visent à protéger
le caller contre des situations qui peuvent toujours survenir, même si notre classe est valide.  

FINALEMENT: Vous devez créer un testeur googletest pour la classe...
