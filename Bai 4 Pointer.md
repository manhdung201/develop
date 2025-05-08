# Tổng quan về pointer
## 1.1 Khái niệm
    pointer là 1 biến dùng để lưu trữ địa chỉ của một biến khác hoặc 1 đối tượng như function, array, struct.
## 1.2 Cách dùng thông thường
  pointer p sẽ trỏ tới biến a ngay khi nó được khởi tạo, giá trị pointer p chính là địa chỉ của biến a
  trong khi sử dụng toán tử truy xuất * sẽ in giá trị địa chỉ đó.
  ```c
  int a = 34;
  int* p = &a;
  printf("address of a:%p\n",p);
  printf("value of a:%d",*p);
  ```
## 1.3 Kích thước
Phụ thuộc vào hệ điều hành, 8byte(64bit) or 4byte (32bit)
  - Kích thước của pointer P được in bằng cách sử dụng hàm sizeof()
  - Pointer p được khai báo là NULL khi chưa gán địa chỉ cụ thể, để tránh nhằm trỏ tới địa chỉ rác gây
  ra lỗi không xác định
 ```c
  int* p = NULL;
  printf("size of a:%d\n",sizeof(p));
```
## 1.4 Kiểu dữ liệu của pointer
Kiểu dữ liệu mà pointer được khai báo cho biết số byte mà nó truy xuất đọc ra trong 1 lần. Ta có ví dụ sau
đây để mình hoạ về kiểu dữ liệu pointer
```c
#include<stdio.h>
#include<stdint.h>
void tach_byte(){
    uint16_t sum = 0xabcd;
    uint8_t* px = (uint8_t*)&sum; 
    uint8_t bit_low = *px;
    uint8_t bit_high = *(px + 1);
    printf("2 bit cao: 0x%x\n 2 bit thap: 0x%x",bit_high,bit_low);
}
int main(){
    tach_byte();
    return 0;
}
```
chương trình trên sử dụng pointer để tách 1 biến 2 byte và lưu vào 2 biến 1 byte với cách làm như sau
- pointer px sẽ trỏ tới địa chỉ của sum, và truy xuất 1 làn 1 byte do nó được khai báo là uint8_t, và
  lưu giá trị mà nó truy xuất vào biến bit_low.
```c
  uint8_t* px = (uint8_t*)&sum; 
  uint8_t bit_low = *px;
```
kết quả
```c
2 bit cao: 0xab 
2 bit thap: 0xcd
```

# Ứng dụng của pointer
## 2.1 Pointer and array
pointer có thể được dùng để thao tác với các phần tử trong mảng bằng cách trỏ tới địa chỉ đầu tiên trong 
array
```c
int arr[] = {2,4,6,8,10};
int* px = &arr; //hoặc arr
```
các phần tử trong mảng có thể được truy cập thông qua việc di chuyển địa chỉ của pointer px
```c
for(int i = 0 ; i < 5 ; i++){
  printf("index %d: %d/n",i,*(px + i));
}
```
kết quả
```c
 index 0: 2
 index 1: 4
 index 2: 6
 index 3: 8
 index 4: 10
```
Ứng dụng: khi ta cần truyển 1 mảng vào trong hàm để xử lý thfi ta cần truyền địa chỉ của nó và dùng 1 pointer
như là tham số cả hàm, lúc này pointer sẽ trỏ tới địa chỉ của mảng mà ta muốn xử lý chứ ko phải cần truyển toàn bộ
mảng vào hàm làm tốn tài nguyên của chương trình.

## 2.2 Pointer to constant
Pointer tới vùng nhớ có chức năng read-only mà không thể thay đổi giá trị tại địa chỉ đó. Tuy nhiên nó có thể trỏ tới địa chỉ khác
```c
int a = 23, b = 78;
const int* p = &a;
printf("truoc *p: %d\n",*p);
//*p = 23; -> sai
p = &b;
printf("sau *p: %d\n",*p);
```
kết quá
```
truoc: 23
sau: 78
```
Ứng dụng: tạ có thể sử dụng con trỏ hằng để bảo vệ dữ liệu quan trọng mà không muón bị tác động thay đổi trong quá trình thực
thi chương trình.

## 2.3 Constant pointer (Hằng con trỏ)
pointer có thể thay đổi giá trị của địa chỉ mà nó trỏ tới nhưng không thể trỏ sang vùng nhớ khác
```c
int a = 23, b = 78;
int* const p = &a;
printf("truoc *p: %d\n",*p);
//p = &b; -> sai
*p = 45;
printf("sau *p: %d\n",*p);
```
kết quả
```
truoc: 23
sau: 45
```
Ứng dụng: Hằng con trỏ có thể được dùng để lưu trữ địa chỉ của 1 thanh ghi và chỉ thao tác với giá trị trên thanh ghi đó,
giúp tách biệt và xử lý chính xác trên thanh ghi mà ta mong muốn.

## 2.4 VOID POINTER (con trỏ vô định)
Con trỏ có thể trỏ tới bất kỳ dữ liệu nào
- Con trỏ p dưới đây sau khi trỏ tới biến a sẽ được ép lại theo kiểu dữ liệu mà nó trỏ tới và dùng
toán tử truy xuất * để lấy giá trị tại địa chỉ đó.
```c
int a = 43;
void* p = &a;
printf("%d",*((int*)p));
```
- Con trỏ VOID có cũng có thể dùng để trỏ tới 1 mảng lưu trữ nhiều giá trị đa dữ liệu
```c
    double c = 765656.65653;
    float d = 23.54;
    int e = 21;
    char f = 'e';
    void* ph[] = {&c,&d,&e,&f};
    printf("c = %lf\n",*((double*)ph[0]));
    printf("d = %.2f\n",*((float*)ph[1]));
    printf("e = %d\n",*((int*)ph[2]));
    printf("f = %c\n",*((char*)ph[3]));
```
kết quả
```
c = 765656.656530
d = 23.54
e = 21
f = e
```
Ứng dụng: Con trỏ void có thể được dùng truyền nhiều loại dữ liệu khác nhau mà không cần phải viết lại hàm cho mỗi loại kiểu
dữ liệu riêng biệt, giúp tối ưu và rút gọn chương trình.

## 2,5 Function pointer (con trỏ hàm)
pointer lưu địa chỉ của một  hàmm có cấu trúc
```c
Cách khai báo: (*pointer_name)(input parameter)
```
Ta có thể gọi 1 hàm thông qua con trỏ như sau:
```c
void print(){
  printf("hello world");
}
int main(){
  void (*ptr)();
  ptr = print; //gán địa chỉ hàm print cho con trỏ ptr
  ptr(); //gọi con trỏ ptr để thực hiện hàm print
}
```
Ta có thể gọi nhiều hàm thông qua việc trỏ tới từng hàm:
CÁCH1
```c
//định nghĩa các hàm
void Tong(int a,int b){
    printf("%d + %d = %d\n",a,b,a + b);
}
void Hieu(int a,int b){
    printf("%d - %d = %d\n",a,b,a - b);
}
void Tich(int a,int b){
    printf("%d x %d = %d\n",a,b,a*b);

}
void Thuong(int a,int b){
    if(b != 0)
       printf("%d / %d = %.2f\n",a,b,(float)a/b);
    else printf("value of b is invalid\n");
}
```
trong hàm main ta khai báo 1 con trỏ kiểu void với tham số truyền vào lần lượt trỏ tới từng hàm và
truyển vào các giá trị để thực thi sau void(*operator)(int, int)
```c
int main(){
  void (*operator)(int,int);
  operator = Tong;
  operator(34,56);

  operator = Hieu;
  (*operator)(84,96);

  operator = Tich;
  operator(34,5);

  operator = Thuong;
  operator(34,12);
  return 0;
}
```
kết quả
```
34 + 56 = 90
84 - 96 = -12
34 x 5 = 170
34 / 12 = 2.83
```
CÁCH 2
- Ngoài ra ta cũng có thể sử dụng con trỏ hàm như 1 đối số truyền vào, bằng cách
```c
void Operator(void (*op)(int,int),int a,int b){
    op(a,b);
}
```
- Ta sẽ gọi hàm trên ở trong main, và lần lượt truyền địa chỉ các hàm vào, cùng với giá trị để tính toán là a và bit_high
```c
int main(){
  int a = 23 , b = 2;
  void (*operator)(int,int);
  Operator(Tong,a,b);
  Operator(Hieu,a,b);
  Operator(Tich,a,b);
  Operator(Thuong,a,b);
  return 0;
}
```
CÁCH3
- Ta cũng có thể tạo 1 mảng con trỏ hàm để trỏ tới từng địa chỉ của các hàm và sử dụng chúng như sau
```c
int main(){
 void (*opeArr[])(int,int) = {Tong,Hieu,Tich,Thuong};
    for(int n = 0 ; n < 4 ; n++){
        opeArr[n](a,b);
    }
return 0;
}
```
Ta truy xuất và gọi các hàm thông qua việc sử dụng chỉ số và tăng giá trịi của nó mỗi khi di chuyển đến địa chỉ và hàm tiếp theo

Ứng dụng: Ta có thể dụng con trỏ hàm ứng dụng trong việc chọn hàm mà ta muốn xử lý ở những thời điểm khác nhau trong chương trình
thông qua 1 con trỏ duy nhất, giúp tăng tốc và tiết keiemj thời gia mỗi hàm thông qua việ truy cập chúng bằng pointer

