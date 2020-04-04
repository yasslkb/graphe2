#include<iostream>
#include <ctime>
#include<cstdlib>
using namespace std;

class sommet {
public:
    int valsom;
    sommet* suivant;
};

class arret {
public:
    int source, destination;

};

class graph {
    int N; //nb des sommets.
    //sommet* neveau_Sommet(int, sommet*);
public:
    sommet** tete;
    //graph(arret*, int, int);
    //~graph();


    sommet* neveau_Sommet(int val_S, sommet* tete) {
        sommet* neveauS = new sommet;
        neveauS->valsom = val_S;
        neveauS->suivant = tete;
        return neveauS;
    }



graph(int nbsomm, int dens) {
        this->N = nbsomm;
        tete = new sommet * [N+1];
        srand((unsigned int)time(NULL));
        int prob=0 ; //le nb qui va decider si on ajoute une arrete ou non.
        
        arret* tabdesarret = new arret[N];//tableau des aretes.

        for (int i = 0; i <N; i++) {
            
            tabdesarret[i].source= rand()%N;
            for (int j = 0; j < N; j++) { 
                if (j == i) continue;
                else {
                   
                    prob = rand() % 10;
                    
                    if (prob > dens) {
                        tabdesarret[i].destination = j;
                     
                    }
                }
            }

        }
        
       
            //sizeof(tabdesarret)/sizeof(tabdesarret[0]); 
        int n = N;
        for (int i = 0; i < N; i++) {
            tete[i] = nullptr;
        }

        for (int i = 0; i < n; i++) {
            int source = tabdesarret[i].source;
            int destination = tabdesarret[i].destination;

            sommet* neveauS = neveau_Sommet(destination, tete[source]);
           tete[source] = neveauS;
            //  sommet* neveauS1 = neveau_Sommet(source, tete[destination]);
              //tete[destination] = neveauS1;
        }
    
        

    }
    
    int n = N;
        for (int i = 0; i < N; i++) {
            tete[i] = nullptr;
        }

        for (int i = 0; i < n; i++) {
            int source = tabdesarret[i].source;
            int destination = tabdesarret[i].destination;

            sommet* neveauS = neveau_Sommet(destination, tete[source]);
           tete[source] = neveauS;
            //  sommet* neveauS1 = neveau_Sommet(source, tete[destination]);
              //tete[destination] = neveauS1;
        }
    
        

    }
   
   ~graph() {
        for (int i = 0; i < N; i++) {
            delete tete[i];
        }
        delete[] tete;

    }
};
  

void afficherlistevoisin(sommet* vs) {
    while (vs != NULL) {
        cout << "->" << vs->valsom << " ";
        vs = vs->suivant;
    }
    cout << endl;
}





int main()
{
    
    int N = 40;     
    int dens =4 ;
    graph GA(N, dens);

    for (int i = 0; i < N; i++)
    {
        // print given vertex
        cout << i << " --";

        // print all its neighboring vertices
        afficherlistevoisin(GA.tete[i]);
    }

    return 0;
}
