#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class TreeNode{
public:
    const int data;
    TreeNode*left;
    TreeNode*right;


    TreeNode(int d):data(d),left(NULL),right(NULL){

    }
};

void traverseTree(TreeNode*root,unordered_map<int,vector<int> > &m,int d=0)
{
    if(root==NULL){
        return;
    }

    int key = d;
    m[key].push_back(root->data);

    traverseTree(root->left,m, d-1);
    traverseTree(root->right,m, d+1);



}

int main(){
    TreeNode* n = new TreeNode(1);
    n->left = new TreeNode(2);
    n->right = new TreeNode(3);
    n->left->left = new TreeNode(4);
    n->left->right = new TreeNode(5);
    n->right->left = new TreeNode(6);
    n->right->right = new TreeNode(7);
    n->left->right->right = new TreeNode(8);
    n->right->right->right = new TreeNode(9);

    unordered_map<int, vector<int> > m;

    traverseTree(n,m);
    int min_key=INT_MAX, max_key=INT_MIN;

    for(auto it=m.begin();it!=m.end();it++){
        min_key = min(min_key,it->first);
        max_key = max(max_key,it->first);
    }

    for(int key = min_key;key<=max_key;key++){

        for(int i=0;i < m[key].size();i++){
            cout<< m[key][i] <<" ";
        }
        cout<<endl;
    }


return 0;
}
