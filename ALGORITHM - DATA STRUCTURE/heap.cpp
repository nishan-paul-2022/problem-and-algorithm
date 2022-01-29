///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vli vector<long long>::iterator
#define vvl vector< vector<long long> >
#define vvli vector< vector<long long> >::iterator
#define vul vector<unsigned long long>
#define vuli vector<unsigned long long>::iterator
#define pll pair<long long,long long>
#define vpll vector< pair<long long,long long> >
#define vplli vector< pair<long long,long long> >::iterator
#define pls pair<long long,string>
#define vpls vector< pair<long long,string> >
#define vplsi vector< pair<long long,string> >::iterator
#define psl pair<string,long long>
#define vpsl vector< pair<string,long long> >
#define vpsli vector< pair<string,long long> >::iterator
#define vvpll vector< vector< pair<long long,long long> > >
#define vvplli vector< vector< pair<long long,long long> > >::iterator
#define mll map<long long,long long>
#define mlli map<long long,long long>::iterator
#define msl map<string,long long>
#define msli map<string,long long>::iterator
#define mls map<long long,string>
#define mlsi map<long long,string>::iterator
#define ud unsigned double
#define vd vector<double>
#define vdi vector<double>::iterator
#define vvd vector< vector<double> >
#define vvdi vector< vector<double> >::iterator
#define vud vector<unsigned double>
#define vudi vector<unsigned double>::iterator
#define pdd pair<double,double>
#define vpdd vector< pair<double,double> >
#define vpddi vector< pair<double,double> >::iterator
#define pds pair<double,string>
#define vpds vector< pair<double,string> >
#define vpdsi vector< pair<double,string> >::iterator
#define psd pair<string,double>
#define vpsd vector< pair<string,double> >
#define vpsdi vector< pair<string,double> >::iterator
#define vvpdd vector< vector< pair<double,double> > >
#define vvpddi vector< vector< pair<double,double> > >::iterator
#define mdd map<double,double>
#define mddi map<double,double>::iterator
#define msd map<string,double>
#define msdi map<string,double>::iterator
#define mds map<double,string>
#define mdsi map<double,string>::iterator
#define vs vector<string>
#define vsi vector<string>::iterator
#define vb vector<bool>
#define vbi vector<bool>::iterator
#define vtrpl vector<trpl>
#define vtrpli vector<trpl>::iterator
#define vvtrpl vector< vector<trpl> >
#define vvtrpli vector< vector<trpl> >::iterator
#define pushb push_back
#define pushf pop_front
#define popb pop_back
#define popf push_front
#define mpair make_pair
#define tostring to_string
#define cntbit(n) __builtin_popcount(n)
#define sqr(n) (n*n)
#define cube(n) (n*n*n)
#define lne '\n'
#define spc ' '
#define ff first
#define ss second
#define mod 1000000007
#define PI acos(-1)
#define infp 1000000000000000000
#define infn -1000000000000000000
#define lsw(n) left<<setw(n)
#define rsw(n) right<<setw(n)
#define usp(n) cout.unsetf(ios::fixed); cout<<setprecision(n);
#define fsp(n) cout.setf(ios::fixed); cout<<setprecision(n);
#define normal cout.setf(ios::fixed); cout<<setprecision(6);
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//#define fileopen FILE *my1=freopen("fileb.txt","r",stdin); FILE *my2=freopen("filec.txt","w",stdout);
#define fileopen system("fileb.txt"); FILE *my1=freopen("fileb.txt","r",stdin); FILE *my2=freopen("filec.txt","w",stdout);
//#define fileopen system("filea.txt"); system("fileb.txt"); FILE *my1=freopen("fileb.txt","r",stdin); FILE *my2=freopen("filec.txt","w",stdout);
#define fileclose fclose(my1); fclose(my2); system("filec.txt");
//#define fileclose fclose(my1); fclose(my2); system("filec.txt"); freopen("CON","w",stdout); string s1="filea.txt",s2="filec.txt"; char *name1=&s1[0], *name2=&s2[0]; FILE *f1=fopen(name1,"r"), *f2=fopen(name2,"r");char c1(spc), c2(spc);if(!f1){ cout<<s1<<" doesn't EXIST"<<lne; exit(0);} if(!f2){ cout<<s2<<" doesn't EXIST"<<lne; exit(0);}ll ex=0, ey=0;while(c1!=EOF && c2!=EOF){c1=getc(f1); c2=getc(f2);if(c1==lne){ ex++; ey=0;}if(c1!=c2){cout<<"ERROR at "<<"("<<1+ex<<","<<ey<<")"<<lne;cout<<c1<<" INSTEAD of "<<c2<<lne;exit(0);}ey++;}fclose(f1); fclose(f2);cout<<"NO ERROR"<<lne;
using namespace std;

class MinHeap// A class for Min Heap
{
    public:
        ll *harr; // poller to array of elements in heap
        ll capacity; // maximum possible size of min heap
        ll heap_size; // Current number of elements in min heap

        MinHeap(ll capacity);// Constructor

        void MinHeapify(ll );// to heapify a subtree with the root at given index

        ll parent(ll i) { return (i-1)/2; }

        ll left(ll i) { return (2*i + 1); }// to get index of left child of node at index i

        ll right(ll i) { return (2*i + 2); }// to get index of right child of node at index

        ll extractMin();// to extract the root which is the minimum element

        void decreaseKey(ll i, ll new_val);// Decreases key value of key at index i to new_val

        ll getMin() { return harr[0]; }// Returns the minimum key (key at root) from min heap

        void deleteKey(ll i);// Deletes a key stored at index i

        void insertKey(ll k);// Inserts a new key 'k'
};


MinHeap::MinHeap(ll cap){// Constructor: Builds a heap from a given array a[] of given size
	heap_size = 0;
	capacity = cap;
	harr = new ll[cap];
}

void MinHeap::insertKey(ll k){// Inserts a new key 'k'
	if (heap_size == capacity) {
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	heap_size++;// First insert the new key at the end
	ll i = heap_size - 1;
	harr[i] = k;
	while (i != 0 && harr[parent(i)] > harr[i]){// Fix the min heap property if it is violated
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
	}
}

void MinHeap::decreaseKey(ll i, ll new_val){// Decreases value of key at index 'i' to new_val. It is assumed that new_val is smaller than harr[i].
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i]){
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
	}
}

ll MinHeap::extractMin(){// Method to remove minimum element (or root) from min heap
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1){
		heap_size--;
		return harr[0];
	}
	ll root = harr[0];// Store the minimum value, and remove it from heap
	harr[0] = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);
	return root;
}

void MinHeap::deleteKey(ll i){// This function deletes key at index i. It first reduced value to minus infinite, then calls extractMin()
	decreaseKey(i, INT_MIN);
	extractMin();
}

void MinHeap::MinHeapify(ll i){// A recursive method to heapify a subtree with the root at given index This method assumes that the subtrees are already heapified
	ll l = left(i);
	ll r = right(i);
	ll smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i) {
		swap(harr[i], harr[smallest]);
		MinHeapify(smallest);
	}
}

int main()
{
//    inout
//    fileopen
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << spc;
	cout << h.getMin() << spc;
	h.decreaseKey(2, 1);
	cout << h.getMin();
//	fileclose
	return 0;
}

