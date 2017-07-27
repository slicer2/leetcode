#include <iostream>
using namespace std;

class Solution {
	public:
		int maxProduct(int A[], int n) {
			int maxProd = A[0];
			int maxProdR = A[0];
			int minProdR = A[0];
			int lowerEdgeMaxProdR = 0;
			int lowerEdgeMinProdR = 0;
			int lowerEdgeMax = 0;
			int upperEdgeMax = 0;

			for (int i=1; i<n; i++)
			{
				if (A[i] == 0) {
					maxProdR = 0;
					minProdR = 0;
					lowerEdgeMaxProdR = i;
					lowerEdgeMinProdR = i;
				}
				else {
					if (A[i] > 0) {
						if (maxProdR > 0)
							maxProdR *= A[i];
						else {
							maxProdR = A[i];
							lowerEdgeMaxProdR = i;
						}


						if (minProdR < 0)
							minProdR *= A[i];
						else {
							if (minProdR > 0) {
								minProdR = A[i];
								lowerEdgeMinProdR = i;
							}
						}
					}

					if (A[i] == 0) {
						maxProdR = 0;
						minProdR = 0;
						lowerEdgeMaxProdR = i;
						lowerEdgeMinProdR = i;
					}

					if (A[i] < 0) {
						int t_maxProdR = maxProdR;
						int t_minProdR = minProdR;
						int t_lowerEdgeMaxProdR = lowerEdgeMaxProdR;
						int t_lowerEdgeMinProdR = lowerEdgeMinProdR;

						if (maxProdR > 0) {
							t_minProdR = maxProdR * A[i];
							t_lowerEdgeMinProdR = lowerEdgeMaxProdR;
						}
						else {
							t_minProdR = A[i];
							t_lowerEdgeMinProdR = i;
						}


						if (minProdR <= 0) {
							t_maxProdR = minProdR * A[i];
							t_lowerEdgeMaxProdR = lowerEdgeMinProdR;
						}
						else {
							t_maxProdR = A[i];
							lowerEdgeMaxProdR = i;
						}

						maxProdR = t_maxProdR;
						minProdR = t_minProdR;
						lowerEdgeMaxProdR = t_lowerEdgeMaxProdR;
						lowerEdgeMinProdR = t_lowerEdgeMinProdR;
					}
				}


				if (maxProdR > maxProd) {
					maxProd = maxProdR;
					lowerEdgeMax = lowerEdgeMaxProdR;
					upperEdgeMax = i;
				}
				/*
				cout<<"i="<<i<<" A[i]="<<A[i]<<" maxProd="<<maxProd<<" lowerEdgeMax="<<lowerEdgeMax<<" upperEdgeMax="<<upperEdgeMax
				    <<" maxProdR="<<maxProdR<<" lowerEdgeMaxProdR="<<lowerEdgeMaxProdR<<" minProdR="<<minProdR
					<<" lowerEdgeMinProdR="<<lowerEdgeMinProdR<<endl;
				*/
			}

			/* cout<<"lower edge = "<<lowerEdgeMax<<"\tupper edge = "<<upperEdgeMax<<endl; */
			return maxProd;
		}
};


int main()
{
	int n;
	cin>>n;
	int *A = new int[n];

	for (int i=0; i<n; i++)
		cin>>A[i];

	Solution s;
	cout<<s.maxProduct(A, n)<<endl;
	return 0;
}
