#include "Sudoku.h"
#include <cstdlib>
#include <ctime>
using namespace std;
Sudoku::Sudoku(){
	for(int i=0;i<81;i++)
		map[i]=0;
}
void Sudoku::readIn(){
	
	for(int i=0;i<81;i++){
		cin>>map[i];
		}
	}
void Sudoku::printmap(){
	
	for(int i=0;i<81;i++){
		cout<<map[i]<<" ";
		if((i+1)%9==0)
			cout<<"\n";	
		}
	}

bool Sudoku::check(){
	if(checkRow()&&checkCol()&&checkCell())
		return true;
	else
		return false;
}

bool Sudoku::checkRow(){
	int check_arr[9];
	int temp[9];
	for(int i=0;i<9;i++){

		for(int j=0;j<9;j++){
			temp[j]=0;
			check_arr[j]=0;
		}

		for(int j=0;j<9;j++){
			if(map[j+i*9]!=0){
				check_arr[j]=map[j+i*9];
			}
		}
		for(int j=0;j<9;j++){
			if(check_arr[j]!=0)
				++temp[check_arr[j]-1];
		}
		for(int j=0;j<9;j++)
			if(temp[j]>1)
				return false;
	}
	return true;
}

bool Sudoku::checkCol(){

	int check_arr[9];
	int temp[9];
	for(int i=0;i<9;i++){

		for(int j=0;j<9;j++){
			temp[j]=0;
			check_arr[j]=0;
		}		
		for(int j=0;j<9;j++){
			if(map[9*j+i]!=0){
				check_arr[j]=map[9*j+i];
			}
		}	
		for(int j=0;j<9;j++){
			if(check_arr[j]!=0)
				++temp[check_arr[j]-1];
		}
		for(int j=0;j<9;j++)
			if(temp[j]>1)
				return false;		
	}
	return true;
	
}
bool Sudoku::checkCell(){
	int check_arr[9];
	int temp[9];
	int location;
	for(int i=0;i<9;i++){

		for(int j=0;j<9;j++){
			temp[j]=0;
			check_arr[j]=0;
		}
		for(int j=0;j<9;j++){
			location = 27*(i/3)+3*(i%3)+9*(j/3)+(j%3);
			if(map[location]!=0)
				check_arr[j]=map[location];		
		}
		for(int j=0;j<9;j++){
			if(check_arr[j]!=0)
				++temp[check_arr[j]-1];
		}
		for(int j=0;j<9;j++)
			if(temp[j]>1)
				return false;		
	}
		return true;
}


bool Sudoku::solver(int row,int col){
	if(col==9){
			return true;
	}
	if(map[row+col*9]!=0){
			if(row==8){
				if(solver(0,col+1))
					return true;
			}
			else {
				if(solver(row+1,col))
					return true;
			}
			return false;
		}

	for(int i=0;i<9;i++){
		map[row+col*9]=num[i];
		if(check()==true){
			if(row==8){
				if(solver(0,col+1))
					return true;
			}
			else {
				if(solver(row+1,col))
					return true;
			}
		}
			map[row+col*9]=0;
	}
	return false;
}

void Sudoku::solve(){
	int	temp1[81];
	int temp2[81];
	int j=1;
	for(int i=0;i<9;i++){
		num[i]=j;
		j++;
	}
	for(int i=0;i<81;i++){
		temp1[i]=map[i];
	}
	if(check()==false){
		cout<<"0"<<endl;
			return;
	}
	else{
	solver(0,0);
	for(int i=0;i<81;i++){
		if(map[i]==0){
			cout<<"0"<<endl;
				return;
		}
	}
	for(int j=0;j<9;j++){
		for(int i=0;i<81;i++){
			temp2[i]=map[i];
		}
		for(int i=0;i<81;i++){
			map[i]=temp1[i];
		}

		for(int i=0;i<9;i++){
		num[i]+=1;
			if(num[i]==10)
				num[i]=1;
	}
	solver(0,0);		
	for(int i=0;i<81;i++){
			if(map[i]!=temp2[i]){
				cout<<"2"<<endl;
				return;
			}
		}
	}

	for(int i=0;i<81;i++){
			if(map[i]!=temp2[i]){
				cout<<"2"<<endl;
				return;
			}
		}
			cout<<"1"<<endl;
			printmap();
	}

	
}

void Sudoku::changeNum(int a,int b){
	for(int i=0;i<81;i++){
		if(map[i]==a)
			map[i]=b;
		else if(map[i]==b)
			map[i]=a;
	}
}
void Sudoku::changeRow(int a,int b){
	int k;
	switch(a){
		case 1:
			a=27;
			break;
		case 2:
			a=54;
			break;
		}	
	switch(b){
		case 1:
			b=27;
			break;
		case 2:
			b=54;
			break;
		}
		for(int i=0;i<27;i++,a++,b++){
			k=map[a];
			map[a]=map[b];
			map[b]=k;			
		}
}		
void Sudoku::changeCol(int a, int b){
	int k;
	switch(a){
		case 1:
			a=3;
			break;
		case 2:
			a=6;
			break;
		}	
	switch(b){
		case 1:
			b=3;
			break;
		case 2:
			b=6;
			break;
		}
		for(int i=0;i<3;i++,a++,b++){
			for(int j=0;j<9;j++){
				k=map[a+9*j];
				map[a+9*j]=map[b+9*j];
				map[b+9*j]=k;
			}
		}

	}
void Sudoku::rotate(int n){
	int temp[81];
	int i=0,k=0,j=0,m=0;
	for(i=0;i<81;i++){
		temp[i]=map[i];
	}
	
	for(m=0;m<n;m++){
		for(i=0;i<9;i++){
			for(j=8;j>=0;j--,k++){
				map[k]=temp[i+9*j];
			}		
		}
		for(i=0;i<81;i++){
			temp[i]=map[i];
		}
		k=0;
	}
}

void Sudoku::flip(int n){
	int temp[81];
	int i=0,j=0;
	for(i=0;i<81;i++){
		temp[i]=map[i];
	}
	if(n==0){
		for(i=0;i<9;i++){
			for(j=0;j<4;j++){				
				map[j+i*9]=temp[8-j+i*9];
				map[8-j+i*9]=temp[j+i*9];
			}	
		}
	}
	else{
		for(i=0;i<4;i++){
			for(j=0;j<9;j++){
				map[j+9*i]=temp[j+9*(8-i)];
				map[j+9*(8-i)]=temp[j+9*i];
			}
		}
	}
}



void Sudoku::giveQuestion(){	
	int arr[]{8,0,0,0,0,6,0,0,0,
			  0,0,4,0,9,0,6,0,2,
			  9,0,0,0,0,8,0,7,0,
			  0,0,5,0,0,0,0,6,7,
			  0,6,0,1,0,9,0,3,0,
			  7,8,0,0,0,0,4,0,0,
			  0,4,0,8,0,0,0,0,6,
			  5,0,8,0,1,0,3,0,0,
			  0,0,0,9,0,0,0,0,4};

	for(int i=0;i<81;i++){
		cout<<arr[i]<<" ";
		if((i+1)%9==0)
			cout<<"\n";
	
	}
}
void Sudoku::transform(){
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	printmap();
}
