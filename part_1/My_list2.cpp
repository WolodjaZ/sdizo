//
// Created by vladimir on 15.03.19.
//

#include "My_list2.h"


// tworzymy początek listy
My_list2::My_list2(){
    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

// Usuwanie tablicy poprzez przechodzenie ze wskaźnika na inny wskaźnik i usuwanie poprzedniego wskaźnika po czym zostaje usunięty koniec
My_list2::~My_list2(){
    while(head->next != nullptr){
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

// ustawiamy nowy element o waryości data oraz ustawiamy wskaźnik na poprzedniego na nullptr i następnego na głowę po czym przypisujemy
// głowe do nowej struktury. Spradzamy również czy występował wcześniej element i ustawiamy odpowiednie wskaźniki z tym związane
void My_list2::push_front(int data){
    auto t1 = std::chrono::steady_clock::now();
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

    auto t2 = std::chrono::steady_clock::now();
    auto result = t2 - t1;
    std::cout << "Execution time:" << result.count() << std::endl;
}

// pobieramy pierwszy element do zmiennej po czym ustawiamy głowę na następny element oraz sptawdzamy czy istnieje nastęþny element i ustawiamy
// wskaźniki odpowiednio po czym usuwamy ten element
My_list2::Node* My_list2::pop_front() {
    if(this->head != nullptr){
        auto t1 = std::chrono::steady_clock::now();
        Node* element = this->head;
        this->head = this->head->next;
        if(this->head == nullptr){
            this->tail = nullptr;
        } else{
            this->head->prev = nullptr;
        }
        delete element;
        this->length--;

        auto t2 = std::chrono::steady_clock::now();
        auto result = t2 - t1;
        std::cout << "Execution time:" << result.count() << std::endl;
    }
}


// analogicznie do push front tylko że z wykorzystaniem ogona
void My_list2::push_tail(int data) {
    auto t1 = std::chrono::steady_clock::now();
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

    auto t2 = std::chrono::steady_clock::now();
    auto result = t2 - t1;
    std::cout << "Execution time:" << result.count() << std::endl;
}


// analogicznie do pop front tylko że z wykorzystaniem ogona
My_list2::Node* My_list2::pop_tail() {
    if(this->tail != nullptr){
        auto t1 = std::chrono::steady_clock::now();
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

        auto t2 = std::chrono::steady_clock::now();
        auto result = t2 - t1;
        std::cout << "Execution time:" << result.count() << std::endl;
    }
}

// funkcja przechodzi od ogona do ostatniego elementu sprawdzająć czy wartość podana jest równa wartosci wskaźnika
// po znalezieniu zwraca wskaźnik na ten element jeśli nie znajdzie to zwraca nullptr
My_list2::Node* My_list2::find_by_value(int data) {
    auto t1 = std::chrono::steady_clock::now();
    Node* element = this->head;
    while(element != nullptr){
        if(element->data == data){
            std::cout << "Value exist in list" <<std::endl;

            auto t2 = std::chrono::steady_clock::now();
            auto result = t2 - t1;
            std::cout << "Execution time:" << result.count() << std::endl;
            return element;
        }
        element = element->next;
    }
    std::cout << "Element don't exit"<< std::endl;
    auto t2 = std::chrono::steady_clock::now();
    auto result = t2 - t1;
    std::cout << "Execution time:" << result.count() << std::endl;

    return element;
}

// funkcja przechodzi tyle razy ile indeks podaje i zwraca wartość znajdującą się za tym indeksem
My_list2::Node* My_list2::find(int index) {
    if(this->length > index){
        auto t1 = std::chrono::steady_clock::now();
        Node* element = this->head;
        for(int inc = 0; inc != index; inc++){
            element = element->next;
        }
        auto t2 = std::chrono::steady_clock::now();
        auto result = t2 - t1;
        std::cout << "Execution time:" << result.count() << std::endl;

        return element;
    }

    std::cout <<"index out off range!" <<std::endl;
    return nullptr;
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
            auto t1 = std::chrono::steady_clock::now();
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

            auto t2 = std::chrono::steady_clock::now();
            auto result = t2 - t1;
            std::cout << "Execution time:" << result.count() << std::endl;
        }

    }
    else{
        std::cout <<"index out off range!" <<std::endl;
    }

}

// Funkcja przelatuje po wskaźnika szukając odpowiedniej wartości bądz kiedy dojdzie do nullptr.
// Jeśli znajdzie tą wartość to wtedy ustawia poprzednika i następnika na siebie i usuwa dany element
void My_list2::remove_by_value(int data) {
    auto t1 = std::chrono::steady_clock::now();
    Node* element = this->head;
    while(element != nullptr and element->data != data){
        element = element->next;
    }
    if(element != nullptr){
        if(element->prev != nullptr){
            element->prev->next = element->next;
        }
        if(element->next != nullptr){
            element->next->prev = element->prev;
        }
        this->length--;
    }
    delete element;

    auto t2 = std::chrono::steady_clock::now();
    auto result = t2 - t1;
    std::cout << "Execution time:" << result.count() << std::endl;
}

// analogicznie działą jka remove_by_value tylko tutaj przelatuje po aż nie znajdzie danego indeksu
void My_list2::remove(int index) {
    if(this->length > index){
        auto t1 = std::chrono::steady_clock::now();
        Node* element = this->head;
        int inc = 0;
        while(element != nullptr and index != inc){
            element = element->next;
            inc++;
        }
        if(element != nullptr){
            if(element->prev != nullptr){
                element->prev->next = element->next;
            }
            if(element->next != nullptr){
                element->next->prev = element->prev;
            }
            this->length--;
        }
        delete element;

        auto t2 = std::chrono::steady_clock::now();
        auto result = t2 - t1;
        std::cout << "Execution time:" << result.count() << std::endl;
    }
}

// wypisuje elementy zaczynająć od głowy potem wypisuje zaczynająć od ogonu
void My_list2::print() {
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


//creates random values in table
void My_list2::create_random(int size, int minimum, int maximum) {
    while(head->next != nullptr){
        head = head->next;
        delete head->prev;
    }
    delete head;

    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
    int data;
    srand( time( nullptr ) );
    for(int inc = 0; size > inc; inc++){
        data = ((std::rand() % (maximum-minimum+1)) + minimum);
        this->push_front(data);
    }

}

// tworzy listę z pliku wpierw czyszcząć całą listę
void My_list2::create_from_a_file(std::string name) {
    std::ifstream infile(name);
    std::string line;

    while(head->next != nullptr){
        head = head->next;
        delete head->prev;
    }
    delete head;

    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
    while (std::getline(infile, line)){
        this->push_tail(std::atof(line.c_str()));
    }
}

