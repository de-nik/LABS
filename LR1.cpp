#include "TString.h"
int StrLen(const char* Data){
	int size = 0;
	for (; Data[size] != 0; size++);
	return size;
}
void StrCpy(char* first, const char* second){
	for (int i = 0; i < StrLen(first); i++) first[i] = second[i];
}
bool StrCmp(char* first, char* second){
	int i = 0;
	while (first[i] == second[i] && i < StrLen(first)) i++; 
	if (i == StrLen(first)) return true;
	else return false;
}
TString::~TString() {
	if (Data != "")	delete[] Data;
}
TString::TString(){
	Data = "";
}
TString::TString(const TString& rhs) {
	Data = new char[StrLen(rhs.Data) + 1];
	StrCpy(Data, rhs.Data);
}
TString::TString(const char* data){
	Data = new char[StrLen(data) + 1];
	StrCpy(Data, data);
}
TString& TString:: operator =(const TString& rhs){
	if (Data == ""){
		Data = new char[StrLen(rhs.Data) + 1];
		StrCpy(Data, rhs.Data);
	}
	if (this != &rhs){
		Data = new char[StrLen(rhs.Data) + 1];
		StrCpy(Data, rhs.Data);
	}
	return *this;
}
TString& TString::operator +=(const TString& rhs){
	int first = Size(), second = rhs.Size();
	char *data = new char[first + second + 1];
	for (int i = 0; i < first; i++) data[i] = Data[i];
	for (int i = 0; i <= second; i++) data[first + i] = rhs.Data[i];
	Data = data;
	return *this;
}
bool TString::operator ==(const TString &rhs) const{
	int size1 = Size(), size2 = rhs.Size(), i = 0;
	if (size1 != size2) return false;
	while (Data[i] == rhs.Data[i] && Data[i] != '\0' && rhs.Data[i] != '\0') i++;
	if (i == size1)	return true;
	else return false;
}
bool TString::operator <(const TString& rhs) const{
	if (Size() < StrLen(rhs.Data)) return true;
	else return false;
}
size_t TString::Find(const TString& substr) const{
	int pos = 0, check = 0;
	for (int i = 0; i < Size(); i++){
		if (this->Data[i] == substr.Data[0]){
			check++;
			pos = i;
			for (int j = 1; j < StrLen(substr.Data); j++){
				i++;
				if (this->Data[i] == substr.Data[j]) check++;
				else{
					check = 0;
					break;
				}
			}
		}
	}
	if (check == StrLen(substr.Data)) return pos;
	else return -1;
}
void TString::Replace(char oldSymbol, char newSymbol){
	for (int i = 0; i < Size(); i++)
		if (this->Data[i] == oldSymbol) Data[i] = newSymbol;
	}
size_t TString::Size() const{
	return StrLen(Data);
}
bool TString::Empty() const{
	if (StrLen(Data) == 0) return true;
	else return false;
}
char TString::operator[](size_t index) const{
	if (index > Size()) {
		std::cout << "ERROR";
		return 0;
	}
	else {
		std::cout << "Search " << index << " symbol in string: " << this->Data << std::endl << "Symbol: " << std::endl;
		return this->Data[index];
	}
}
char& TString::operator[](size_t index){
	if (index > Size()) std::cout << "Error";
	else return this->Data[index];
}
void TString::RTrim(char symbol){
	int size = Size(), j = 0;
	for (int i = 0; i < size; i++){
		j = size - i;
		if (this->Data[j] != symbol){
			Data[j - 1] = '\0';
			break;
		}
	}
}
void TString::LTrim(char symbol) {
	bool find = false;
	int a = 0, i = 0;
	char* data = new char[Size()];
	for (int i = 0; i < Size(); i++) {
		if (this->Data[i] == symbol) a++;
		else break;
	}
	int c = a;
	for (int i = 0; i < Size() - c; a++, i++) data[i] = this->Data[a];
	data[Size() - c] = '\0';
	this->Data = data;
}
TString operator +(const TString& a, const TString& b){
	TString obj(a);
	obj += b;
	return obj;
}
bool operator!=(const TString& a, const TString& b)
{
	int x = 0, size1 = a.Size(), size2 = b.Size();
	if (size1 != size2) return true;
	for (int i = 0; a[i] == b[i]; i++) x++;
	if (x == size1) return false;
	else return true;
}
bool operator >(const TString& a, const TString& b) {
	TString str1(a), str2(b);
	return(str1.Size() > str2.Size() ? true : false);
}
std::ostream & operator <<(std::ostream &out, const TString & str){
	out << str.Data;
	return out;
}



