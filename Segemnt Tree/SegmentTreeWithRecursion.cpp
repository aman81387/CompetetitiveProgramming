#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int arr[100001];

void build(int node, int st, int en) {
  if (st == en) {
    // left node ,string the single array element
    seg[node] = arr[st];
    return;
  }

  int mid = (st + en) / 2;

  // recursively call for left child
  build(2 * node, st, mid);

  // recursively call for the right child
  build(2 * node + 1, mid + 1, en);

  // Updating the parent with the values of the left and right child.
  seg[node] = seg[2 * node] + seg[2 * node + 1];
}


void update(int node, int st, int en, int l, int r, int val) {
  if (lazy[node] != 0) // if node is lazy then update it
  {
    seg[node] += (en - st + 1) * lazy[node];

    if (st != en) // if its children exist then mark them lazy
    {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0; // No longer lazy
  }
  if ((en < l) || (st > r)) // case 1
  {
    return;
  }
  if (st >= l && en <= r) // case 2
  {
    seg[node] += (en - st + 1) * val;
    if (st != en) {
      lazy[2 * node] += val; // mark its children lazy
      lazy[2 * node + 1] += val;
    }
    return;
  }

  // case 3
  int mid = (st + en) / 2;

  // recursively call for updating left child
  update(2 * node, st, mid, l, r, val);
  // recursively call for updating right child
  update(2 * node + 1, mid + 1, en, l, r, val);

  // Updating the parent with the values of the left and right child.
  seg[node] = (seg[2 * node] + seg[2 * node + 1]);
}


int query(int node, int st, int en, int l, int r) {
  /*If the node is lazy, update it*/
  if (lazy[node] != 0) {

    seg[node] += (en - st + 1) * lazy[node];
    if (st != en) //Check if the child exist
    {
      // mark both the child lazy
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    // no longer lazy
    lazy[node] = 0;
  }
  // case 1
  if (en < l || st > r) {
    return 0;
  }

  // case 2
  if ((l <= st) && (en <= r)) {
    return seg[node];
  }
  int mid = (st + en) / 2;

  //query left child 
  ll q1 = query(2 * node, st, mid, l, r);

  // query right child
  ll q2 = query(2 * node + 1, mid + 1, end, l, r);

  return (q1 + q2);
}


int main() {

// do something here. 

}