#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int info;
    vector<Node *>child;
};

Node *newNode(int info) {
    Node *temp = new Node;
    temp->info = info;
    return temp;
}

void printNode(Node *node) {
    cout << node->info << " ";
    for (auto elem : node->child) {
        cout << elem->info << " ";
    }
    cout << endl;
    
    for (int i = 0; i < node->child.size(); i++) {
        for (int j = 0; j < node->child[i]->child.size(); j++) {
            printNode(node->child[i]->child[j]);
        }
    }
}

void printPreorderByLevel(Node* root) {
    if (root == nullptr) return;
    
    printNode(root);
    cout << 0 << endl;
}

int main()
{
    FILE* originalTree = freopen("alice.in", "r", stdin);
	FILE* mirrorTree = freopen("alice.out", "w", stdout);
	
    vector<Node*> treeNodes;
    string line;
    
    Node *root = NULL;

    while(getline(cin, line)) {
        istringstream iss(line);
        
        int parent, children;
        iss >> parent;
        root = newNode(parent);
        vector<int> temp;
        while (iss >> children) temp.push_back(children);
        reverse(temp.begin(), temp.end());
        for (auto elem: temp) {
            root->child.push_back(newNode(elem));
        }

        treeNodes.push_back(root);
    }
    
    for (int i = 0; i < treeNodes.size(); i++) {
        int key = treeNodes[i]->info;
        vector<Node*> children = treeNodes[i]->child;
        
        for (int j = 0; j < treeNodes.size(); j++) {
            for (Node* child : children) {
                if (child->info == treeNodes[j]->info) {
                    child->child.push_back(treeNodes[j]);
                }
            }
        }
    }
    
    auto it = find_if(treeNodes.begin(), treeNodes.end(), [](const Node* node) {
        return node->info == 1;
    });
    
    if (it != treeNodes.end()) printPreorderByLevel(*it);
    else printPreorderByLevel(treeNodes[0]);
}