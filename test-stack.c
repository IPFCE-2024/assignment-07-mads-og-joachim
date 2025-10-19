#include <assert.h>
#include "stack.h"

int main(void){
    stack* s;
    int u, v;

    initialize(s);
    v = 3;
    push(v,s);
    u = pop(s);
    assert(v == u);

    push(1,s);
    push(2,s);
    push(3,s);
    push(4,s);
    print(s);

    destroy_stack(s);
}