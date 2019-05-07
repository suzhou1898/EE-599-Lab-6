#include "sort.h"

Sort::Sort(string filename,int n){
	ifstream infile;
	this->n=n;
	num=new int[n];
	infile.open(filename.c_str(),ios::in);
	for(int i=0;i<n;i++){
		infile>>num[i];
	}
	for(int i=0;i<n;i++)
		cout<<num[i]<<' ';
	infile.close();
}

Sort::~Sort(){
	delete []num;
}

void Sort::method(int n){
	if(n==1)
		bubbleSort();
	else if(n==2)
		selectionSort();
	else if(n==3)
		mergeSort();
	else if(n==4)
		quickSort();
	else if(n==5)
		radixSort();
}

void Sort::bubbleSort(){
	int oldn=n;
	int temp,newn;
	while(oldn!=0){
		newn=0;
		for(int i=0;i<oldn;i++){
			if(num[i-1]>num[i]){
				temp=num[i-1];
				num[i-1]=num[i];
				num[i]=temp;
				newn=i;
			}
		}
		oldn=newn;
	}
}

void Sort::selectionSort(){
	int temp,index,min;
	for(int i=0;i<n-1;i++){
		min=num[i];
		index=i;
		for(int j=i+1;j<n;j++){
			if(min>num[j]){
				min=num[j];
				index=j;
			}
		}
		temp=num[i];
		num[i]=num[index];
		num[index]=temp;
	}
}

void Sort::merge(int st,int mid,int ed,int *temp){
	int i=st,j=mid+1;
	int m=mid,n=ed;
	int k=0;
	while(i<=m && j<=n){
		if(num[i]<=num[j]){
			temp[k++]=num[i++];
		}
		else{
			temp[k++]=num[j++];
		}
	}
	while(i<=m){
		temp[k++]=num[i++];
	}
	while(j<=n){
		temp[k++]=num[j++];
	}
	for(int i=0;i<k;i++){
		num[st+i]=temp[i];
	}
}

void Sort::mergesort(int st,int ed,int *temp){
	if(st<ed){
		int mid=(st+ed)/2;
		mergesort(st,mid,temp);
		mergesort(mid+1,ed,temp);
		merge(st,mid,ed,temp);
	}
}

void Sort::mergeSort(){
	int *temp=new int[n];
	mergesort(0,n-1,temp);
	delete []temp;
}

int Sort::quicksort(int st,int ed){
	int i,j,temp;
	temp=num[st];
	i=st;
	j=ed;
	while(i!=j){
		while(num[j]>=temp && j>i){
			j--;
		}
		if(j>i){
			num[i]=num[j];
			i++;
		}
		while(num[i]<=temp && i<j){
			i++;
		}
		if(i<j){
			num[j]=num[i];
			j--;
		}
	}
	num[i]=temp;
	return i;
}

void Sort::conquer(int st,int ed){
	if (st < ed)
	{
		int i = quicksort(st, ed);
		conquer(st, i - 1);
		conquer(i + 1, ed);
	}

}

void Sort::quickSort(){
	conquer(0,n-1);
}

void Sort::radixSort() {
	int max = num[0];
	for (int i = 0; i < n; i++) {
		if (max < num[i])
			max = num[i];
	}

	int count[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int *output = new int[n];
	for (int i = 1; max >= (pow(10, (double)i-1)); i++) {
		int exp = pow(10, (double)i - 1);
		for (int j = 0; j < n; j++) {
			count[num[j] / exp % 10]++;
		}
		for (int j = 1; j < 10; j++)
			count[j] = count[j] + count[j-1];
		for (int j = n-1; j>=0; j--) {
			output[count[num[j] / exp % 10]-1] = num[j];
			count[num[j] / exp % 10]--;
		}
		for (int j = 0; j < n; j++) {
			num[j] = output[j];
		}
		for (int i = 0; i < 10; i++) {
			count[i] = 0;
		}
	}
}

void Sort::printdt(string filename){
	ofstream outfile;
	outfile.open(filename.c_str(),ios::out);
	for(int i=0;i<n;i++)
		outfile<<num[i]<<' ';
	outfile.close();
}
