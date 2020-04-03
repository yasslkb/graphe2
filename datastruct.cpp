#include<iostream>
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

    graph(arret* Arrets, int n, int N) {
        this->N = N;
        tete = new sommet * [N];
        for (int i = 0; i < N; i++) {
            tete[i] = nullptr;
        }

        for (unsigned i = 0; i < n; i++) {
            int source = Arrets[i].source;
            int destination = Arrets[i].destination;

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
    while (vs != nullptr) {
        cout << "->" << vs->valsom << " ";
        vs = vs->suivant;
    }
    cout << endl;
}

int main()
{
    // array of graph edges as per above diagram.
    arret edges[] =
    {
        // pair (x, y) represents edge from x to y
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 7 },

    };

    // Number of vertices in the graph
    int N = 6;

    // calculate number of edges
    int n = sizeof(edges) / sizeof(edges[0]);

    // construct graph
    graph GA(edges, n, N);

    // print adjacency list representation of graph
    for (int i = 0; i < N; i++)
    {
        // print given vertex
        cout << i << " --";

        // print all its neighboring vertices
        afficherlistevoisin(GA.tete[i]);
    }

    return 0;
}
