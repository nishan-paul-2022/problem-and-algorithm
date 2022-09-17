struct node
{
    int val,prior,size;
    struct node *l,*r;
    void Show()
    {
		printf("address : %d\n",&val);
		printf("val %d prior %d size %d\n",val,prior,size);
		printf("left %d right %d\n",l,r);
		puts("----------------------------");
    }
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
void Split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t)l = r = 0;
    else if(t->val <= key)Split(t->r,t->r,r,key),l = t; //elem=key comes in l
    else Split(t->l,l,t->l,key),r = t;
    upd_sz(t);
}
void Merge(pnode &t,pnode l,pnode r)
{
    if(!l || !r)t = l ? l : r;
    else if(l->prior > r->prior)Merge(l->r,l->r,r),t = l;
    else Merge(r->l,l,r->l),t = r;
    upd_sz(t);
}
void Insert(pnode &t,pnode it)
{
	if(!t)t = it;
	else if(it->prior > t->prior)Split(t,it->l,it->r,it->val),t = it;
	else Insert(t->val <= it->val ? t->r : t->l,it);
	upd_sz(t);
}
void Erase(pnode &t,int key)
{
	if(!t)return;
	else if(t->val == key)
	{
		pnode temp = t;
		Merge(t,t->l,t->r);
		free(temp);
	}
	else Erase(t->val < key ? t->r : t->l,key);
	upd_sz(t);
}
pnode init(int val)
{
	pnode ret = new node();
	ret->val = val;
	ret->size = 1;
	ret->prior = rand();
	ret->l = ret->r = 0;
	return ret;
}
void dfs(pnode t)
{
	if(!t)return;
	t->Show();
	if(t->l)dfs(t->l);
	if(t->r)dfs(t->r);
}

