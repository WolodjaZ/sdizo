//
// Created by vladimir on 24.04.19.
//

#include "menu.h"

using namespace std;
menu::menu() {
    int petla=0;
    do {
        int x;
        cout << "POJEKT SDIZO NR1" << endl;
        cout << "1 - Problem najmniejszego drzewa rozpinającego" << endl;
        cout << "2 - Problem najkrótszej ścieżki" << endl;
        cout << "3 - Zakoncz program" << endl;

        cin >> x;
        switch (x) {
            case 1:
                MST();
                petla=0;
                break;
            case 2:
                QPG();
                petla=0;
                break;
            case 3:
                petla=1;
                break;
            default: {
                cout << "Error"<<endl;
                break;

            }
        }
    }while(petla==0);
}

menu::~menu() {

}

void menu::MST() {
    string path;
    List_graph Lista;
    Matrix_graph Macierz;
    int koniec = 0;
    do {
        int x;
        cout << "1 - Stworz losowo generowana liste sasiadow" << endl;
        cout << "2 - Stworz losowo generowana macierz sasiedaow" << endl;
        cout << "3 - Wczytaj liste sasiadow z pliku" << endl;
        cout << "4 - Wczytaj macierz sasiadow z pliku" << endl;
        cout << "5 - Wczytaj liste i macierz sasiadow z pliku" << endl;
        cout << "6 - Wypisz wynik algorytmu Kruskala dla listy" << endl;
        cout << "7 - Wypisz wynik algorytmu Kruskala dla macierzy" << endl;
        cout << "8 - Wypisz wynik algorytmu Prima dla listy" << endl;
        cout << "9 - Wypisz wynik algorytmu Prima dla macierzy" << endl;
        cout << "10 - Wypisz wynik algorytmu Kruskala dla listy i macierzy" << endl;
        cout << "11 - Wypisz wynik algorytmu Prima dla listy i macierzy" << endl;
        cout << "12 - Wydrukuj graf dla listy" << endl;
        cout << "13 - Wydrukuj graf dla macierzy" << endl;

        cout << "14 - zakoncz program" << endl;
        cin >> x;
        cout << endl;
        switch (x) {
            case 1:
                int ilosc;
                int max;
                int min;
                int density;
                cout << "Ilu wierzchołków ma mieć graf?" << endl;
                cin >> ilosc;
                cout << "Jaka ma być gęstość grafu podana w procentach" << endl;
                cin >> density;
                cout << "Maxymalna wartość krawędzi w grafie?" << endl;
                cin >> max;
                cout << "Minimalna wartość krawędzi w grafie?" << endl;
                cin >> min;
                Lista.generator(ilosc, density, 0, max, min);
                Lista.print(nullptr, 0);
                cout << endl;
                break;
            case 2:
                cout << "Ilu wierzchołków ma mieć graf?" << endl;
                cin >> ilosc;
                cout << "Jaka ma być gęstość grafu podana w procentach" << endl;
                cin >> density;
                cout << "Maxymalna wartość krawędzi w grafie?" << endl;
                cin >> max;
                cout << "Minimalna wartość krawędzi w grafie?" << endl;
                cin >> min;
                Macierz.generator(ilosc, density, 0, max, min);
                Macierz.print(nullptr, 0);
                cout << endl;
                break;
            case 3:
                cout << "Podaj scieżke do pliku" << endl;
                cin >> path;
                Lista.readFromFile(path, 0);
                Lista.print(nullptr, 0);
                cout << endl;
                break;
            case 4:
                cout << "Podaj scieżke do pliku" << endl;
                cin >> path;
                Macierz.readFromFile(path, 0);
                Macierz.print(nullptr, 0);
                cout << endl;
                break;
            case 5:
                cout << "Podaj scieżke do pliku" << endl;
                cin >> path;
                Lista.readFromFile(path, 0);
                Lista.print(nullptr, 0);
                Macierz.readFromFile(path, 0);
                Macierz.print(nullptr, 0);
                cout << endl;
                break;
            case 6:
                cout << "Algorytm Kruskala dla listy" << endl;
                Lista.Kruskal_algorithm();
                cout << endl;
                break;
            case 7:
                cout << "Algorytm Kruskala dla macierzy" << endl;
                Macierz.Kruskal_algorithm();
                cout << endl;
                break;
            case 8:
                cout << "Algorytm Prima dla listy" << endl;
                Lista.Prims_algorithm();
                cout << endl;
                break;
            case 9:
                cout << "Algorytm Prima dla macierzy" << endl;
                Macierz.Prims_algorithm();
                cout << endl;
                break;
            case 10:
                cout << "Algorytm Kruskala dla listy i macierzy" << endl;
                Lista.Kruskal_algorithm();
                Macierz.Kruskal_algorithm();
                cout << endl;
                break;
            case 11:
                cout << "Algorytm Prima dla listy i macierzy" << endl;
                Lista.Prims_algorithm();
                Macierz.Prims_algorithm();
                cout << endl;
                break;
            case 12:
                Lista.print(nullptr, 0);
                cout << endl;
                break;
            case 13:
                Macierz.print(nullptr, 0);
                cout << endl;
                break;
            case 14:
                koniec = 1;
                break;
        }
    } while (koniec == 0);
}

void menu::QPG() {
    string path;
    List_graph Lista;
    Matrix_graph Macierz;
    int koniec = 0;
    do {
        int x;
        cout << "1 - Stworz losowo generowana liste sasiadow" << endl;
        cout << "2 - Stworz losowo generowana macierz sasiedaow" << endl;
        cout << "3 - Wczytaj liste sasiadow z pliku" << endl;
        cout << "4 - Wczytaj macierz sasiadow z pliku" << endl;
        cout << "5 - Wczytaj liste i macierz sasiadow z pliku" << endl;
        cout << "6 - Wypisz wynik algorytmu Dijkstry dla listy" << endl;
        cout << "7 - Wypisz wynik algorytmu Dijkstry dla macierzy" << endl;
        cout << "8 - Wypisz wynik algorytmu Bellmana-Forda dla listy" << endl;
        cout << "9 - Wypisz wynik algorytmu Bellmana-Forda dla macierzy" << endl;
        cout << "10 - Wypisz wynik algorytmu Dijkstry dla listy i macierzy" << endl;
        cout << "11 - Wypisz wynik algorytmu Bellmana-Forda dla listy i macierzy" << endl;
        cout << "12 - Wydrukuj graf dla listy" << endl;
        cout << "13 - Wydrukuj graf dla macierzy" << endl;

        cout << "14 - zakoncz program" << endl;
        cin >> x;
        cout << endl;
        switch (x) {
            case 1:
                int ilosc;
                int max;
                int min;
                int density;
                cout << "Ilu wierzchołków ma mieć graf?" << endl;
                cin >> ilosc;
                cout << "Jaka ma być gęstość grafu podana w procentach" << endl;
                cin >> density;
                cout << "Maxymalna wartość krawędzi w grafie?" << endl;
                cin >> max;
                cout << "Minimalna wartość krawędzi w grafie?" << endl;
                cin >> min;
                Lista.generator(ilosc, density, 1, max, min);
                Lista.print(nullptr, 0);
                cout << endl;
                break;
            case 2:
                cout << "Ilu wierzchołków ma mieć graf?" << endl;
                cin >> ilosc;
                cout << "Jaka ma być gęstość grafu podana w procentach" << endl;
                cin >> density;
                cout << "Maxymalna wartość krawędzi w grafie?" << endl;
                cin >> max;
                cout << "Minimalna wartość krawędzi w grafie?" << endl;
                cin >> min;
                Macierz.generator(ilosc, density, 1, max, min);
                Macierz.print(nullptr, 0);
                cout << endl;
                break;
            case 3:
                cout << "Podaj scieżke do pliku" << endl;
                cin >> path;
                Lista.readFromFile(path, 1);
                Lista.print(nullptr, 0);
                cout << endl;
                break;
            case 4:
                cout << "Podaj scieżke do pliku" << endl;
                cin >> path;
                Macierz.readFromFile(path, 1);
                Macierz.print(nullptr, 0);
                cout << endl;
                break;
            case 5:
                cout << "Podaj scieżke do pliku" << endl;
                cin >> path;
                Lista.readFromFile(path, 1);
                Lista.print(nullptr, 0);
                Macierz.readFromFile(path, 1);
                Macierz.print(nullptr, 0);
                cout << endl;
                break;
            case 6:
                cout << "Algorytm Dijkstry dla listy" << endl;
                Lista.Dijikstras_algorithm();
                cout << endl;
                break;
            case 7:
                cout << "Algorytm Dijkstry dla macierzy" << endl;
                Macierz.Dijikstras_algorithm();
                cout << endl;
                break;
            case 8:
                cout << "Algorytm Bellmana-Forda dla listy" << endl;
                Lista.Bellmana_Forda_algorithm();
                cout << endl;
                break;
            case 9:
                cout << "Algorytm Bellmana-Forda dla macierzy" << endl;
                Macierz.Bellmana_Forda_algorithm();
                cout << endl;
                break;
            case 10:
                cout << "Algorytm Dijkstry dla listy i macierzy" << endl;
                Lista.Dijikstras_algorithm();
                Macierz.Dijikstras_algorithm();
                cout << endl;
                break;
            case 11:
                cout << "Algorytm Bellmana-Forda dla listy i macierzy" << endl;
                Lista.Bellmana_Forda_algorithm();
                Macierz.Bellmana_Forda_algorithm();
                cout << endl;
                break;
            case 12:
                Lista.print(nullptr, 0);
                cout << endl;
                break;
            case 13:
                Macierz.print(nullptr, 0);
                cout << endl;
                break;
            case 14:
                koniec = 1;
                break;
        }
    } while (koniec == 0);
}
