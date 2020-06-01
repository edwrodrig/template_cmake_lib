#include "tpl_project_tpl/Element.h"

namespace tpl_project_tpl {

Element::Element(int a, int b) {
    this->a = a;
    this->b = b;
}

int Element::sum() {
    return this->a + this->b;
}

}


