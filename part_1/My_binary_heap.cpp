//
// Created by vladimir on 16.03.19.
//

#include <iomanip>
#include "My_binary_heap.h"

// tworzymy kopiec na podstawie tablicy intowej o rozmiarze size
My_binary_heap::My_binary_heap(int size) {
    this->size = size;
    this->root = new int [size];
    this->real_size = 0;
}

// usuwamy kopiec wpierw usuwająć tablice
My_binary_heap::~My_binary_heap() {
    delete[] root;
    this->size = 0;
    this->real_size = 0;
}

// przeszukujemy kopiec przechodząć po kolejnych elementach w tablicy dopuki nie znajdzie odpowiedni element i wtedy
// zwraca index na ten element
int My_binary_heap::find(int value) {
    
    for(int inc = 0; this->real_size > inc; inc++){
        if(*(this->root+inc) == value){
            std::cout<< "Value exist in binary heap"<< std::endl;
            
            return inc;
        }
    }
    std::cout<< "Value don't exist in binary heap" <<std::endl;
    
    return -1;
}

// naprawa kopca w dół. Podajemy index od kótego ma zacząć naprawę spradza czy jego wartość jest większa od wartości
// swoich dzieci jeżli tak to przerywa jak nie to zamienia wartości i index przepisuje na dziecko i zaczyna od nowa sprawdzanie
void My_binary_heap::heap_fix_down(int index) {
    int p, l = 2*index+1;
    while (index < this->real_size){
        p = l+1;
        int max = index;
        if(l < this->real_size &&*(this->root+l) > *(this->root+index)){
            max = l;
        }
        if(p < this->real_size && *(this->root+p) > *(this->root+max)){
            max = p;
        }
        if(max == index){
            return;
        }
        int buf = *(this->root+index);
        *(this->root+index) = *(this->root+max);
        *(this->root+max) = buf;
        index = max;
        l = 2*index+1;
    }
}

// naprawa kopca w góre. Podajemy index od kótego ma zacząć naprawę spradza czy jego wartość jest mniejsza od wartości
// rodzica jeżli tak to przerywa jak nie to zamienia wartości i index przepisuje na rodzica i zaczyna od nowa sprawdzanie
void My_binary_heap::heap_fix_up(int index) {
    while (index > 0){
        int parent = (index-1)/2;
        if(*(this->root+parent) >= *(this->root+index)){
            return;
        }
        int buf = *(this->root+index);
        *(this->root+index) = *(this->root+parent);
        *(this->root+parent) = buf;
        index = parent;
    }
}


// tworzymy nowy obiekt o podanych wartościach na końcu tablicy. Zwikęszamy rozmiat tablicy i zaczynamy naprawę w góre kopca
void My_binary_heap::add(int value) {
    if(this->size > this->real_size){
        
        *(this->root+this->real_size) = value;
        this->real_size++;

        this->heap_fix_up(this->real_size-1);

        std::cout<< "Element added!" << std::endl;
        
    }
    else{
        std::cout<< "Binary heap is full" << std::endl;
    }

}
// wyszukujemy element o podanych wartościach przy pomocy find. Po czym zamieniamy ostatni element ze znalezionym elementem i usuwamy
// ostatni element. Następnie wracamy do poprzedniego elementu i zaczynamy naprawę kopca w dól.
void My_binary_heap::remove(int value) {
    int index = this->find(value);
    if(index != -1){
        
        *(this->root+index) = *(this->root+this->real_size-1);
        *(this->root+this->real_size-1) = 0;
        this->real_size--;

        this->heap_fix_up(index);
        this->heap_fix_down(index);

        std::cout<< "Element removed!" << std::endl;
        
    }
    else{
        std::cout<< "Element don't exist" << std::endl;
    }
}


void My_binary_heap::heap_create() {
    
    for(int inc = (this->real_size-2)/2; inc>=0; --inc)
        this->heap_fix_down(inc);
}

// tworzy tablice z randomowymi elementami  wpierw czyszcząć całą tablice. Po czym wrzucamy tą tablice do algorytmu Floyda
void My_binary_heap::create_random(int real_size , int size, int minimum, int maximum) {
    this->size = size;
    this->real_size = real_size;
    delete [] this->root;
    this->root = new int [size];
    int data;
    srand( time( nullptr ) );
    for(int inc = 0; real_size > inc; inc++){
        data = ((std::rand() % (maximum-minimum+1)) + minimum);
        *(this->root+inc) = data;
    }

    this->heap_create();
}

// tworzy tablice z pliku wpierw czyszcząć całą tablice
void My_binary_heap::create_from_a_file(int size, std::string name) {
    std::ifstream infile(name);
    std::string line;
    delete[] this->root;
    this->size = size;
    this->root = new int [size];
    this->real_size = 0;
    int a = 0;
    while (std::getline(infile, line)){
        if(a == 0){
            a++;
            continue;
        }
        this->add(std::atof(line.c_str()));
    }
}



//  print binarry heap
void My_binary_heap::print() {
    if(size==0){
        std::cout<<"brak elementow do wyswietlenia"<<std::endl;
        return;
    }
    std::cout<<std::setw(40)<<*(this->root)<<std::endl<<std::endl;
    for(int i=1;i<3;i++) {
        if(size>i) {
            std::cout << std::setw(27);
            if(*(this->root+i) != 0)
                std::cout << *(this->root+i);
            else
                std::cout << 'x';
        }
    }
    std::cout<<std::endl<<std::endl;
    for(int i=3;i<7;i++) {
        if(size>i) {
            std::cout << std::setw(16);
            if(*(this->root+i) != 0)
                std::cout << *(this->root+i);
            else
                std::cout << 'x';
        }
    }
    std::cout<<std::endl<<std::endl;
    for(int i=7;i<16;i++) {
        if(size>i) {
            std::cout << std::setw(9);
            if(*(this->root+i) != 0)
                std::cout << *(this->root+i);
            else
                std::cout << 'x';    ;
        }
    }
    std::cout<<std::endl<<std::endl;
}

// drukuje mniej elegancko ale pokazuje wszystkie element pierszy to jest wartość drugi to głębokość
void My_binary_heap::print2() {
    print2help(0,0);
    std::cout << std::endl;
}

void My_binary_heap::print2help(int index, int in) {
    in++;
    if(index < this->real_size){

        print2help( 2*index+1, in);
        // przechodzimy lewe poddrzewo
        std::cout << this->root[index] <<"(" << in << "), "; // odwiedzamy węzeł

        print2help( 2*index+2, in);      // przechodzimy prawe poddrzewo
    }
    in--;
}