template <typename KEY, typename T>

struct Elem 
{
  Elem():left(0), right(0), height(-1), rightThread(false) {}
  KEY key;
  T data;
  Elem *left;
  Elem *right;
  int height;
  bool rightThread; //normal right child link or a threadlink
};

Elem *_root; // a dummy root sentinel
int _size;

// helper method for inserting record into tree.
bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft);

// helper method for print tree
void printTree(ostream& out, int level, Elem *p) const;

// common code for deallocation
void destructCode(Elem *& p);

void rotateRight(Elem *& node);
void rotateLeft(Elem *& node);
void doubleRotateRight(Elem *& node);
void doubleRotateLeft(Elem *& node);

int balanceFactor(Elem *cur);
void balance(Elem*& cur, const KEY &key);

int height(Elem *node);
void updateHeight(Elem*& cur);
