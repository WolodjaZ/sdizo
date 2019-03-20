//
// Created by vladimir on 20.03.19.
//

#include "menu.h"

using namespace std;
menu::menu() {

    int petla=1;
    do {
        int x;
        cout << "POJEKT SDIZO NR1" << endl;
        cout << "1 - Tablica" << endl;
        cout << "2 - Lista" << endl;
        cout << "3 - Kopiec Binarny" << endl;
        cout << "4 - Drezwo przeszukiwań binarnych" << endl;
        cout << "5 - Drzewo Czerwono-Czarne" << endl;

        cin >> x;
        switch (x) {
            case 1:
                Tablica();
                petla=0;
                break;
            case 2:
                Lista();
                petla=0;
                break;
            case 3:
                BinaryHeap();
                petla=0;
                break;
            case 4:
                Bst();
                petla=0;
                break;
            default: {
                cout << "Error";
                break;

            }
        }
    }while(petla==1);
}
void menu::Lista() {
    string path;
    My_list2 Lista;
    int koniec=0;
    do {
        int x;
        int element;
        cout << "1 - Stworz losowo generowana liste" << endl;
        cout << "2 - Wczytaj liste z pliku" << endl;
        cout << "3 - Dodaj   liczbe do listy na poczatku" << endl;
        cout << "4 - Dodaj  liczbe do listy na koncu " << endl;
        cout << "5 - usun ostatni element"<<endl;
        cout << "6 - usun pierwszy element"<<endl;
        cout << "7 - Wyszukaj element w liscie" << endl;
        cout << "8 - Wyswietl Liste"<<endl;
        cout << "9 - dodaj za liczba" << endl;
        //cout << "10 - Test" << endl;

        cout << "10 - zakoncz program" << endl;
        cin>>x;
        cout<<endl;
        switch (x) {
            case 1:
                int ilosc;
                int max;
                int min;
                cout << "Ilu elementowa ma być lista?" << endl;
                cin >> ilosc;
                cout << "Maxymalny element w liście?" << endl;
                cin >> max;
                cout << "Minimalny element w liście?" << endl;
                cin >> min;
                Lista.create_random(ilosc, min, max);
                cout << endl;
                break;
            case 2:
                cout<<"Podaj sciezke do pliku"<<endl;
                cin >>path;
                Lista.create_from_a_file(path);
                break;
            case 3:

                cout<<"jaka liczba ma zostac dodana?"<<endl;
                cin>>element;
                Lista.push_front(element);
                break;
            case 4:
                cout<<"jaka liczba ma zostac dodana?"<<endl;
                cin>>element;
                Lista.push_tail(element);
                break;
            case 5:
                cout<<"usun ostatni element"<<endl;
                Lista.pop_tail();
                cout<<"Ostatni element zostal usuniety pomyslnie"<<endl;
                break;
            case 6:
                cout<<"usun pierwszy elemnet"<<endl;
                Lista.pop_front();
                cout<<"Poczatkow element zostal usuniety pomyslnie"<<endl;
                break;
            case 7:
                cout<<"jakiej wartosci szukasz?"<<endl;
                cin>>element;
                Lista.find_by_value(element);
                break;
            case 8:
                Lista.print();
                break;
            case 9:
                int szukany;
                cout<<"podaj index w który ma być wpisany elemnet?"<<endl;
                cin>>szukany;
                cout<<endl<<"jaka liczba ma zostac dodana"<<endl;
                cin>>element;
                Lista.add(szukany,element);

                break;

            case 10:
                koniec=1;
                break;
        }
    }while(koniec==0);
}
void menu::Tablica() {
    My_array2 Tablica;
    int koniec=0;
    do {
        int x;
        string path;
        int element;
        cout << "1 - Stworz losowo generowana tablice" << endl;
        cout << "2 - Wczytaj tablice z pliku" << endl;
        cout << "3 - Dodaj   liczbe do tablicy na poczatku" << endl;
        cout << "4 - Dodaj  liczbe do tablicy na koncu " << endl;
        cout << "5 - Usun liczbe z konca tablicy" << endl;
        cout << "6 - Usun liczbe z poczatku tablicy" << endl;
        cout << "7 - Wyszukaj element w tablicy" << endl;
        cout << "8 - Wyswietl tablce"<<endl;
        cout <<" 9 - Dodaj liczbe w okreslonym miejscu "<<endl;
        cout << "10 - Usun Liczbe z okreslonego miejsca"<<endl;
        //cout << "11 - Testy" << endl;
        cout << "11 - zakoncz program" << endl;
        cin>>x;
        cout<<endl;
        switch (x) {
            case 1:
                int ilosc;
                int max;
                int min;
                cout << "Ilu elementowa ma być tablica?" << endl;
                cin >> ilosc;
                cout << "Maxymalny element w tablica?" << endl;
                cin >> max;
                cout << "Minimalny element w tablica?" << endl;
                cin >> min;
                Tablica.create_random(ilosc, min, max);
                cout << endl;
                break;
            case 2:
                cout<<"Podaj sciezke do pliku"<<endl;
                cin >>path;
                Tablica.create_from_a_file(path);
                break;
            case 3:

                cout<<"jaka liczba ma zostac dodana?"<<endl;
                cin>>element;
                Tablica.push_front(element);
                break;
            case 4:
                cout<<"jaka liczba ma zostac dodana?"<<endl;
                cin>>element;
                Tablica.push_tail(element);
                break;
            case 5:
                Tablica.pop_tail();
                cout<<"Ostatni element zostal usuniety pomyslnie"<<endl;
                break;
            case 6:
                Tablica.pop_front();
                cout<<"Poczatkow element zostal usuniety pomyslnie"<<endl;
                break;
            case 7:
                cout<<"jakiej wartosci szukasz?"<<endl;
                cin>>element;
                Tablica.find(element);
                break;
            case 8:
                Tablica.print();
                break;
            case 9:
                int szukany;
                cout<<"W jakim miejscu  umiescic liczbe?"<<endl;
                cin>>szukany;
                cout<<endl<<"jaka liczba ma zostac dodana"<<endl;
                cin>>element;
                Tablica.add(szukany, element);
                break;
            case 10:
                cout<<"z jakiego miejsca chcesz usunac liczbe?"<<endl;
                cin>>szukany;
                Tablica.remove(szukany);
                break;
            case 11:
                koniec=1;
                break;
        }
    }while(koniec==0);
}
void menu::BinaryHeap() {
    int size;
    cout<<"Jak duży ma być max kopiec?"<<endl;
    cin>>size;
    My_binary_heap BinaryHeap = My_binary_heap(size);
    int koniec=0;
    do {
        int x;
        string path;
        int element;
        cout << "1 - Stworz losowo generowany kopiec binarny" << endl;
        cout << "2 - Wczytaj kopiec z pliku" << endl;
        cout << "3 - Dodaj   element do kopca" << endl;
        cout << "4 - Usun liczbe z kopca" << endl;
        cout << "5 - Wyszukaj element w kopcu" << endl;
        cout << "6 - Wyswietl kopiec"<<endl;
        cout << "7 - zakoncz program" << endl;
        cin>>x;
        cout<<endl;
        switch (x) {
            case 1:
                int ilosc;
                int max;
                int min;
                cout << "Ilu elementowa ma być kopiec?" << endl;
                cin >> ilosc;
                cout << "Maxymalny element w kopiec?" << endl;
                cin >> max;
                cout << "Minimalny element w kopiec?" << endl;
                cin >> min;
                BinaryHeap.create_random(ilosc, size, min, max);
                break;
            case 2:
                cout<<"podaj sciezke do pliku"<<endl;
                cin>>path;
                BinaryHeap.create_from_a_file(size, path);
                break;
            case 3:

                cout<<"jaka liczba ma zostac dodana?"<<endl;
                cin>>element;
                BinaryHeap.add(element);
                break;
            case 4:
                cout<<"jaka liczba ma zostac usunieta?"<<endl;
                cin>>element;
                BinaryHeap.remove(element);
                break;
            case 5:
                cout<<"jakiego elementu szukasz?"<<endl;
                cin>>element;
                BinaryHeap.find(element);
                break;
            case 6:
                BinaryHeap.print();
                break;
            case 7:
                koniec=1;

        }
    }while(koniec==0);
}

void menu::Bst() {
    My_binary_search_tree Bst;
    int koniec=0;
    do {
        int x;
        string path;
        int element;
        cout << "1 - Stworz losowo generowany drzewo BST" << endl;
        cout << "2 - Wczytaj kopiec z pliku" << endl;
        cout << "3 - Dodaj   element do kopca" << endl;
        cout << "4 - Usun liczbe z kopca" << endl;
        cout << "5 - Wyszukaj element w drzewie" << endl;
        cout << "6 - Wyswietl drzewo"<<endl;
        cout << "7 - zakoncz program" << endl;
        cin>>x;
        cout<<endl;
        switch (x) {
            case 1:
                int ilosc;
                int max;
                int min;
                cout << "Ilu elementowa ma być kopiec?" << endl;
                cin >> ilosc;
                cout << "Maxymalny element w kopiec?" << endl;
                cin >> max;
                cout << "Minimalny element w kopiec?" << endl;
                cin >> min;
                Bst.create_random(ilosc, min, max);
                break;
            case 2:
                cout<<"podaj sciezke do pliku"<<endl;
                cin>>path;
                Bst.create_from_a_file(path)
                break;
            case 3:

                cout<<"jaka liczba ma zostac dodana?"<<endl;
                cin>>element;
                Bst.add(element);
                break;
            case 4:
                cout<<"jaka liczba ma zostac usunieta?"<<endl;
                cin>>element;
                Bst.remove(element);
                break;
            case 5:
                cout<<"jakiego elementu szukasz?"<<endl;
                cin>>element;
                Bst.find(element);
                break;
            case 6:
                Bst.print();
                break;
            case 7:
                koniec=1;

        }
    }while(koniec==0);
}
menu::~menu() {}