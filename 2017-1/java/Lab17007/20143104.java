import java.util.*;

/**
 */

class WinnerTree  {
	int[] tree; // Winner tree

	int capacity;	// size of the tree
	int n;	// number of external elements in WinnerTree


	WinnerTree(int theCapacity) { // WinnerTree constructor.
		capacity = theCapacity;
		tree = new int[capacity];	// tree[0] is not used
		n = 0;
	}

	public String toString() { // Show all the element in sequence
		String str = new String();
		str = "WT : - ";

		// print all the nodes in the tree
		for(int i = 1; i < n * 2; i++)
			str += tree[i] + "  ";
		return str;

	}

	void  Init(int[] treedata, int nitems) {
		// initialize the tree by using the input
		n = nitems / 2;

		int i = 1;
		for(i = 1; i < nitems; i++) {
			tree[i] = treedata[i];
		}
	}

	void PopNReplace(int data) {
		// NEED TO IMPLEMENT
		for(int i=n; i<2*n; i++){
			if((tree[1]==tree[i])){
				tree[i]=data;
				break;
			}
		}
		for(int i=n-1; i>=1; i--){
			if(tree[2*i]>tree[2*i+1])
				tree[i]=tree[2*i+1];
			else
				tree[i]=tree[2*i];
		}
	}
}
