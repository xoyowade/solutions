class Solution
{
public:
    double findKth(int A[], int m, int B[], int n, int k)
    {
        // ensure m > n
        if (m < n) {
            return findKth(B, n, A, m, k);
        }
        if (n == 0) {
            return A[k];
        }
        if (k == 0) {
            return min(A[0], B[0]);
        }
        
        int b = min(k/2, n-1);
        int a = k - b - 1;
        
        if (A[a] > B[b]) {
            return findKth(A, a+1, B+b+1, n-b-1, k-b-1);
        } else if (A[a] < B[b]) {
            return findKth(A+a+1, m-a-1, B, b+1, k-a-1);
        } else {
            return A[a];
        }
    }

	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
        int total = m + n;
        if (total % 2 == 1) {
            return findKth(A, m, B, n, total/2);
        } else {
            return (findKth(A, m, B, n, total/2-1) + 
                    findKth(A, m, B, n, total/2))/2;
        }
	}
};
