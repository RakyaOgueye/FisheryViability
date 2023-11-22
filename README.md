# FisheryViability

## Installer viabLab sur ubuntu 

On installe dans un premier temps les dependances 
```bash
apt-get install cmake
apt-get install gcc
apt-get install libboost-dev-all
```

se mettre dans le repertoire `VIABLAB/source`

```bash
cmake .
make
```
Une fois le `make` executé la compilation doit avoir produit un executable qu'on peut lancer comme cela :
```
./viabLabExe 
```
VIABLAB s'execute alors sur un modèle près enregistré. Les résultats du modèle sont à retrouver dans le repertoire `OUTPUT`

## faire tourner un premier modele :

Comme vous avez déjà fait tourner viablab, il faudra refaire la compilation en netoyant le cache avec `make clean`

1. Ensuite vous pourrez déplacer le fichier `ModelDataInclusion.h` et `model_peche.h` dans `VIABLAB/source/data`
2. Deplacer le fichier `peche.json` dans `VIABLAB/INPUT`
3. lancer la compilation avec `make`
4. executer votre modèle `./viabLabExe`

les resultats sont alors générer dans `OUTPUT` avec le préfix `peche`

## Le fonctionnement générique

creer un fichier `.h` dans `VIABLAB/source/data` qui va contenir les dynamiques du systèmes, les contraintes, *etc.*
creer un fichier `.json` dans `VIABLAB/INPUT` on trouvera les parametre du systèmes, les variables d'état et de controle.

ajouter `string paramsFile = "fichier.json"` et `#include "../data/fichier.h"` dans `VIABLAB/source/data/ModelDataInclusion.h`
Une fois que les fichier ont les bon pointeurs, dans le terminal on va dans le répertoire `VIABLAB/source` pour lancer les commandes suivantes :
```bash
make
./viabLabExe 
``` 
Les fichiers résultat sont produits dans `VIABLAB/OUTPUT`sous forme de fichier `.dat`que l'on peut ensuite manipuler avec python ou R. 
