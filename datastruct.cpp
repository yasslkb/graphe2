#include<iostream>
using namespace std;

class sommet {
public:
    int valsom;    // hadi hiya la valeur ta3 sommet .  
    sommet* suivant; // hadi hiya l pointeur sur le sommet suivant .
};

class arret {
public:
    int source, destination; // hadi class arrret drnaha ghir bax n7to fih les valeurs ta3 sommet source o sommet destination bax tshal 3lina remplisage ta3 liste chinee(liste d'adjacence) ta3 les sommet 
                               // ghir des int kafyin 7it m7taj ghir l valeurs ta3 source w ta3 dest dima kaykono des entiers.
};

class graph {
    int N; //nb des sommets.
    //sommet* neveau_Sommet(int, sommet*); // hadi ghir prototype fax ghadi nbghiw n9samo les fichiers ghadi n 7ydohom mn commentaire.
public:
    sommet** tete;// hada tableau ta3 les pointeurs de type sommet 7it ghadi nkriyiw tableau qui contient des liste chinee c-a-d tableau lifih les adress ta3 dok les tete ta3 kola liste d'adjacence.
    //graph(arret*, int, int);
    //~graph();


    sommet* neveau_Sommet(int val_S, sommet* tete) {   // hadi fonction li ka t cree des sommet jdad o kat7t lihom comme vals hadik val_s li mn b3d f creation ta3 l graph ghadi n3wdoha b dik destination li f class arrete 7it hadi liste chinee ta3 les voisin (ghadi nxr7ha mzn f constricteur.)
        sommet* neveauS = new sommet;//reservation memoir ta3 dak sommet.
        neveauS->valsom = val_S;
        neveauS->suivant = tete;// dak suivant ta3 had sommet jdid ghadi n7to fiha l'@ ta3 la tete dyal la liste 7it hna drna liste chinne m9loba sommet jdid kaypointer 3la la tete ta3 la liste bax t kon l'ansertion ta3 les sommet bzerba maxii nb9a dima n parcourer la liste 7ta lkhar 3ad n7t sommet jdid kif ma f la liste chinne 3adiya .
        return neveauS;// hna kanrdo l'@ ta3 had sommet jdid ghadi nxofo f constricteur fax ghadi nfhmo mzyan.
    }

    graph(arret* Arrets, int n, int N) {
        //kandwzo comme argument tableau ta3 les arrete w n le nombre ta3 les arrete et N le nb ta3 les sommet.
        
        this->N = N;//hadi kangolo b li dik N li f les attributs ta3 class graph katsawi N li dwzna f argument.
        tete = new sommet * [N];//hna kandiro wahd reservation memeoir dyal tableauu ta3 les@ d les tete d les liste chinee.
        for (int i = 0; i < N; i++) {
            tete[i] = nullptr;//hna boucle ka n initialisiw hom kamlin comme nullptr ghir bax mankhliwhomx hkdak i9dr tkon f dok les casses memoir xi valeur 9dima li tkhsrna les resultet. hadik nullptr kayn li ghadi tkhdm lih kayn li la 3la 7sab version ta3 c++ li makhdmatx lih ibdlha b NULL(majuscule).
            
        }

        for (unsigned i = 0; i < n; i++) {
            int source = Arrets[i].source;//hna crryina var jdid smito source li kan7to fih source ta3 tableau arrete li dwzna comme argument.
            
            int destination = Arrets[i].destination;//hna nafs l7aja drnaha l destination.

            sommet* neveauS = neveau_Sommet(destination, tete[source]);//hna cryina sommet jdidi 7tani fih comme valeur destination w 3tinah comme @tete ta3 la liste 3lax i pointer tete[source]
            tete[source] = neveauS;//hna fin kayna xwiya d so3oba ,7it kanbdlo dik la tete ta3 la liste katwli la tete hiya hadak sommet jdid 
            //exemple : cree un graph fih  comme des tabl d'arretes {{0,1},{0,2},{0,3},{0,4}}
            //1etape cree tableau ta3 des pointeur des sommet
            //2etape initialiser had le tableau b nullptr
            //3etape cree somme 1 li ghadi i pointer 3 la la tete li 3tinah li ghadi tkon f had l7ala 0  ghadi nb dlo dik tete[source]=tete[0] b l'@ dyal sommet 1  ghadi tete[source=0]=@ de 1
          // 5etep ghadi n cree sommet 2 li 3ndo comme tete[source]=tete[1] donc 2 ghadi t pointer 3la 1. w ghadi nbdolo 3aw tani tete[1]=@de2
            //6 etepa ghadi n cree sommet 3 li ghadi ikon 3ndo tete[source]=tete[2] donc 3 ghadi t pointer 3la 2. w ghadi nbdlo 3aw tani tete[2] = @de 3
            // w b7al ma hakda 7ta nkmlo donk ghadi twli 2dna had liste :pour sommet 0:4-->3-->2-->1 
            // 7it l'ordre bax kandkhlhom ma kayhmx dakxi bax wakh nglbhom maxi moxkil b l3aks ghadi nrb7o ou terme de complexity 7it ma kanb9ax n parcourer la liste kamla bax n insirer hadak sommet w inama ka ndkhlo f lwl .
            
            
            
            
            //hado nafs l7aja ghir had lmra ila bghina graph non oriante.
            //  sommet* neveauS1 = neveau_Sommet(source, tete[destination]);
              //tete[destination] = neveauS1; 
        }
    }


    ~graph() {
        for (int i = 0; i < N; i++) {
            delete tete[i]; //hada destricteur f lwl kanhras hadok les liste .
        }
        delete[] tete;//hna knhras tableau kaml (mn sghir lkbir ).

    }
};

void afficherlistevoisin(sommet* vs) {//hadi ghir l'affichage ka takhd pointeur ta3 sommet bax t affichih
    while (vs != nullptr) {
        cout << "->" << vs->valsom << " ";
        vs = vs->suivant;
    }
    cout << endl;
}

int main()
{
    // tableau d'arrete.
    arret edges[] =
    {
        // hada exemple ta3 dik tableau d'arrete {source,destination} c-a-d kayna arrte mn source-->destination.
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 7 },

    };

    // nb ta3 les sommet hada ghir exemple.
    int N = 6;

    // calculate number of edges
    int n = sizeof(edges) / sizeof(edges[0]);//hna bax n7sbo x7al mn arret dkhl utilistaeur ka taille ta3 tableau des arrete kaml 3la case whda mn dak tableau(case fiha source et destination)
    

    // construir le graph drna apelle l graph.
    graph GA(edges, n, N);

    // affiche la liste d'adjacence.
    for (int i = 0; i < N; i++)
    {
        //afficher l'index de sommet. 
        cout << i << " --";

        //apelle l dik fonction li drna l fo9.  
        afficherlistevoisin(GA.tete[i]);
    }

    return 0;
}
