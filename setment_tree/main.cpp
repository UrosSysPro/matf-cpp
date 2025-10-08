#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class SegmentTree
{
    std::vector<int> values;
    void buildTree(int index);
public:
    SegmentTree();
    ~SegmentTree();
    void init(std::vector<int> values);
    int sum(int i,int j);
};

SegmentTree::SegmentTree()
{
    values=std::vector<int>(0);
}

void SegmentTree::buildTree(int index)
{
    
}
void SegmentTree::init(std::vector<int> values)
{
    // init array
    int len=values.size();
    int size=1;
    for (size=1;size<len;size*=2);
    size*=2;
    size-=1;
    this->values = std::vector<int>(size);
    // copy array
    for (int i=0;i<size/2+1;i++)this->values[size/2+i]=i<len?values[i]:0;
    //build tree
    buildTree(0);
}

int main(int argc, char** argv) {
    SegmentTree tree;
    tree.init({1,2,3,4,5,6});
    std::cout << tree.sum(2,5) << std::endl;
    std::cout << tree.sum(1,5) << std::endl;
    return 0;
}
