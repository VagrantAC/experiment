#include <iostream>
#include <map>
using namespace std;

class Node {
public:
  int value;
  Node *next;
  Node *pre;

  Node(int value);
};

Node::Node(int value) {
  this->value = value;
  this->next = nullptr;
  this->pre = nullptr;
}

class NodeManager {
private:
  Node *l, *r;
  int len;
  map<int, Node *> mp;

  Node *newNode(int value);

public:
  NodeManager();
  void addRNode(int pos, int value);
  void addLNode(int pos, int value);
  void delNode(int pos);
  void print();
};

Node *NodeManager::newNode(int value) {
  Node *node = new Node(value);
  mp[len] = node;
  len++;
  return node;
}

NodeManager::NodeManager() {
  len = 0;
  mp.clear();
  l = newNode(0);
  r = newNode(0);
  l->next = r;
  r->pre = l;
}

void NodeManager::addRNode(int pos, int value) {
  Node *node = newNode(value);
  Node *preNode = mp[pos];
  Node *nextNode = mp[pos]->next;
  preNode->next = node;
  node->next = nextNode;
  nextNode->pre = node;
  node->pre = preNode;
}

void NodeManager::addLNode(int pos, int value) {
  Node *node = newNode(value);
  Node *preNode = mp[pos]->pre;
  Node *nextNode = mp[pos];
  preNode->next = node;
  node->next = nextNode;
  nextNode->pre = node;
  node->pre = preNode;
}

void NodeManager::delNode(int pos) {
  Node *preNode = mp[pos]->pre;
  Node *nextNode = mp[pos]->next;
  nextNode->pre = preNode;
  preNode->next = nextNode;
}

void NodeManager::print() {
  Node *node = l->next;
  while (node->next != nullptr) {
    cout << node->value << " ";
    node = node->next;
  }
  cout << endl;
}

int main() {
  int n, x, k;
  cin >> n;
  NodeManager *nodeManager = new NodeManager();
  while (n--) {
    string str;
    cin >> str;
    switch (str[0]) {
    case 'L':
      cin >> x;
      nodeManager->addRNode(0, x);
      break;
    case 'R':
      cin >> x;
      nodeManager->addLNode(1, x);
      break;
    case 'D':
      cin >> k;
      nodeManager->delNode(k + 1);
      break;
    default:
      cin >> k >> x;
      if (str[1] == 'L') {
        nodeManager->addLNode(k + 1, x);
      } else {
        nodeManager->addRNode(k + 1, x);
      }
      break;
    }
  }

  nodeManager->print();
  return 0;
}
