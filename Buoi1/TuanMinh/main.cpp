#include <iostream>
#include<conio.h>

#define MAX 300

using namespace std;

typedef struct {
    int ID;
    char name[50]; // Một mảng các ký tự để lưu tên.
    int term;
    int age;
    int group;
} member;

//khai báo biến
member listmem[MAX];
member tmp;
int totalnumber = 0;
int yesno;

//Khai báo các hàm
int find_member_name(member listmem[MAX]);
int find_member_id(int id);
int add_member(member listmem[MAX]);
int edit_member(member listmem[MAX]);
int delete_member(member listmem[MAX], int id);

int* press_id();
char* press_name();
int* press_term();
int* press_age();
int* press_group();
int main()
{
    int yesno = 1;
    int choose, id;
    while(yesno == 1) {
    cout<<"\n";
    cout<<" ********************* MENU **********************"<<endl;
    cout<<" |    Them thong tin 1 thanh vien :           1  |"<<endl;
    cout<<" |    Xoa thong tin 1 thanh vien  :           2  |"<<endl;
    cout<<" |    Sua thong tin 1 thanh vien  :           3  |"<<endl;
    cout<<" |    Tim thong tin thanh vien bang ID :      4  |"<<endl;
    cout<<" |    Tim thong tin thanh vien bang tuoi :    5  |"<<endl;
    cout<<" |    Tim thong tin thanh vien bang ten nhom: 6  |"<<endl;
    cout<<" |    In ra danh sach thanh vien :            7  |"<<endl;
    cout<<" *************************************************"<<endl;

    cout<<"Mời bạn chọn chức năng: "<<endl;
    cin>>choose;
    switch(choose) {
         case 1:
             add_member(listmem);
             break;
         case 2:
             cout<<"Nhập vào ID thành viên bạn muốn xóa";
             cin>>id;
            delete_member(listmem, id);
            break;
         case 3:
            edit_member(listmem);
            break;
    }
    cout<<"Bạn có muốn tiếp tục không"<<"yes: 1/no: 0"<<endl;;
    cin>>yesno;
    }
    return 0;
}

int *press_id() {
    cout<<"Nhập vào id thành viên: ";
    cin>>tmp.ID;
    return &tmp.ID;
}
char *press_name() {
    cout<<"Nhập vào tên thành viên: ";
    cin>>tmp.name;
    return tmp.name; //nếu để &tmp.name sẽ báo lỗi cannot conver char (*)[50] to char* in return
}
int *press_age() {
    cout<<"Nhập vào tuổi thành viên: ";
    cin>>tmp.age;
    return &tmp.age;
}
int *press_term() {
    cout<<"Nhập vào khóa thành viên: ";
    cin>>tmp.term;
    return &tmp.term;
}
int *press_group() {
    cout<<"Nhập vào nhóm thành viên: ";
    cin>>tmp.group;
    return &tmp.group;
}
int add_member(member listmem[MAX]) {
   for(int i = totalnumber; i<MAX; i++) {
      press_id();
      press_name();
      press_age();
      press_term();
      press_group();
      totalnumber++;
      cout<<"Bạn có muốn tiếp tục không"<<"yes: 1/no: 0";
      cin>>yesno;
      if(yesno == 0) break;
   }
   return 1;
}
int find_member_id(int id) {
    int yesno = 1;
    while(yesno = 1) {

    for(int i = 0; i< totalnumber; i++) {
        if(listmem[i].ID==id) {
            cout<<"Thành viên cần tìm là: "<<endl;
            cout<<"Tên: "<<listmem[i].name;
            cout<<"Tuổi: "<<listmem[i].age;
            cout<<"Khóa: "<<listmem[i].term;
            cout<<"Nhóm: "<<listmem[i].group;
            return i;
        }
      }
    cout<<"Không tìm được thành viên nào có ID như vậy";
    cout<<"Bạn có muốn tiếp tục không"<<"yes: 1/no: 0";
    cin>>yesno;
    if(yesno == 0) return -1;
    }
}
int delete_member(member listmem[MAX], int id) {
   int i = find_member_id(id);
   int yesno = 1;
   if(i = -1) {
    cout<<"Không thể thực hiện xóa";
    cout<<"Bạn có muốn tiếp tục không"<<"yes: 1/no: 0";
    cin>>yesno;
   }
   if(yesno==1) {
    for(; i<totalnumber -1 ;i++) {
        listmem[i] = listmem[i+1];
        totalnumber--;
        cout<<"Xóa thành công";
    }
    return totalnumber;
   }
   if(yesno==0) {
    return totalnumber;
   }
}
int edit_member(member listmem[MAX], int id) {
   int i = find_member_id(id);
   int yesno = 1;
   if(i = -1) {
    cout<<"Không thể thực hiện chỉnh sửa";
    cout<<"Bạn có muốn tiếp tục không"<<"yes: 1/no: 0";
    cin>>yesno;
   }
   if(yesno==1) {
        press_id();
        press_name();
        press_age();
        press_term();
        press_group();
        listmem[i] = tmp;
        cout<<"Cập nhật thành công";
        return i;
}
   if(yesno==0) {
        cout<<"Không thực hiện cập nhật";
    return -1;
   }
}
