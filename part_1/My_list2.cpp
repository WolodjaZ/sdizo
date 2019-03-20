//
// Created by vladimir on 15.03.19.
//

#include "My_list2.h"


// tworzymy początek listy
My_list2::My_list2(){
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

// Usuwanie tablicy poprzez przechodzenie ze wskaźnika na inny wskaźnik i usuwanie poprzedniego wskaźnika po czym zostaje usunięty koniec
My_list2::~My_list2(){
    while(head->next != NULL){
        head = head->next;
        delete head->prev;
    }
    delete head;

    std::cout << "LIST DELETED" <<std::endl;
}

// zwraca długość listy
int My_list2::getLength(){
    return this->length;
}

// ustawiamy nowy element o waryości data oraz ustawiamy wskaźnik na poprzedniego na NULL i następnego na głowę po czym przypisujemy
// głowe do nowej struktury. Spradzamy również czy występował wcześniej element i ustawiamy odpowiednie wskaźniki z tym związane
void My_list2::push_front(int data){
    Node* element = new Node;

    element->data = data;
    element->prev = NULL;
    element->next = this->head;

    if(this->head == NULL){
        this->tail = element;
    }
    else{
        this->head->prev = element;
    }

    this->head = element;
    this->length++;
}

// pobieramy pierwszy element do zmiennej po czym ustawiamy głowę na następny element oraz sptawdzamy czy istnieje nastęþny element i ustawiamy
// wskaźniki odpowiednio po czym usuwamy ten element
My_list2::Node* My_list2::pop_front() {
    if(this->head != NULL){
        Node* element = this->head;
        this->head = this->head->next;
        if(this->head == NULL){
            this->tail = NULL;
        } else{
            this->head->prev = NULL;
        }
        delete element;
        this->length--;
    }
}


// analogicznie do push front tylko że z wykorzystaniem ogona
void My_list2::push_tail(int data) {
    Node* element = new Node;

    element->data = data;
    element->prev = this->tail;
    element->next = NULL;

    if(this->tail == NULL){
        this->head = element;
    }
    else{
        this->tail->next = element;
    }

    this->tail = element;
    this->length++;
}


// analogicznie do pop front tylko że z wykorzystaniem ogona
My_list2::Node* My_list2::pop_tail() {
    if(this->tail != NULL){
        Node* element = this->tail;
        this->tail = this->tail->prev;
        if(this->tail == NULL){
            this->head = NULL;
        }
        else{
            this->tail->next = NULL;
        }
        delete element;
        this->length--;
    }
}

// funkcja przechodzi od ogona do ostatniego elementu sprawdzająć czy wartość podana jest równa wartosci wskaźnika
// po znalezieniu zwraca wskaźnik na ten element jeśli nie znajdzie to zwraca NULL
My_list2::Node* My_list2::find_by_value(int data) {
    Node* element = this->head;
    while(element != NULL){
        if(element->data == data){
            std::cout << "Value exist in list" <<std::endl;
            return element;
        }
        element = element->next;
    }
    std::cout << "Element don't exit"<< std::endl;
    return element;
}

// funkcja przechodzi tyle razy ile indeks podaje i zwraca wartość znajdującą się za tym indeksem
My_list2::Node* My_list2::find(int index) {
    if(this->length > index){
        Node* element = this->head;
        for(int inc = 0; inc != index; inc++){
            element = element->next;
        }
        return element;
    }

    std::cout <<"index out off range!" <<std::endl;
    return NULL;
}

// funkcja tworzy strukture o podanych danych i ustawia ją na miejscu podanym w indeksie
// Na początku sprawdza się czy nowa strukutra nie ma być stworzona na miejscu ostatnim lub pierwszym
// wtedy funkcja przekazuje push_tail abo push_front. Jeśli nie to funkcja iteruje aż nie dojdzie do tego indeksu
// wtedy przesuwa ten element i wstawia w jego miejsce nowoutworzoną strukture i ustawia jej wskaźniki
void My_list2::add(int index, int data) {
    if(this->length >= index) {
        if(index == 0){
            this->push_front(data);
        }
        else if(index == this->length){
            this->push_tail(data);
        }
        else
        {
            Node *element = this->head;
            for (int inc = 0; inc != index; inc++) {
                element = element->next;
            }

            Node* new_element = new Node;
            new_element->data = data;
            new_element->prev = element->prev;
            new_element->next = element;

            element->prev->next = new_element;
            element->prev = new_element;
            this->length++;
        }

    }
    else{
        std::cout <<"index out off range!" <<std::endl;
    }

}

// Funkcja przelatuje po wskaźnika szukając odpowiedniej wartości bądz kiedy dojdzie do NULL.
// Jeśli znajdzie tą wartość to wtedy ustawia poprzednika i następnika na siebie i usuwa dany element
void My_list2::remove_by_value(int data) {
    Node* element = this->head;
    while(element != NULL and element->data != data){
        element = element->next;
    }
    if(element != NULL){
        if(element->prev != NULL){
            element->prev->next = element->next;
        }
        if(element->next != NULL){
            element->next->prev = element->prev;
        }
        this->length--;
    }
    delete element;
}

// analogicznie działą jka remove_by_value tylko tutaj przelatuje po aż nie znajdzie danego indeksu
void My_list2::remove(int index) {
    if(this->length > index){
        Node* element = this->head;
        int inc = 0;
        while(element != NULL and index != inc){
            element = element->next;
            inc++;
        }
        if(element != NULL){
            if(element->prev != NULL){
                element->prev->next = element->next;
            }
            if(element->next != NULL){
                element->next->prev = element->prev;
            }
            this->length--;
        }
        delete element;
    }
}

// wypisuje elementy zaczynająć od głowy potem wypisuje zaczynająć od ogonu
void My_list2::print() {
    Node* element = this->head;
    std::cout << "List have " << this->length << " elements, ";
    std::cout << "normal: ";
    while(element != NULL){
        std::cout << element->data << ", ";
        element = element->next;
    }

    element = this->tail;
    std::cout << std::endl << "reverse: ";
    while(element != NULL){
        std::cout << element->data << ", ";
        element = element->prev;
    }
    std::cout << std::endl;
}


//creates random values in table
void My_list2::create_random(int size, int minimum, int maximum) {
    while(head->next != NULL){
        head = head->next;
        delete head->prev;
    }
    delete head;

    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
    int data;
    srand( time( NULL ) );
    for(int inc = 0; size > inc; inc++){
        data = ((std::rand() % (maximum-minimum+1)) + minimum);
        this->push_front(data);
    }

}

// tworzy listę z pliku wpierw czyszcząć całą listę
void My_list2::create_from_a_file(std::string name) {
    std::ifstream infile(name);
    std::string line;

    while(head->next != NULL){
        head = head->next;
        delete head->prev;
    }
    delete head;

    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
    while (std::getline(infile, line)){
        this->push_tail(std::atof(line.c_str()));
    }
}

