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
