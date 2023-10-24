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

## faire tourner un premier modele :

creer un fichier `.h` dans `VIABLAB/source/data` qui va contenir les dynamiques du systèmes, les contraintes, *etc.*
creer un fichier `.json` dans `VIABLAB/INPUT` on trouvera les parametre du systèmes, les variables d'état et de controle.

ajouter `string paramsFile = "fichier.json"` et `#include "../data/fichier.h"` dans `VIABLAB/source/data/ModelDataInclusion.h`
Une fois que les fichier ont les bon pointeurs, dans le terminal on va dans le répertoire `VIABLAB/source` pour lancer les commandes suivantes :
```bash
make
./viabLabExe 
``` 
Les fichiers résultat sont produits dans `VIABLAB/OUTPUT`sous forme de fichier `.dat`que l'on peut ensuite manipuler avec python ou R. 
