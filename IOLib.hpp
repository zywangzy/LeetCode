#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void readVector(vector<int>& input){
	string line;
	int num;
	cout << "Input number elements in linked list:" << endl;
    getline(cin, line);
    istringstream stream(line);
  	while(stream >> num){
    	input.push_back(num);
  	}
}

void viewVector(vector<int>& vec, int length = -1){
    if(length == -1) length = vec.size();
    cout << "[";
    for(int i = 0; i < length; i++){
        cout << vec[i];
    if(i < length - 1) cout << ", ";
    }
    cout << "]" << endl;
}

ListNode* readLinkedList(){
	string line;
    int num;
    cout << "Input number elements in linked list:" << endl;
    getline(cin, line);
    istringstream stream(line);
    ListNode* root = new ListNode(0), *ptr = root;
    while(stream >> num){
        ptr->next = new ListNode(num);
	    ptr = ptr->next;
    }
    ptr = root->next;
    delete root;
    return ptr;
}

void viewLinkedList(ListNode* head){
    cout << "[";
    ListNode* ptr = head;
    while(ptr != NULL){
        cout << ptr->val;
        if(ptr->next != NULL){
            cout << ", ";
        }
        ptr = ptr->next;
    }
    cout << "]" << endl;
}

int readInt(){
    cout << "Input a number: ";
    int res;
    cin >> res;
    return res;
}

/*
This version of buildBinaryTree is with problem,
it cannot successfully build a tree. Cannot link
child nodes to parent node.
*/
void buildBinaryTree(TreeNode* root, vector<int>& nums, int idx){
    int length = nums.size();
    if(idx >= length) return;
    if(idx == 0) root = new TreeNode(nums[idx]);
    int leftidx = 2 * idx + 1, rightidx = leftidx + 1;
    if(leftidx < length){
        root->left = new TreeNode(nums[leftidx]);
        buildBinaryTree(root->left, nums, leftidx);
    }
    if(rightidx < length){
        root->right = new TreeNode(nums[rightidx]);
        buildBinaryTree(root->right, nums, rightidx);
    }
}

TreeNode* readBinaryTree(){
    vector<int> nums;
    string line;
    int num;
    cout << "Input number elements in binary tree: " << endl;
    getline(cin, line);
    istringstream stream(line);
    while(stream >> num){
        nums.push_back(num);
    }
    viewVector(nums);
    TreeNode* root = NULL;
    buildBinaryTree(root, nums, 0);
    return root;
}

void InOrderTraverse(TreeNode* node){
    if(node == NULL){
        cout << "null ";
        return;
    }
    if(node->left != NULL) InOrderTraverse(node->left);
    cout << node->val << " ";
    if(node->right != NULL) InOrderTraverse(node->right);
}

void viewBinaryTree(TreeNode* root){
    cout << "In-Order Traverse of tree: " << endl;
    InOrderTraverse(root);
    cout << endl;
}