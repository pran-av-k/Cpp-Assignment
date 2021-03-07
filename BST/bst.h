
 template <typename KEY, typename T>

	
   	struct Elem {
			KEY key;
			T data;
			Elem *left;
			Elem *right;
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



	
	   
	
