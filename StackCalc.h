//
// Created by Mikhail Okan on 15.11.2021.
//

#ifndef STACK_CALC_STACKCALC_H
#define STACK_CALC_STACKCALC_H
#include <string>
#include "Actions.h"
#include "ConcreteActionCreator.h"
#include "SafeInt/SafeInt.hpp"

namespace SC {
    class StackCalc {
    private:
        std::map<std::string, SafeInt<long>> vars;
        std::stack<SafeInt<long>> st;
        SafeInt<long> last;
    public:
        void act(Action *action);

        void execute(std::istream &in);
        SafeInt<long> get_last();
    };
}

#endif //STACK_CALC_STACKCALC_H
