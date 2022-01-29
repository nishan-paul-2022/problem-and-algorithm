struct node
{
	int prior,size;
	int val; ///value stored in the array
	int sum; ///whatever info you want to maintain in segtree for each node
	int lazy; ///whatever lazy update you want to do
	struct node *l,*r;
};
typedef node* pnode;
int SZ(pnode t)
{
    return t ? t->size : 0;
}
void upd_sz(pnode t)
{
    if(t)t->size = SZ(t->l) + SZ(t->r) + 1;
}
void lazy(pnode t)
{
	if(!t || !t->lazy)return;
	t->val += t->lazy; ///operation of lazy
	t->sum += t->lazy * SZ(t);
	if(t->l)t->l->lazy += t->lazy;///propagate lazy
	if(t->r)t->r->lazy += t->lazy;
	t->lazy = 0;
}
void reset(pnode t)
{
	if(t)t->sum = t->val;///no need to reset lazy coz when we call this lazy would itself be propagated
}
void combine(pnode& t,pnode l,pnode r)
{
	///combining two ranges of segtree
	if(!l || !r)return void(t = l ? l : r);
	t->sum = l->sum + r->sum;
}
void operation(pnode t)
{
	///operation of segtree
	if(!t)return;
	reset(t);///reset the value of current node assuming it now represents a single element of the array
	lazy(t->l);lazy(t->r);///imp:propagate lazy before combining t->l,t->r;
	combine(t,t->l,t);
	combine(t,t,t->r);
}
void Split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
	if(!t)return void(l = r = NULL);
	lazy(t);
	int curr_pos = add + SZ(t->l) + 1;
	if(curr_pos <= pos)Split(t->r,t->r,r,pos,curr_pos),l = t;///element at pos goes to left subtree(l)
	else Split(t->l,l,t->l,pos,add),r = t;
	upd_sz(t);
	operation(t);
}
void Merge(pnode &t,pnode l,pnode r)
{
	///l->leftarray,r->rightarray,t->resulting array
	lazy(l);lazy(r);
	if(!l || !r) t = l ? l : r;
	else if(l->prior > r->prior)Merge(l->r,l->r,r),t = l;
	else Merge(r->l,l,r->l),t = r;
	upd_sz(t);
	operation(t);
}
pnode init(int val)
{
	pnode ret = new node();
	ret->prior = rand();
	ret->size = 1;
	ret->val = val;
	ret->sum = val;
	ret->lazy = 0;
	return ret;
}
void ArrayInsert(pnode &t,pnode it,int pos)
{
	pnode L,R,tmp;
	Split(t,L,R,pos);
	Merge(L,L,it);
	Merge(t,L,R);
}
void ArrayDelete(pnode &t,int pos)
{
	pnode L,R,tmp;
	Split(t,L,R,pos);
	Split(L,L,tmp,pos-1);
	Merge(t,L,R);
}
int ArrayValue(pnode t,int pos)
{
	int cur = 1 + SZ(t->l);
	if(cur == pos)return t->val;
	if(cur < pos)return ArrayValue(t->r,pos-cur);
	else return ArrayValue(t->l,pos);
}
int query(pnode t,int l,int r)
{
	///[l,r]
	pnode L,mid,R;
	Split(t,L,mid,l-1);
	Split(mid,t,R,r-l+1);///note: r-l!!
	int ans = t->sum;
	Merge(mid,L,t);
	Merge(t,mid,R);
	return ans;
}
void update(pnode t,int l,int r,int val)
{
	///[l,r]
	pnode L,mid,R;
	Split(t,L,mid,l-1);
	Split(mid,t,R,r-l+1);///note: r-l!!
	t->lazy += val; ///lazy_update
	Merge(mid,L,t);
	Merge(t,mid,R);
}

