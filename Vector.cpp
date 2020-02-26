#include<iostream>

using namespace std;

class Vector{
	private:
		int sochieu;
		int giaTri[15];
	public:
		bool check;
		Vector(){
			sochieu = 1;
			giaTri[0] = 0;
			check = true;
		}
		
		friend ostream &operator << (ostream &out , Vector &v){
			out << "( ";
			for(int i = 0 ; i < v.sochieu ; ++i){
				if(i != v.sochieu - 1)
					out << v.giaTri[i] << " ; ";
				else
					out << v.giaTri[i] << " )" << endl;
			}
			return out;
		}
		
		friend istream &operator >> (istream &in , Vector &v){
			cout << "Nhap so chieu cua vector : ";
			in >> v.sochieu;
			cout << "Nhap vector " << v.sochieu << " chieu : ";
			for(int i = 0 ; i < v.sochieu ; ++i){
				in >> v.giaTri[i];
			}
			return in;
		}
		
		Vector operator + (Vector &v){
			Vector v1 = v;
			if(sochieu != v.sochieu){
				cout << "Khong the cong hai vector nay !!!!\n";
				v1.check = false;
			}
			else{
				for(int i = 0 ; i < v.sochieu ; ++i){
					v1.giaTri[i] = giaTri[i] + v.giaTri[i];
				}
			}
			return v1;
		}
		
		Vector operator *(Vector &v){
			Vector v1 = v;
			if(sochieu != v.sochieu){
				cout << "Khong the thuc hien tich vo huong cua hai vector nay !!!\n";
				v1.check = false;
			}
			else{
				for(int i = 0 ; i < v.sochieu ; ++i){
					v1.giaTri[i] = giaTri[i] * v.giaTri[i];
				}
			}
			return v1;
		}
};

int main(){
	Vector v1 , v2 , tmp1 , tmp2;
	cout << "Nhap thong so cua 2 vector\n";
	cout << "Vector 1 \n";
	cin >> v1;
	cout << "Vector 2 \n";
	cin >> v2;
	tmp1 = v1 + v2;
	tmp2 = v1 * v2;
	if(tmp1.check ){
		cout << "Tong cua 2 vector vua nhap la : ";
		cout << tmp1;
		cout << "Tich vo huong cua 2 vector la : ";
		cout << tmp2;
	}
	return 0;
}
