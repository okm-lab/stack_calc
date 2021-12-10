//
// Created by Mikhail Okan on 15.11.2021.
//

#include "ConcreteActionCreator.h"

std::map<std::string, std::function<Action*(std::string)>> actions = {
        {"PUSH", [](std::string s){ return new Push(s); }},
        {"POP", [](std::string s){ return new Pop(s); }},
        {"PEEK", [](std::string s){ return new Peek(s); }},
        {"PRINT", [](std::string s){ return new Print(s); }},
        {"READ", [](std::string s){ return new Read(s); }},
        {"ABS", [](std::string s){ return new Abs(s); }},
        {"PLUS", [](std::string s){ return new Plus(s); }},
        {"MINUS", [](std::string s){ return new Minus(s); }},
        {"MUL", [](std::string s){ return new Mul(s); }},
        {"DIV", [](std::string s){ return new Div(s); }}
};


Action *CAC::ConcreteActionCreator::getAction(std::stringstream &line) {
    std::string action;
    line >> action;
    std::string args = line.str();
    if (action[0] != '#') {
        if (actions.count(action) == 0) {
            throw std::invalid_argument("Invalid operation (" + action  + ")!");
//            exit(1);;
//            std::cerr << "Invalid operation " << action << "!" << std::endl;
        }
        return actions[action](args);
    }
    return nullptr;
}