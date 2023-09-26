const int dynType = CC  //dynamique continue en temps et en espace

// variables
double Bmin = 3600
double k = 900000
double E1max = 2400
double E2max = 1560
double umax = 3500
double vmax = 2000
double r = 0.015

// dimensions
int dim = 3 // dimension de l'état
int dimc = 2 // dimension de contrôle


// fonction dynamique
void dynamics(double * x, double *u, double * image)
{
image[0]= x[0] + r*x[0]*(1 - x[0]/k) - x[1] - x[2]; // modèle logistique avec x[0]=B(t), x[1]=E1(t) et x[2]=E2(t)
}

// contrôle
inline double constraintsXU( double * x, double * u ){
return 1.0;
}

double CONTROL_MIN[dimc]={-umax, -vmax}; // bornes inférieures des variables de contrôle
double CONTROL_MAX[dimc]={umax, vmax}; // bornes supérieures des variables de contrôle


double STATE_MIN [dim] ={Bmin, 0, 0} // bornes inférieures des variables d'état
double STATE_MAX [dim] ={k, Emax, E2max} // bornes supérieures des variables d'état

// Contraintes
//L’ensemble de contraintes dans cet exemple coı̈ncide avec le domaine de calcul. On le
//définit alors comme suit :
inline double constraintsX( double * x ){
return 1.0;
}

// On définit également les paramètres de discrétisation de ce pavé.
unsigned int nbPointsControl [dimc] = {401, 401}
unsigned int nbPointsState [dim] = {401, 401, 401} 

//Le paramètre suivant permet d’indiquer quelle représentation d’ensembles utiliser :
//BS : fonction caractéristique
int gridMethod=BS;

//Le paramètre suivant définit le type d’ensemble à calculer. Ici il s’agit du noyau de viabilité.
int setType=VIAB;

//Le paramètre suivant permet d’indiquer s’il faut recalculer l’ensemble ou le charger depuis une
//sauvegarde (pour un calcul de trajectoire, par exemple).
int computeSet=1;

//L’utilisateur peut définir un préfix qui sera utilisé pour nommer tous les fichiers de sortie produits
//par le code. Cela permet de ne pas effacer les résultats des calculs précédents.
string prefix="pêche--";

