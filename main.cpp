#include <iostream>
#include <limits>

int i = 0;
const int MAX_SIZE = std::numeric_limits<int>::max();
int stack[MAX_SIZE];

int stack_empty(){
    return (i==0);
}

int push(int x){
    if (i< MAX_SIZE){
        stack[i++]=x;
        return (0);
    }
    else {
        return (-1);
    }
}

int pop(){
    return (stack[--i]);
}

bool loop();

int main() {
    bool exit_flag = false;
    while (!exit_flag) {
        exit_flag = loop();
    }
    return 0;
}

bool loop(){
    int choice=-1;
    std::cout << "[1]. Push" << std::endl;
    std::cout << "[2]. Pop" << std::endl;
    std::cout << "[3]. Print stack" << std::endl;
    std::cout << "[0]. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    int value;
    switch (choice) {
                case 1:
                    std::cout << "Enter integer value: ";
                    std::cin >> value;
                    push(value);
                    std::cout << "Saved "<< value << " to stack." << std::endl;
                    break;
                case 2:
                    if (stack_empty()) {
                        std::cout << "Stack empty." << std::endl;
                        return false;
                    }
                    value = pop();
                    std::cout << "Popped value ["<< value << "] from stack." << std::endl;
                    break;
                case 3:
                    if (stack_empty()) {
                        std::cout << "Stack empty." << std::endl;
                        return false;
                    }
                    std::cout << "Printing " << i << " value(s) inside the stack. " << std::endl;
                    for (int j = 0; j < i; j++){
                        std::cout << stack[j] << "; ";
                    }
                    std::cout << std::endl;
                    break;
                case 0:
                    return true;
                default: break;
    }
    return false;
}

//
//typedef struct st_t {
//    item_t item;
//    struct st_t *next;
//} stack_t;
//
//stack_t *create_stack(){
//    stack_t *st;
//    st= get_node();
//    st->next = NULL;
//    return (st);
//}