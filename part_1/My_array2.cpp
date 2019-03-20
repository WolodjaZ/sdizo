//
// Created by vladimir on 15.03.19.
//

#include "My_array2.h"



// Tworzymy tablice o długości równej 0
My_array2::My_array2() {
    this->length = 0;
    this->head = new int [this->length];
}

// Usuwamy naszą tablice
My_array2::~My_array2() {
    this->length = 0;
    delete[] head;
}

// Dodajemy nowy element na początek poprzez tworzenie nowej tablicy o rozmiarze o jeden większym niż tablica i
// dodajemy do niej w odpowiednie miejsca dane
void My_array2::push_front(int data) {
    //QueryPerformanceCounter(&this->Starting);
    int *new_head = new int [this->length+1];
    for(int inc = this->length-1; inc > 0; inc--){
        *(new_head+inc) = *(this->head+inc);
    }
    *(new_head) = data;
    this->head = new_head;
    this->length++;
    //QueryPerformanceCounter(&this->Ending);
    //std::cout<< "Execution Timer = " << this->Ending.QuadPart - this->Starting.QuadPart << "ms" << std::endl;

}

//Usuwamy element na początku poprzez tworzenie nowej tablicy o rozmiarze o jeden mniejszym niż tablica i
// dodajemy do niej w odpowiednie miejsca dane
int My_array2::pop_front() {
    if(this->head){
        int *new_head = new int [this->length-1];
        for(int inc = 0; this->length-1 > inc; inc++){
            *(new_head+inc) = *(this->head+inc+1);
        }
        int *buf = this->head;
        this->head = new_head;
        new_head = buf;
        this->length--;
        int data = *(this->head);
        delete[] new_head;
        return data;
    }
    return NULL;

}


// Dodajemy nowy element na koniec poprzez tworzenie nowej tablicy o rozmiarze o jeden większym niż tablica i
// dodajemy do niej w odpowiednie miejsca dane
void My_array2::push_tail(int data) {
    int *new_head = new int [this->length+1];
    for(int inc = 0; this->length > inc; inc++){
        *(new_head+inc) = *(this->head+inc);
    }
    *(new_head+this->length) = data;
    int *buf = this->head;
    this->head = new_head;
    new_head = buf;
    this->length++;
    delete[] new_head;
}


//Usuwamy element na końcu poprzez tworzenie nowej tablicy o rozmiarze o jeden mniejszym niż tablica i
// dodajemy do niej w odpowiednie miejsca dane
int My_array2::pop_tail() {
    if(this->head){
        int *new_head = new int [this->length-1];
        for(int inc = 0; this->length-1 > inc; inc++){
            *(new_head+inc) = *(this->head+inc);
        }
        int data = *(this->head+this->length-1);
        int *buf = this->head;
        this->head = new_head;
        new_head = buf;
        this->length--;
        delete[] new_head;
        return data;
    }
    return NULL;

}

// zwraca wartość na danym indeksie
int My_array2::get(int index) {
    if(this->length > index){
        return *(this->head+index);
    }
    return NULL;
}


// funkcja przeszukuje przechodząc przez każdy element i sprawdza czy wartość na danym indeksie zgadza się
// z podaną wartością i zwraca indeks lub null jeśli nie ma
int My_array2::find(int data) {
    for(int inc = 0; this->length > inc; inc++){
        if(*(this->head+inc) == data){
            std::cout<< "Value exist in array"<< std::endl;
            return inc;
        }
    }
    std::cout<< "Value don't exist in array" <<std::endl;
    return NULL;

}


// działanie tej funkcji jest zbliżone do działania push_tail tylko kiedy dochodzimy do indexu wtedy w miejsce tablicy wstawiamy
// podaną liczbę a potem wstawiam pozostałe wartości ze starej tablicy do nowej tablicy. Po czym zamieniamy tablice nazwami
void My_array2::add(int index, int data) {
    if(index >= 0 && index <= length){
        int *new_head = new int [this->length+1];
        int inc = 0;

        for(; index > inc; inc++){
            *(new_head+inc) = *(this->head+inc);
        }

        *(new_head+index) = data;

        for(; this->length > inc; inc++){
            *(new_head+inc+1) = *(this->head+inc);
        }

        int *buf = this->head;
        this->head = new_head;
        new_head = buf;
        this->length++;
        delete[] new_head;
    }

}

// działanie tej funkcji jest zbliżone do działania pop_tail tylko kiedy dochodzimy do indexu wtedy zwiększami wartość zmiennej odpowiedzialnej
// za indeks i dodajemy pozostałe wartości  ze starej tablicy do nowej tablicy przy tym że dodajemy je na indeks mniejszy o 1.
// Po czym zamieniamy tablice nazwami
void My_array2::remove(int index) {
    if(index >= 0 && index < length){
        int *new_head = new int [this->length-1];
        int inc = 0;

        for(; index > inc; inc++){
            *(new_head+inc) = *(this->head+inc);
        }

        inc++;

        for(; this->length > inc; inc++){
            *(new_head+inc-1) = *(this->head+inc);
        }

        int *buf = this->head;
        this->head = new_head;
        new_head = buf;
        this->length--;
        delete[] new_head;
    }
}

// prints all values in array
void My_array2::print() {
    std::cout << "My array sizeof: " << this->length << " have: ";
    for(int inc = 0; this->length > inc; inc++){
        std::cout<< *(this->head+inc) << " ";
    }
    std::cout << std::endl;
}

//creates random values in table
void My_array2::create_random(int size, int minimum, int maximum) {
    this->length = size;
    int* new_head = new int [size];
    int data;
    srand( time( NULL ) );
    for(int inc = 0; size > inc; inc++){
        data = ((std::rand() % (maximum-minimum+1)) + minimum);
        *(new_head+inc) = data;
    }
    int *buf = this->head;
    this->head = new_head;
    new_head = buf;
    delete[] new_head;
}

// tworzy tablice z pliku wpierw czyszcząć całą tablice
void My_array2::create_from_a_file(std::string name) {
    std::ifstream infile(name);
    std::string line;
    int* buf = this->head;
    delete[] buf;
    this->length = 0;
    this->head = new int [this->length];
    while (std::getline(infile, line)){
        this->push_tail(std::atof(line.c_str()));
    }
}