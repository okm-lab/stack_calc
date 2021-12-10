//
// Created by Mikhail Okan on 15.11.2021.
//

#include "Actions.h"

Action::Action(std::string &_args) {
    std::string str;
    args = std::stringstream(_args);
    args >> str;
}

bool Action::is_number(const std::string &line) { // stupid but simple way to check if input is num or var
    try {
        std::stol(line);
        return true;
    }
    catch (const std::invalid_argument &err) {
        return false;
    }
}

SafeInt<long> ArithmeticAction::pop(std::stack<SafeInt<long>> &st) {
    SafeInt<long> val = st.top();
    st.pop();
    return val;
}

void Push::act(std::stack<SafeInt<long>> &st, std::map<std::string, SafeInt<long>> &vars) {
    std::string value;
    args >> value;
    if (is_number(value)) {
        st.push(std::stol(value));
    } else {
        if (vars.count(value) == 0) {
//            std::cerr << "Invalid argument to push!" << std::endl;
//            std::cerr << "You should push only integers or variables!" << std::endl;
//            std::cerr << "\"" << value << "\" is not an integer or variable";
//            exit(1);
            throw std::invalid_argument("Invalid argument to push! (" + value + " is not an integer or variable)");
        }
        st.push(vars[value]);
    }
}

void Pop::act(std::stack<SafeInt<long>> &st, std::map<std::string, SafeInt<long>> &vars) {
    if (st.empty()) {
//        std::cerr << "Empty argument to pop!" << std::endl;
//        std::cerr << "There are no numbers in stack!";
//        exit(1);
        throw std::invalid_argument("Stack is empty!");
    }
    st.pop();
}

void Peek::act(std::stack<SafeInt<long>> &st, std::map<std::string, SafeInt<long>> &vars)  {
    std::string value;
    args >> value;
    if (st.empty()) {
//        std::cerr << "Empty argument to peek!" << std::endl;
//        std::cerr << "There are no numbers in stack!";
//        exit(1);
        throw std::invalid_argument("Stack is empty!");
    }
    vars[value] = st.top();
}

void Print::act(std::stack<SafeInt<long>> &st, std::map<std::string, SafeInt<long>> &vars)  {
    if (st.empty()) {
//        std::cerr << "Empty argument to print!" << std::endl;
//        std::cerr << "There are no numbers in stack!";
//        exit(1);
        throw std::invalid_argument("Stack is empty!");
    }
    vars["0x0badc0de"] = st.top();
    std::cout << (long)st.top() << std::endl;
}

void Read::act(std::stack<SafeInt<long>> &st, std::map<std::string, SafeInt<long>> &vars) {
    std::string value;
    std::cin >> value;
    if (!is_number(value)) {
//        std::cerr << "Invalid argument to read!" << std::endl;
//        std::cerr << "You can read only integers!" << std::endl;
//        std::cerr << "\"" << value << "\" is not an integer or variable";
//        exit(1);
        throw std::invalid_argument("Invalid argument to read!");
    }
    st.push(std::stol(value));
}

void Abs::act(std::stack<SafeInt<long>> &st, std::map<std::string, SafeInt<long>> &vars) {
    if (st.empty()) {
//        std::cerr << "Empty argument to abs!" << std::endl;
//        std::cerr << "There are no numbers in stack!";
//        exit(1);
        throw std::invalid_argument("Stack is empty!");
    }
    st.push(st.top() * (pop(st) > 0 ? 1 : -1));
}

void Plus::act(std::stack<SafeInt<long>> &st, std::map<std::string, SafeInt<long>> &vars) {
    if (st.size() < 2) {
//        std::cerr << "Not enough arguments to plus!" << std::endl;
//        std::cerr << "Stack has only " << st.size() << " elements";
//        exit(1);
        throw std::invalid_argument("Stack has only " + std::to_string(st.size()) + " element(s)!");
    }
    SafeInt<long> b=st.top(); st.pop(); SafeInt<long> a = st.top(); st.pop();
    try {
        st.push(a + b);
    }
    catch (SafeIntException &err){
        throw std::invalid_argument("Overflow exception (" + std::to_string((long)a) + " + " + std::to_string((long)b) + ")!");
//        std::cerr << "Overflow exception (" << (long)a << " + " << (long)b << ")!" << std::endl;
//        exit(1);
    }
}

void Minus::act(std::stack<SafeInt<long>> &st, std::map<std::string, SafeInt<long>> &vars) {
    if (st.size() < 2) {
//        std::cerr << "Not enough arguments to minus!" << std::endl;
//        std::cerr << "Stack has only " << st.size() << " elements";
//        exit(1);
        throw std::invalid_argument("Stack has only " + std::to_string(st.size()) + " element(s)!");
    }
    SafeInt<long> b=st.top(); st.pop(); SafeInt<long> a = st.top(); st.pop();
    try {
        st.push(a - b);
    }
    catch (SafeIntException &err){
//        std::cerr << "Overflow exception (" << (long)a << " - " << (long)b << ")!" << std::endl;
//        exit(1);
        throw std::invalid_argument("Overflow exception (" + std::to_string((long)a) + " - " + std::to_string((long)b) + ")!");
    }
}

void Mul::act(std::stack<SafeInt<long>> &st, std::map<std::string, SafeInt<long>> &vars) {
    if (st.size() < 2) {
//        std::cerr << "Not enough arguments to mul!" << std::endl;
//        std::cerr << "Stack has only " << st.size() << " elements";
//        exit(1);
        throw std::invalid_argument("Stack has only " + std::to_string(st.size()) + " element(s)!");
    }
    SafeInt<long> b=st.top(); st.pop(); SafeInt<long> a = st.top(); st.pop();
    try {
        st.push(a * b);
    }
    catch (SafeIntException &err){
//        std::cerr << "Overflow exception (" << (long)a << " * " << (long)b << ")!" << std::endl;
//        exit(1);
        throw std::invalid_argument("Overflow exception (" + std::to_string((long)a) + " * " + std::to_string((long)b) + ")!");
    }
}

void Div::act(std::stack<SafeInt<long>> &st, std::map<std::string, SafeInt<long>> &vars) {
    if (st.size() < 2) {
//        std::cerr << "Not enough arguments to div!" << std::endl;
//        std::cerr << "Stack has only " << st.size() << " elements";
//        exit(1);
        throw std::invalid_argument("Stack has only " + std::to_string(st.size()) + " element(s)!");
    }
    SafeInt<long> b=st.top(); st.pop(); SafeInt<long> a = st.top(); st.pop();
    if (b == 0) {
//        std::cerr << "Zero division error!" << std::endl;
//        exit(1);
        throw std::invalid_argument("Zero division error!");
    }
    st.push(a / b);
}