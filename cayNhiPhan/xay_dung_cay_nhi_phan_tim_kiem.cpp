#include<bits/stdc++.h>
using namespace std;

void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct node{
    int value;
    node *left;
    node *right;
    node(int x){
        value = x;
        left = right = NULL;
    }
};

// tạo cây nhị phân tìm kiếm
void insertnode(node* &root,int val){
    if(root == NULL){
        root = new node(val);
        return;
    }
    if(root->value > val) insertnode(root->left,val);
    if(root->value < val) insertnode(root->right,val);
}

void postorder(node *root){
    if(root == NULL) return;
    cout << root->value << " ";
    if(root->left != NULL) postorder(root->left);
    if(root->right != NULL) postorder(root->right);
}

void solution(){
    faster();
    int t;
    cin >> t;
    while(t--){
        int n,a[1005];
        cin >> n;
        node *tree = NULL;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            insertnode(tree,a[i]);
        }
        postorder(tree);
        cout << endl;
    }
}

int main(){
    solution();
    return 0;
}