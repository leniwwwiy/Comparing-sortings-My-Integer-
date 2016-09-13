#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <list>
#include <clocale>
#include <ctime>
#include <cmath>
#include <random>
#include <cassert>
#include <stdio.h>

using namespace std;

typedef double db;

int cpris, csrav;

#define all(s) s.begin(),s.end()
#define f(a, b, c) for (int i=a; i<b; i+=c)

struct Integer{
	int val;
	Integer(int i) : val(i) {}
	Integer() {}

	Integer(const Integer& other) {
		val = other.val;
		++cpris;
	}
	friend const Integer operator+(const Integer& left, const Integer& right);

	friend Integer& operator+=(Integer& left, const Integer& right);

	friend bool operator==(const Integer& left, const Integer& right);

	Integer& operator=(const Integer& right) {
		cpris++; csrav++;
		Integer tmp(right);
		swap(tmp.val, val);
		return *this;
	}
};

const Integer operator+(const Integer& left, const Integer& right) {
	return Integer(left.val + right.val);
}

Integer& operator+=(Integer& left, const Integer& right) {
	left.val += right.val;
	return left;
}

bool operator==(const Integer& left, const Integer& right) {
	csrav++;
	return left.val == right.val;
}

bool operator!=(const Integer& left, const Integer& right) {
	csrav++;
	return left.val != right.val;
}

bool operator>(const Integer& left, const Integer& right) {
	csrav++;
	return left.val > right.val;
}

bool operator>=(const Integer& left, const Integer& right) {
	csrav++;
	return left.val >= right.val;
}

bool operator<(const Integer& left, const Integer& right) {
	csrav++;
	return left.val < right.val;
}

bool operator<=(const Integer& left, const Integer& right) {
	csrav++;
	return left.val <= right.val;
}

void shell_sort(vector<Integer> &a){
	int N = a.size();
	for (int d = N / 2; d > 0; d /= 2)
		for (int i = d; i < N; i++)
			for (int j = i; j >= d && a[j - d] > a[j]; j -= d)
				swap(a[j], a[j - d]);
}

void shake_sort(vector<Integer> &a){
	int Start = 0, N = a.size(), l = Start, r = N - 1;
	do
	{
		for (int i = r; i > l; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
			}
		}

		l++;
		for (int i = l; i < r; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
			}
		}

		r--;
	} while (l <= r);
}

void print(vector<Integer> &a, int Start, char c){
	int N = a.size();
	for (int i = Start; i < N; i++)
		cout << a[i].val << c;
}

int compare(const void * a, const void * b)
{
	if (*(Integer*)a < *(Integer*)b) return -1;
	if (*(Integer*)a == *(Integer*)b) return 0;
	if (*(Integer*)a > *(Integer*)b) return 1;
}

int Partition(vector<Integer> &a, int beg, int end){
	Integer pivot = a[beg];
	int p = beg, loc;
	for (loc = beg + 1; loc <= end; loc++)
	{
		if (pivot>a[loc])
		{
			a[p] = a[loc];
			a[loc] = a[p + 1];
			a[p + 1] = pivot;

			p = p + 1;
		}
	}
	return p;
}

void qusort(vector<Integer> &a, int beg, int end){
	if (beg < end){
		int p = Partition(a, beg, end);

		qusort(a, beg, p - 1);
		qusort(a, p + 1, end);
	}
}

void bubble_sort(vector<Integer> a){
	int n = a.size();
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j<n; j++)
			if (a[i]>a[j])
				swap(a[i], a[j]);
}

void merge(vector<Integer> &a, const int low, const int mid, const int high){
	vector<Integer>b(high + 1 - low);
	int h, i, j, k;
	h = low;
	i = 0;
	j = mid + 1;
	while ((h <= mid) && (j <= high)){
		if (a[h] <= a[j]){
			b[i] = a[h];
			h++;
		}
		else{
			b[i] = a[j];
			j++;
		}
		i++;
	}
	if (h > mid){
		for (k = j; k <= high; k++){
			b[i] = a[k];
			i++;
		}
	}
	else{
		for (k = h; k <= mid; k++){
			b[i] = a[k];
			i++;
		}
	}
	for (k = 0; k <= high - low; k++) {
		a[k + low] = b[k];
	}
}

void InsertionSort(vector<Integer> &a) {
	int N = a.size();
	for (int i = 1; i < N; i++) {
		Integer CurEl = a[i];
		int Index = i - 1;
		while (Index >= 0 && a[Index] > CurEl) {
			a[Index + 1] = a[Index];
			a[Index] = CurEl;
			Index--;
		}
	}
}

void merge_sort(vector<Integer> &a, const int low, const int high){
	int mid;
	if (low < high){
		mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

default_random_engine gen(time(0));
void genera(vector<Integer> &a){
	normal_distribution<double> dist(0, 100);
	for (int i = 0; i < a.size(); i++)
		a[i] = dist(gen);
}

void better_bubble_sort(vector<Integer> &a){
	int n = a.size(), i, ilast, j, h = 0;
	for (i = 0; i < n - 1; i++){
		ilast = 0;
		for (j = n - 1; j > h; j--){
			if (a[j - 1] > a[j]){
				ilast = j;
				swap(a[j - 1], a[j]);
			}
		}
		h = ilast;
		if (ilast == 0)
			break;
	}
}


int main(){
	vector<Integer> a(100), b, c;
	genera(a);
	b = a; c = a;
	cpris = 0; csrav = 0;
	bubble_sort(a);
	cout << "Buble sort:" << '\n' << cpris << ' ' << csrav << '\n';
	cpris = 0; csrav = 0;
	better_bubble_sort(b);
	cout << "Better_buble sort:" << '\n' << cpris << ' ' << csrav << '\n';
	cpris = 0; csrav = 0;
	bin_insert(c);
	cout << "Shake sort:" << '\n' << cpris << ' ' << csrav << '\n';
	return 0;
}

//shake_sort, shell_sort, merge_sort, buble_sort, qusort, InsertionSort;