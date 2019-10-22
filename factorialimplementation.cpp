/*this method is used to calculate the factorial of large numbers and the max size we are using to calculate the value is 500
and so we can use this code to calculate the factorial of large numbers for which we get integer overflows due to the large 
size.
*/

#define MAX 500
int res[MAX];

void factorial(int n){
	int res[MAX];
	res[0] = 1;
	int res_size = 1;
	
	for (int i = 2; i<=n; i++)
		multiply(res,i,res_size);
		
		for(int a = res_size -1;a>=0; a--){
					cout<< res[a];
					}
					
void multiply(int res[], int x,int res_size){
		int carry =0;
		for (int i = 0; i< res_size;i++){
			int prod = res[i]*x+carry;
			res[i] = prod%10;
			carry = prod/10;
			}
			while (carry){
					res[res_size]= carry%10;
					carry = carry/10;
					res_size++;
					}
					}
