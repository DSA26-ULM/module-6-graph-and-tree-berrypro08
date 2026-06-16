#include <iostream>
#include <string>
#include "RedBlackTree.h"

using namespace std;

// Fungsi sederhana untuk mencetak urutan Preorder (Akar, Kiri, Kanan) 
void cetakPreorder(const RedBlackTree::Node* node, bool &first) {
    if (node->isNil) return;

    if (!first) cout << " ";
    cout << node->key;
    first = false;

    cetakPreorder(node->left, first);
    cetakPreorder(node->right, first);
}

// Fungsi sederhana untuk mencetak urutan Inorder (Kiri, Akar, Kanan)
void cetakInorder(const RedBlackTree::Node* node, bool &first) {
    if (node->isNil) return;

    cetakInorder(node->left, first);
    
    if (!first) cout << " ";
    cout << node->key;
    first = false;

    cetakInorder(node->right, first);
}

// Fungsi sederhana untuk mencetak urutan Postorder (Kiri, Kanan, Akar)
void cetakPostorder(const RedBlackTree::Node* node, bool &first) {
    if (node->isNil) return;

    cetakPostorder(node->left, first);
    cetakPostorder(node->right, first);

    if (!first) cout << " ";
    cout << node->key;
    first = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    RedBlackTree rbt;
    int N;

    // 1. Ambil berapa banyak angka yang akan dimasukkan
    if (!(cin >> N)) return 0;

    // 2. Masukkan angka satu per satu
    for (int i = 0; i < N; i++) {
        int angka;
        cin >> angka;
        // Sesuai aturan: jika angka sudah ada, jangan masukkan lagi (abaikan duplikat)
        if (!rbt.contains(angka)) {
            rbt.insert(angka);
        }
    }

    // 3. Baca jumlah query
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string tipeQuery;
        cin >> tipeQuery;

        bool first = true;
        if (tipeQuery == "PREORDER") {
            cout << "[Preorder]  : ";
            cetakPreorder(rbt.root(), first);
            cout << endl;
        } else if (tipeQuery == "INORDER") {
            cout << "[Inorder]   : ";
            cetakInorder(rbt.root(), first);
            cout << endl;
        } else if (tipeQuery == "POSTORDER") {
            cout << "[Postorder] : ";
            cetakPostorder(rbt.root(), first);
            cout << endl;
        } else if (tipeQuery == "ALL") {
            first = true;
            cout << "[Preorder]  : ";
            cetakPreorder(rbt.root(), first);
            cout << endl;
            first = true;
            cout << "[Inorder]   : ";
            cetakInorder(rbt.root(), first);
            cout << endl;
            first = true;
            cout << "[Postorder] : ";
            cetakPostorder(rbt.root(), first);
            cout << endl;
        }
    }

    return 0;
}