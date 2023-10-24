# FisheryViability

## Installer viabLab sur ubuntu 

## faire tourner un premier modele : delimiter un noyau de viabilité 

On installe dans un premier temps les dependances 
```bash
apt-get install cmake
apt-get install gcc
apt-get install libboost-dev-all
```

se mettre dans le repertoire VIABLAB/source

```bash
cmake .
make
./viabLabExe 
```

## faire tourner un deuxieme modele :

creer un fichier .h dans VIABLAB/source/data
creer un fichier .json dans VIABLAB/INPUT

```bash
make
./viabLabExe 
``` 
recuperer le fichier resultat dans VIABLAB/OUTPUT
