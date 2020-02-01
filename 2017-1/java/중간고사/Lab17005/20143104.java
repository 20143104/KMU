import java.util.*;

/**
 * Generic version of the SortedList class.
 */

class SortedList <T extends Comparable<T> > {

	class SortedListNode <U extends Comparable<U> >{
	    U data; // storage for data
		SortedListNode<U> link;    // link to the next node
	};

	private SortedListNode<T> first; // pointer to the dummy header node
	private SortedListNode<T> av; // pointer to the available list

	public SortedList() {
		av = null;
		first = null;
	}

	void Init(T data) { // SortedList constructor. Create a dummy first node
		first = GetNode();
		first.data = data;
		first.link = first;
	}


	void Clear() {
		SortedListNode<T> x = first.link;
		first.link = av;
		av =x;

	}

	SortedListNode<T> GetNode() {
		SortedListNode<T> x = null;
		if(av==null){
		   x = new SortedListNode<T>();
		}
		else{
			x = av;
			av  = av.link;
		}
		return x;
	}


	void  Insert(T e) {
		SortedListNode<T> x = GetNode();
		x.data = e;

		SortedListNode<T> p = first;
		while(true){
			if(0>e.compareTo(p.link.data))
			{
					break;
			}
			p=p.link;
		}
		x.link = p.link;
		p.link = x;
	}


	public String toString() {
		String str = "";

		if(first == null) return "";
		SortedListNode<T> p = first.link;

		str += "List : ";
		// traverse all the nodes
		while (p != first) {
			str += p.data + "  ";
			p = p.link;
		}
		str += "\n";

		p = av;
		// show the count of av list
		int cnt = 0;
		while (p != null) {
			cnt++;
			p = p.link;
		}
		str +=  "Av : " + cnt;

		return str;
	}
};
