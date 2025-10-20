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
    printf("Test 1 succeful: Consistency through 1 push and pop");

    assert(empty(s));
    push(1,s);
    assert(!empty(s));
    push(2,s);
    assert(!empty(s));
    assert(!full(s));
    push(3,s);
    push(4,s);
    print(s);
    printf("Test 2 succeful: Print works");

    int v0 = 3;
    int v1 = 2;
    push(v0,s);
    push(v1,s);
    int u0 = pop(s);
    int u1 = pop(s);
    printf("Test 3 succeful: 2 push then pop");

    assert(v0 == u1);
    assert(v1 == u0);

    assert(v == u);

    destroy_stack(s);
    assert(empty(s));
}