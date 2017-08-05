#include <BinarySearchTree/BST.hpp>
#include <Helper.hpp>
#include <array>
#include <iostream>

using namespace std;

int main() {
    BinarySearchTree<int> a;
    cout << "Is a empty: " << a.isEmpty() << '\n';
    array<int, 15> v = {};
    helper::randomize(v);
    cout << "vector size: " << v.size() << '\n';
    for (auto &e : v) {
        cout << e << " ";
    }
    cout << '\n';

    for (auto &e : v) {
        a.insert(e);
    }
    cout << "Is a empty: " << a.isEmpty() << '\n';
    cout << "Size: " << a.size() << '\n';
    cout << "Min: " << a.findMin() << '\n';
    cout << "Max: " << a.findMax() << '\n';
    a.print_inorder();
    a.print_preorder();
    a.print_postorder();
    a.makeEmpty();
    cout << "Is a empty: " << a.isEmpty() << '\n';
    return 0;
}
