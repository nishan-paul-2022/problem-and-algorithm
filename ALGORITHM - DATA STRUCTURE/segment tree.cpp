#include<bits/stdc++.h>
using namespace std;

int get_mid(int s, int e) { 
    return (s+e)/2; 
}

void update_value_back(int *st, int ss, int se, int i, int diff, int si) {

	if (i < ss || i > se)
		return;

	st[si] = st[si] + diff;

	if (se != ss) {
		int mid = get_mid(ss, se);
		update_value_back(st, ss, mid, i, diff, 2*si + 1);
		update_value_back(st, mid+1, se, i, diff, 2*si + 2);
	}
}

void update_value(int arr[], int *st, int n, int i, int new_val) {

	if (i < 0 || i > n-1) {
		printf("invalid input");
		return;
	}

	int diff = new_val - arr[i];

	arr[i] = new_val;

	update_value_back(st, 0, n-1, i, diff, 0);
}

int get_sum_back(int *st, int ss, int se, int qs, int qe, int si) {

	if (qs <= ss && qe >= se)
		return st[si];

	if (se < qs || ss > qe)
		return 0;

	int mid = get_mid(ss, se);

	return get_sum_back(st, ss, mid, qs, qe, 2*si+1) + get_sum_back(st, mid+1, se, qs, qe, 2*si+2);
}

int get_sum(int *st, int n, int qs, int qe) {

	if (qs < 0 || qe > n-1 || qs > qe) {
		printf("Invalid Input");
		return -1;
	}

	return get_sum_back(st, 0, n-1, qs, qe, 0);
}

int construct_back(int arr[], int ss, int se, int *st, int si) {

	if (ss == se) {
		st[si] = arr[ss];
		return arr[ss];
	}

	int mid = get_mid(ss, se);

	st[si] = construct_back(arr, ss, mid, st, si*2+1) + construct_back(arr, mid+1, se, st, si*2+2);

	return st[si];
}

int* construct(int arr[], int n) {

	int x = (int)(ceil(log2(n)));

	int max_size = (int)pow(2, x+1) - 1;

	int *st = new int[max_size];

	construct_back(arr, 0, n-1, st, 0);

	return st;
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(arr)/sizeof(arr[0]);

	int *st = construct(arr, n);

	printf("%d \n", get_sum(st, n, 1, 3));

	update_value(arr, st, n, 1, 10);

	printf("%d \n", get_sum(st, n, 1, 3));

	return 0;
}
