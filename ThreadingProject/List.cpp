//
// Created by vladimir on 24.04.19.
//

#include "List.h"

// tworzymy początek listy
List::List(){
    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

// Usuwanie tablicy poprzez przechodzenie ze wskaźnika na inny wskaźnik i usuwanie poprzedniego wskaźnika po czym zostaje usunięty koniec
List::~List(){
    if(tail != nullptr){
        while(tail->prev != nullptr){
            tail = tail->prev;
            delete tail->next;
        }
        delete head;
    }

    std::cout << "LIST DELETED" <<std::endl;
}

// zwraca długość listy
int List::getLength(){
    return this->length;
}

// ustawiamy nowy element o waryości data oraz ustawiamy wskaźnik na poprzedniego na nullptr i następnego na głowę po czym przypisujemy
// głowe do nowej struktury. Spradzamy również czy występował wcześniej element i ustawiamy odpowiednie wskaźniki z tym związane
void List::push_front(int data){

    Node* element = new Node;

    element->data = data;
    element->prev = nullptr;
    element->next = this->head;

    if(this->head == nullptr){
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
List::Node* List::pop_front() {
    if(this->head != nullptr){

        Node* element = this->head;
        this->head = this->head->next;
        if(this->head == nullptr){
            this->tail = nullptr;
        } else{
            this->head->prev = nullptr;
        }
        delete element;
        this->length--;


    }
}


// analogicznie do push front tylko że z wykorzystaniem ogona
void List::push_tail(int data) {

    Node* element = new Node;

    element->data = data;
    element->prev = this->tail;
    element->next = nullptr;

    if(this->tail == nullptr){
        this->head = element;
    }
    else{
        this->tail->next = element;
    }

    this->tail = element;
    this->length++;


}


// analogicznie do pop front tylko że z wykorzystaniem ogona
List::Node* List::pop_tail() {
    if(this->tail != nullptr){

        Node* element = this->tail;
        this->tail = this->tail->prev;
        if(this->tail == nullptr){
            this->head = nullptr;
        }
        else{
            this->tail->next = nullptr;
        }
        delete element;
        this->length--;


    }
}

// funkcja przechodzi od ogona do ostatniego elementu sprawdzająć czy wartość podana jest równa wartosci wskaźnika
// po znalezieniu zwraca wskaźnik na ten element jeśli nie znajdzie to zwraca nullptr
bool List::find_by_value(int data) {
    if(head == nullptr)
        return false;

    Node* element = this->head;
    while(element != nullptr){
        if(element->data == data){
            return true;
        }
        element = element->next;
    }

    return false;
}

// funkcja przechodzi tyle razy ile indeks podaje i zwraca wartość znajdującą się za tym indeksem
List::Node* List::find(int index) {
    if(this->length > index){

        Node* element = this->head;
        for(int inc = 0; inc != index; inc++){
            element = element->next;
        }


        return element;
    }

    std::cout <<"index out off range!" <<std::endl;
    return nullptr;
}

// funkcja tworzy strukture o podanych danych i ustawia ją na miejscu podanym w indeksie
// Na początku sprawdza się czy nowa strukutra nie ma być stworzona na miejscu ostatnim lub pierwszym
// wtedy funkcja przekazuje push_tail abo push_front. Jeśli nie to funkcja iteruje aż nie dojdzie do tego indeksu
// wtedy przesuwa ten element i wstawia w jego miejsce nowoutworzoną strukture i ustawia jej wskaźniki
void List::add(int index, int data) {
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

// Funkcja przelatuje po wskaźnika szukając odpowiedniej wartości bądz kiedy dojdzie do nullptr.
// Jeśli znajdzie tą wartość to wtedy ustawia poprzednika i następnika na siebie i usuwa dany element
void List::remove_by_value(int data) {

    Node* element = this->head;
    while(element != nullptr and element->data != data){
        element = element->next;
    }
    if(element != nullptr){
        if(element->prev != nullptr){
            element->prev->next = element->next;
        }else{
            this->head = element->next;
        }
        if(element->next != nullptr){
            element->next->prev = element->prev;
        } else{
            this->tail = element->prev;
        }
        this->length--;
    }
    delete element;


}

// analogicznie działą jka remove_by_value tylko tutaj przelatuje po aż nie znajdzie danego indeksu
void List::remove(int index) {
    if(this->length > index){

        Node* element = this->head;
        int inc = 0;
        while(element != nullptr and index != inc){
            element = element->next;
            inc++;
        }
        if(element != nullptr){
            if(element->prev != nullptr){
                element->prev->next = element->next;
            }else{
                this->head = element->next;
            }
            if(element->next != nullptr){
                element->next->prev = element->prev;
            } else{
                this->tail = element->prev;
            }
            this->length--;
        }
        delete element;


    }
}

// wypisuje elementy zaczynająć od głowy potem wypisuje zaczynająć od ogonu
void List::print() {
    Node* element = this->head;
    std::cout << "List have " << this->length << " elements, ";
    std::cout << "normal: ";
    while(element != nullptr){
        std::cout << element->data << ", ";
        element = element->next;
    }

    element = this->tail;
    std::cout << std::endl << "reverse: ";
    while(element != nullptr){
        std::cout << element->data << ", ";
        element = element->prev;
    }
    std::cout << std::endl;
}


