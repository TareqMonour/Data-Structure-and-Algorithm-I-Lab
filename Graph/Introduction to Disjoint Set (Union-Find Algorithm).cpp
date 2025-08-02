// Finds the representative of the set
// that i is an element of

#include<bits/stdc++.h>
using namespace std;

int find(int i)

{

	// If i is the parent of itself
	if (parent[i] == i) {

		// Then i is the representative of
		// this set
		return i;
	}
	else {

		// Else if i is not the parent of
		// itself, then i is not the
		// representative of his set. So we
		// recursively call Find on its parent
		return find(parent[i]);
	}
}

// The code is contributed by Nidhi goel
