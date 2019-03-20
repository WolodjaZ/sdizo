//
// Created by vladimir on 17.03.19.
//

#include "My_red_black_tree2.h"

// tworzymy drzewo bst gdzie wszystko ustawiamy na zero
My_red_black_tree2::My_red_black_tree2() {
    this->size = 0;
    this->war = new My_red_black_tree2::Node;
    this->war->color = true;
    this->root = this->war;
}


My_red_black_tree2::~My_red_black_tree2() {
    this->deleteHelper(this->root);
    delete this->war;
}

// funkcja przechodzi od najbardziej lewego elementu potem prawego i usuwa element;
// poczym wraca i jęsli element nie ma dzieci to sam się usuwa i wraca do rodzica
void My_red_black_tree2::deleteHelper(My_red_black_tree2::Node *element) {
    if(element == this->war){
        return;
    }
    if(element->left != this->war){
        this->deleteHelper(element->left);
    }
    if(element->right != this->war){
        this->deleteHelper(element->right);
    }
    delete element;
    element = this->war;
}

My_red_black_tree2::Node* My_red_black_tree2::find(int value) {
    return this->findHelper(value, this->root);
}

// funckja zwraca element który ma podaną wartość bądz zwraca NULL, jeśli nie znajdzie akiego elementu to sprawdza wpierw
// czy wartość danego elementu nie jest większ od podanej wartości i idzie powtarza tą funkcje dla lewego elementu, analogicznie
// potem sprawdza dla prawego elementu
My_red_black_tree2::Node* My_red_black_tree2::findHelper(int value, My_red_black_tree2::Node *element) {
    if(element == this->war){
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

// funkcja kóra wstawia jedno poddrzewo w miejsce drugiego poddrzewa
// dzięki tej funckji zastępujemy poddrzewo o korzeniu first poddrzewem o korzeniu second
void My_red_black_tree2::transplant(My_red_black_tree2::Node *first, My_red_black_tree2::Node *second) {
    // sprawdzamy czy first jest synem jakiegoś elementu
    if(first->parent == this->war){
        this->root = second;
    }
        // zamieniamy dziecko rodzica first elementem second
    else if(first == first->parent->left){
        first->parent->left = second;
    }
    else{
        first->parent->right = second;
    }
    second->parent = first->parent;
}

void My_red_black_tree2::add(int value) {
    // na początku tworzymy element o podanej wartości i ustawiamy wszystkie jego wskaźniki na NULL
    Node* new_element = new My_red_black_tree2::Node;

    new_element->data = value;


    My_red_black_tree2::Node* parent = this->war;
    My_red_black_tree2::Node* child = this->root;
    // teraz zostaje wyszukany element który nie ma dziecka
    // zaczynająć od głowy idziemy do lewego dziecka jeśli ma większą wartość od nowego element w przeciwnym razie idzie do prawego dziecka
    while (child != this->war){
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
    if(parent == this->war){
        this->root = new_element;
    }
        // teraz ustawiamy którym dzieckiem jest nowy element
    else if (new_element->data < parent->data){
        parent->left = new_element;
    }
    else {
        parent->right = new_element;
    }
    new_element->left = this->war;
    new_element->right = this->war;
    new_element->color = false;
    this->size++;
    this->addHelper(new_element);

}


// sprawdzenie i naprawa naruszenia własności: Każdy liść war jest czarny, jeśli węzeł jest czerwony to jego synowie czarni
void My_red_black_tree2::addHelper(My_red_black_tree2::Node *element) {
    // jeśli z parent jest czerwony to wiadomo że będzie miał on rodzica rodzica ponieważ korzeń jest czarny
    // jeśli ojciez jest czarny to dobrze dodaliśmy element i nic nie trzeba zmieniać
    while(!element->parent->color){
        // sprawadzamy któryn synem jest rodzic nowo dodanego elementu
        if(element->parent == element->parent->parent->left) {
            My_red_black_tree2::Node *y = element->parent->parent->right;
            // przypadek kiedy brat y ojca węzła element jest czerwony
            if (!y->color) {
                //kolorujemy ojca i jego brata na czarno a ich ojca na czerwono i przechodzimy do dziadka elemenut żeby teraz od góry naprawić dalej
                element->parent->color = true;
                y->color = true;
                element->parent->parent->color = false;
                element = element->parent->parent;
                continue;
            }
                // y jest czarny i jest prawym synem. Rotujemy ojca elementy aby ustawić syna z ojcem
            else if (element == element->parent->right) {
                element = element->parent;
                this->rotate_left(element);

            }
            //y jest czarny i lewym synem ustawaimy element i jego ojca w jednej lini
            element->parent->color = true;
            element->parent->parent->color = false;
            this->rotate_right(element->parent->parent);
        }
        else{
            // Analogicznie
            My_red_black_tree2::Node* y = element->parent->parent->left;
            if(!y->color){
                element->parent->color = true;
                y->color = true;
                element->parent->parent->color = false;
                element = element->parent->parent;
                continue;
            }
            else if(element == element->parent->left){
                element = element->parent;
                this->rotate_right(element);

            }
            element->parent->color = true;
            element->parent->parent->color = false;
            this->rotate_left(element->parent->parent);
        }

    }
    this->root->color = true;
}


// funckja wyszukuje wpierw element o podanej wartości a potem go usuwa;
void My_red_black_tree2::remove(int value) {
    My_red_black_tree2::Node* element = this->find(value);
    if(element != this->war){
        My_red_black_tree2::Node* y = element;
        My_red_black_tree2::Node* x;
        //zapamiętujemy kolor
        bool y_original_color = y->color;
        //jeśli element nie ma lewego dziecka to podmieniamy element na jego prawe dziecko
        if(element->left == this->war){
            x = element->right;
            this->transplant(element, element->right);
        }
            // analogicznie gdy element nie ma prawego dziecka
        else if(element->right == this->war){
            x = element->left;
            this->transplant(element, element->left);
        }
        else {
            // szukamy teraz w prawym poddrzewie najmniejszy element po to aby go podmienić bo dzięki temu zachowamy własności drzewa
            // jęsli element ma dwoje synów to szukamy taki element w naszym prawej częsci poddrzewie który ma najmniejszą wartość
            y = this->mini_value(element->right);
            // element!=z więc trzeba zmienić original
            y_original_color = y->color;
            x = y->right;
            // więc y nie ma lewego syna
            if(y->parent != element){
                // jeśli y nie jest prawym synem elementu to zastępujemy y u jego ojca przez prawego syna y i zamieniamy prawego syna
                // elementu na prawego syna y
                this->transplant(y, y->right);
                y->right = element->right;
                y->right->parent = y;
            }
            else{
                // w tym wypadku nic nie musimy przestawiać po prostu przesuwamy prawego syna na miejsce ojca
                x->parent = y;
            }
            // zastępujemy element u jego ojca przez y i czynimy lewego syna z lewym synem y
            this->transplant(element, y);
            y->left = element->left;
            y->left->parent = y;
            y->color = element->color;
        }
        delete element;
        this->size--;
        //jesli kolor przesun→ętego liscia był czarny to mogliśmy naruszyć strukture i trzeba ją naprawić
        if(y_original_color){
            this->removeHelper(x);
        }
    }
}

// naprawia trzy naruszenia: korzeń jest czarny, jeśli węzeł czerowny to synowie czarni, nie równa liczba czarnych każdej z ścieżki
void My_red_black_tree2::removeHelper(My_red_black_tree2::Node *element) {
    while(element != this->root && element->color){
        // pętla się wykonuje aż element wskazuje na czerwony i czarny węzeł i naprawiamy
        // element wskazuje na korzeń i można już zakończyć
        if(element == element->parent->left){
            // ustalenie którym synem jest element
            // brat nie jest równ war bo element jest podwójnie czarny
            My_red_black_tree2::Node* w = element->parent->right;
            if(!w->color){
                // jeśli brat jest czerwony to trzeba go zamienić na czarnego i wykonać rotacje
                w->color = true;
                element->parent->color = false;
                this->rotate_left(element->parent);
                w = element->parent->right;
                // nowt brat elementu będący jednym z synów w jest teraz czarny
            }
            // przypadki jesli brat jest czanry
            if(w->left->color && w->right->color){
                // brat oraz jego dzieci są czarne więc zamieniamy kolor brata i idziemy do ojca
                w->color = false;
                element = element->parent;
            }
            //brat 'w' wezła element jest czarny, lewy syn węzła 'w' jest czerwony, a prawy syn węzła 'w' jest czarny
            // zamieniamy kolory i rotujemy
            else if(w->right->color){
                w->left->color = true;
                w->color = false;
                this->rotate_right(element->parent);
                w = element->right;
            }
            // przypisujemy odpowiednie kolory
            // rotujemy b z d i przypisujemy root
            w->color = element->parent->color;
            element->parent->color = true;
            w->right->color = true;
            this->rotate_left(element->parent);
            element = this->root;
        }
        else{
            // analogicznie
            My_red_black_tree2::Node* w = element->parent->left;
            if(!w->color){
                w->color = true;
                element->parent->color = false;
                this->rotate_right(element->parent);
                w = element->parent->left;
            }
            if(w->right->color && w->left->color){
                w->color = false;
                element = element->parent;
            }
            else if(w->left->color){
                w->right->color = true;
                w->color = false;
                this->rotate_left(element->parent);
                w = element->left;
            }
            if(w->color && !w->left->color){
                w->color = element->parent->color;
                element->parent->color = true;
                w->left->color = true;
                this->rotate_right(element->parent);
                element = this->root;
            }
        }
    }
    element->color = true;
}

// wyszukuje element o największej wartości w podanym podrzewie
My_red_black_tree2::Node* My_red_black_tree2::max_value(My_red_black_tree2::Node* element) {
    while(element->right != this->war){
        element = element->right;
    }
    return element;
}

// wyszukuje element o najmniejszej wartości w podanym podrzewie
My_red_black_tree2::Node* My_red_black_tree2::mini_value(My_red_black_tree2::Node* element) {
    while(element->left != this->war){
        element = element->left;
    }
    return element;
}

// rotacja z prawej na lewą. Zamaina elementu z jego prawym synem na prawego syna z lewym synem jako element
My_red_black_tree2::Node* My_red_black_tree2::rotate_left(My_red_black_tree2::Node *element) {
    My_red_black_tree2::Node* y = element->right;
    //prawy syn elementu staje się lewy syn y
    element->right = y->left;
    if(y->left != this->war){
        // jeżeli lewy syn istnieje to zostaje przypisane to samo tylko od strony lewgo syna
        y->left->parent = element;
    }
    y->parent = element->parent;
    // rodzicem y jesy rodzic elementu i jeśli to jest NULL to oznacza że to jest pierszy element i ustawiamy korzeń na y
    if(element->parent == this->war){
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
My_red_black_tree2::Node* My_red_black_tree2::rotate_right(My_red_black_tree2::Node *element) {
    My_red_black_tree2::Node* y = element->left;
    element->left = y->right;
    if(y->right != this->war){
        y->right->parent = element;
    }
    y->parent = element->parent;
    if(element->parent == this->war){
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

void My_red_black_tree2::create_random(int size, int minimum, int maximum) {
    this->size = 0;
    this->deleteHelper(this->root);
    this->root = this->war;
    int data;
    srand( time( NULL ) );
    for(int inc = 0; size > inc; inc++){
        data = ((std::rand() % (maximum-minimum+1)) + minimum);
        this->add(data);
    }
}

void My_red_black_tree2::print() {
    this->printHelp(this->root, 0);
    std::cout << std::endl;
}

void My_red_black_tree2::printHelp(My_red_black_tree2::Node* v, int in) {
    in++;
    if(v != this->war)
    {

        printHelp(v->left, in);
        // przechodzimy lewe poddrzewo
        if(v->color){
            std::cout << v->data << "Black" << in <<", "; // odwiedzamy węzeł
        } else{
            std::cout << v->data << "RED" << in <<", "; // odwiedzamy węzeł
        }

        printHelp(v->right, in);      // przechodzimy prawe poddrzewo
    }
    in--;
}