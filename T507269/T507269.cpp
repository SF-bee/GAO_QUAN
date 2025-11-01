#include <bits/stdc++.h>

struct bst{  //左节点大于根，右节点小于根
    int val,count,size;
    bst *left, *right;

    bst(int v)
        : val(v),count(1),size(1),left(nullptr),right(nullptr) {}
};

int n;
bst *root;

bst* insert(bst *node,int x){  //插入节点
    if(node == nullptr)
        return new bst(x);
    else if(x < node->val)
        return insert(node->left,x);
    else if(node->val < x)
        return insert(node->right,x);
    else
        node->count++;
    node->size = node->count + (node->left ? node->left->size : 0) +
            (node->right ? node->right->size : 0);
    return node;
}
bst* gpre(bst *node,int x){ //获取根小于x的子树的根
    if(node == nullptr) return nullptr;
    else if(node->val < x) return node;
    else return gpre(node->left,x);
}
bst* gnxt(bst *node,int x){ //获取根大于x的子树的根
    if(node == nullptr) return nullptr;
    else if(node->val > x) return node;
    else return gnxt(node->right,x);
}
bst* gmax(bst *node){  //获取以node为根的最大值
    while(node->right != nullptr)
        node = node->right;
    return node;
}
bst* gmin(bst *node){  //获取以node为根的最小值
    while(node->left != nullptr)
        node = node->left;
    return node;
}
bst* erase(bst *node,int x){  //删除节点x
    if(node == nullptr) return node;
    else if(x < node->val)
        return erase(node->left,x);
    else if(node->val < x)
        return erase(node->right,x);
    else{
        if(node->count > 1) node->count--;
        else{
            if(node->left == nullptr){
                bst *t = node->right;
                delete node;
                return t;
            }
            else if(node->right == nullptr){
                bst *t = node->left;
                delete node;
                return t;
            }
            else{
                bst *t = gmin(node);
                node->val = t->val;
                node->count = t->count;
                t->count = 1;
                node->right = erase(node->right,t->val);
            }
        }
    }
    return node;
}
int grank(bst *node,int x){
    if(node == nullptr) return 0;
    else if(node->val == x) return (node->left ? node->left->size : 0) + 1;
    else if (node->val > x) return grank(node->left,x);
    return grank(node->right,x) + (node->left ? node->left->size : 0) +
        node->count;
}
int gkth(bst *node,int k){
    if(node == nullptr) return -1;
    if(node->left){
        if (node->left->size >= k) return gkth(node->left, k);
        if (node->left->size + node->count >= k) return node->val;
    }
    else 
        if (k == 1) return node->val;
    return gkth(node->right,
                  k - (node->left ? node->left->size : 0) - node->count);
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    while(n--){
        int op,x;
        std::cin >> op >> x;
        switch (op){
            case 1:
                root = insert(root,x);
                break;
            case 2:
                root = erase(root,x);
                break;
            case 3:
                std::cout << grank(root,x) << '\n';
                break;
            case 4:
                std::cout << gkth(root,x) << '\n';
                break;
            case 5:
                std::cout << gmax(gpre(root,x))->val << '\n';
                break;
            case 6:
                std::cout << gmin(gnxt(root,x))->val << '\n';
                break;
        }
    }
    return 0;
}