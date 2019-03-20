//
// Created by vladimir on 16.03.19.
//
#include "My_binary_search_tree.h"

// algorytm dsw psuje jedno założenie drzewa mogą się zdarzyć liczby równe rodzicowi po lewej stronie
// tworzymy drzewo bst gdzie wszystko ustawiamy na zero
My_binary_search_tree::My_binary_search_tree() {
    this->size = 0;
    this->root = nullptr;
}

// funkcja przechodzi od najbardziej lewego elementu potem prawego i usuwa element;
// poczym wraca i jęsli element nie ma dzieci to sam się usuwa i wraca do rodzica
void My_binary_search_tree::deleteHelper(My_binary_search_tree::Node *element) {
    if(element == nullptr){
        return;
    }
    if(element->left != nullptr){
        this->deleteHelper(element->left);
    }
    if(element->right != nullptr){
        this->deleteHelper(element->right);
    }
    delete element;
}

// ustawia usuwanie w deleteHelper od początkowego elementu
My_binary_search_tree::~My_binary_search_tree() {
    this->deleteHelper(this->root);
}

// funckja zwraca element który ma podaną wartość bądz zwraca NULL, jeśli nie znajdzie akiego elementu to sprawdza wpierw
// czy wartość danego elementu nie jest większ od podanej wartości i idzie powtarza tą funkcje dla lewego elementu, analogicznie
// potem sprawdza dla prawego elementu
My_binary_search_tree::Node* My_binary_search_tree::findHelper(int value, My_binary_search_tree::Node *element) {
    if(element == nullptr){
        std::cout << "Element don't exist in bst!" <<std::endl;
        return element;
    }
    if(value == element->data){
        std::cout << "Element exist in bst!" <<std::endl;
        return element;
    }
    if(value < element->data){
        return this->findHelper(value, element->left);
    }
    else{
        return this->findHelper(value, element->right);
    }
}

// ustawia wyszukiwanie w findHelper od pierwszego elementu
My_binary_search_tree::Node* My_binary_search_tree::find(int value){
    return this->findHelper(value, this->root);

}

// funckja dodaje element do drzewa
void My_binary_search_tree::add(int value) {
    // na początku tworzymy element o podanej wartości i ustawiamy wszystkie jego wskaźniki na nullptr
    Node* new_element = new My_binary_search_tree::Node;

    new_element->right = nullptr;
    new_element->left = nullptr;
    new_element->parent = nullptr;
    new_element->data = value;


    My_binary_search_tree::Node* parent = nullptr;
    My_binary_search_tree::Node* child = this->root;
    // teraz zostaje wyszukany element który nie ma dziecka
    // zaczynająć od głowy idziemy do lewego dziecka jeśli ma większą wartość od nowego element w przeciwnym razie idzie do prawego dziecka
    while (child != nullptr){
        parent = child;
        if(new_element->data < child->data){
            child = child->left;
        }
        else{
            child = child->right;
        }
    }
    // w taki sposób otrzymujemy rodzica nowego elementu
    new_element->parent = parent;
    if(parent == nullptr){
        this->root = new_element;
    }
    // teraz ustawiamy którym dzieckiem jest nowy element
    else if (new_element->data < parent->data){
        parent->left = new_element;
    }
    else {
        parent->right = new_element;
    }
    this->size++;
    this->dsw();
}

// funkcja kóra wstawia jedno poddrzewo w miejsce drugiego poddrzewa
// dzięki tej funckji zastępujemy poddrzewo o korzeniu first poddrzewem o korzeniu second
void My_binary_search_tree::transplant(My_binary_search_tree::Node *first, My_binary_search_tree::Node *second) {
    // sprawdzamy czy first jest synem jakiegoś elementu
    if(first->parent == nullptr){
        this->root = second;
    }
    // zamieniamy dziecko rodzica first elementem second
    else if(first == first->parent->left){
        first->parent->left = second;
    }
    else{
        first->parent->right = second;
    }
    if(second != nullptr){
        second->parent = first->parent;
    }
}

// wyszukuje element o największej wartości w podanym podrzewie
My_binary_search_tree::Node* My_binary_search_tree::max_value(My_binary_search_tree::Node* element) {
    while(element->right != nullptr){
        element = element->right;
    }
    return element;
}

// wyszukuje element o najmniejszej wartości w podanym podrzewie
My_binary_search_tree::Node* My_binary_search_tree::mini_value(My_binary_search_tree::Node* element) {
    while(element->left != nullptr){
        element = element->left;
    }
    return element;
}

// funckja wyszukuje wpierw element o podanej wartości a potem go usuwa;
void My_binary_search_tree::remove(int value) {
    My_binary_search_tree::Node* element = this->find(value);
    if(element){
        //jeśli element nie ma lewego dziecka to podmieniamy element na jego prawe dziecko
        if(element->left == nullptr){
            this->transplant(element, element->right);
        }
        // analogicznie gdy element nie ma prawego dziecka
        else if(element->right == nullptr){
            this->transplant(element, element->left);
        }
        else {
            // szukamy teraz w prawym poddrzewie najmniejszy element po to aby go podmienić bo dzięki temu zachowamy własności drzewa
            // jęsli element ma dwoje synów to szukamy taki element w naszym prawej częsci poddrzewie który ma najmniejszą wartość
            My_binary_search_tree::Node* y = this->mini_value(element->right);
            // więc y nie ma lewego syna
            if(y->parent != element){
                // jeśli y nie jest prawym synem elementu to zastępujemy y u jego ojca przez prawego syna y i zamieniamy prawego syna
                // z na prawego syna y
                this->transplant(y, y->right);
                y->right = element->right;
                y->right->parent = y;
            }
            // zastępujemy element u jego ojca przez y i czynimy lewego syna z lewym synem y
            this->transplant(element, y);
            y->left = element->left;
            y->left->parent = y;


        }
        delete element;
        this->size--;
        this->dsw();
    }
}

// rotacja z prawej na lewą. Zamaina elementu z jego prawym synem na prawego syna z lewym synem jako element
My_binary_search_tree::Node* My_binary_search_tree::rotate_left(My_binary_search_tree::Node *element) {
    My_binary_search_tree::Node* y = element->right;
    //prawy syn elementu staje się lewy syn y
    element->right = y->left;
    if(y->left != nullptr){
        // jeżeli lewy syn istnieje to zostaje przypisane to samo tylko od strony leego syna
        y->left->parent = element;
    }
    y->parent = element->parent;
    // rodzicem y jesy rodzic elementu i jeśli to jest NULL to oznacza że to jest pierszy element i ustawiamy korzeń na y
    if(element->parent == nullptr){
        this->root = y;
    }
    else if(element == element->parent->left){
        //jeśli element jest lewym dzieckiem to podstawiamy y jako lewe dziecko
        // a jak prawy to podsyawiwamy y jako prawe dziecko
        element->parent->left = y;
    }
    else{
        //
        element->parent->right = y;
    }
    // teraz przyisujemy do lewego syna element i rodzica elementu do y
    y->left = element;
    element->parent = y;

    return y;
}

// rotacja z lewej na prawa. Zamiana elemnetu z jego lewym synem na lewego syna z prawym synem jako element
// analogicznie wygląda robota jak dla rotate_left
My_binary_search_tree::Node* My_binary_search_tree::rotate_right(My_binary_search_tree::Node *element) {
    My_binary_search_tree::Node* y = element->left;
    element->left = y->right;
    if(y->right != nullptr){
        y->right->parent = element;
    }
    y->parent = element->parent;
    if(element->parent == nullptr){
        this->root = y;
    }
    else if(element == element->parent->right){
        element->parent->right = y;
    }
    else{
        element->parent->left = y;

    }
    y->right = element;
    element->parent = y;
    return y;

}

// modyfukiujemy drzewi w taki sposób aby wszystkie element znajdowały sie po prawej stronie
void My_binary_search_tree::dswHelper() {
    My_binary_search_tree::Node* element = this->root;
    while(element){
        if(element->left){
            element = this->rotate_right(element);}
        else{
            element = element->right;
        }
    }
}

//rozkłądamy drzewo tak jak powinno być
void My_binary_search_tree::dsw() {
    this->dswHelper();
    int count = this->size;
    My_binary_search_tree::Node* element = this->root;
    int number = (int)pow(2, (int)log2(count+1)) - 1;  //ilość wierzchołków w drzewie w części zapełnionej
    for(int a = 0; a < count-number; a++){
        //wykonaj n-m rotacji w lewo , startując od początkowego
        //wierzchołka co drugi wierzchołek
        element =   this->rotate_left(element); // TODO sprawdzić te linijki
        element = element->right;
    }

    while(number > 1){
        element = this->root;
        number = number/2;
        for(int a = 0; a < number; a++){
            // wykonaj m rotacji w lewo , startując
            // od początkowego wierzchołka co drugi wierzchołek
            element = this->rotate_left(element); // TODO sprawdzić te linijki
            element = element->right;
        }

    }
}

// czyści drzewo i potem tworzy drzewo z losowymi obiektami. Użytkownik podaje zakres losowań oraz ich ilość
void My_binary_search_tree::create_random(int size, int minimum, int maximum) {
    this->size = 0;
    this->deleteHelper(this->root);
    this->root = nullptr;
    int data;
    srand( time( NULL ) );
    for(int inc = 0; size > inc; inc++){
        data = ((std::rand() % (maximum-minimum+1)) + minimum);
        this->add(data);
    }

}

// tworzy drzewo od nowa z pliku wpierw czyszcząć całe drzewo
void My_binary_search_tree::create_from_a_file(std::string name) {
    std::ifstream infile(name);
    std::string line;
    this->deleteHelper(this->root);
    this->root = nullptr;
    this->size = 0;
    while (std::getline(infile, line)){
        this->add(std::atof(line.c_str()));
    }
}


void My_binary_search_tree::print() {
    this->printHelp(this->root, 0);
    std::cout << std::endl;
}

void My_binary_search_tree::printHelp(My_binary_search_tree::Node *v, int in) {
    in++;
    if(v != NULL)
    {

        printHelp(v->left, in);
        // przechodzimy lewe poddrzewo
        std::cout << v->data << " " << in <<", "; // odwiedzamy węzeł

        printHelp(v->right, in);      // przechodzimy prawe poddrzewo
    }
    in--;
}
