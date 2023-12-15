#include "dsets.h"

DisjointSets::DisjointSets() {}

DisjointSets::~DisjointSets() {
    sets.clear();
}

void DisjointSets::addElements(int num) {
    for (int i = 0; i < num; i ++) {
        sets.push_back(-1);
    }
    return;
}

int DisjointSets::find(int elem) {
    if (sets[elem] < 0) {
        return elem;
    } else {
        int out = 0;
        out = find(sets[elem]);
        sets[elem] = out;
        return out;
    }
}

void DisjointSets::setUnion(int a, int b) {
    a = find(a);
    b = find(b);
    int size = sets[a] + sets[b];

    if (sets[a] <= sets[b]) {
        sets[b] = a;
        sets[a] = size;
    } else {
        sets[a] = b;
        sets[b] = size;
    }

    return;
}

int DisjointSets::size(int elem) {
    return -(sets[find(elem)]);
}