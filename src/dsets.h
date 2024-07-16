#include <vector>

class DisjointSets {
    public:
        DisjointSets();
        ~DisjointSets();
        void addElements(int num);
        int find(int elem);
        void setUnion(int a, int b);
        int size(int elem);
    
    private:
        std::vector<int> sets;
};