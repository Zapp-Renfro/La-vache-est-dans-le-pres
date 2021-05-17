#include <iostream>
#include <cmath>
#include <math.h>
#define N 50

using namespace std;

//calcule l'aire de la enclos
long double  aire (long double abscisse[N],long double ordonne[N],int taille){
    long double somme = 0;
    for(int i=0;i<taille;i++){
        somme = somme + (abscisse[i]*ordonne[(i+1)%taille] - abscisse[(i+1)%taille]*ordonne[i]);
    }
return(somme/2);
}

// calcule l'abscisse du centre de gravité
long double grav_abs (long double abscisse[N],long double ordonne[N],int taille){
    long double somme = 0;
    long double AIRE;
    AIRE = aire(abscisse,ordonne,taille);
    cout << "L'aire est de : " << AIRE << endl;
    for(int i=0;i<taille;i++){
        somme = somme + ((abscisse[i]+abscisse[(i+1)%taille])*(abscisse[i]*ordonne[(i+1)%taille] - abscisse[(i+1)%taille]*ordonne[i]));
    }
return(1/(AIRE*6)*somme);
}
//calcule l'ordonné du centre de gravité
long double grav_ordo (long double abscisse[N],long double ordonne[N],int taille){
    long double somme = 0;
    long double AIRE;
    AIRE = aire(abscisse,ordonne,taille);
    for(int i=0;i<taille;i++){
        somme = somme + ((ordonne[i]+ordonne[(i+1)%taille])*(abscisse[i]*ordonne[(i+1)%taille] - abscisse[(i+1)%taille]*ordonne[i]));
    }
return(1/(AIRE*6)*somme);
}

//verifie si le centre de gravité est dans l'enclos
void appartien (long double abscisse[N],long double ordonne[N],int taille){
    //sauvegrade l'abscisse du centre de gravité pour pas avoir a le calculer plusieur fois.
    long double a_grav = grav_abs(abscisse,ordonne,taille);
    //idem pour l'ordonné
    long double o_grav = grav_ordo(abscisse,ordonne,taille);
    cout << "Le centre de gravite a pour coordonne : " << a_grav << " ; " << o_grav << endl;

    long double somme = 0;
    for(int i=0;i<taille;i++){
        // vec1_1 et vec1_2 sont les normes du vecteur 1
        long double vec1_1 = abscisse[i] - a_grav;
        long double vec1_2 = ordonne[i] - o_grav;
        // vec2_1 et vec2_2 sont les normes du vecteur 2
        long double vec2_1 = abscisse[(i+1)%taille] - a_grav;
        long double vec2_2 = ordonne[(i+1)%taille] - o_grav;
        //produit scalaire
        long double scal = (vec1_1*vec2_1)+(vec1_2*vec2_2);
        //multiplication des deux vecteurs
        long double vecteur = sqrt(vec1_1*vec1_1+vec1_2*vec1_2)*sqrt(vec2_1*vec2_1+vec2_2*vec2_2);
        //l'angle en radian en utilisant arccosinus
        long double angle = acos(scal/vecteur);

        somme = somme + angle;

    }
    //On utilise un encadrement parce que le resultat n'est jamais assez précis au point d'être égale a 2 PI
    if(somme>=6.28318 && somme<=6.28320){
        cout << "la vache est dans l'eclos" << endl;
    }
    else{
        cout << "la vache s'echape" << endl;
    }
}



int main()
{
    //On utilise des long double pour pouvoir être le plus precis possible au vu du nombre de calcule.
    long double abss[N];
    long double ordo[N];
    int piquet;
    cout << "Nombre de piquet" << endl;
    cin >> piquet;
    for (int i=0;i<piquet;i++){
        cout << "Saisir piquet " << i+1 << endl;
        cout << "Abcisse : ";
        cin >> abss[i];
        cout << endl;
        cout << "Ordonne : ";
        cin >> ordo[i];
    }


    appartien(abss,ordo,piquet);

}

