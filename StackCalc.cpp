//
// Created by Mikhail Okan on 15.11.2021.
//

#include "StackCalc.h"

void SC::StackCalc::act(Action *action) {
    action->act(st, vars);
}

void SC::StackCalc::execute(std::istream &input) {
    std::string line;
    Action *action;
    while (!input.eof()) {
        std::getline(input, line);
        std::stringstream action_line(line);
        try {
            action = CAC::ConcreteActionCreator::getAction(action_line);
        }
        catch (std::invalid_argument &err) {
            std::cerr << "Error while receiving command!" << std::endl;
            throw err;
        }
        if (action != nullptr) {
            try {
                this->act(action);
            }
            catch (std::invalid_argument &err) {
                std::cerr << "Error during the execution!" << std::endl;
                delete action;
                throw err;
            }
            delete action;
        }
    }
}
SafeInt<long> SC::StackCalc::get_last() {
    return vars["0x0badc0de"];
}