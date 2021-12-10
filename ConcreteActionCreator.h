//
// Created by Mikhail Okan on 15.11.2021.
//

#ifndef STACK_CALC_CONCRETEACTIONCREATOR_H
#define STACK_CALC_CONCRETEACTIONCREATOR_H
#include "Actions.h"
namespace CAC {
    class ConcreteActionCreator {
    public:
        static Action* getAction(std::stringstream &line);
    };
}


#endif //STACK_CALC_CONCRETEACTIONCREATOR_H
