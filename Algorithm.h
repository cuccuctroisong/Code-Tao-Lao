#pragma once

void swap(int &a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

int linerSearch(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			return i;
	}
	return -1;
}

int binarySearch(int a[],int n,int x)
{
	int l = 0, r = n - 1;
	while (l<=r)
	{
		int mid = (l+r) / 2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] > x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

void selectionSort(int a[], int n)
{
	for (int k = 0; k < n - 1; k++)
	{
		int pos_min = k;
		for (int i = k + 1; i < n; i++)
		{
			if (a[i] > a[pos_min])// doi dk de doi chieu thu tu
				pos_min = i;
		}
		swap(a[pos_min], a[k]);
	}
}

void insertSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		int pos = i - 1;
		while (pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])// doi dk de doi chieu thu tu
				swap(a[i], a[j]);
		}
	}
}

void bubleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])// doi dk de doi chieu thu tu
				swap(a[j], a[j + 1]);
		}
	}
}

void quickSort(int a[], int left, int right)
{
	int pivot = a[(left + right) / 2];
	int l = left, r = right;
	do {
		while (a[l] < pivot)
			l++;
		while (a[r] > pivot)
			r--;
		if (l <= r)
		{
			swap(a[l], a[r]);
			l++;
			r--;
		}
	} while (l <= r);
	if (left < r)
		quickSort(a, left, r);
	if (right > l)
		quickSort(a, l, right);
}

int *merge(int *a, int n1, int *b, int n2)
{
	int *c = new int[n1 + n2];
	int i = 0, j = 0, dem = 0;
	while (i < n1&&j < n2)
	{
		if (a[i] < b[j])
		{
			c[dem++] = a[i++];
		}
		else
		{
			c[dem++] = b[j++];
		}
	}
	for (int k = i; k < n1; k++)
	{
		c[dem++] = a[k];
	}
	for (int k = j; k < n2; k++)
	{
		c[dem++] = b[k];
	}
	return c;
}

int *mergeSort(int a[], int n)
{
	if (n == 1)
		return a;

	int mid = n / 2;
	int *m1 = new int[mid];
	int *m2 = new int[n - mid];

	for (int i = 0; i < mid; i++)
	{
		m1[i] = a[i];
	}
	for (int i = 0; i < n - mid; i++)
	{
		m2[i] = a[mid + i];
	}

	m1 = mergeSort(m1, mid);
	m2 = mergeSort(m2, n - mid);

	return merge(m1, mid, m2, n - mid);
}

void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}